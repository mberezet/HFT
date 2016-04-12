`include "Const.svh"
/* verilator lint_off WIDTH */
module Comp(input logic [6:0] d1, d2, //Destination Vertex Index
						input logic [24:0] dv1, dv2, //Weight of Destination Vertex
						input logic [31:0] e1, e2, //Weight of Edge
						output logic [31:0] o_e1, o_e2); //Output Edge

	logic [30:0] w1, w2;
	logic u_e1, u_e2;

	always_comb begin

		w1 = e1[30:0];
		w2 = e2[30:0];
		u_e1 = e1[31];
		u_e2 = e2[31];

    o_e1 = e1;
		o_e2 = e2;

		if (w1 == 0 && w2 == 0) begin //Both non-edges
			o_e1[17] = 0;
			o_e2[17] = 0;
		end else if(w1 == 0) begin //1 is non-edge
			o_e1[17] = 0;
			o_e2[17] = 1;
		end else if(w2 == 0) begin //2 is non-edge
			o_e1[17] = 1;
			o_e2[17] = 0;
		end else begin //neither is a non-edge
			if (u_e1 == u_e2 == 1) begin
				if (d1 == d2) begin
					if (dv1 + w1 < w2 + dv2) begin
						o_e1[17] = 1;
						o_e2[17] = 0;
					end else begin
						o_e1[17] = 0;
						o_e2[17] = 1;
					end
				end else begin
					if (d1 < d2) begin
						o_e1[17] = 1;
						o_e2[17] = 0;
					end else begin
						o_e1[17] = 0;
						o_e2[17] = 1;
					end
				end
			end else if (u_e1 != u_e2) begin
				if (u_e1 == 1) begin
					o_e1[17] = 1;
					o_e2[17] = 0;
				end else begin
					o_e1[17] = 0;
					o_e2[17] = 1;
				end
			end else begin
				o_e1[17] = 1;
				o_e2[17] = 0;
			end
		end
	end
endmodule
