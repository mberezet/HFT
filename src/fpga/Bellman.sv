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

              output logic [31:0] test, //For testing purposes only
              output logic [31:0] test1, //For testing purposes only
              //output logic [31:0] test2, //For testing purposes only

              /*AdjMat Memory*/
              output logic [`PRED_WIDTH:0] adjmat_row_addr,
              output logic [`PRED_WIDTH:0] adjmat_col_addr,
              output logic bellman_done);

  enum logic [3:0] {SETUP, SETUP_WRITE_INTER, FINISH_SETUP, READ, WRITE, WRITE_INTER, DONE} state;
  logic [`PRED_WIDTH:0] i, j, k; //Indices
  logic signed [`WEIGHT_WIDTH:0] svw, dvw; //Source Vertex Weight, Destination Vertex Weight, Signed
  logic signed [`WEIGHT_WIDTH:0] e; //Edge Weight, Signed

  assign adjmat_row_addr = i;
  assign adjmat_col_addr = j;
  assign e = adjmat_q;
  assign svw = vertmat_q_a[`WEIGHT_WIDTH:0];
  assign dvw = vertmat_q_b[`WEIGHT_WIDTH:0];
  //assign test1 = j;
  //assign test1 = vertmat_addr_b;

  always_comb begin
    case (state)
      SETUP: begin
        vertmat_addr_a = k;
      end
      SETUP_WRITE_INTER: begin
        vertmat_addr_a = k;
      end
      FINISH_SETUP: begin
        vertmat_addr_a = k;
      end
      READ: begin
        vertmat_addr_a = i;
        vertmat_addr_b = j;
      end
      WRITE:begin
        vertmat_addr_a = i;
        vertmat_addr_b = j;
      end
      WRITE_INTER: begin
        vertmat_addr_a = i;
        vertmat_addr_b = j;
      end
    endcase
  end

  always_ff @(posedge clk) begin
    if (bellman_reset) begin
      //test <= 8008;
      i <= 0;
      j <= 0;
      k <= 0;
      bellman_done <= 0;
		  vertmat_we_a <= 1;
      state <= SETUP;
    end else case (state)
      SETUP: begin
        if (k + 1 == `NODES) begin
			    k <= 0; //V Iterations below
          state <= FINISH_SETUP;
        end else if (k == src) begin
          vertmat_data_a[`WEIGHT_WIDTH:0] <= 0;
          k <= k + 1;
          state <= SETUP_WRITE_INTER;
        end else begin
          vertmat_data_a[`WEIGHT_WIDTH:0] <= 31'h777fffff; //INT MAX; THIS WILL CHANGE WITH WIDTH
          k <= k + 1;
          state <= SETUP_WRITE_INTER;
        end
      end
      SETUP_WRITE_INTER: state <= SETUP;
      FINISH_SETUP: begin
        vertmat_we_a <= 0;
        state <= READ;
      end
      READ: begin
        if (j + 1 == `NODES && i + 1 == `NODES && k + 1 == `NODES) begin //V Times
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
      //test <= i;
      //test1 <= j;
      //test2 <= svw;
        if (e != 0 && $signed(svw + e) < $signed(dvw)) begin
          //test <= 31;
          vertmat_we_b <= 1;
          vertmat_data_b <= {i, $signed(svw + e)};
        end
        state <= WRITE_INTER;
      end
      WRITE_INTER: begin
        vertmat_we_b <= 0;
        state <= READ;
      end
      DONE: begin /*test <= 8001; */bellman_done <= 1; end
      default: state <= DONE;
    endcase
  end
endmodule
