`include "Const.svh"
/* verilator lint_off WIDTH */
/* verilator lint_off UNUSED */
module Relax(input logic [6:0] s1, s2, s3, s4, //Index of Predescessor Vertex
						 input logic [31:0] e1, e2, e3, e4, //Weight of Edge
						 input logic [31:0] sv1, sv2, sv3, sv4, //Weight of Source Vertex
						 input logic [31:0] dv1, dv2, dv3, dv4, //Weight of Destination Vertex
						 output logic [31:0] o_dv1, o_dv2, o_dv3, o_dv4,
						 output logic [3:0] update_mask);
	logic [24:0] sum;
	logic u_e1, u_e2, u_e3, u_e4;
	always_comb begin
		sum = 0;
		u_e1 = e1[31];
		u_e2 = e2[31];
		u_e3 = e3[31];
		u_e4 = e4[31];

		if (u_e1 == 1) begin
			sum = e1[30:0] + sv1[24:0];
			if (sum < dv1) begin
				o_dv1[24:0] = sum;
				o_dv1[31:25] = s1;
				update_mask[0] = 1;
			end
		end
		if (u_e2 == 1) begin
			sum = e2[30:0] + sv2[24:0];
			if (sum < dv2) begin
				o_dv2[24:0] = sum;
				o_dv2[31:25] = s2;
				update_mask[1] = 1;
			end
		end
		if (u_e3 == 1) begin
			sum = e3[30:0] + sv3[24:0];
			if (sum < dv3) begin
				o_dv3[24:0] = sum;
				o_dv3[31:25] = s3;
				update_mask[2] = 1;
			end
		end
		if (u_e4 == 1) begin
			sum = e4[30:0] + sv4[24:0];
			if (sum < dv4) begin
				o_dv4[24:0] = sum;
				o_dv4[31:25] = s4;
				update_mask[3] = 1;
			end
		end
	end
endmodule
