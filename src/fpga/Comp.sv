`include "Const.svh"
/* verilator lint_off WIDTH */
module Comp(input logic [31:0] vertmat [`NODES:0],
						input logic [31:0] e1, e2,
						output logic [31:0] o_e1, o_e2);

	logic [6:0] v1, v2;
	logic [16:0] w_v1, w_v2, w_e1, w_e2;
	logic u_e1, u_e2;

	always_comb begin
		v1 = e1[24:18]; //Dest
		v2 = e2[24:18];
		w_v1 = vertmat[v1][16:0];
		w_v2 = vertmat[v2][16:0];
		w_e1 = e1[16:0];
		w_e2 = e2[16:0];
		u_e1 = e1[17];
		u_e2 = e2[17];
    o_e1 = e1;
		o_e2 = e2;
		if (w_e1 == 0 && w_e2 == 0) begin //Both non-edges
			o_e1[17] = 0;
			o_e2[17] = 0;
		end else if(w_e1 == 0) begin //1 is non-edge
			o_e1[17] = 0;
			o_e2[17] = 1;
		end else if(w_e2 == 0) begin //2 is non-edge
			o_e1[17] = 1;
			o_e2[17] = 0;
		end else begin //neither is a non-edge
			if (u_e1 == u_e2 == 1) begin
				if (v1 == v2) begin
					if (w_v1 + w_e1 < w_v2 + w_e2) begin
						o_e1[17] = 1;
						o_e2[17] = 0;
					end else begin
						o_e1[17] = 0;
						o_e2[17] = 1;
					end
				end else begin
					if (v1 < v2) begin
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
