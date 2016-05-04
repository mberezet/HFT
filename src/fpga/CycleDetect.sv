`include "Const.vh"

module CycleDetect(input logic clk, cycle_reset,
                   /*Vertmat/Adjmat Read Inputs*/
                   input logic [`VERT_WIDTH:0] vertmat_q_a,
                   input logic [`VERT_WIDTH:0] vertmat_q_b,
						       input logic [`WEIGHT_WIDTH:0] adjmat_q,
                   /*VertMat Memory*/
                   output logic [`PRED_WIDTH:0] vertmat_addr_a,
                   output logic [`PRED_WIDTH:0] vertmat_addr_b,
                   /*AdjMat Memory*/
                   output logic [`PRED_WIDTH:0] adjmat_row_addr,
                   output logic [`PRED_WIDTH:0] adjmat_col_addr,

                   //output logic [31:0] test, //For testing purposes only
                   output logic [31:0] test1, //For testing purposes only
                   //output logic [31:0] test2, //For testing purposes only

                   /*Screen*/
                   /*This is temporary testing things*/
                   output logic [4:0] frame_char,
                   output logic [5:0] frame_x,
                   output logic [5:0] frame_y,
                   output logic frame_we,
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
      //assign test1 = vertmat_addr_b;

      /*This is temporary testing things*/
      logic [5:0] px, py;
      assign frame_char = l;
      assign frame_x = px;
      assign frame_y = py;

      always_comb begin
        if (cycle_reset) begin
          i = 0;
          j = 0;
          k = 0;
          cycle_done = 0;
        end else case (state)
          READ: begin
            if (j + 1 == `NODES && i + 1 == `NODES) begin
              ; //All finished looping through edges //GETS TRIGGERED SOMEHOW ON RESET
            end else if (j + 1 == `NODES) begin
              i = i + 1;
              j = 0;
            end else begin
              j <= j + 1;
            end
          end
          CHECK_CYCLE: begin
            if (e != 0 && $signed(svw + e) < $signed(dvw)) begin //Found Negative Weight Cycle
              k = j;
              /*This is temporary testing things*/
              frame_we = 1;
              if (px + 1 == 40 && py + 1 == 30) begin
                py = 0;
                px = 0;
              end else if (px + 1 == 40) begin
                py = py + 1;
                px = 0;
              end else px = px + 1;
            end
          end
          READ_CYCLE: begin
            /*This is temporary testing things*/
            if (px + 1 == 40 && py + 1 == 30) begin
              py = 0;
              px = 0;
            end else if (px + 1 == 40) begin
              py = py + 1;
              px = 0;
            end else px = px + 1;

            if (l == k) begin //Read Cycle
              /*This is temporary testing things*/
              frame_we = 0;
            end
          end
          DONE: cycle_done = 1;
        endcase
      end
      always_ff @(posedge clk) begin
        if (cycle_reset) begin
          state <= READ;
          test1 <= 8008;
        end else case (state)
          READ: begin
            if (j + 1 == `NODES && i + 1 == `NODES) begin
              state <= DONE; //All finished looping through edges //GETS TRIGGERED SOMEHOW ON RESET
            end else if (j + 1 == `NODES) begin
              state <= CHECK_CYCLE;
            end else begin
              state <= CHECK_CYCLE;
            end
          end
          CHECK_CYCLE: begin
            //test <= i;
            //test1 <= j;
            //test2 <= dvw;
            if (e != 0 && $signed(svw + e) < $signed(dvw)) begin //Found Negative Weight Cycle
              state <= READ_CYCLE;
            end else state <= READ;
          end
          READ_CYCLE: begin
            if (l == k) begin //Read Cycle
              state <= READ;
            end
            state <= READ; //TESTING ONLY
          end
          default: state <= DONE;
        endcase
      end
endmodule
