/*
 * Seven-segment LED emulator
 *
 * Stephen A. Edwards, Columbia University
 */

module Frame(input logic clk, reset,
             input logic [5:0] x, y,
             input logic [5:0] char,
             input logic we,
             input logic [2:0] adv,
             input logic [5:0] line_start,
             input logic [5:0] line_end,
             output logic [7:0] VGA_R, VGA_G, VGA_B,
             output logic VGA_CLK, VGA_HS, VGA_VS, VGA_BLANK_n, VGA_SYNC_n);

    /*
    * 640 X 480 VGA timing for a 50 MHz clock: one pixel every other cycle
    *
    * HCOUNT 1599 0             1279       1599 0
    *             _______________              ________
    * ___________|    Video      |____________|  Video
    *
    *
    * |SYNC| BP |<-- HACTIVE -->|FP|SYNC| BP |<-- HACTIVE
    *       _______________________      _____________
    * |____|       VGA_HS          |____|
    */
   // Parameters for hcount
   parameter HACTIVE      = 11'd 1280,
             HFRONT_PORCH = 11'd 32,
             HSYNC        = 11'd 192,
             HBACK_PORCH  = 11'd 96,
             HTOTAL       = HACTIVE + HFRONT_PORCH + HSYNC + HBACK_PORCH; // 1600

   // Parameters for vcount
   parameter VACTIVE      = 10'd 480,
             VFRONT_PORCH = 10'd 10,
             VSYNC        = 10'd 2,
             VBACK_PORCH  = 10'd 33,
             VTOTAL       = VACTIVE + VFRONT_PORCH + VSYNC + VBACK_PORCH; // 525

   logic [10:0] hcount; // Horizontal counter
                        // Hcount[10:1] indicates pixel column (0-639)
   logic endOfLine;

   always_ff @(posedge clk or posedge reset)
     if (reset) hcount <= 0;
     else if (endOfLine) hcount <= 0;
     else hcount <= hcount + 11'd 1;

   assign endOfLine = hcount == HTOTAL - 1;

   // Vertical counter
   logic [9:0] vcount;
   logic endOfField;

   always_ff @(posedge clk or posedge reset)
     if (reset) vcount <= 0;
     else if (endOfLine)
       if (endOfField) vcount <= 0;
       else vcount <= vcount + 10'd 1;

   assign endOfField = vcount == VTOTAL - 1;

   // Horizontal sync: from 0x520 to 0x5DF (0x57F)
   // 101 0010 0000 to 101 1101 1111
   assign VGA_HS = !( (hcount[10:8] == 3'b101) & !(hcount[7:5] == 3'b111));
   assign VGA_VS = !( vcount[9:1] == (VACTIVE + VFRONT_PORCH) / 2);

   assign VGA_SYNC_n = 1; // For adding sync to video signals; not used for VGA

   // Horizontal active: 0 to 1279     Vertical active: 0 to 479
   // 101 0000 0000  1280	       01 1110 0000  480
   // 110 0011 1111  1599	       10 0000 1100  524
   assign VGA_BLANK_n = !( hcount[10] & (hcount[9] | hcount[8]) ) &
			!( vcount[9] | (vcount[8:5] == 4'b1111) );

   /* VGA_CLK is 25 MHz
    *             __    __    __
    * clk    __|  |__|  |__|
    *
    *             _____       __
    * hcount[0]__|     |_____|
    */
    assign VGA_CLK = hcount[0]; // 25 MHz clock: pixel latched on rising edge

    /* Logic required for drawing characters*/
    logic [10:0] wp;
    logic [10:0] rp;
    logic [5:0] num_char;
    logic [5:0] frame_buffer[1199:0]; //40 accross by 30 down
<<<<<<< HEAD
    logic [5:0] mid_frame_buffer[439:0]; // 40*11
=======
>>>>>>> 9ec8d5612d16fa1250b92a8d96b1ed7225904e55

    logic [13:0] char_addr;
    logic char_show;

    logic [5:0] X,Y;
    assign Y = vcount[9:4];
    assign X = hcount[10:5];
    assign wp = 40 * y + x;
    assign rp = 40 * vcount[9:4] + hcount[10:5];

//    assign {VGA_R, VGA_G, VGA_B} = char_show && num_char != 0 ? 24'hff0000 : 24'd0;
//    assign num_char = frame_buffer[rp];

    assign char_addr = (hcount[10:1] - hcount[10:5] * 16) + (vcount[9:0] - vcount[9:4] * 16) * 16 + (num_char - 1) * 256; //Simplify

    Character character(.address(char_addr),.clock(clk),.q(char_show));

<<<<<<< HEAD
    logic [5:0] y_out;
    logic [5:0] y_record_out;
    logic [3:0] size;
    logic [2:0] stateFlag; // 3'd1: Mid_Forward state, 3'd2: Mid_Idler state, 3'd3: Mid_Back state,
    logic [9:0] mid_buffer_pos;
    logic [9:0] buffer_pos;
    
    logic [23:0] red = 24'hff0000;
    logic [23:0] blue = 24'h0000ff;
    logic [23:0] white = 24'hffffff;
    logic [23:0] char_color;

    FanShow fanshow (.bottom(6'd29), .*);

    logic [5:0] number_char_1;
	 logic [5:0] number_char_2;
    logic [5:0] name_char_1;
    logic [5:0] name_char_2;
    logic [5:0] name_char_3;

    Translation translation (.*);

    enum logic [4:0] {Normal, Mid_Forward, Mid_Translation, Mid_Show, Mid_Back} state;

    always_ff @(posedge clk) begin
        if (reset)	begin
            state <= Normal ;
            buffer_pos<=0;
            mid_buffer_pos<=0;
            number_char_1 <=0;
				number_char_2 <=0;
        end
    else case (state)
    Normal : begin
        if(stateFlag==1) state <= Mid_Forward;
        else state <= Normal;
    end
    Mid_Forward : begin

        if(stateFlag==2) begin
            state <= Mid_Translation;
            number_char_1<=frame_buffer[y_record_out*40+buffer_pos];
				number_char_2<=frame_buffer[y_record_out*40+buffer_pos+1];
        end
        else state <= Mid_Forward;
    end
    Mid_Translation : begin
        if(frame_buffer[y_record_out*40+buffer_pos]!=0&&buffer_pos<40) begin
            mid_frame_buffer[mid_buffer_pos]<=name_char_1;
            mid_frame_buffer[mid_buffer_pos+1]<=name_char_2;
            mid_frame_buffer[mid_buffer_pos+2]<=name_char_3;

                if(frame_buffer[y_record_out*40+buffer_pos+2]!=0) begin
                    mid_frame_buffer[mid_buffer_pos+3]<=37;
                    buffer_pos<=buffer_pos+3;
                    mid_buffer_pos<=mid_buffer_pos+4;
                    state<=Mid_Translation;
                    number_char_1<=frame_buffer[y_record_out*40+buffer_pos+3];
						  number_char_2<=frame_buffer[y_record_out*40+buffer_pos+4];
                end
                else begin
                   
                    mid_buffer_pos<=mid_buffer_pos+3;
                    buffer_pos<=buffer_pos+2;
                end
        end
        else begin
            if(mid_buffer_pos<440) begin
                mid_frame_buffer[mid_buffer_pos]<=0;
                mid_buffer_pos<=mid_buffer_pos+1;
            end
            else begin
                state<= Mid_Show;
                mid_buffer_pos<=0;
                buffer_pos<=0;
            end
        end
    end
    Mid_Show : begin
        if(stateFlag==3) state <= Mid_Back;
        else state <= Mid_Show;
    end
    Mid_Back : begin
        if(stateFlag==4) state <= Normal;
        else state <= Mid_Back;
    end
	 default: ;
    endcase
    end
	
	always_comb begin
		if(line_start<=line_end) begin
			if(Y>=line_start&&Y<=line_end) char_color<= red;
			else char_color <= white;
		end
		else begin
			if((Y>=line_start&&Y<=29)||(Y>=0&&Y<=line_end)) char_color<= red;
			else char_color <= white;
		end
	end	
	
    always_comb begin
        case (state)
            Normal: begin
                num_char = frame_buffer[rp];
                if(Y==y_out) {VGA_R, VGA_G, VGA_B} = char_show && num_char != 0 ? char_color : 24'h404040;
                else  {VGA_R, VGA_G, VGA_B} = char_show && num_char != 0 ? char_color : 24'h000000;
            end
            Mid_Forward : begin
					 num_char = 0;
                if(Y<=y_out+size&&Y>=y_out-size) {VGA_R, VGA_G, VGA_B}=24'h404040;
                else {VGA_R, VGA_G, VGA_B}=24'h000000;
            end
            Mid_Show : begin
                if(Y<=y_out+size&&Y>=y_out-size) begin
                num_char = mid_frame_buffer[(Y-(y_out-size))*40+X];
                {VGA_R, VGA_G, VGA_B} = char_show && num_char != 0 ? blue : 24'h404040;
                end else begin 
							{VGA_R, VGA_G, VGA_B}=24'h000000;
							num_char=0;
							end
            end
            Mid_Back : begin
					  num_char = 0;
                if(Y<=y_out+size&&Y>=y_out-size) {VGA_R, VGA_G, VGA_B}=24'h404040;
                else {VGA_R, VGA_G, VGA_B}=24'h000000;
            end
				default : begin
					num_char=0;
					{VGA_R, VGA_G, VGA_B}=24'h000000;
					end
        endcase
    end

=======
>>>>>>> 9ec8d5612d16fa1250b92a8d96b1ed7225904e55
    always_ff @(posedge clk) begin
      if (we) frame_buffer[wp] <= char;
    end

endmodule // VGA_LED_Emulator


module FanShow (
    input logic [5:0] bottom,
    input logic clk, reset,
    input logic [2:0] adv, // 3'd0 0, 3'd1 -1, 3'd2 +1, 3'd3 enter, 3'd4 esc
    output logic [5:0] y_out,
    output logic [5:0] y_record_out,
    output logic [3:0] size,
    output logic [2:0] stateFlag // 3'd1: Mid_Forward state, 3'd2: Mid_Idler state, 3'd3: Mid_Back state, 3'd4: Mid_Back finish
    );

logic [5:0] y_record;
assign y_record_out = y_record;
logic [5:0] y_pos;
assign y_out = y_pos;

logic [23:0] clk_count;

enum logic [4:0] {Initial, Idler, Plus, Minus, Mid, Mid_Idler, Mid_Forward, Mid_Back, Image} state;

    always_ff @(posedge clk)
    if (reset)	state <= Initial ;
    else case (state)
    Initial: begin
    y_pos <= 6'd0;
    y_record <= 6'd0;
    size <= 4'd0;
    stateFlag <= 3'd0;
    clk_count <= 10'd0;
    state <= Idler;
    end
    Idler: begin
    if (y_pos == 6'd0) begin
    if (adv == 3'd0 || adv == 3'd4 || adv == 3'd1) begin
    state <= Idler;
    end else if (adv == 3'd2) begin
    state <= Plus;
    end else if (adv == 3'd3) begin
    state <= Mid;
    end
    end else if (y_pos == bottom) begin
    if (adv == 3'd0 || adv == 3'd4 || adv == 3'd2) begin
    state <= Idler;
    end else if (adv == 3'd1) begin
    state <= Minus;
    end else if (adv == 3'd3) begin
    state <= Mid;
    end
    end else begin
    if (adv == 3'd1) state <=  Minus;
    else if (adv == 3'd2) state <= Plus;
    else if (adv == 3'd3) state <= Mid;
    else state <= Idler;
    end
    end
    Plus: begin
    y_pos <= y_pos +1;
    state <= Image;
    end
    Minus: begin
    y_pos <= y_pos - 1;
    state <= Image;
    end
    Image: begin
    if (adv == 3'd0)
    state <= Idler;
    else state <= Image;
    end
    Mid: begin
    y_record <= y_pos;
    stateFlag <= 3'd1;
    state <= Mid_Forward;
    end
    Mid_Forward: begin
    if(clk_count<24'd500000) begin
    clk_count <= clk_count+1;
    state <= Mid_Forward;
    end
    else begin
    clk_count <= 0;
    if (y_pos < 6'd15) begin
    y_pos <= y_pos +1;
    if(size<4'd5) size <= size +1;
    state <= Mid_Forward;
    end else if (y_pos > 6'd15) begin
    y_pos <= y_pos -1;
    if(size<4'd5) size <= size +1;
    state <= Mid_Forward;
    end else if (y_pos == 6'd15) begin
    if(size<4'd5) begin
    size <= size +1;
    state <= Mid_Forward;
    end
    else begin
    state <= Mid_Idler;
    stateFlag <=3'd2;
    end
    end
    end
    end
    Mid_Idler: begin
    if (adv == 3'd4) begin
    state <= Mid_Back;
    stateFlag <= 3'd3;
    end else begin
    state <= Mid_Idler;
    end
    end
    Mid_Back: begin
    if(clk_count<24'd500000) begin
    clk_count <= clk_count+1;
    state <= Mid_Back;
    end
    else begin
    clk_count <= 0;
    if (y_pos < y_record) begin
    y_pos <= y_pos + 1;
    if(size>4'd0) size <= size -1;
    state <= Mid_Back;
    end else if (y_pos > y_record) begin
    y_pos <= y_pos - 1;
    if(size>4'd0) size <= size -1;
    state <= Mid_Back;
    end else begin
    if(size>4'd0) begin
    size <= size -1;
    state <= Mid_Back;
    end
    else begin
    state <= Idler;
    stateFlag <= 3'd4;
    end
    end
    end
    end
    default:          state <= Initial;
    endcase
endmodule

module Translation (
    input logic [5:0] number_char_1,
	 input logic [5:0] number_char_2,
    output logic [5:0] name_char_1,
    output logic [5:0] name_char_2,
    output logic [5:0] name_char_3);

always_comb begin
	case(number_char_1)
	6'd10: begin  //0
		 case(number_char_2)
		 6'd10: begin
		 name_char_1 <= 31; //U
		 name_char_2 <= 29; //S
		 name_char_3 <= 13; //D
		 end
		 6'd1: begin
		 name_char_1 <= 15; //E
		 name_char_2 <= 31; //U
		 name_char_3 <= 28; //R
		 end
		 6'd2: begin
		 name_char_1 <= 13; //C
		 name_char_2 <= 11; //A
		 name_char_3 <= 14; //D
		 end
		 6'd3: begin
		 name_char_1 <= 17; //G
		 name_char_2 <= 12; //B
		 name_char_3 <= 26; //P
		 end
		 6'd4: begin
		 name_char_1 <= 24; //N
		 name_char_2 <= 36; //Z
		 name_char_3 <= 14; //D
		 end
		 6'd5: begin
		 name_char_1 <= 11; //A
		 name_char_2 <= 31; //U
		 name_char_3 <= 14; //D
		 end
		 6'd6: begin
		 name_char_1 <= 13; //C
		 name_char_2 <= 18; //H
		 name_char_3 <= 16; //F
		 end
		 default: begin
		 name_char_1 <= 0; //
		 name_char_2 <= 0;
		 name_char_3 <= 0;
		 end
		 endcase
	end
	default: begin
		 name_char_1 <= 0; //
		 name_char_2 <= 0;
		 name_char_3 <= 0;
		 end
	endcase
end

endmodule



