/*
 * Seven-segment LED emulator
 *
 * Stephen A. Edwards, Columbia University
 */

module VGA_LED_Emulator(
 input logic 	    clk50, reset,
 input logic [7:0]  hex0, hex1, hex2, hex3, hex4, hex5, hex6, hex7,
 output logic [7:0] VGA_R, VGA_G, VGA_B,
 output logic 	    VGA_CLK, VGA_HS, VGA_VS, VGA_BLANK_n, VGA_SYNC_n);

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

   logic [10:0]			     hcount; // Horizontal counter
                                             // Hcount[10:1] indicates pixel column (0-639)
   logic 			     endOfLine;
   
   always_ff @(posedge clk50 or posedge reset)
     if (reset)          hcount <= 0;
     else if (endOfLine) hcount <= 0;
     else  	         hcount <= hcount + 11'd 1;

   assign endOfLine = hcount == HTOTAL - 1;

   // Vertical counter
   logic [9:0] 			     vcount;
   logic 			     endOfField;
   
   always_ff @(posedge clk50 or posedge reset)
     if (reset)          vcount <= 0;
     else if (endOfLine)
       if (endOfField)   vcount <= 0;
       else              vcount <= vcount + 10'd 1;

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
    * clk50    __|  |__|  |__|
    *        
    *             _____       __
    * hcount[0]__|     |_____|
    */
   assign VGA_CLK = hcount[0]; // 25 MHz clock: pixel latched on rising edge


    logic [8:0] x,y,start_x,start_y;
    logic [5:0] character_number;
    logic [3:0] color_number;
    assign x=hcount[10:2];
    assign y=vcount[9:1];
    logic [5:0] in_area;

    SHOW show(.*);
    SHOW_CHARACTER show_character(.*);
        

endmodule // VGA_LED_Emulator

module SHOW(
    input logic [8:0] x,y,
    output logic [8:0] start_x,start_y,
    output logic [5:0] character_number,
    output logic [3:0] color_number,
    output logic [5:0] in_area);

    always_comb begin
    if(x>=9'd0&&x<9'd8&&y>=9'd0&&y<9'd8)
        begin
        start_x=9'd0;
        start_y=9'd0;
        character_number=30;
        color_number=0;
        in_area=6'd1;
        end
    else if(x>=9'd8&&x<9'd16&&y>=9'd0&&y<9'd8)
        begin
        start_x=9'd8;
        start_y=9'd0;
        character_number=28;
        color_number=1;
        in_area=6'd2;
        end
    else if(x>=9'd16&&x<9'd24&&y>=9'd0&&y<9'd8)
        begin
        start_x=9'd16;
        start_y=9'd0;
        character_number=13;
        color_number=2;
        in_area=6'd2;
        end

    else if(x>=9'd0&&x<9'd8&&y>=9'd8&&y<9'd16)
        begin
        start_x=9'd0;
        start_y=9'd8;
        character_number=0;
        color_number=2;
        in_area=6'd3;
        end
    else if(x>=9'd8&&x<9'd16&&y>=9'd8&&y<9'd16)
        begin
        start_x=9'd8;
        start_y=9'd8;
        character_number=1;
        color_number=1;
        in_area=6'd4;
        end
    else if(x>=9'd16&&x<9'd24&&y>=9'd8&&y<9'd16)
        begin
        start_x=9'd16;
        start_y=9'd8;
        character_number=2;
        color_number=1;
        in_area=6'd4;
        end

    else
        begin
        start_x=9'd0;
        start_y=9'd0;
        character_number=0;
        color_number=0;
        in_area=6'd0;
        end
    end
    
endmodule


