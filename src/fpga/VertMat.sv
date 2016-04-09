// Quartus II Verilog Template
// Single port RAM with single read/write address 
`include "Const.vh"

module single_port_ram 
#(parameter DATA_WIDTH=`VERT_WIDTH, parameter ADDR_WIDTH=`PRED_WIDTH)
(
	input [DATA_WIDTH:0] data,
	input [ADDR_WIDTH:0] addr,
	input we, clk,
	output [DATA_WIDTH:0] q
);

	// Declare the RAM variable
	reg [DATA_WIDTH:0] ram[2**ADDR_WIDTH:0];

	// Variable to hold the registered read address
	reg [ADDR_WIDTH:0] addr_reg;

	always @ (posedge clk)
	begin
		// Write
		if (we)
			ram[addr] <= data;

		addr_reg <= addr;
	end

	// Continuous assignment implies read returns NEW data.
	// This is the natural behavior of the TriMatrix memory
	// blocks in Single Port mode.  
	assign q = ram[addr_reg];

endmodule
