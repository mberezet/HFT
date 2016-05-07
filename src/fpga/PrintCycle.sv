module PrintCycle(input logic clk, print_reset,
                   /*Vertmat Read Inputs*/
                   input logic [`VERT_WIDTH:0] vertmat_q_b,
                   /*VertMat Memory*/
                   output logic [`VERT_WIDTH:0] vertmat_data_b,
                   output logic [`PRED_WIDTH:0] vertmat_addr_b,
                   output logic vertmat_we_b,
                   /*Screen*/
                   output logic [5:0] frame_char,
                   output logic [5:0] frame_x,
                   output logic [5:0] frame_y,
                   output logic frame_we,
                   output logic print_done);

    enum logic [3:0] {READ, IDLE, CHECK_CYCLE, START_WRITE, FIRST_DIGIT, SECOND_DIGIT, ARROW, RECHECK_CYCLE, FINISH_CYCLE, DONE} state;

    logic [`PRED_WIDTH:0] i, j, k, l, m; //Indices

    logic [5:0] px, py = -1;
    assign frame_x = px;
    assign frame_y = py;

    always_comb begin
      frame_we = 0;
      frame_char = 0;
      vertmat_addr_b = j;
      vertmat_data_b = 0;
      vertmat_we_b = 0;
      case (state)
        READ: ;
        IDLE: ;
        CHECK_CYCLE: begin
          vertmat_addr_b = j;
          if (vertmat_q_b[`VERT_WIDTH]) vertmat_addr_b = l;
        end
        START_WRITE: begin
          vertmat_addr_b = l;
        end
        FIRST_DIGIT: begin
          vertmat_addr_b = m;
          vertmat_data_b = {1'b0, vertmat_q_b[`VERT_WIDTH - 1:0]};
          vertmat_we_b = 1;
          frame_we = 1;
          if (m < 10) frame_char = 10;
          else if (m >= 60) frame_char = 6; //To avoid division
          else if (m >= 50) frame_char = 5;
          else if (m >= 40) frame_char = 4;
          else if (m >= 30) frame_char = 3;
          else if (m >= 20) frame_char = 2;
          else frame_char = 1;
        end
        SECOND_DIGIT: begin
          vertmat_we_b = 0;
          vertmat_addr_b = m;
          frame_we = 1;
          if (m < 10) frame_char = m;
          else if (m >= 60) frame_char = m - 60;
          else if (m >= 50) frame_char = m - 50;
          else if (m >= 40) frame_char = m - 40;
          else if (m >= 30) frame_char = m - 30;
          else if (m >= 20) frame_char = m - 20;
          else frame_char = m - 10;
        end
        ARROW: begin
          vertmat_addr_b = j;
          if (l != k) begin
            vertmat_addr_b = l;
            frame_we = 1;
            frame_char = 37;
          end
        end
        RECHECK_CYCLE: vertmat_addr_b = l;
        default: ;
      endcase
    end

    always_ff @(posedge clk) begin
      if (print_reset) begin
        i <= 0;
        j <= 0;
        k <= -1;
        l <= 0;
        m <= 0;
        print_done <= 0;
        state <= READ;
      end else case (state)
        READ: begin
          k <= -1;
          if (j + 1 == `NODES) begin
            state <= DONE;
          end else begin
            j <= j + 1;
            state <= IDLE;
          end
        end
        IDLE: begin
          k <= j;
          m <= j;
          state <= CHECK_CYCLE;
        end
        CHECK_CYCLE: begin
          l <= vertmat_q_b[(`VERT_WIDTH-1):(`WEIGHT_WIDTH+1)];
          if (vertmat_q_b[`VERT_WIDTH]) state <= START_WRITE;
          else state <= READ;
        end
        START_WRITE: begin
          if (py + 1 == 30) begin
            py <= 0;
            px <= 0;
          end else begin
            py <= py + 1;
            px <= 0;
          end 
			 state <= FIRST_DIGIT;
        end
        FIRST_DIGIT: begin
          if (px + 1 == 40 && py + 1 == 30) begin
            py <= 0;
            px <= 0;
          end else if (px + 1 == 40) begin
            py <= py + 1;
            px <= 0;
          end else px <= px + 1;
          state <= SECOND_DIGIT;
        end
        SECOND_DIGIT: begin
          if (px + 1 == 40 && py + 1 == 30) begin
            py <= 0;
            px <= 0;
          end else if (px + 1 == 40) begin
            py <= py + 1;
            px <= 0;
          end else px <= px + 1;
          state <= ARROW;
        end
        ARROW: begin
          if (px + 1 == 40 && py + 1 == 30) begin
            py <= 0;
            px <= 0;
          end else if (px + 1 == 40) begin
            py <= py + 1;
            px <= 0;
          end else px <= px + 1;
          state <= RECHECK_CYCLE;
        end
        RECHECK_CYCLE: begin
          m <= l;
          if (l == k) state <= READ;
          else begin
            l <= vertmat_q_b[(`VERT_WIDTH-1):(`WEIGHT_WIDTH+1)];
            state <= FIRST_DIGIT;
          end
        end
        DONE: print_done <= 1;
        default: state <= DONE;
      endcase
    end
endmodule
