`include "Const.svh"
/* verilator lint_off WIDTH */
/* verilator lint_off UNDRIVEN */
module CycleDetect(input logic clk, cycle_reset,
                   /*input logic [`PRED_WIDTH:0] src,*/
                   input logic signed [`WEIGHT_WIDTH:0] adjmat [`NODES:0][`NODES:0],
                   input logic [`VERT_WIDTH:0] vertmat [`NODES:0],
                   output logic cycle_done,
                   /*Vars for testing purposes only*/
                   output logic [`WEIGHT_WIDTH:0] test,
                   output logic [`VERT_WIDTH:0] o_vertmat [`NODES:0]);
      enum logic [3:0] {READ_SOURCE, READ_DESTINATION, CHECK_CYCLE, READ_CYCLE, DONE} state;
      logic [`PRED_WIDTH:0] i, j, k, l; //Indices
      logic signed [`WEIGHT_WIDTH:0] svw, dvw; //Source Vertex Weight, Destination Vertex Weight, Signed
      logic signed [`WEIGHT_WIDTH:0] e; //Edge Weight, Signed
      always_ff @(posedge clk) begin
        if (cycle_reset) begin
          i <= 0;
          j <= 0;
          k <= 0;
          l <= 0;
          cycle_done <= 0;
          state <= READ_SOURCE;
        end else case (state)
          READ_SOURCE: begin
            svw <= vertmat[i][`WEIGHT_WIDTH:0];
            e <= adjmat[i][j];
            state <= READ_DESTINATION;
          end
          READ_DESTINATION: begin
            dvw <= vertmat[j][`WEIGHT_WIDTH:0];
            state <= CHECK_CYCLE;
          end
          CHECK_CYCLE: begin
            if (e != 0 && $signed(svw[`WEIGHT_WIDTH:0]) + e < $signed(dvw[`WEIGHT_WIDTH:0])) begin //Found Negative Weight Cycle
              k <= j;
              l <= vertmat[j][(`VERT_WIDTH-1):(`WEIGHT_WIDTH+1)]; //Pred index of found cycle
              state <= READ_CYCLE;
            end else begin
              if (j+1 == `NODES && i+1 == `NODES) begin
                state <= DONE; //All finished looping through edges
              end else if (j+1 == `NODES) begin
                i <= i + 1;
                j <= 0;
                state <= READ_SOURCE;
              end else begin
                j <= j + 1;
                state <= READ_SOURCE;
              end
            end
          end
          READ_CYCLE: begin
            l <= vertmat[l][(`VERT_WIDTH-1):(`WEIGHT_WIDTH+1)]; //Pred of vert
            o_vertmat[l][`PRED_WIDTH:0] <= l;
            if (l == k) begin //Read Cycle
              if (j+1 == `NODES && i+1 == `NODES) begin
                state <= DONE; //All finished looping through edges
              end else if (j+1 == `NODES) begin
                i <= i + 1;
                j <= 0;
                state <= READ_SOURCE;
              end else begin
                j <= j + 1;
                state <= READ_SOURCE;
              end
            end
          end
          DONE: cycle_done <= 1;
          default: state <= DONE;
        endcase
      end
endmodule
