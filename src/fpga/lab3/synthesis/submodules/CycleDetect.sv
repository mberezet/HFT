`include "Const.vh"

module CycleDetect(input logic clk, cycle_reset,
                   /*Vertmat/Adjmat Read Inputs*/
                   input logic [`VERT_WIDTH:0] vertmat_q_a,
                   input logic [`VERT_WIDTH:0] vertmat_q_b,
						       input logic [`WEIGHT_WIDTH:0] adjmat_q,
                   /*VertMat Memory*/
                   output logic [`PRED_WIDTH:0] vertmat_addr_a,
                   output logic [`PRED_WIDTH:0] vertmat_addr_b,
                   output logic [`VERT_WIDTH:0] vertmat_data_b,
                   output logic vertmat_we_b,
                   /*AdjMat Memory*/
                   output logic [`PRED_WIDTH:0] adjmat_row_addr,
                   output logic [`PRED_WIDTH:0] adjmat_col_addr,
                   output logic cycle_done);

      enum logic [3:0] {READ, IDLE, CHECK_CYCLE, READ_CYCLE, WRITE_CYCLE, FINISH_CYCLE, DONE} state;
      logic [`PRED_WIDTH:0] i, j, k, l, m; //Indices
      logic signed [`WEIGHT_WIDTH:0] svw, dvw; //Source Vertex Weight, Destination Vertex Weight, Signed
      logic signed [`WEIGHT_WIDTH:0] e; //Edge Weight, Signed

  		assign adjmat_row_addr = i;
  		assign adjmat_col_addr = j;
  		assign e = adjmat_q;
      assign svw = vertmat_q_a[`WEIGHT_WIDTH:0];
      assign dvw = vertmat_q_b[`WEIGHT_WIDTH:0];
      assign vertmat_addr_a = i;

      always_comb begin
        vertmat_addr_b = 0;
        vertmat_we_b = 0;
        vertmat_data_b = 0;
        case (state)
          READ: vertmat_addr_b = j;
          IDLE: vertmat_addr_b = j;
          CHECK_CYCLE: begin
            vertmat_addr_b = j;
            if (e != 0 && $signed(svw + e) < $signed(dvw)) begin //Found Negative Weight Cycle
              vertmat_addr_b = l;
            end
          end
          READ_CYCLE: begin
            vertmat_we_b = 0;
            vertmat_addr_b = l;
          end
          WRITE_CYCLE: begin
            vertmat_we_b = 1;
            vertmat_data_b = {1'b1, vertmat_q_b[`VERT_WIDTH - 1:0]};
            vertmat_addr_b = m;
          end
          FINISH_CYCLE: begin
            vertmat_we_b = 0;
            vertmat_addr_b = j;
          end
          default: vertmat_addr_b = j;
        endcase
      end

      always_ff @(posedge clk) begin
        if (cycle_reset) begin
          i <= 0;
          j <= 0;
          k <= -1;
          cycle_done <= 0;
          state <= READ;
        end else case (state)
          READ: begin
            k <= -1;
            if (j + 1 == `NODES && i + 1 == `NODES) begin
              state <= DONE; //All finished looping through edges //GETS TRIGGERED SOMEHOW ON RESET
            end else if (j + 1 == `NODES) begin
              i <= i + 1;
              j <= 0;
              state <= IDLE;
            end else begin
              j <= j + 1;
              state <= IDLE;
            end
          end
          IDLE: begin
            k <= j;
            //m <= j;
            state <= CHECK_CYCLE;
            //l <= vertmat_q_b[(`VERT_WIDTH-1):(`WEIGHT_WIDTH+1)];
          end
          CHECK_CYCLE: begin
            l <= vertmat_q_b[(`VERT_WIDTH-1):(`WEIGHT_WIDTH+1)];
            if (e != 0 && $signed(svw + e) < $signed(dvw)) begin //Found Negative Weight Cycle
              state <= WRITE_CYCLE;
            end else state <= READ;
          end
          READ_CYCLE: begin
            m <= l;
            l <= vertmat_q_b[(`VERT_WIDTH-1):(`WEIGHT_WIDTH+1)];
            if (l == k) begin //Read Cycle
              state <= FINISH_CYCLE;
            end else state <= WRITE_CYCLE;
          end
          WRITE_CYCLE: begin
            state <= READ_CYCLE;
          end
          FINISH_CYCLE: state <= READ;
          DONE: cycle_done <= 1;
          default: state <= DONE;
        endcase
      end
endmodule
