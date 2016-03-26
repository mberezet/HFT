module Sort(input [31:0] vertmat [NODES:0],
				input [31 :0] e1, e2, e3, e4,
				output [31:0] o_e1, o_e2, o_e3, o_e4);
	logic [31:0] w1, w2, w3, w4, w5, w6, w7, w8;
	always_comb begin
		Comp c1(.e1(e1), .e2(e2), .o_e1(w1). .o_e2(w2), .*);
		Comp c2(.e1(e3), .e2(e4), .o_e1(w3). .o_e2(w4), .*);
		Comp c3(.e1(w1), .e2(w3), .o_e1(w5). .o_e2(w6), .*);
		Comp c4(.e1(w2), .e2(w4), .o_e1(w7). .o_e2(w8), .*);
		Comp c5(.e1(w5), .e2(w7), .o_e1(o_e1). .o_e2(o_e2), .*);
		Comp c6(.e1(w6), .e2(w8), .o_e1(o_e3). .o_e2(o_e4), .*);
	end
endmodule

module Comp(input [31:0] vertmat [NODES:0],
				input [31:0] e1, e2,
				output [31:0] o_e1, o_e2);
				
	logic [6:0] v1 = e1[24:18]; //Dest
	logic [6:0] v2 = e2[24:18];
	logic [16:0] w_v1 = vertmat[v1][17:0];
	logic [16:0] w_v2 = vertmat[v1][17:0];
	logic [16:0] w_e1 = e1[16:0];
	logic [16:0] w_e2 = e2[16:0];
	logic u_e1 = e1[17];
	logic u_e2 = e1[17];
	
	always_comb begin
		if (u_e1 == u_e2 == 1) begin
			if (v1 == v2) begin
				if (w_v1 + w_e1 < w_v2 + w_e2) begin
					e1[17] = 1;
					e2[17] = 0;
				end else begin
					e1[17] = 0;
					e2[17] = 1;
				end
			end else begin
				if v1 < v2 begin
					e1[17] = 1;
					e2[17] = 0;
				end else begin
					e1[17] = 0;
					e2[17] = 1;
				end
			end
		end else if (u_e1 != u_e2) begin
			if (u_e1 == 1) begin
				e1[17] = 1;
				e2[17] = 0;
			end else begin
				e1[17] = 0;
				e2[17] = 1;
			end
		end
		else begin
			e1[17] = 1;
			e2[17] = 0;
		end
		o_e1 = e1;
		o_e2 = e2;
	end
endmodule