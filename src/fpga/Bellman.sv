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
				   output logic [`PRED_WIDTH:0] adjmat_row_addr,
				   output logic [`PRED_WIDTH:0] adjmat_col_addr,
               output logic bellman_done);

  enum logic [3:0] {SETUP, READ_SOURCE, READ_DESTINATION, WRITE_DESTINATION_1, WRITE_DESTINATION_2, NEXT_ITERATION, DONE} state;
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
		vertmat_we <= 1;
      state <= SETUP;
    end else case (state)
      SETUP: begin
        if (k == `NODES) begin
			 k <= 0; //V-1 Iterations below
			 vertmat_we <= 0;
			 vertmat_addr <= i;
          state <= READ_SOURCE;
        end else if (k == src) begin
          vertmat_data[`WEIGHT_WIDTH:0] <= 0;
          k <= k + 1;
			 vertmat_addr <= k + 1;
        end else begin
          vertmat_data[`WEIGHT_WIDTH:0] <= 32'hffffffff; //INT MAX; THIS WILL CHANGE WITH WIDTH
          k <= k + 1;
			 vertmat_addr <= k + 1;
        end
      end
      READ_SOURCE: begin
        svw <= vertmat_q[`WEIGHT_WIDTH:0];
		  vertmat_addr <= j;
        state <= READ_DESTINATION;
      end
      READ_DESTINATION: begin
        dvw <= vertmat_q[`WEIGHT_WIDTH:0];
		  vertmat_we <= 1;
        state <= WRITE_DESTINATION_1;
      end
      WRITE_DESTINATION_1: begin
        if (e != 0 && $signed(svw[`WEIGHT_WIDTH:0] + e) < $signed(dvw[`WEIGHT_WIDTH:0])) begin
          vertmat_we <= 1;
			 state <= WRITE_DESTINATION_2;
        end else state <= NEXT_ITERATION;
		end
		WRITE_DESTINATION_2: begin
			vertmat_data <= {i, svw[`WEIGHT_WIDTH:0] + e}; 
			state <= NEXT_ITERATION;
		end
		NEXT_ITERATION: begin
		  vertmat_we <= 0;
        if (j + 1 == `NODES && i + 1 == `NODES && k + 1 == `NODES - 1) begin //V-1 Times
          state <= DONE;
        end else if (j + 1 == `NODES && i + 1 == `NODES) begin
          i <= 0;
          j <= 0;
          k <= k + 1;
			 vertmat_addr <= 0;
          state <= READ_SOURCE;
        end else if (j + 1 == `NODES) begin
          i <= i + 1;
          j <= 0;
			 vertmat_addr <= i + 1;
          state <= READ_SOURCE;
        end else begin
          j <= j + 1;
			 vertmat_addr <= i;
          state <= READ_SOURCE;
        end
      end
      DONE: bellman_done <= 1;
      default: state <= DONE;
    endcase
  end
endmodule
