`include "Const.svh"
/* verilator lint_off WIDTH */
module Bellman(input logic clk, start,
              input logic [6:0] src,
              input logic [31:0] adjmat [`NODES:0][`NODES:0],
              output logic [31:0] o_vertmat [`NODES:0],
              output logic [2:0] done);

  enum logic {RUNNING, DONE} state;
  logic [31:0] t_vertmat [`NODES:0];
  logic [31:0] e1, e2, e3, e4;
  logic [31:0] o_e1, o_e2, o_e3, o_e4;
  integer k;
  logic [6:0] i, j;

  //Wire up the modules
  Sort sort(.vertmat(o_vertmat), .e1(e1), .e2(e2), .e3(e3), .e4(e4),
      .o_e1(o_e1), .o_e2(o_e2), .o_e3(o_e3), .o_e4(o_e4));

  Relax relax(.e1(o_e1), .e2(o_e2), .e3(o_e3), .e4(o_e4), .vertmat(o_vertmat), .o_vertmat(t_vertmat));

  always_ff @(posedge clk) begin
    if (start) begin
      for (k=0; k < `NODES; k=k+1) begin //ASK ABOUT THIS
        if (k[6:0] == src) o_vertmat[k][16:0] <= 0;
        else o_vertmat[k][16:0] <= 17'b01111111111111111; //INFINITY
      end
      i <= 0;
      j <= 0;
      done <= 0;
      state <= RUNNING;
    end else case (state)
      RUNNING: begin
        o_vertmat <= t_vertmat;
        e1 <= adjmat[i][j];
        e2 <= adjmat[i][j+1];
        e3 <= adjmat[i][j+2];
        e4 <= adjmat[i][j+3];
        if (i < `NODES && j < `NODES) begin //In mid col mid row
          i <= i + 4;
        end else if (i == `NODES && j < `NODES) begin //At end of row
          j <= j + 1;
          i <= 0;
        end else if (i == `NODES && j == `NODES) state <= DONE; //At end of mat
      end
      DONE: done <= 1;
      default: state <= DONE;
    endcase
  end
endmodule
