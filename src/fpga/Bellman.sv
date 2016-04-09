`include "Const.vh"

module Bellman(input logic clk, bellman_reset,
               input logic [`PRED_WIDTH:0] src,
					/*Vertmat/Adjmat Read Inputs*/
					input logic [`VERT_WIDTH:0] vertmat_q,
					input logic [`WEIGHT_WIDTH:0] adjmat_q,
					/*VertMat Memory*/
					output logic [`VERT_WIDTH:0] vertmat_data,
   	 		   output logic [`PRED_WIDTH:0] vertmat_addr,
				   output logic vertmat_we,
					/*AdjMat Memory*/
				   output logic [`WEIGHT_WIDTH:0] adjmat_data,
				   output logic [`PRED_WIDTH:0] adjmat_row_addr,
				   output logic [`PRED_WIDTH:0] adjmat_col_addr,
				   output logic adjmat_we,
               output logic bellman_done);

  enum logic [4:0] {SETUP, READ_SOURCE, READ_DESTINATION, WRITE_DESTINATION_PRED, WRITE_DESTINATION_WEIGHT, DONE} state;
  logic [`PRED_WIDTH:0] i, j, k; //Indices
  logic signed [`WEIGHT_WIDTH:0] svw, dvw; //Source Vertex Weight, Destination Vertex Weight, Signed
  logic signed [`WEIGHT_WIDTH:0] e; //Edge Weight, Signed
  
  assign adjmat_row_addr = i;
  assign adjmat_col_addr = j;
  assign e = adjmat_q;

  always_ff @(posedge clk) begin
    if (bellman_reset) begin
      i <= 0;
      j <= 0;
      k <= 0;
      bellman_done <= 0;
      state <= SETUP;
    end else case (state)
      SETUP: begin
        if (k == `NODES) begin
          state <= READ_SOURCE;
          k <= 0; //V-1 Iterations below
        end else if (k == src) begin
          vertmat[k][`WEIGHT_WIDTH:0] <= 0;  //<=====WRITE
          k <= k + 1;
        end else begin
          vertmat[k][`WEIGHT_WIDTH:0] <= 32'hffffffff; //INT MAX; THIS WILL CHANGE WITH WIDTH  //<=====WRITE
          k <= k + 1;
        end
      end
      READ_SOURCE: begin
        svw <= vertmat[i][`WEIGHT_WIDTH:0];  //<=====READ i
        state <= READ_DESTINATION;
      end
      READ_DESTINATION: begin
        dvw <= vertmat[j][`WEIGHT_WIDTH:0];  //<=====READ j
        state <= WRITE_DESTINATION_PRED;
      end
      WRITE_DESTINATION_PRED: begin
        if (e != 0 && $signed(svw[`WEIGHT_WIDTH:0]) + e < $signed(dvw[`WEIGHT_WIDTH:0])) begin
          vertmat[j][(`VERT_WIDTH-1):(`WEIGHT_WIDTH+1)] <= i;  //<=====WRITE
        end
        state <= WRITE_DESTINATION_WEIGHT;
      end
      WRITE_DESTINATION_WEIGHT: begin
        if (e != 0 && $signed(svw[`WEIGHT_WIDTH:0] + e) < $signed(dvw[`WEIGHT_WIDTH:0])) begin
          vertmat[j][`WEIGHT_WIDTH:0] <= svw[`WEIGHT_WIDTH:0] + e;  //<=====WRITE
        end
        if (j+1 == `NODES && i+1 == `NODES && k + 1 == `NODES - 1) begin //V-1 Times
          state <= DONE;
        end else if (j+1 == `NODES && i+1 == `NODES) begin
          i <= 0;
          j <= 0;
          k <= k + 1;
          state <= READ_SOURCE;
        end else if (j+1 == `NODES) begin
          i <= i + 1;
          j <= 0;
          state <= READ_SOURCE;
        end else begin
          j <= j + 1;
          state <= READ_SOURCE;
        end
      end
      DONE: bellman_done <= 1;
      default: state <= DONE;
    endcase
  end
endmodule
