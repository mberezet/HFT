// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VFOREX__Syms.h"


//======================

void VFOREX::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VFOREX* t=(VFOREX*)userthis;
    VFOREX__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void VFOREX::traceChgThis(VFOREX__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VFOREX::traceChgThis__2(VFOREX__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgQuad (c+5,(vlTOPp->v__DOT__container__DOT__vertmat_data_b),40);
	vcdp->chgBus  (c+7,(vlTOPp->v__DOT__container__DOT__vertmat_addr_a),7);
	vcdp->chgBus  (c+8,(vlTOPp->v__DOT__container__DOT__vertmat_addr_b),7);
	vcdp->chgBit  (c+10,(vlTOPp->v__DOT__container__DOT__vertmat_we_b));
	vcdp->chgBus  (c+11,(vlTOPp->v__DOT__container__DOT__adjmat_data),32);
	vcdp->chgBus  (c+12,(vlTOPp->v__DOT__container__DOT__adjmat_row_addr),7);
	vcdp->chgBus  (c+13,(vlTOPp->v__DOT__container__DOT__adjmat_col_addr),7);
	vcdp->chgBit  (c+14,(vlTOPp->v__DOT__container__DOT__adjmat_we));
	vcdp->chgBus  (c+15,(vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_a),7);
	vcdp->chgBus  (c+16,(vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_b),7);
	vcdp->chgQuad (c+17,(vlTOPp->v__DOT__container__DOT__bellman_vertmat_data_b),40);
	vcdp->chgBit  (c+19,(vlTOPp->v__DOT__container__DOT__bellman_vertmat_we_b));
	vcdp->chgBus  (c+20,(vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b),7);
	vcdp->chgQuad (c+21,(vlTOPp->v__DOT__container__DOT__cycle_vertmat_data_b),40);
	vcdp->chgBit  (c+23,(vlTOPp->v__DOT__container__DOT__cycle_vertmat_we_b));
	vcdp->chgBus  (c+24,(vlTOPp->v__DOT__container__DOT__print_vertmat_addr_b),7);
	vcdp->chgQuad (c+25,(vlTOPp->v__DOT__container__DOT__print_vertmat_data_b),40);
	vcdp->chgBit  (c+27,(vlTOPp->v__DOT__container__DOT__print_vertmat_we_b));
	vcdp->chgBus  (c+1,(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__py),6);
	vcdp->chgQuad (c+3,(vlTOPp->v__DOT__container__DOT__vertmat_data_a),40);
	vcdp->chgBit  (c+9,(vlTOPp->v__DOT__container__DOT__vertmat_we_a));
	vcdp->chgBus  (c+2,(vlTOPp->v__DOT__container__DOT__adjmat_q),32);
	vcdp->chgBus  (c+28,(vlTOPp->v__DOT__container__DOT__adjmat__DOT__addr),14);
    }
}

void VFOREX::traceChgThis__3(VFOREX__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+29,(vlTOPp->v__DOT__state),4);
	vcdp->chgBus  (c+30,(vlTOPp->v__DOT__next_state),4);
	vcdp->chgBus  (c+31,(vlTOPp->v__DOT__u_src),7);
	vcdp->chgBus  (c+32,(vlTOPp->v__DOT__u_dst),7);
	vcdp->chgBus  (c+33,(vlTOPp->v__DOT__u_e),32);
	vcdp->chgBit  (c+35,(vlTOPp->v__DOT__container_done));
	vcdp->chgBit  (c+36,(vlTOPp->v__DOT__container_reset));
	vcdp->chgBus  (c+37,(vlTOPp->v__DOT__container__DOT__state),5);
	vcdp->chgBus  (c+38,(vlTOPp->v__DOT__container__DOT__next_state),5);
	vcdp->chgBit  (c+39,(vlTOPp->v__DOT__container__DOT__bellman_done));
	vcdp->chgBit  (c+40,(vlTOPp->v__DOT__container__DOT__cycle_done));
	vcdp->chgBit  (c+41,(vlTOPp->v__DOT__container__DOT__bellman_reset));
	vcdp->chgBit  (c+42,(vlTOPp->v__DOT__container__DOT__cycle_reset));
	vcdp->chgBit  (c+43,(vlTOPp->v__DOT__container__DOT__print_reset));
	vcdp->chgBit  (c+44,(vlTOPp->v__DOT__container__DOT__print_done));
	vcdp->chgBus  (c+53,(vlTOPp->v__DOT__container__DOT__bellman__DOT__state),4);
	vcdp->chgBus  (c+49,(vlTOPp->v__DOT__container__DOT__bellman__DOT__i),7);
	vcdp->chgBus  (c+50,(vlTOPp->v__DOT__container__DOT__bellman__DOT__j),7);
	vcdp->chgBus  (c+54,(vlTOPp->v__DOT__container__DOT__bellman__DOT__k),7);
	vcdp->chgBus  (c+55,((IData)(vlTOPp->v__DOT__container__DOT__vertmat_q_a)),32);
	vcdp->chgBus  (c+56,((IData)(vlTOPp->v__DOT__container__DOT__vertmat_q_b)),32);
	vcdp->chgBus  (c+57,(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state),4);
	vcdp->chgBus  (c+51,(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__i),7);
	vcdp->chgBus  (c+52,(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j),7);
	vcdp->chgBus  (c+58,(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__k),7);
	vcdp->chgBus  (c+59,(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__l),7);
	vcdp->chgBus  (c+60,(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state),4);
	vcdp->chgBus  (c+61,(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__i),7);
	vcdp->chgBus  (c+62,(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__j),7);
	vcdp->chgBus  (c+63,(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__k),7);
	vcdp->chgBus  (c+64,(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l),7);
	vcdp->chgBus  (c+34,(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__px),6);
	vcdp->chgQuad (c+45,(vlTOPp->v__DOT__container__DOT__vertmat_q_a),40);
	vcdp->chgQuad (c+47,(vlTOPp->v__DOT__container__DOT__vertmat_q_b),40);
	vcdp->chgBus  (c+65,(vlTOPp->v__DOT__container__DOT__adjmat__DOT__addr_reg),14);
    }
}

void VFOREX::traceChgThis__4(VFOREX__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+67,(vlTOPp->reset));
	vcdp->chgBus  (c+68,(vlTOPp->writedata),32);
	vcdp->chgBit  (c+69,(vlTOPp->write));
	vcdp->chgBit  (c+70,(vlTOPp->chipselect));
	vcdp->chgBus  (c+71,(vlTOPp->address),3);
	vcdp->chgBus  (c+72,(vlTOPp->VGA_R),8);
	vcdp->chgBus  (c+73,(vlTOPp->VGA_G),8);
	vcdp->chgBus  (c+74,(vlTOPp->VGA_B),8);
	vcdp->chgBit  (c+75,(vlTOPp->VGA_CLK));
	vcdp->chgBit  (c+76,(vlTOPp->VGA_HS));
	vcdp->chgBit  (c+77,(vlTOPp->VGA_VS));
	vcdp->chgBit  (c+78,(vlTOPp->VGA_BLANK_n));
	vcdp->chgBit  (c+79,(vlTOPp->VGA_SYNC_n));
	vcdp->chgBus  (c+81,(vlTOPp->frame_char),6);
	vcdp->chgBit  (c+80,(vlTOPp->frame_we));
	vcdp->chgBus  (c+82,(vlTOPp->test),32);
	vcdp->chgBit  (c+66,(vlTOPp->clk));
    }
}
