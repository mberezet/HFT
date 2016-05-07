// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFOREX__Syms.h"


//======================

void VFOREX::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&VFOREX::traceInit, &VFOREX::traceFull, &VFOREX::traceChg, this);
}
void VFOREX::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VFOREX* t=(VFOREX*)userthis;
    VFOREX__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) vl_fatal(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VFOREX::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VFOREX* t=(VFOREX*)userthis;
    VFOREX__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void VFOREX::traceInitThis(VFOREX__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name()); // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VFOREX::traceFullThis(VFOREX__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VFOREX::traceInitThis__1(VFOREX__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+66,"clk",-1);
	vcdp->declBit  (c+67,"reset",-1);
	vcdp->declBus  (c+68,"writedata",-1,31,0);
	vcdp->declBit  (c+69,"write",-1);
	vcdp->declBit  (c+70,"chipselect",-1);
	vcdp->declBus  (c+71,"address",-1,2,0);
	vcdp->declBus  (c+72,"VGA_R",-1,7,0);
	vcdp->declBus  (c+73,"VGA_G",-1,7,0);
	vcdp->declBus  (c+74,"VGA_B",-1,7,0);
	vcdp->declBit  (c+75,"VGA_CLK",-1);
	vcdp->declBit  (c+76,"VGA_HS",-1);
	vcdp->declBit  (c+77,"VGA_VS",-1);
	vcdp->declBit  (c+78,"VGA_BLANK_n",-1);
	vcdp->declBit  (c+79,"VGA_SYNC_n",-1);
	vcdp->declBit  (c+80,"frame_we",-1);
	vcdp->declBus  (c+81,"frame_char",-1,5,0);
	vcdp->declBus  (c+82,"test",-1,31,0);
	vcdp->declBit  (c+66,"v clk",-1);
	vcdp->declBit  (c+67,"v reset",-1);
	vcdp->declBus  (c+68,"v writedata",-1,31,0);
	vcdp->declBit  (c+69,"v write",-1);
	vcdp->declBit  (c+70,"v chipselect",-1);
	vcdp->declBus  (c+71,"v address",-1,2,0);
	vcdp->declBus  (c+72,"v VGA_R",-1,7,0);
	vcdp->declBus  (c+73,"v VGA_G",-1,7,0);
	vcdp->declBus  (c+74,"v VGA_B",-1,7,0);
	vcdp->declBit  (c+75,"v VGA_CLK",-1);
	vcdp->declBit  (c+76,"v VGA_HS",-1);
	vcdp->declBit  (c+77,"v VGA_VS",-1);
	vcdp->declBit  (c+78,"v VGA_BLANK_n",-1);
	vcdp->declBit  (c+79,"v VGA_SYNC_n",-1);
	vcdp->declBit  (c+80,"v frame_we",-1);
	vcdp->declBus  (c+81,"v frame_char",-1,5,0);
	vcdp->declBus  (c+82,"v test",-1,31,0);
	vcdp->declBus  (c+29,"v state",-1,3,0);
	vcdp->declBus  (c+30,"v next_state",-1,3,0);
	vcdp->declBus  (c+83,"v src",-1,6,0);
	vcdp->declBus  (c+31,"v u_src",-1,6,0);
	vcdp->declBus  (c+32,"v u_dst",-1,6,0);
	vcdp->declBus  (c+33,"v u_e",-1,31,0);
	vcdp->declBus  (c+34,"v frame_x",-1,5,0);
	vcdp->declBus  (c+1,"v frame_y",-1,5,0);
	vcdp->declBit  (c+35,"v container_done",-1);
	vcdp->declBit  (c+36,"v container_reset",-1);
	vcdp->declBit  (c+66,"v container clk",-1);
	vcdp->declBit  (c+36,"v container container_reset",-1);
	vcdp->declBus  (c+83,"v container src",-1,6,0);
	vcdp->declBus  (c+31,"v container u_src",-1,6,0);
	vcdp->declBus  (c+32,"v container u_dst",-1,6,0);
	vcdp->declBus  (c+33,"v container u_e",-1,31,0);
	vcdp->declBus  (c+81,"v container frame_char",-1,5,0);
	vcdp->declBus  (c+34,"v container frame_x",-1,5,0);
	vcdp->declBus  (c+1,"v container frame_y",-1,5,0);
	vcdp->declBit  (c+80,"v container frame_we",-1);
	vcdp->declBit  (c+35,"v container container_done",-1);
	vcdp->declBus  (c+82,"v container test",-1,31,0);
	vcdp->declBus  (c+37,"v container state",-1,4,0);
	vcdp->declBus  (c+38,"v container next_state",-1,4,0);
	vcdp->declBit  (c+39,"v container bellman_done",-1);
	vcdp->declBit  (c+40,"v container cycle_done",-1);
	vcdp->declBit  (c+41,"v container bellman_reset",-1);
	vcdp->declBit  (c+42,"v container cycle_reset",-1);
	vcdp->declBit  (c+43,"v container print_reset",-1);
	vcdp->declBit  (c+44,"v container print_done",-1);
	vcdp->declQuad (c+45,"v container vertmat_q_a",-1,39,0);
	vcdp->declQuad (c+47,"v container vertmat_q_b",-1,39,0);
	vcdp->declBus  (c+2,"v container adjmat_q",-1,31,0);
	vcdp->declQuad (c+3,"v container vertmat_data_a",-1,39,0);
	vcdp->declQuad (c+5,"v container vertmat_data_b",-1,39,0);
	vcdp->declBus  (c+7,"v container vertmat_addr_a",-1,6,0);
	vcdp->declBus  (c+8,"v container vertmat_addr_b",-1,6,0);
	vcdp->declBit  (c+9,"v container vertmat_we_a",-1);
	vcdp->declBit  (c+10,"v container vertmat_we_b",-1);
	vcdp->declBus  (c+11,"v container adjmat_data",-1,31,0);
	vcdp->declBus  (c+12,"v container adjmat_row_addr",-1,6,0);
	vcdp->declBus  (c+13,"v container adjmat_col_addr",-1,6,0);
	vcdp->declBit  (c+14,"v container adjmat_we",-1);
	vcdp->declBus  (c+15,"v container bellman_vertmat_addr_a",-1,6,0);
	vcdp->declBus  (c+16,"v container bellman_vertmat_addr_b",-1,6,0);
	vcdp->declBus  (c+49,"v container bellman_adjmat_row_addr",-1,6,0);
	vcdp->declBus  (c+50,"v container bellman_adjmat_col_addr",-1,6,0);
	vcdp->declQuad (c+17,"v container bellman_vertmat_data_b",-1,39,0);
	vcdp->declBit  (c+19,"v container bellman_vertmat_we_b",-1);
	vcdp->declBus  (c+51,"v container cycle_vertmat_addr_a",-1,6,0);
	vcdp->declBus  (c+20,"v container cycle_vertmat_addr_b",-1,6,0);
	vcdp->declBus  (c+51,"v container cycle_adjmat_row_addr",-1,6,0);
	vcdp->declBus  (c+52,"v container cycle_adjmat_col_addr",-1,6,0);
	vcdp->declQuad (c+21,"v container cycle_vertmat_data_b",-1,39,0);
	vcdp->declBit  (c+23,"v container cycle_vertmat_we_b",-1);
	vcdp->declBus  (c+24,"v container print_vertmat_addr_b",-1,6,0);
	vcdp->declQuad (c+25,"v container print_vertmat_data_b",-1,39,0);
	vcdp->declBit  (c+27,"v container print_vertmat_we_b",-1);
	vcdp->declBit  (c+66,"v container bellman clk",-1);
	vcdp->declBit  (c+41,"v container bellman bellman_reset",-1);
	vcdp->declBus  (c+83,"v container bellman src",-1,6,0);
	vcdp->declQuad (c+45,"v container bellman vertmat_q_a",-1,39,0);
	vcdp->declQuad (c+47,"v container bellman vertmat_q_b",-1,39,0);
	vcdp->declBus  (c+2,"v container bellman adjmat_q",-1,31,0);
	vcdp->declQuad (c+3,"v container bellman vertmat_data_a",-1,39,0);
	vcdp->declQuad (c+17,"v container bellman vertmat_data_b",-1,39,0);
	vcdp->declBus  (c+15,"v container bellman vertmat_addr_a",-1,6,0);
	vcdp->declBus  (c+16,"v container bellman vertmat_addr_b",-1,6,0);
	vcdp->declBit  (c+9,"v container bellman vertmat_we_a",-1);
	vcdp->declBit  (c+19,"v container bellman vertmat_we_b",-1);
	vcdp->declBus  (c+49,"v container bellman adjmat_row_addr",-1,6,0);
	vcdp->declBus  (c+50,"v container bellman adjmat_col_addr",-1,6,0);
	vcdp->declBit  (c+39,"v container bellman bellman_done",-1);
	vcdp->declBus  (c+53,"v container bellman state",-1,3,0);
	vcdp->declBus  (c+49,"v container bellman i",-1,6,0);
	vcdp->declBus  (c+50,"v container bellman j",-1,6,0);
	vcdp->declBus  (c+54,"v container bellman k",-1,6,0);
	vcdp->declBus  (c+55,"v container bellman svw",-1,31,0);
	vcdp->declBus  (c+56,"v container bellman dvw",-1,31,0);
	vcdp->declBus  (c+2,"v container bellman e",-1,31,0);
	vcdp->declBit  (c+66,"v container cycle_detect clk",-1);
	vcdp->declBit  (c+42,"v container cycle_detect cycle_reset",-1);
	vcdp->declQuad (c+45,"v container cycle_detect vertmat_q_a",-1,39,0);
	vcdp->declQuad (c+47,"v container cycle_detect vertmat_q_b",-1,39,0);
	vcdp->declBus  (c+2,"v container cycle_detect adjmat_q",-1,31,0);
	vcdp->declBus  (c+51,"v container cycle_detect vertmat_addr_a",-1,6,0);
	vcdp->declBus  (c+20,"v container cycle_detect vertmat_addr_b",-1,6,0);
	vcdp->declQuad (c+21,"v container cycle_detect vertmat_data_b",-1,39,0);
	vcdp->declBit  (c+23,"v container cycle_detect vertmat_we_b",-1);
	vcdp->declBus  (c+51,"v container cycle_detect adjmat_row_addr",-1,6,0);
	vcdp->declBus  (c+52,"v container cycle_detect adjmat_col_addr",-1,6,0);
	vcdp->declBit  (c+40,"v container cycle_detect cycle_done",-1);
	vcdp->declBus  (c+57,"v container cycle_detect state",-1,3,0);
	vcdp->declBus  (c+51,"v container cycle_detect i",-1,6,0);
	vcdp->declBus  (c+52,"v container cycle_detect j",-1,6,0);
	vcdp->declBus  (c+58,"v container cycle_detect k",-1,6,0);
	vcdp->declBus  (c+59,"v container cycle_detect l",-1,6,0);
	vcdp->declBus  (c+55,"v container cycle_detect svw",-1,31,0);
	vcdp->declBus  (c+56,"v container cycle_detect dvw",-1,31,0);
	vcdp->declBus  (c+2,"v container cycle_detect e",-1,31,0);
	vcdp->declBit  (c+66,"v container print_cycle clk",-1);
	vcdp->declBit  (c+43,"v container print_cycle print_reset",-1);
	vcdp->declQuad (c+47,"v container print_cycle vertmat_q_b",-1,39,0);
	vcdp->declQuad (c+25,"v container print_cycle vertmat_data_b",-1,39,0);
	vcdp->declBus  (c+24,"v container print_cycle vertmat_addr_b",-1,6,0);
	vcdp->declBit  (c+27,"v container print_cycle vertmat_we_b",-1);
	vcdp->declBus  (c+81,"v container print_cycle frame_char",-1,5,0);
	vcdp->declBus  (c+34,"v container print_cycle frame_x",-1,5,0);
	vcdp->declBus  (c+1,"v container print_cycle frame_y",-1,5,0);
	vcdp->declBit  (c+80,"v container print_cycle frame_we",-1);
	vcdp->declBit  (c+44,"v container print_cycle print_done",-1);
	vcdp->declBus  (c+60,"v container print_cycle state",-1,3,0);
	vcdp->declBus  (c+61,"v container print_cycle i",-1,6,0);
	vcdp->declBus  (c+62,"v container print_cycle j",-1,6,0);
	vcdp->declBus  (c+63,"v container print_cycle k",-1,6,0);
	vcdp->declBus  (c+64,"v container print_cycle l",-1,6,0);
	vcdp->declBus  (c+34,"v container print_cycle px",-1,5,0);
	vcdp->declBus  (c+1,"v container print_cycle py",-1,5,0);
	vcdp->declBus  (c+84,"v container vertmat DATA_WIDTH",-1,31,0);
	vcdp->declBus  (c+85,"v container vertmat ADDR_WIDTH",-1,31,0);
	vcdp->declQuad (c+3,"v container vertmat data_a",-1,39,0);
	vcdp->declQuad (c+5,"v container vertmat data_b",-1,39,0);
	vcdp->declBus  (c+7,"v container vertmat addr_a",-1,6,0);
	vcdp->declBus  (c+8,"v container vertmat addr_b",-1,6,0);
	vcdp->declBit  (c+9,"v container vertmat we_a",-1);
	vcdp->declBit  (c+10,"v container vertmat we_b",-1);
	vcdp->declBit  (c+66,"v container vertmat clk",-1);
	vcdp->declQuad (c+45,"v container vertmat q_a",-1,39,0);
	vcdp->declQuad (c+47,"v container vertmat q_b",-1,39,0);
	vcdp->declBus  (c+82,"v container vertmat test",-1,31,0);
	// Tracing: v container vertmat ram // Ignored: Wide memory > --trace-max-array ents at VertMat.sv:16
	vcdp->declBus  (c+86,"v container adjmat DATA_WIDTH",-1,31,0);
	vcdp->declBus  (c+87,"v container adjmat ADDR_WIDTH",-1,31,0);
	vcdp->declBus  (c+11,"v container adjmat data",-1,31,0);
	vcdp->declBus  (c+12,"v container adjmat row_addr",-1,6,0);
	vcdp->declBus  (c+13,"v container adjmat col_addr",-1,6,0);
	vcdp->declBit  (c+14,"v container adjmat we",-1);
	vcdp->declBit  (c+66,"v container adjmat clk",-1);
	vcdp->declBus  (c+2,"v container adjmat q",-1,31,0);
	vcdp->declBus  (c+28,"v container adjmat addr",-1,13,0);
	// Tracing: v container adjmat ram // Ignored: Wide memory > --trace-max-array ents at AdjMat.sv:18
	vcdp->declBus  (c+65,"v container adjmat addr_reg",-1,13,0);
    }
}

