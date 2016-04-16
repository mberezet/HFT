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

    logic [5:0] frame_buffer [1:0][9:0];

   VGA_LED_Emulator led_emulator(.clk50(clk), .*);

   always_ff @(posedge clk)
     if (reset) begin
        frame_buffer[0][0]=37;   //"->"
        frame_buffer[0][1]=30;   //"T"
        frame_buffer[0][2]=32;   //"V"
        frame_buffer[0][3]=25;   //"O"
        frame_buffer[0][4]=4;    //"4"
        frame_buffer[0][5]=5;
        frame_buffer[0][6]=6;
        frame_buffer[0][7]=7;
        frame_buffer[0][8]=8;
        frame_buffer[0][9]=9;
        frame_buffer[1][0]=10;   //"0"
        frame_buffer[1][1]=11;
        frame_buffer[1][2]=12;
        frame_buffer[1][3]=13;
        frame_buffer[1][4]=14;
        frame_buffer[1][5]=0;    // black
        frame_buffer[1][6]=0;
        frame_buffer[1][7]=35;
        frame_buffer[1][8]=36;
        frame_buffer[1][9]=37;

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
