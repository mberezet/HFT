/*
 * Avalon memory-mapped peripheral for the VGA LED Emulator
 *
 * Stephen A. Edwards
 * Columbia University
 */

module FOREX(input logic clk,
			       input logic reset,
			       input logic [7:0] writedata,
			       input logic write,
			       input chipselect,
			       input logic [2:0] address,

			       output logic [7:0] VGA_R, VGA_G, VGA_B,
			       output logic VGA_CLK, VGA_HS, VGA_VS, VGA_BLANK_n,
			       output logic VGA_SYNC_n);

		logic [5:0] x, y;
		x = 1;
		y = 1;
		logic [4:0] char = 5'd1;
		logic [23:0] color = 24'hff0000;
		Frame buffer(.*);

		/*always_ff @(posedge clk)
		 if (reset) begin

		 end else if (chipselect && write)
		   case (address)
				 3'h0 : ;
				 3'h1 : ;
				 3'h2 : ;
				 3'h3 : ;
				 3'h4 : ;
				 3'h5 : ;
				 3'h6 : ;
				 3'h7 : ;
		   endcase*/

endmodule
