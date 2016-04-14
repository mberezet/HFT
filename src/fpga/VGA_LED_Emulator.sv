/*
 * Seven-segment LED emulator
 *
 * Stephen A. Edwards, Columbia University
 */

module VGA_LED_Emulator(
 input logic 	    clk50, reset,
// input logic [7:0]  hex0, hex1, hex2, hex3, hex4, hex5, hex6, hex7,
 input logic [5:0] frame_buffer [9:0][1:0],
// input logic [15:0]  x, y, r, color,
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


 logic [5:0] x,y;
assign x=hcount[10:5];
assign y=vcount[9:4];
                            
 logic show;
 logic [3:0] number;
 logic[7:0] address;
 
 logic[23:0] RGB_1;
 logic[23:0] RGB_2;
 logic[23:0] RGB_3;
 logic[23:0] RGB_4;
 logic[23:0] RGB_5;
 logic[23:0] RGB_6; 

                            
 always_comb 
	begin
		if (x>= 0 && x <= 9 && y >= 0 && y <= 1&&(frame_buffer[x][y]!=0))
			begin
            address = ((hcount[10:1]- x*16) + ( vcount[9:0]- y*16) * 16);
            number = frame_buffer[x][y];
            show = 1;
            end
        else
            begin
            address=0;
            number=0;
            show=0;
            end
	end
                            
n_0 num1(.address(address),.clock(clk50),.q(RGB_1));
n_2 num2(.address(address),.clock(clk50),.q(RGB_2));
n_9 num3(.address(address),.clock(clk50),.q(RGB_3));
c_A num4(.address(address),.clock(clk50),.q(RGB_4));
c_G num5(.address(address),.clock(clk50),.q(RGB_5));
c_Z num6(.address(address),.clock(clk50),.q(RGB_6));
 
   always_comb begin
      {VGA_R, VGA_G, VGA_B} = {8'h0, 8'h0, 8'h0}; // Black
	if(show == 1'b1) begin
		case(number)
            4'd1: {VGA_R, VGA_G, VGA_B} = RGB_1;
	    4'd2: {VGA_R, VGA_G, VGA_B} = RGB_2;
	    4'd3: {VGA_R, VGA_G, VGA_B} = RGB_3;
	    4'd4: {VGA_R, VGA_G, VGA_B} = RGB_4;
	    4'd5: {VGA_R, VGA_G, VGA_B} = RGB_5;
	    4'd6: {VGA_R, VGA_G, VGA_B} = RGB_6;
		default: {VGA_R, VGA_G, VGA_B} = RGB_1;
		endcase
	end
  end  
   
endmodule // VGA_LED_Emulator









