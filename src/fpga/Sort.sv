`include "Const.svh"

module Sort(input logic [31:0] vertmat [`NODES:0],
						input logic [31 :0] e1, e2, e3, e4,
						output logic [31:0] o_e1, o_e2, o_e3, o_e4);
	logic [31:0] w1, w2, w3, w4, w5, w6, w7, w8;
	//Wire up the comparator modules
	Comp c1(.e1(e1), .e2(e2), .o_e1(w1), .o_e2(w2), .vertmat(vertmat));
	Comp c2(.e1(e3), .e2(e4), .o_e1(w3), .o_e2(w4), .vertmat(vertmat));
	Comp c3(.e1(w1), .e2(w3), .o_e1(w5), .o_e2(w6), .vertmat(vertmat));
	Comp c4(.e1(w2), .e2(w4), .o_e1(w7), .o_e2(w8), .vertmat(vertmat));
	Comp c5(.e1(w5), .e2(w7), .o_e1(o_e1), .o_e2(o_e2), .vertmat(vertmat));
	Comp c6(.e1(w6), .e2(w8), .o_e1(o_e3), .o_e2(o_e4), .vertmat(vertmat));
endmodule
