`include "Const.svh"
/* verilator lint_off WIDTH */
/* verilator lint_off UNDRIVEN */
module Bellman(input logic clk, reset,
               input logic [`PRED_WIDTH:0] src,
               input logic signed [`WORD_WIDTH:0] adjmat [`NODES:0][`NODES:0], //Edges are signed
               output logic [`WORD_WIDTH:0] vertmat [`NODES:0], //Not signed since both pred and weight
               output logic done,
               output logic [`WORD_WIDTH:0] test);

  enum logic [4:0] {SETUP, READ_SOURCE, READ_DESTINATION, WRITE_DESTINATION_PRED, WRITE_DESTINATION_WEIGHT, DONE} state;
  logic [`PRED_WIDTH:0] i, j, k; //Indices
  logic signed [`WEIGHT_WIDTH:0] svw, dvw; //Source Vertex Weight, Destination Vertex Weight, Signed
  logic signed [`WORD_WIDTH:0] e; //Edge Weight, Signed

  always_ff @(posedge clk) begin
    if (reset) begin
      i <= 0;
      j <= 0;
      k <= 0;
      done <= 0;
      state <= SETUP;
    end else case (state)
      SETUP: begin
        if (k == `NODES) begin
          state <= READ_SOURCE;
          k <= 0; //V-1 Iterations below
        end else if (k == src) begin
          vertmat[k][`WEIGHT_WIDTH:0] <= 0;
          k <= k + 1;
        end else begin
          vertmat[k][`WEIGHT_WIDTH:0] <= `WEIGHT_WIDTH'hffffff; //INT MAX; THIS WILL CHANGE WITH WIDTH
          k <= k + 1;
        end
      end
      READ_SOURCE: begin
        svw <= vertmat[i][`WEIGHT_WIDTH:0];
        e <= adjmat[i][j];
        state <= READ_DESTINATION;
      end
      READ_DESTINATION: begin
        dvw <= vertmat[j][`WEIGHT_WIDTH:0];
        state <= WRITE_DESTINATION_PRED;
      end
      WRITE_DESTINATION_PRED: begin
        if (e != 0 && svw[`WEIGHT_WIDTH:0] + e < dvw[`WEIGHT_WIDTH:0]) begin
          vertmat[j][`WORD_WIDTH:(`WEIGHT_WIDTH+1)] <= i;
        end
        state <= WRITE_DESTINATION_WEIGHT;
      end
      WRITE_DESTINATION_WEIGHT: begin
        if (e != 0 && svw[`WEIGHT_WIDTH:0] + e < dvw[`WEIGHT_WIDTH:0]) begin
          vertmat[j][`WEIGHT_WIDTH:0] <= svw[`WEIGHT_WIDTH:0] + e;
        end
        if (j+1 == `NODES && i+1 == `NODES && k + 1 == `NODES - 1) begin //V-1 Times
          state <= DONE;
        end else if (j+1 == `NODES && i+1 == `NODES) begin
          i <= 0;
          j <= 0;
          k <= k + 1;
          state <= READ_SOURCE;
        end else if (j == `NODES) begin
          i <= i + 1;
          j <= 0;
          state <= READ_SOURCE;
        end else begin
          j <= j + 1;
          state <= READ_SOURCE;
        end
      end
      DONE: done <= 1;
      default: state <= DONE;
    endcase
  end
endmodule