module SHOW_CHARACTER(
    input logic [5:0] in_area,
    input logic [8:0] x,y,start_x,start_y,
    input logic [5:0] character_number,
    input logic [3:0] color_number,
    output logic [7:0] VGA_R, VGA_G, VGA_B);

    logic [8:0] char_x, char_y;
    logic inchar;
    assign char_x=x-start_x;
    assign char_y=y-start_y;
    
    always_comb begin
    if (in_area>0)
        begin
        case (character_number)
            // '0'
            6'd0: begin if (char_y==9'd0&&char_x>=9'd1&&char_x<=9'd3) inchar=1;
                        else if (char_y==9'd1&&(char_x==9'd0||char_x==9'd4)) inchar =1;
                        else if (char_y==9'd2&&(char_x==9'd0||char_x==9'd3||char_x==9'd4)) inchar =1;
                        else if (char_y==9'd3&&(char_x==9'd0||char_x==9'd2||char_x==9'd4)) inchar =1;
                        else if (char_y==9'd4&&(char_x==9'd0||char_x==9'd1||char_x==9'd4)) inchar =1;
                        else if (char_y==9'd5&&(char_x==9'd0||char_x==9'd4)) inchar =1;
                        else if (char_y==9'd6&&(char_x>=9'd1&&char_x<=9'd3)) inchar =1;
                        else inchar=0;
                end
            // '1'
            6'd1: begin if (char_y==9'd0&&char_x==9'd2) inchar=1;
                        else if (char_y==9'd1&&(char_x==9'd1||char_x==9'd2)) inchar =1;
                        else if (char_y==9'd2&&char_x==9'd2) inchar =1;
                        else if (char_y==9'd3&&char_x==9'd2) inchar =1;
                        else if (char_y==9'd4&&char_x==9'd2) inchar =1;
                        else if (char_y==9'd5&&char_x==9'd2) inchar =1;
                        else if (char_y==9'd6&&(char_x>=9'd1&&char_x<=9'd3)) inchar =1;
                        else inchar=0;
                end
            // '2'
            6'd2: begin if (char_y==9'd0&&char_x>=9'd1&&char_x<=9'd3) inchar=1;
                        else if (char_y==9'd1&&(char_x==9'd0||char_x==9'd4)) inchar =1;
                        else if (char_y==9'd2&&char_x==9'd4) inchar =1;
                        else if (char_y==9'd3&&char_x==9'd3) inchar =1;
                        else if (char_y==9'd4&&char_x==9'd2) inchar =1;
                        else if (char_y==9'd5&&char_x==9'd1) inchar =1;
                        else if (char_y==9'd6&&(char_x>=9'd0&&char_x<=9'd5)) inchar =1;
                        else inchar=0;
                end
             // '3'
             6'd3: begin if (char_y==9'd0&&char_x>=9'd1&&char_x<=9'd3) inchar=1;
                      else if (char_y==9'd1&&(char_x==9'd0||char_x==9'd4)) inchar =1;
                      else if (char_y==9'd2&&char_x==9'd4) inchar =1;
                      else if (char_y==9'd3&&(char_x==9'd2||char_x==9'd3)) inchar =1;
                      else if (char_y==9'd4&&char_x==9'd4) inchar =1;
                      else if (char_y==9'd5&&(char_x==9'd0||char_x==9'd4)) inchar =1;
                      else if (char_y==9'd6&&(char_x>=9'd1&&char_x<=9'd3)) inchar =1;
                      else inchar=0;
                end

            // 'D'
            6'd13: begin if (char_y==9'd0&&char_x>=9'd0&&char_x<=9'd3) inchar=1;
                        else if (char_y==9'd1&&(char_x==9'd0||char_x==9'd4)) inchar =1;
                        else if (char_y==9'd2&&(char_x==9'd0||char_x==9'd4)) inchar =1;
                        else if (char_y==9'd3&&(char_x==9'd0||char_x==9'd4)) inchar =1;
                        else if (char_y==9'd4&&(char_x==9'd0||char_x==9'd4)) inchar =1;
                        else if (char_y==9'd5&&(char_x==9'd0||char_x==9'd4)) inchar =1;
                        else if (char_y==9'd6&&(char_x>=9'd0&&char_x<=9'd3)) inchar =1;
                        else inchar=0;
                end

            // 'S'
            6'd28: begin if (char_y==9'd0&&char_x>=9'd1&&char_x<=9'd3) inchar=1;
                        else if (char_y==9'd1&&(char_x==9'd0||char_x==9'd4)) inchar =1;
                        else if (char_y==9'd2&& char_x==9'd0) inchar =1;
                        else if (char_y==9'd3&&(char_x>=9'd1&&char_x<=9'd3)) inchar =1;
                        else if (char_y==9'd4&&char_x==9'd4) inchar =1;
                        else if (char_y==9'd5&&(char_x==9'd0||char_x==9'd4)) inchar =1;
                        else if (char_y==9'd6&&(char_x>=9'd1&&char_x<=9'd3)) inchar =1;
                        else inchar=0;
                end

                                 
            // 'U'
            6'd30: begin if (char_y==9'd0&&char_x>=9'd1&&char_x<=9'd3) inchar=1;
                        else if (char_y==9'd1&&(char_x==9'd0||char_x==9'd4)) inchar =1;
                        else if (char_y==9'd2&&(char_x==9'd0||char_x==9'd4)) inchar =1;
                        else if (char_y==9'd3&&(char_x==9'd0||char_x==9'd4)) inchar =1;
                        else if (char_y==9'd4&&(char_x==9'd0||char_x==9'd4)) inchar =1;
                        else if (char_y==9'd5&&(char_x==9'd0||char_x==9'd4)) inchar =1;
                        else if (char_y==9'd6&&(char_x>=9'd1&&char_x<=9'd3)) inchar =1;
                        else inchar=0;
                end

                                 
            default: inchar =0;
        endcase
        end
    
    else inchar=0;

    if(inchar==1)
        case(color_number)
            4'd0: {VGA_R, VGA_G, VGA_B} = {8'hff, 8'h00, 8'h00}; // Red
            4'd1: {VGA_R, VGA_G, VGA_B} = {8'h00, 8'hff, 8'h00}; // green
            4'd2: {VGA_R, VGA_G, VGA_B} = {8'h00, 8'h00, 8'hff}; // blue
            default: {VGA_R, VGA_G, VGA_B} = {8'hff, 8'hff, 8'hff}; // white
        endcase
    else
        {VGA_R, VGA_G, VGA_B} = {8'h0, 8'h0, 8'h0}; // Black
            
    end
endmodule

