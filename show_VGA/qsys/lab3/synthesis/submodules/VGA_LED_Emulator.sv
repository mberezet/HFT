/*
 * Seven-segment LED emulator
 *
 * Stephen A. Edwards, Columbia University
 */

module VGA_LED_Emulator(
 input logic 	    clk50, reset,
 input logic [7:0]  hex0, hex1, hex2, hex3, hex4, hex5, hex6, hex7,
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

  

logic show_p1;
logic show_p2;
logic show_p3;
logic show_p4;
logic show_p5;
logic show_p6;
logic [3:0] number_1, number_2;
 logic[7:0] address_1;
 logic[7:0] address_2;
 logic[7:0] address_3;
 logic[7:0] address_4;
 logic[7:0] address_5;
 logic[7:0] address_6;
 logic[23:0] RGB_1;
 logic[23:0] RGB_2;
 logic[23:0] RGB_3;
 logic[23:0] RGB_4;
 logic[23:0] RGB_5;
 logic[23:0] RGB_6; 
assign number_1 = 4'd2;
assign number_2 = 4'd4;


 always_comb 
	begin
		if (hcount[10:1]>= 200 && hcount[10:1] <= 215 && vcount[9:0] >= 200 && vcount[9:0] <= 215)
			begin
				show_p1 <= 1'b1;
				show_p2 <= 1'b0;
				address_1 <= ((hcount[10:1]- 200) + ( vcount[9:0]- 200) * 16);
				address_2 <= ((hcount[10:1]- 200) + ( vcount[9:0]- 200) * 16);
				address_3 <= ((hcount[10:1]- 200) + ( vcount[9:0]- 200) * 16);
				address_4 <= ((hcount[10:1]- 200) + ( vcount[9:0]- 200) * 16);
				address_5 <= ((hcount[10:1]- 200) + ( vcount[9:0]- 200) * 16);
				address_6 <= ((hcount[10:1]- 200) + ( vcount[9:0]- 200) * 16);
			end
		else if (hcount[10:1]>= 100 && hcount[10:1] <= 115 && vcount[9:0] >= 100 && vcount[9:0] <= 115)
			begin
				show_p2 <= 1'b1;
				show_p1 <= 1'b0;
				address_1 <= ((hcount[10:1]- 100) + ( vcount[9:0]- 100) * 16);
				address_2 <= ((hcount[10:1]- 100) + ( vcount[9:0]- 100) * 16);
				address_3 <= ((hcount[10:1]- 100) + ( vcount[9:0]- 100) * 16);
				address_4 <= ((hcount[10:1]- 100) + ( vcount[9:0]- 100) * 16);
				address_5 <= ((hcount[10:1]- 100) + ( vcount[9:0]- 100) * 16);
				address_6 <= ((hcount[10:1]- 100) + ( vcount[9:0]- 100) * 16);
			end
		else 
			begin
				show_p2 <= 1'b0;
				show_p1 <= 1'b0;
				address_1 <= 0;
				address_2 <= 0;
				address_3 <= 0;
				address_4 <= 0;
				address_5 <= 0;
				address_6 <= 0;
			end
	end
n_0 num1(.address(address_1),.clock(clk50),.q(RGB_1));
n_2 num2(.address(address_2),.clock(clk50),.q(RGB_2));
c_Z num3(.address(address_3),.clock(clk50),.q(RGB_3));
c_A num4(.address(address_4),.clock(clk50),.q(RGB_4));
c_G num5(.address(address_5),.clock(clk50),.q(RGB_5));
n_9 num6(.address(address_6),.clock(clk50),.q(RGB_6));
 
   always_comb begin
      {VGA_R, VGA_G, VGA_B} = {8'h0, 8'h0, 8'h0}; // Black
	if(show_p1 == 1'b1) begin
		case(number_1)
            4'd0: {VGA_R, VGA_G, VGA_B} = RGB_6;
            4'd1: {VGA_R, VGA_G, VGA_B} = RGB_1;
	    4'd2: {VGA_R, VGA_G, VGA_B} = RGB_2;
	    4'd3: {VGA_R, VGA_G, VGA_B} = RGB_3;
	    4'd4: {VGA_R, VGA_G, VGA_B} = RGB_4;
	    4'd5: {VGA_R, VGA_G, VGA_B} = RGB_5;
	    4'd6: {VGA_R, VGA_G, VGA_B} = RGB_6;
		default: {VGA_R, VGA_G, VGA_B} = RGB_1;
		endcase
	end
	else if (show_p2 == 1'b1) begin
		case(number_2) 
            4'd0: {VGA_R, VGA_G, VGA_B} = RGB_6;
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









