`include "Const.vh"

module CycleDetect(input logic clk, cycle_reset,
                   /*Vertmat/Adjmat Read Inputs*/
                   input logic [`VERT_WIDTH:0] vertmat_q_a,
                   input logic [`VERT_WIDTH:0] vertmat_q_b,
                   /*VertMat Memory*/
                   output logic [`PRED_WIDTH:0] vertmat_addr_a,
                   output logic [`PRED_WIDTH:0] vertmat_addr_b,
                   /*AdjMat Memory*/
                   output logic [`PRED_WIDTH:0] adjmat_row_addr,
                   output logic [`PRED_WIDTH:0] adjmat_col_addr,
                   /*Screen*/
                   output logic [4:0] frame_char,
                   output logic [5:0] frame_x,
                   output logic [5:0] frame_y,
                   output logic frame_wen,
                   output logic cycle_done);

      enum logic [3:0] {READ, CHECK_CYCLE, READ_CYCLE, DONE} state;
      logic [`PRED_WIDTH:0] i, j, k, l; //Indices
      logic signed [`WEIGHT_WIDTH:0] svw, dvw; //Source Vertex Weight, Destination Vertex Weight, Signed
      logic signed [`WEIGHT_WIDTH:0] e; //Edge Weight, Signed

  		assign adjmat_row_addr = i;
  		assign adjmat_col_addr = j;
  		assign e = adjmat_q;
      assign svw = vertmat_q_a[`WEIGHT_WIDTH:0];
      assign dvw = vertmat_q_b[`WEIGHT_WIDTH:0];
      assign vertmat_addr_a = i;
      assign vertmat_addr_b = state == CHECK_CYCLE ? l : j;
      assign l = vertmat_q_b[(`VERT_WIDTH-1):(`WEIGHT_WIDTH+1)];

      always_ff @(posedge clk) begin
        if (cycle_reset) begin
          i <= 0;
          j <= 0;
          k <= 0;
          l <= 0;
          cycle_done <= 0;
			    vertmat_addr <= 0;
          state <= CHECK_CYCLE;
        end else case (state)
          READ: begin
            if (j+1 == `NODES && i + 1 == `NODES) begin
              state <= DONE; //All finished looping through edges
            end else if (j+1 == `NODES) begin
              i <= i + 1;
              j <= 0;
              state <= CHECK_CYCLE;
            end else begin
              j <= j + 1;
              state <= CHECK_CYCLE;
            end
          end
          CHECK_CYCLE: begin
            if (e != 0 && $signed(svw) + e < $signed(dvw)) begin //Found Negative Weight Cycle
              k <= j;
              state <= READ_CYCLE;
            end else state <= READ;
          end
          READ_CYCLE: begin
            if (l == k) begin //Read Cycle
              state <= READ_SOURCE;
            end
          end
          DONE: cycle_done <= 1;
          default: state <= DONE;
        endcase
      end
endmodule