`include "Const.vh"

module CycleDetect(input logic clk, cycle_reset,
                   /*Vertmat/Adjmat Read Inputs*/
						input logic [`VERT_WIDTH:0] vertmat_q,
						input logic [`WEIGHT_WIDTH:0] adjmat_q,
						/*VertMat Memory*/
						output logic [`PRED_WIDTH:0] vertmat_addr,
						/*AdjMat Memory*/
						output logic [`PRED_WIDTH:0] adjmat_row_addr,
						output logic [`PRED_WIDTH:0] adjmat_col_addr,
						output logic cycle_done);
      enum logic [3:0] {READ_SOURCE, READ_DESTINATION, CHECK_CYCLE, READ_CYCLE, DONE} state;
      logic [`PRED_WIDTH:0] i, j, k, l; //Indices
      logic signed [`WEIGHT_WIDTH:0] svw, dvw; //Source Vertex Weight, Destination Vertex Weight, Signed
      logic signed [`WEIGHT_WIDTH:0] e; //Edge Weight, Signed
		

		assign adjmat_row_addr = i;
		assign adjmat_col_addr = j;
		assign e = adjmat_q;
		
      always_ff @(posedge clk) begin
        if (cycle_reset) begin
          i <= 0;
          j <= 0;
          k <= 0;
          l <= 0;
          cycle_done <= 0;
			 vertmat_addr <= 0;
          state <= READ_SOURCE;
        end else case (state)
          READ_SOURCE: begin
            svw <= vertmat_q[`WEIGHT_WIDTH:0];
				vertmat_addr <= j;
            state <= READ_DESTINATION;
          end
          READ_DESTINATION: begin
            dvw <= vertmat_q[`WEIGHT_WIDTH:0];
            state <= CHECK_CYCLE;
          end
          CHECK_CYCLE: begin
            if (e != 0 && $signed(svw[`WEIGHT_WIDTH:0]) + e < $signed(dvw[`WEIGHT_WIDTH:0])) begin //Found Negative Weight Cycle
              k <= j;
              l <= vertmat_q[(`VERT_WIDTH-1):(`WEIGHT_WIDTH+1)]; //Pred index of found cycle
              state <= READ_CYCLE;
            end else begin
              if (j+1 == `NODES && i + 1 == `NODES) begin
                state <= DONE; //All finished looping through edges
              end else if (j+1 == `NODES) begin
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
          end
          READ_CYCLE: begin
            l <= vertmat_q[(`VERT_WIDTH - 1):(`WEIGHT_WIDTH + 1)]; //Pred of vert
				vertmat_addr <= l;
            if (l == k) begin //Read Cycle
              if (j + 1 == `NODES && i + 1 == `NODES) begin
                state <= DONE; //All finished looping through edges
              end else if (j+1 == `NODES) begin
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
          end
          DONE: cycle_done <= 1;
          default: state <= DONE;
        endcase
      end
endmodule
