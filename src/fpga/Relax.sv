`include "Const.svh"

module Relax(input logic [31:0] vertmat [`NODES:0],
				input logic [31:0] e1, e2, e3, e4,
				output logic [31:0] o_vertmat [`NODES:0]);
	logic [17:0] sum;
	logic u_e1, u_e2, u_e3, u_e4;
	always_comb begin
		sum = 0;
		u_e1 = e1[17];
		u_e2 = e2[17];
		u_e3 = e3[17];
		u_e4 = e4[17];
		o_vertmat = vertmat;
		if (u_e1 == 1) begin
			sum = e1[16:0] + vertmat[e1[31:25]][17:0];
			if (sum < vertmat[e1[24:18]][17:0]) begin
				o_vertmat[e1[24:18]][17:0] = sum;
				o_vertmat[e1[24:18]][24:18] = e1[24:18];
			end
		end
		if (u_e2 == 1) begin
			sum = e2[16:0] + vertmat[e2[31:25]][17:0];
			if (sum < vertmat[e2[24:18]][17:0]) begin
				o_vertmat[e2[24:18]][17:0] = sum;
				o_vertmat[e2[24:18]][24:18] = e2[24:18];
			end
		end
		if (u_e3 == 1) begin
			sum = e3[16:0] + vertmat[e3[31:25]][17:0];
			if (sum < vertmat[e3[24:18]][17:0]) begin
				o_vertmat[e3[24:18]][17:0] = sum;
				o_vertmat[e3[24:18]][24:18] = e3[24:18];
			end
		end
		if (u_e4 == 1) begin
			sum = e4[16:0] + vertmat[e4[31:25]][17:0];
			if (sum < vertmat[e4[24:18]][17:0]) begin
				o_vertmat[e4[24:18]][17:0] = sum;
				o_vertmat[e4[24:18]][24:18] = e4[24:18];
			end
		end
	end
endmodule
