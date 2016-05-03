`include "Const.vh"

module Container(input logic clk, container_reset,
                 input logic [`PRED_WIDTH:0] src,
					       input logic [`PRED_WIDTH:0] u_src,
					       input logic [`PRED_WIDTH:0] u_dst,
					       input logic [`WEIGHT_WIDTH:0] u_e,
                 output logic [4:0] frame_char,
                 output logic [5:0] frame_x,
                 output logic [5:0] frame_y,
                 output logic frame_we,

                 output logic [31:0] test, //For testing purposes only

                 output logic container_done);

  enum logic [3:0] {UPDATE_FOR, UPDATE_REV, RUN_BELLMAN, RUN_CYCLE_DETECT, DONE} state;
  logic bellman_done, cycle_done, bellman_reset, cycle_reset; //Reset and done registers

  //Memory
  /*Vertmat/Adjmat Read Outputs*/
  logic [`VERT_WIDTH:0] vertmat_q_a;
  logic [`VERT_WIDTH:0] vertmat_q_b;
  logic [`WEIGHT_WIDTH:0] adjmat_q;
  /*VertMat Memory*/
  logic [`VERT_WIDTH:0] vertmat_data_a;
  logic [`VERT_WIDTH:0] vertmat_data_b;
  logic [`PRED_WIDTH:0] vertmat_addr_a; //Both write
  logic [`PRED_WIDTH:0] vertmat_addr_b; //Both write
  logic vertmat_we_a;
  logic vertmat_we_b;
  /*AdjMat Memory*/
  logic [`WEIGHT_WIDTH:0] adjmat_data;
  logic [`PRED_WIDTH:0] adjmat_row_addr; //Both write
  logic [`PRED_WIDTH:0] adjmat_col_addr; //Both write
  logic adjmat_we;
  /*Memory specific module vars*/
  logic [`PRED_WIDTH:0] bellman_vertmat_addr_a;
  logic [`PRED_WIDTH:0] bellman_vertmat_addr_b;
  logic [`PRED_WIDTH:0] bellman_adjmat_row_addr;
  logic [`PRED_WIDTH:0] bellman_adjmat_col_addr;
  logic [`PRED_WIDTH:0] cycle_vertmat_addr_a;
  logic [`PRED_WIDTH:0] cycle_vertmat_addr_b;
  logic [`PRED_WIDTH:0] cycle_adjmat_row_addr;
  logic [`PRED_WIDTH:0] cycle_adjmat_col_addr;

  //logic [4:0] frame_char1;

  assign vertmat_addr_a = bellman_done ? bellman_vertmat_addr_a : cycle_vertmat_addr_a;
  assign vertmat_addr_b = bellman_done ? bellman_vertmat_addr_b : cycle_vertmat_addr_b;

  Bellman bellman(.vertmat_addr_a(bellman_vertmat_addr_a), .vertmat_addr_b(bellman_vertmat_addr_b),
                  .adjmat_row_addr(bellman_adjmat_row_addr), .adjmat_col_addr(bellman_adjmat_col_addr), .*);
  CycleDetect cycle_detect(.vertmat_addr_a(cycle_vertmat_addr_a), .vertmat_addr_b(cycle_vertmat_addr_b),
                          .adjmat_row_addr(cycle_adjmat_row_addr), .adjmat_col_addr(cycle_adjmat_col_addr), .*);
  VertMat vertmat(.data_a(vertmat_data_a), .data_b(vertmat_data_b),
                  .addr_a(vertmat_addr_a), .addr_b(vertmat_addr_b),
                  .we_a(vertmat_we_a), .we_b(vertmat_we_b),
                  .q_a(vertmat_q_a), .q_b(vertmat_q_b), .*);
  AdjMat adjmat(.data(adjmat_data), .row_addr(adjmat_row_addr), .col_addr(adjmat_col_addr),
					 .we(adjmat_we), .q(adjmat_q), .*);

  always_ff @(posedge clk) begin
    if (container_reset) begin
      container_done <= 0;
      state <= UPDATE_FOR;
    end else case (state)
  		UPDATE_FOR: begin
  			adjmat_row_addr <= u_src;
  			adjmat_col_addr <= u_dst;
  			adjmat_data <= u_e;
  			state <= UPDATE_REV;
  		end
      UPDATE_REV: begin
        adjmat_we <= 1;
        adjmat_row_addr <= u_dst;
        adjmat_col_addr <= u_src;
        adjmat_data <= -1*u_e;
        state <= RUN_BELLMAN;
        bellman_reset <= 1;
      end
      RUN_BELLMAN: begin
		    adjmat_we <= 0;
        bellman_reset <= 0;
		    adjmat_row_addr <= bellman_adjmat_row_addr;
		    adjmat_col_addr <= bellman_adjmat_col_addr;
        if (bellman_done) begin
          cycle_reset <= 1;
          state <= RUN_CYCLE_DETECT;
        end
      end
      RUN_CYCLE_DETECT: begin
        cycle_reset <= 0;
		    adjmat_row_addr <= cycle_adjmat_row_addr;
		    adjmat_col_addr <= cycle_adjmat_col_addr;
        if (cycle_done) state <= DONE;
      end
      DONE: container_done <= 1;
      default: state <= DONE;
    endcase
  end

endmodule
