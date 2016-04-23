`include "Const.vh"

module Bellman(input logic clk, bellman_reset,
               input logic [`PRED_WIDTH:0] src,
    				/*Vertmat/Adjmat Read Inputs*/
    				input logic [`VERT_WIDTH:0] vertmat_q_a,
               input logic [`VERT_WIDTH:0] vertmat_q_b,
    				input logic [`WEIGHT_WIDTH:0] adjmat_q,
    				/*VertMat Memory*/
					output logic [`VERT_WIDTH:0] vertmat_data_a,
               output logic [`VERT_WIDTH:0] vertmat_data_b,
       	 		output logic [`PRED_WIDTH:0] vertmat_addr_a,
               output logic [`PRED_WIDTH:0] vertmat_addr_b,
    				output logic vertmat_we_a,
               output logic vertmat_we_b,
					/*AdjMat Memory*/
    				output logic [`PRED_WIDTH:0] adjmat_row_addr,
    				output logic [`PRED_WIDTH:0] adjmat_col_addr,
               output logic bellman_done);

  enum logic [3:0] {SETUP, READ, WRITE, DONE} state;
  logic [`PRED_WIDTH:0] i, j, k; //Indices
  logic signed [`WEIGHT_WIDTH:0] svw, dvw; //Source Vertex Weight, Destination Vertex Weight, Signed
  logic signed [`WEIGHT_WIDTH:0] e; //Edge Weight, Signed

  assign adjmat_row_addr = i;
  assign adjmat_col_addr = j;
  assign e = adjmat_q;
  assign svw = vertmat_q_a[`WEIGHT_WIDTH:0];
  assign dvw = vertmat_q_b[`WEIGHT_WIDTH:0];
  assign vertmat_addr_a = state == SETUP ? k : i;
  assign vertmat_addr_b = state == SETUP ? k + 1 : j;

  always_ff @(posedge clk) begin
    if (bellman_reset) begin
      i <= 0;
      j <= 0;
      k <= 0;
      bellman_done <= 0;
		  vertmat_we_a <= 1;
      vertmat_we_b <= 1;
      state <= SETUP;
    end else case (state)
      SETUP: begin
        if (k == `NODES) begin
			 k <= 0; //V-1 Iterations below
			 vertmat_we_a <= 0;
          vertmat_we_b <= 0;
          state <= WRITE;
        end else if (k == src) begin
          vertmat_data_a[`WEIGHT_WIDTH:0] <= 0;
          k <= k + 1;
        end else begin
          vertmat_data_a[`WEIGHT_WIDTH:0] <= 32'hffffffff; //INT MAX; THIS WILL CHANGE WITH WIDTH
          k <= k + 1;
        end
      end
      READ: begin
        if (j + 1 == `NODES && i + 1 == `NODES && k + 1 == `NODES - 1) begin //V-1 Times
          state <= DONE;
        end else if (j + 1 == `NODES && i + 1 == `NODES) begin
          i <= 0;
          j <= 0;
          k <= k + 1;
          state <= WRITE;
        end else if (j + 1 == `NODES) begin
          i <= i + 1;
          j <= 0;
          state <= WRITE;
        end else begin
          j <= j + 1;
          state <= WRITE;
        end
      end
      WRITE: begin
        if (e != 0 && $signed(svw + e) < $signed(dvw)) begin
          vertmat_we_b <= 1;
          vertmat_data_b <= {i, svw + e};
        end
        state <= READ;
      end
      DONE: bellman_done <= 1;
      default: state <= DONE;
    endcase
  end
endmodule
