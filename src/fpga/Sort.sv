`include "Const.svh"
/* verilator lint_off WIDTH */
module Sort(input logic [6 :0] d1, d2, d3, d4, //Index of Destionation Vertex
						input logic [24:0] dv1, dv2, dv3, dv4, //Weight of Destination Vertex
						input logic [31 :0] e1, e2, e3, e4, //Weight of Edge
						output logic [31:0] o_e1, o_e2, o_e3, o_e4); //Out Edges
	logic [31:0] wi1, wi2, wi3, wi4, wi5, wi6, wi7, wi8;
	//Wire up the comparator modules
	Comp c1(.d1(d1), .d2(d2),
					.dv1(dv1), .dv2(dv2),
					.e1(e1), .e2(e2),
					.o_e1(wi1), .o_e2(wi2));
	Comp c2(.d1(d3), .d2(d4),
					.dv1(dv3), .dv2(dv4),
					.e1(e3), .e2(e4),
					.o_e1(wi3), .o_e2(wi4));
	Comp c3(.d1(d1), .d2(d3),
					.dv1(dv1), .dv2(dv3),
					.e1(wi1), .e2(wi3),
					.o_e1(wi5), .o_e2(wi6));
	Comp c4(.d1(d2), .d2(d4),
					.dv1(dv2), .dv2(dv4),
					.e1(wi2), .e2(wi4),
					.o_e1(wi7), .o_e2(wi8));
	Comp c5(.d1(d1), .d2(d4),
					.dv1(dv1), .dv2(dv4),
					.e1(wi5), .e2(wi8),
					.o_e1(o_e1), .o_e2(o_e2));
	Comp c6(.d1(d2), .d2(d3),
					.dv1(dv2), .dv2(dv3),
					.e1(wi7), .e2(wi6),
					.o_e1(o_e3), .o_e2(o_e4));
endmodule