void VFOREX::traceFullThis__1(VFOREX__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullQuad (c+5,(vlTOPp->v__DOT__container__DOT__vertmat_data_b),40);
	vcdp->fullBus  (c+7,(vlTOPp->v__DOT__container__DOT__vertmat_addr_a),7);
	vcdp->fullBus  (c+8,(vlTOPp->v__DOT__container__DOT__vertmat_addr_b),7);
	vcdp->fullBit  (c+10,(vlTOPp->v__DOT__container__DOT__vertmat_we_b));
	vcdp->fullBus  (c+11,(vlTOPp->v__DOT__container__DOT__adjmat_data),32);
	vcdp->fullBus  (c+12,(vlTOPp->v__DOT__container__DOT__adjmat_row_addr),7);
	vcdp->fullBus  (c+13,(vlTOPp->v__DOT__container__DOT__adjmat_col_addr),7);
	vcdp->fullBit  (c+14,(vlTOPp->v__DOT__container__DOT__adjmat_we));
	vcdp->fullBus  (c+15,(vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_a),7);
	vcdp->fullBus  (c+16,(vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_b),7);
	vcdp->fullQuad (c+17,(vlTOPp->v__DOT__container__DOT__bellman_vertmat_data_b),40);
	vcdp->fullBit  (c+19,(vlTOPp->v__DOT__container__DOT__bellman_vertmat_we_b));
	vcdp->fullBus  (c+20,(vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b),7);
	vcdp->fullQuad (c+21,(vlTOPp->v__DOT__container__DOT__cycle_vertmat_data_b),40);
	vcdp->fullBit  (c+23,(vlTOPp->v__DOT__container__DOT__cycle_vertmat_we_b));
	vcdp->fullBus  (c+24,(vlTOPp->v__DOT__container__DOT__print_vertmat_addr_b),7);
	vcdp->fullQuad (c+25,(vlTOPp->v__DOT__container__DOT__print_vertmat_data_b),40);
	vcdp->fullBit  (c+27,(vlTOPp->v__DOT__container__DOT__print_vertmat_we_b));
	vcdp->fullBus  (c+1,(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__py),6);
	vcdp->fullQuad (c+3,(vlTOPp->v__DOT__container__DOT__vertmat_data_a),40);
	vcdp->fullBit  (c+9,(vlTOPp->v__DOT__container__DOT__vertmat_we_a));
	vcdp->fullBus  (c+2,(vlTOPp->v__DOT__container__DOT__adjmat_q),32);
	vcdp->fullBus  (c+28,(vlTOPp->v__DOT__container__DOT__adjmat__DOT__addr),14);
	vcdp->fullBus  (c+29,(vlTOPp->v__DOT__state),4);
	vcdp->fullBus  (c+30,(vlTOPp->v__DOT__next_state),4);
	vcdp->fullBus  (c+31,(vlTOPp->v__DOT__u_src),7);
	vcdp->fullBus  (c+32,(vlTOPp->v__DOT__u_dst),7);
	vcdp->fullBus  (c+33,(vlTOPp->v__DOT__u_e),32);
	vcdp->fullBit  (c+35,(vlTOPp->v__DOT__container_done));
	vcdp->fullBit  (c+36,(vlTOPp->v__DOT__container_reset));
	vcdp->fullBus  (c+37,(vlTOPp->v__DOT__container__DOT__state),5);
	vcdp->fullBus  (c+38,(vlTOPp->v__DOT__container__DOT__next_state),5);
	vcdp->fullBit  (c+39,(vlTOPp->v__DOT__container__DOT__bellman_done));
	vcdp->fullBit  (c+40,(vlTOPp->v__DOT__container__DOT__cycle_done));
	vcdp->fullBit  (c+41,(vlTOPp->v__DOT__container__DOT__bellman_reset));
	vcdp->fullBit  (c+42,(vlTOPp->v__DOT__container__DOT__cycle_reset));
	vcdp->fullBit  (c+43,(vlTOPp->v__DOT__container__DOT__print_reset));
	vcdp->fullBit  (c+44,(vlTOPp->v__DOT__container__DOT__print_done));
	vcdp->fullBus  (c+53,(vlTOPp->v__DOT__container__DOT__bellman__DOT__state),4);
	vcdp->fullBus  (c+49,(vlTOPp->v__DOT__container__DOT__bellman__DOT__i),7);
	vcdp->fullBus  (c+50,(vlTOPp->v__DOT__container__DOT__bellman__DOT__j),7);
	vcdp->fullBus  (c+54,(vlTOPp->v__DOT__container__DOT__bellman__DOT__k),7);
	vcdp->fullBus  (c+55,((IData)(vlTOPp->v__DOT__container__DOT__vertmat_q_a)),32);
	vcdp->fullBus  (c+56,((IData)(vlTOPp->v__DOT__container__DOT__vertmat_q_b)),32);
	vcdp->fullBus  (c+57,(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state),4);
	vcdp->fullBus  (c+51,(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__i),7);
	vcdp->fullBus  (c+52,(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j),7);
	vcdp->fullBus  (c+58,(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__k),7);
	vcdp->fullBus  (c+59,(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__l),7);
	vcdp->fullBus  (c+60,(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state),4);
	vcdp->fullBus  (c+61,(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__i),7);
	vcdp->fullBus  (c+62,(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__j),7);
	vcdp->fullBus  (c+63,(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__k),7);
	vcdp->fullBus  (c+64,(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l),7);
	vcdp->fullBus  (c+34,(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__px),6);
	vcdp->fullQuad (c+45,(vlTOPp->v__DOT__container__DOT__vertmat_q_a),40);
	vcdp->fullQuad (c+47,(vlTOPp->v__DOT__container__DOT__vertmat_q_b),40);
	vcdp->fullBus  (c+65,(vlTOPp->v__DOT__container__DOT__adjmat__DOT__addr_reg),14);
	vcdp->fullBit  (c+67,(vlTOPp->reset));
	vcdp->fullBus  (c+68,(vlTOPp->writedata),32);
	vcdp->fullBit  (c+69,(vlTOPp->write));
	vcdp->fullBit  (c+70,(vlTOPp->chipselect));
	vcdp->fullBus  (c+71,(vlTOPp->address),3);
	vcdp->fullBus  (c+72,(vlTOPp->VGA_R),8);
	vcdp->fullBus  (c+73,(vlTOPp->VGA_G),8);
	vcdp->fullBus  (c+74,(vlTOPp->VGA_B),8);
	vcdp->fullBit  (c+75,(vlTOPp->VGA_CLK));
	vcdp->fullBit  (c+76,(vlTOPp->VGA_HS));
	vcdp->fullBit  (c+77,(vlTOPp->VGA_VS));
	vcdp->fullBit  (c+78,(vlTOPp->VGA_BLANK_n));
	vcdp->fullBit  (c+79,(vlTOPp->VGA_SYNC_n));
	vcdp->fullBus  (c+81,(vlTOPp->frame_char),6);
	vcdp->fullBit  (c+80,(vlTOPp->frame_we));
	vcdp->fullBus  (c+82,(vlTOPp->test),32);
	vcdp->fullBit  (c+66,(vlTOPp->clk));
	vcdp->fullBus  (c+83,(0U),7);
	vcdp->fullBus  (c+84,(0x27U),32);
	vcdp->fullBus  (c+85,(6U),32);
	vcdp->fullBus  (c+86,(0x1fU),32);
	vcdp->fullBus  (c+87,(0xdU),32);
    }
}
