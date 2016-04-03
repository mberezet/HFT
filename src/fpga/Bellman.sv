`include "Const.svh"
/* verilator lint_off WIDTH */
/* verilator lint_off UNUSED */
/* verilator lint_off UNDRIVEN */
module Bellman(input logic clk, reset,
               input logic [7:0] src,
               input logic [31:0] adjmat [`NODES:0][`NODES:0],
               output logic [31:0] vertmat [`NODES:0],
               output logic done,
               output logic [31:0] test);

  enum logic [4:0] {PRE,
                    READ_VERT1, READ_EDGE1, READ_VERT2, READ_EDGE2,
                    READ_VERT3, READ_EDGE3, READ_VERT4, READ_EDGE4,
                    WRITE_VERT1, WRITE_VERT2, WRITE_VERT3, WRITE_VERT4,
                    DONE} state;
  logic [6:0] i, j; //Indices
  logic [6:0] s1, s2, s3, s4; //Source Vertex Index
  logic [6:0] d1, d2, d3, d4; //Destination Vertex Index
  logic [31:0] e1, e2, e3, e4; //Weight of Edge
  logic [31:0] dv1, dv2, dv3, dv4; //Weight and Predescessor of Destination Vertex
  logic [31:0] sv1, sv2, sv3, sv4; //Weight and Predescessor of Source Vertex

  logic [31:0] o_e1, o_e2, o_e3, o_e4; //Output Edges
  logic [31:0] o_dv1, o_dv2, o_dv3, o_dv4; //Output Vertix Weights
  logic [3:0] update_mask;

  //Wire up the modules
  Sort sort(.*);

  Relax relax(.e1(o_e1), .e2(o_e2), .e3(o_e3), .e4(o_e4), .*);

  always_ff @(posedge clk) begin
    if (reset) begin
      i <= 0;
      j <= 0;
      done <= 0;
      state <= PRE;
    end else case (state)
      PRE: begin
        if (i == `NODES) begin
          state <= READ_VERT1;
          i <= 0;
        end else if (i == src) begin
          vertmat[i][24:0] <= 0;
          i <= i + 1;
        end else begin
          vertmat[i][24:0] <= 25'hffffff; //INT MAX
          i <= i + 1;
        end
      end
      READ_VERT1: begin
        s1 <= i;
        d1 <= j;
        sv1 <= vertmat[i];
        state <= READ_EDGE1;
      end
      READ_EDGE1: begin
        if (j + 1 == `NODES) begin
          j <= 0;
          i <= i + 1;
        end else j <= j + 1;
        e1 <= adjmat[i][j];
        dv1 <= vertmat[j];
        state <= READ_VERT2;
      end
      READ_VERT2: begin
        s2 <= i;
        d2 <= j;
        sv2 <= vertmat[i];
        state <= READ_EDGE2;
      end
      READ_EDGE2: begin
        if (j + 1 == `NODES) begin
          j <= 0;
          i <= i + 1;
        end else j <= j + 1;
        e2 <= adjmat[i][j];
        dv2 <= vertmat[j];
        state <= READ_VERT3;
      end
      READ_VERT3: begin
        s3 <= i;
        d3 <= j;
        sv3 <= vertmat[i];
        state <= READ_EDGE3;
      end
      READ_EDGE3: begin
        if (j + 1 == `NODES) begin
          j <= 0;
          i <= i + 1;
        end else j <= j + 1;
        e3 <= adjmat[i][j];
        dv3 <= vertmat[j];
        state <= READ_VERT4;
      end
      READ_VERT4: begin
        s4 <= i;
        d4 <= j;
        sv4 <= vertmat[i];
        state <= READ_EDGE4;
      end
      READ_EDGE4: begin
        if (j + 1 == `NODES) begin
          j <= 0;
          i <= i + 1;
        end else j <= j + 1;
        e4 <= adjmat[i][j];
        dv4 <= vertmat[j];
        state <= WRITE_VERT1;
      end
      WRITE_VERT1: begin
        if (update_mask[0]) vertmat[s1] <= o_dv1;
        state <= WRITE_VERT2;
      end
      WRITE_VERT2: begin
        if (update_mask[1]) vertmat[s2] <= o_dv1;
        state <= WRITE_VERT3;
      end
      WRITE_VERT3: begin
        if (update_mask[2]) vertmat[s3] <= o_dv1;
        state <= WRITE_VERT4;
      end
      WRITE_VERT4: begin
        if (update_mask[3]) vertmat[s4] <= o_dv1;
        if (i == `NODES && j == `NODES) begin
          state <= DONE;
        end else state <= READ_VERT1;
      end
      DONE: done <= 1;
      default: state <= DONE;
    endcase
  end
endmodule
