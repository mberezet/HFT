/*
 * Avalon memory-mapped peripheral for the VGA LED Emulator
 *
 * Stephen A. Edwards
 * Columbia University
 */

module VGA_LED(input logic        clk,
	       input logic 	  reset,
	       input logic [7:0]  writedata,
	       input logic 	  write,
	       input 		  chipselect,
	       input logic [2:0]  address,

	       output logic [7:0] VGA_R, VGA_G, VGA_B,
	       output logic 	  VGA_CLK, VGA_HS, VGA_VS, VGA_BLANK_n,
	       output logic 	  VGA_SYNC_n);

	 
   logic [7:0] 			  hex0, hex1, hex2, hex3,
				  hex4, hex5, hex6, hex7;

    logic [5:0] frame_buffer [9:0][1:0];

   VGA_LED_Emulator led_emulator(.clk50(clk), .*);

   always_ff @(posedge clk)
     if (reset) begin
        frame_buffer[0][0]=1;
        frame_buffer[1][0]=10;
        frame_buffer[2][0]=3;
        frame_buffer[3][0]=10;
        frame_buffer[4][0]=4;
        frame_buffer[5][0]=5;
        frame_buffer[6][0]=6;
        frame_buffer[7][0]=0;
        frame_buffer[8][0]=0;
        frame_buffer[9][0]=0;
        frame_buffer[0][1]=6;
        frame_buffer[1][1]=5;
        frame_buffer[2][1]=4;
        frame_buffer[3][1]=3;
        frame_buffer[4][1]=0;
        frame_buffer[5][1]=0;
        frame_buffer[6][1]=0;
        frame_buffer[7][1]=2;
        frame_buffer[8][1]=5;
        frame_buffer[9][1]=1;

     end else if (chipselect && write)
       case (address)
	 3'h0 : hex0 <= writedata;
	 3'h1 : hex1 <= writedata;
	 3'h2 : hex2 <= writedata;
	 3'h3 : hex3 <= writedata;
	 3'h4 : hex4 <= writedata;
	 3'h5 : hex5 <= writedata;
	 3'h6 : hex6 <= writedata;
	 3'h7 : hex7 <= writedata;
       endcase
	       
endmodule
