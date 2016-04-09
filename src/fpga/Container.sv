`include "Const.svh"

module Container(input logic clk, reset,
                 input logic [`PRED_WIDTH:0] src,
                 input logic signed [`WEIGHT_WIDTH:0] adjmat [`NODES:0][`NODES:0],
                 output logic done);

  enum logic [2:0] {RUN_BELLMAN, RUN_CYCLE_DETECT, DONE} state;
  logic bellman_done, cycle_done, bellman_reset, cycle_reset; //Reset and done registers
  logic [`VERT_WIDTH:0] vertmat [`NODES:0];

  Bellman bellman(.*);
  CycleDetect cycle_detect(.*);

  always_ff @(posedge clk) begin
    if (reset) begin
      done <= 0;
      state <= RUN_BELLMAN;
      bellman_reset <= 1;
    end else case (state)
      RUN_BELLMAN: begin
        bellman_reset <= 0;
        if (bellman_done) begin
          cycle_reset <= 1;
          state <= RUN_CYCLE_DETECT;
        end
      end
      RUN_CYCLE_DETECT: begin
        cycle_reset <= 0;
        if (cycle_done) state <= DONE;
      end
      DONE: done <= 1;
      default: state <= DONE;
    endcase
  end

endmodule
