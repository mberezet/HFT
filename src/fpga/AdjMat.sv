// Quartus II Verilog Template
// Single port RAM with single read/write address
`include "Const.vh"

module AdjMat
#(parameter DATA_WIDTH=`WEIGHT_WIDTH, parameter ADDR_WIDTH=(2*`PRED_WIDTH+1))
(
	input [DATA_WIDTH:0] data,
	input [`PRED_WIDTH:0] row_addr,
	input [`PRED_WIDTH:0] col_addr,
	input we, clk,
	output [DATA_WIDTH:0] q
);

	logic [ADDR_WIDTH:0] addr;
	assign addr = row_addr*`NODES + col_addr;

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
