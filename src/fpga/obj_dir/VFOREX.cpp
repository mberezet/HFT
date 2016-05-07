// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFOREX.h for the primary calling header

#include "VFOREX.h"            // For This
#include "VFOREX__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VFOREX) {
    VFOREX__Syms* __restrict vlSymsp = __VlSymsp = new VFOREX__Syms(this, name());
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    writedata = VL_RAND_RESET_I(32);
    write = VL_RAND_RESET_I(1);
    chipselect = VL_RAND_RESET_I(1);
    address = VL_RAND_RESET_I(3);
    VGA_R = VL_RAND_RESET_I(8);
    VGA_G = VL_RAND_RESET_I(8);
    VGA_B = VL_RAND_RESET_I(8);
    VGA_CLK = VL_RAND_RESET_I(1);
    VGA_HS = VL_RAND_RESET_I(1);
    VGA_VS = VL_RAND_RESET_I(1);
    VGA_BLANK_n = VL_RAND_RESET_I(1);
    VGA_SYNC_n = VL_RAND_RESET_I(1);
    frame_we = VL_RAND_RESET_I(1);
    frame_char = VL_RAND_RESET_I(6);
    test = VL_RAND_RESET_I(32);
    v__DOT__state = VL_RAND_RESET_I(4);
    v__DOT__next_state = VL_RAND_RESET_I(4);
    v__DOT__u_src = VL_RAND_RESET_I(7);
    v__DOT__u_dst = VL_RAND_RESET_I(7);
    v__DOT__u_e = VL_RAND_RESET_I(32);
    v__DOT__container_done = VL_RAND_RESET_I(1);
    v__DOT__container_reset = VL_RAND_RESET_I(1);
    v__DOT__container__DOT__state = VL_RAND_RESET_I(5);
    v__DOT__container__DOT__next_state = VL_RAND_RESET_I(5);
    v__DOT__container__DOT__bellman_done = VL_RAND_RESET_I(1);
    v__DOT__container__DOT__cycle_done = VL_RAND_RESET_I(1);
    v__DOT__container__DOT__bellman_reset = VL_RAND_RESET_I(1);
    v__DOT__container__DOT__cycle_reset = VL_RAND_RESET_I(1);
    v__DOT__container__DOT__print_reset = VL_RAND_RESET_I(1);
    v__DOT__container__DOT__print_done = VL_RAND_RESET_I(1);
    v__DOT__container__DOT__vertmat_q_a = VL_RAND_RESET_Q(40);
    v__DOT__container__DOT__vertmat_q_b = VL_RAND_RESET_Q(40);
    v__DOT__container__DOT__adjmat_q = VL_RAND_RESET_I(32);
    v__DOT__container__DOT__vertmat_data_a = VL_RAND_RESET_Q(40);
    v__DOT__container__DOT__vertmat_data_b = VL_RAND_RESET_Q(40);
    v__DOT__container__DOT__vertmat_addr_a = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__vertmat_addr_b = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__vertmat_we_a = VL_RAND_RESET_I(1);
    v__DOT__container__DOT__vertmat_we_b = VL_RAND_RESET_I(1);
    v__DOT__container__DOT__adjmat_data = VL_RAND_RESET_I(32);
    v__DOT__container__DOT__adjmat_row_addr = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__adjmat_col_addr = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__adjmat_we = VL_RAND_RESET_I(1);
    v__DOT__container__DOT__bellman_vertmat_addr_a = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__bellman_vertmat_addr_b = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__bellman_vertmat_data_b = VL_RAND_RESET_Q(40);
    v__DOT__container__DOT__bellman_vertmat_we_b = VL_RAND_RESET_I(1);
    v__DOT__container__DOT__cycle_vertmat_addr_b = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__cycle_vertmat_data_b = VL_RAND_RESET_Q(40);
    v__DOT__container__DOT__cycle_vertmat_we_b = VL_RAND_RESET_I(1);
    v__DOT__container__DOT__print_vertmat_addr_b = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__print_vertmat_data_b = VL_RAND_RESET_Q(40);
    v__DOT__container__DOT__print_vertmat_we_b = VL_RAND_RESET_I(1);
    v__DOT__container__DOT__bellman__DOT__state = VL_RAND_RESET_I(4);
    v__DOT__container__DOT__bellman__DOT__i = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__bellman__DOT__j = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__bellman__DOT__k = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__cycle_detect__DOT__state = VL_RAND_RESET_I(4);
    v__DOT__container__DOT__cycle_detect__DOT__i = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__cycle_detect__DOT__j = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__cycle_detect__DOT__k = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__cycle_detect__DOT__l = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__print_cycle__DOT__state = VL_RAND_RESET_I(4);
    v__DOT__container__DOT__print_cycle__DOT__i = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__print_cycle__DOT__j = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__print_cycle__DOT__k = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__print_cycle__DOT__l = VL_RAND_RESET_I(7);
    v__DOT__container__DOT__print_cycle__DOT__px = VL_RAND_RESET_I(6);
    v__DOT__container__DOT__print_cycle__DOT__py = VL_RAND_RESET_I(6);
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
	    v__DOT__container__DOT__vertmat__DOT__ram[__Vi0] = VL_RAND_RESET_Q(40);
    }}
    v__DOT__container__DOT__adjmat__DOT__addr = VL_RAND_RESET_I(14);
    { int __Vi0=0; for (; __Vi0<8193; ++__Vi0) {
	    v__DOT__container__DOT__adjmat__DOT__ram[__Vi0] = VL_RAND_RESET_I(32);
    }}
    v__DOT__container__DOT__adjmat__DOT__addr_reg = VL_RAND_RESET_I(14);
    v__DOT__container__DOT__adjmat__DOT____Vlvbound1 = VL_RAND_RESET_I(32);
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void VFOREX::__Vconfigure(VFOREX__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VFOREX::~VFOREX() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VFOREX::eval() {
    VFOREX__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VFOREX::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void VFOREX::_eval_initial_loop(VFOREX__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

void VFOREX::_sequent__TOP__1(VFOREX__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFOREX::_sequent__TOP__1\n"); );
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__v__DOT__state,3,0);
    VL_SIG8(__Vdly__v__DOT__next_state,3,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__state,4,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__print_reset,0,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__cycle_reset,0,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__next_state,4,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__bellman_reset,0,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__bellman__DOT__i,6,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__bellman__DOT__j,6,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__bellman__DOT__k,6,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__bellman__DOT__state,3,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__cycle_detect__DOT__i,6,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__cycle_detect__DOT__j,6,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__cycle_detect__DOT__k,6,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__cycle_detect__DOT__state,3,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__cycle_detect__DOT__l,6,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__print_cycle__DOT__j,6,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__print_cycle__DOT__k,6,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__print_cycle__DOT__l,6,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__print_cycle__DOT__state,3,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__print_cycle__DOT__py,5,0);
    VL_SIG8(__Vdly__v__DOT__container__DOT__print_cycle__DOT__px,5,0);
    VL_SIG8(__Vdlyvdim0__v__DOT__container__DOT__vertmat__DOT__ram__v0,5,0);
    VL_SIG8(__Vdlyvset__v__DOT__container__DOT__vertmat__DOT__ram__v0,0,0);
    VL_SIG8(__Vdlyvdim0__v__DOT__container__DOT__vertmat__DOT__ram__v1,5,0);
    VL_SIG8(__Vdlyvset__v__DOT__container__DOT__vertmat__DOT__ram__v1,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__container__DOT__adjmat__DOT__ram__v0,0,0);
    //char	__VpadToAlign31[1];
    VL_SIG16(__Vdlyvdim0__v__DOT__container__DOT__adjmat__DOT__ram__v0,13,0);
    //char	__VpadToAlign34[2];
    VL_SIG(__Vdlyvval__v__DOT__container__DOT__adjmat__DOT__ram__v0,31,0);
    VL_SIG64(__Vdlyvval__v__DOT__container__DOT__vertmat__DOT__ram__v0,39,0);
    VL_SIG64(__Vdlyvval__v__DOT__container__DOT__vertmat__DOT__ram__v1,39,0);
    // Body
    __Vdly__v__DOT__state = vlTOPp->v__DOT__state;
    __Vdly__v__DOT__next_state = vlTOPp->v__DOT__next_state;
    __Vdlyvset__v__DOT__container__DOT__vertmat__DOT__ram__v1 = 0U;
    __Vdlyvset__v__DOT__container__DOT__vertmat__DOT__ram__v0 = 0U;
    __Vdlyvset__v__DOT__container__DOT__adjmat__DOT__ram__v0 = 0U;
    __Vdly__v__DOT__container__DOT__bellman__DOT__k 
	= vlTOPp->v__DOT__container__DOT__bellman__DOT__k;
    __Vdly__v__DOT__container__DOT__bellman__DOT__state 
	= vlTOPp->v__DOT__container__DOT__bellman__DOT__state;
    __Vdly__v__DOT__container__DOT__bellman__DOT__i 
	= vlTOPp->v__DOT__container__DOT__bellman__DOT__i;
    __Vdly__v__DOT__container__DOT__bellman__DOT__j 
	= vlTOPp->v__DOT__container__DOT__bellman__DOT__j;
    __Vdly__v__DOT__container__DOT__print_cycle__DOT__px 
	= vlTOPp->v__DOT__container__DOT__print_cycle__DOT__px;
    __Vdly__v__DOT__container__DOT__print_cycle__DOT__py 
	= vlTOPp->v__DOT__container__DOT__print_cycle__DOT__py;
    __Vdly__v__DOT__container__DOT__print_cycle__DOT__j 
	= vlTOPp->v__DOT__container__DOT__print_cycle__DOT__j;
    __Vdly__v__DOT__container__DOT__print_cycle__DOT__k 
	= vlTOPp->v__DOT__container__DOT__print_cycle__DOT__k;
    __Vdly__v__DOT__container__DOT__print_cycle__DOT__l 
	= vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l;
    __Vdly__v__DOT__container__DOT__print_cycle__DOT__state 
	= vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state;
    __Vdly__v__DOT__container__DOT__cycle_detect__DOT__k 
	= vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__k;
    __Vdly__v__DOT__container__DOT__cycle_detect__DOT__i 
	= vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__i;
    __Vdly__v__DOT__container__DOT__cycle_detect__DOT__state 
	= vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state;
    __Vdly__v__DOT__container__DOT__cycle_detect__DOT__l 
	= vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__l;
    __Vdly__v__DOT__container__DOT__cycle_detect__DOT__j 
	= vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j;
    __Vdly__v__DOT__container__DOT__print_reset = vlTOPp->v__DOT__container__DOT__print_reset;
    __Vdly__v__DOT__container__DOT__cycle_reset = vlTOPp->v__DOT__container__DOT__cycle_reset;
    __Vdly__v__DOT__container__DOT__next_state = vlTOPp->v__DOT__container__DOT__next_state;
    __Vdly__v__DOT__container__DOT__bellman_reset = vlTOPp->v__DOT__container__DOT__bellman_reset;
    __Vdly__v__DOT__container__DOT__state = vlTOPp->v__DOT__container__DOT__state;
    // ALWAYS at AdjMat.sv:29
    vlTOPp->v__DOT__container__DOT__adjmat__DOT__addr_reg 
	= vlTOPp->v__DOT__container__DOT__adjmat__DOT__addr;
    // ALWAYS at AdjMat.sv:26
    if (vlTOPp->v__DOT__container__DOT__adjmat_we) {
	vlTOPp->v__DOT__container__DOT__adjmat__DOT____Vlvbound1 
	    = vlTOPp->v__DOT__container__DOT__adjmat_data;
	if ((0x2000U >= (IData)(vlTOPp->v__DOT__container__DOT__adjmat__DOT__addr))) {
	    __Vdlyvval__v__DOT__container__DOT__adjmat__DOT__ram__v0 
		= vlTOPp->v__DOT__container__DOT__adjmat__DOT____Vlvbound1;
	    __Vdlyvset__v__DOT__container__DOT__adjmat__DOT__ram__v0 = 1U;
	    __Vdlyvdim0__v__DOT__container__DOT__adjmat__DOT__ram__v0 
		= vlTOPp->v__DOT__container__DOT__adjmat__DOT__addr;
	}
    }
    // ALWAYS at Container.sv:68
    if (vlTOPp->v__DOT__container_reset) {
	__Vdly__v__DOT__container__DOT__state = 0U;
	vlTOPp->v__DOT__container_done = 0U;
    } else {
	if ((0x10U & (IData)(vlTOPp->v__DOT__container__DOT__state))) {
	    __Vdly__v__DOT__container__DOT__state = 5U;
	} else {
	    if ((8U & (IData)(vlTOPp->v__DOT__container__DOT__state))) {
		__Vdly__v__DOT__container__DOT__state = 5U;
	    } else {
		if ((4U & (IData)(vlTOPp->v__DOT__container__DOT__state))) {
		    if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__state))) {
			__Vdly__v__DOT__container__DOT__state 
			    = ((1U & (IData)(vlTOPp->v__DOT__container__DOT__state))
			        ? 5U : (IData)(vlTOPp->v__DOT__container__DOT__next_state));
		    } else {
			if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__state))) {
			    vlTOPp->v__DOT__container_done = 1U;
			} else {
			    __Vdly__v__DOT__container__DOT__print_reset = 0U;
			    if (vlTOPp->v__DOT__container__DOT__print_done) {
				__Vdly__v__DOT__container__DOT__state = 5U;
			    }
			}
		    }
		} else {
		    if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__state))) {
			if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__state))) {
			    __Vdly__v__DOT__container__DOT__cycle_reset = 0U;
			    if (vlTOPp->v__DOT__container__DOT__cycle_done) {
				__Vdly__v__DOT__container__DOT__print_reset = 1U;
				__Vdly__v__DOT__container__DOT__next_state = 4U;
				__Vdly__v__DOT__container__DOT__state = 6U;
			    }
			} else {
			    __Vdly__v__DOT__container__DOT__bellman_reset = 0U;
			    if (vlTOPp->v__DOT__container__DOT__bellman_done) {
				__Vdly__v__DOT__container__DOT__cycle_reset = 1U;
				__Vdly__v__DOT__container__DOT__state = 6U;
				__Vdly__v__DOT__container__DOT__next_state = 3U;
			    }
			}
		    } else {
			if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__state))) {
			    __Vdly__v__DOT__container__DOT__bellman_reset = 1U;
			    __Vdly__v__DOT__container__DOT__state = 6U;
			    __Vdly__v__DOT__container__DOT__next_state = 2U;
			} else {
			    __Vdly__v__DOT__container__DOT__state = 1U;
			}
		    }
		}
	    }
	}
    }
    // ALWAYSPOST at AdjMat.sv:27
    if (__Vdlyvset__v__DOT__container__DOT__adjmat__DOT__ram__v0) {
	vlTOPp->v__DOT__container__DOT__adjmat__DOT__ram[(IData)(__Vdlyvdim0__v__DOT__container__DOT__adjmat__DOT__ram__v0)] 
	    = __Vdlyvval__v__DOT__container__DOT__adjmat__DOT__ram__v0;
    }
    vlTOPp->v__DOT__container__DOT__next_state = __Vdly__v__DOT__container__DOT__next_state;
    vlTOPp->v__DOT__container__DOT__state = __Vdly__v__DOT__container__DOT__state;
    // ALWAYS at FOREX.sv:38
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
	if (((IData)(vlTOPp->chipselect) & (IData)(vlTOPp->write))) {
	    if ((0U == (IData)(vlTOPp->address))) {
		vlTOPp->v__DOT__u_src = (0x7fU & (vlTOPp->writedata 
						  >> 7U));
		vlTOPp->v__DOT__u_dst = (0x7fU & vlTOPp->writedata);
	    } else {
		if ((1U == (IData)(vlTOPp->address))) {
		    vlTOPp->v__DOT__u_e = vlTOPp->writedata;
		    __Vdly__v__DOT__state = 0U;
		}
	    }
	}
    }
    if ((0U == (IData)(vlTOPp->v__DOT__state))) {
	vlTOPp->v__DOT__container_reset = 1U;
	__Vdly__v__DOT__state = 2U;
	__Vdly__v__DOT__next_state = 1U;
    } else {
	if ((1U == (IData)(vlTOPp->v__DOT__state))) {
	    vlTOPp->v__DOT__container_reset = 0U;
	} else {
	    if ((2U == (IData)(vlTOPp->v__DOT__state))) {
		__Vdly__v__DOT__state = vlTOPp->v__DOT__next_state;
	    }
	}
    }
    // ALWAYS at Bellman.sv:71
    if (vlTOPp->v__DOT__container__DOT__bellman_reset) {
	__Vdly__v__DOT__container__DOT__bellman__DOT__i = 0U;
	__Vdly__v__DOT__container__DOT__bellman__DOT__j = 0U;
	__Vdly__v__DOT__container__DOT__bellman__DOT__k = 0U;
	vlTOPp->v__DOT__container__DOT__bellman_done = 0U;
	__Vdly__v__DOT__container__DOT__bellman__DOT__state = 0U;
    } else {
	if ((8U & (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__state))) {
	    __Vdly__v__DOT__container__DOT__bellman__DOT__state = 4U;
	} else {
	    if ((4U & (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__state))) {
		if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__state))) {
		    __Vdly__v__DOT__container__DOT__bellman__DOT__state = 4U;
		} else {
		    if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__state))) {
			__Vdly__v__DOT__container__DOT__bellman__DOT__state = 4U;
		    } else {
			vlTOPp->v__DOT__container__DOT__bellman_done = 1U;
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__state))) {
		    __Vdly__v__DOT__container__DOT__bellman__DOT__state 
			= ((1U & (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__state))
			    ? 1U : 3U);
		} else {
		    if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__state))) {
			if ((((7U == ((IData)(1U) + (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__j))) 
			      & (7U == ((IData)(1U) 
					+ (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__i)))) 
			     & (7U == ((IData)(1U) 
				       + (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__k))))) {
			    __Vdly__v__DOT__container__DOT__bellman__DOT__state = 4U;
			} else {
			    if (((7U == ((IData)(1U) 
					 + (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__j))) 
				 & (7U == ((IData)(1U) 
					   + (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__i))))) {
				__Vdly__v__DOT__container__DOT__bellman__DOT__k 
				    = (0x7fU & ((IData)(1U) 
						+ (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__k)));
				__Vdly__v__DOT__container__DOT__bellman__DOT__i = 0U;
				__Vdly__v__DOT__container__DOT__bellman__DOT__j = 0U;
				__Vdly__v__DOT__container__DOT__bellman__DOT__state = 2U;
			    } else {
				if ((7U == ((IData)(1U) 
					    + (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__j)))) {
				    __Vdly__v__DOT__container__DOT__bellman__DOT__i 
					= (0x7fU & 
					   ((IData)(1U) 
					    + (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__i)));
				    __Vdly__v__DOT__container__DOT__bellman__DOT__j = 0U;
				    __Vdly__v__DOT__container__DOT__bellman__DOT__state = 2U;
				} else {
				    __Vdly__v__DOT__container__DOT__bellman__DOT__j 
					= (0x7fU & 
					   ((IData)(1U) 
					    + (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__j)));
				    __Vdly__v__DOT__container__DOT__bellman__DOT__state = 2U;
				}
			    }
			}
		    } else {
			if ((7U == ((IData)(1U) + (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__k)))) {
			    __Vdly__v__DOT__container__DOT__bellman__DOT__k = 0U;
			    __Vdly__v__DOT__container__DOT__bellman__DOT__state = 3U;
			} else {
			    if ((0U == (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__k))) {
				__Vdly__v__DOT__container__DOT__bellman__DOT__k 
				    = (0x7fU & ((IData)(1U) 
						+ (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__k)));
				__Vdly__v__DOT__container__DOT__bellman__DOT__state = 0U;
			    } else {
				__Vdly__v__DOT__container__DOT__bellman__DOT__k 
				    = (0x7fU & ((IData)(1U) 
						+ (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__k)));
				__Vdly__v__DOT__container__DOT__bellman__DOT__state = 0U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at PrintCycle.sv:76
    if (vlTOPp->v__DOT__container__DOT__print_reset) {
	vlTOPp->v__DOT__container__DOT__print_cycle__DOT__i = 0U;
	__Vdly__v__DOT__container__DOT__print_cycle__DOT__j = 0U;
	__Vdly__v__DOT__container__DOT__print_cycle__DOT__k = 0x7fU;
	__Vdly__v__DOT__container__DOT__print_cycle__DOT__l = 0U;
	vlTOPp->v__DOT__container__DOT__print_done = 0U;
	__Vdly__v__DOT__container__DOT__print_cycle__DOT__state = 0U;
    } else {
	if ((8U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
	    if ((4U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
		__Vdly__v__DOT__container__DOT__print_cycle__DOT__state = 9U;
	    } else {
		if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
		    __Vdly__v__DOT__container__DOT__print_cycle__DOT__state = 9U;
		} else {
		    if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
			vlTOPp->v__DOT__container__DOT__print_done = 1U;
		    } else {
			__Vdly__v__DOT__container__DOT__print_cycle__DOT__state = 9U;
		    }
		}
	    }
	} else {
	    if ((4U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
		if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
		    if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
			__Vdly__v__DOT__container__DOT__print_cycle__DOT__state 
			    = (((IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l) 
				== (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__k))
			        ? 0U : 4U);
		    } else {
			if (((0x28U == ((IData)(1U) 
					+ (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__px))) 
			     & (0x1eU == ((IData)(1U) 
					  + (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__py))))) {
			    __Vdly__v__DOT__container__DOT__print_cycle__DOT__py = 0U;
			    __Vdly__v__DOT__container__DOT__print_cycle__DOT__px = 0U;
			} else {
			    if ((0x28U == ((IData)(1U) 
					   + (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__px)))) {
				__Vdly__v__DOT__container__DOT__print_cycle__DOT__py 
				    = (0x3fU & ((IData)(1U) 
						+ (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__py)));
				__Vdly__v__DOT__container__DOT__print_cycle__DOT__px = 0U;
			    } else {
				__Vdly__v__DOT__container__DOT__print_cycle__DOT__px 
				    = (0x3fU & ((IData)(1U) 
						+ (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__px)));
			    }
			}
			__Vdly__v__DOT__container__DOT__print_cycle__DOT__state = 7U;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
			if (((0x28U == ((IData)(1U) 
					+ (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__px))) 
			     & (0x1eU == ((IData)(1U) 
					  + (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__py))))) {
			    __Vdly__v__DOT__container__DOT__print_cycle__DOT__py = 0U;
			    __Vdly__v__DOT__container__DOT__print_cycle__DOT__px = 0U;
			} else {
			    if ((0x28U == ((IData)(1U) 
					   + (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__px)))) {
				__Vdly__v__DOT__container__DOT__print_cycle__DOT__py 
				    = (0x3fU & ((IData)(1U) 
						+ (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__py)));
				__Vdly__v__DOT__container__DOT__print_cycle__DOT__px = 0U;
			    } else {
				__Vdly__v__DOT__container__DOT__print_cycle__DOT__px 
				    = (0x3fU & ((IData)(1U) 
						+ (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__px)));
			    }
			}
			__Vdly__v__DOT__container__DOT__print_cycle__DOT__state = 6U;
		    } else {
			if (((0x28U == ((IData)(1U) 
					+ (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__px))) 
			     & (0x1eU == ((IData)(1U) 
					  + (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__py))))) {
			    __Vdly__v__DOT__container__DOT__print_cycle__DOT__py = 0U;
			    __Vdly__v__DOT__container__DOT__print_cycle__DOT__px = 0U;
			} else {
			    if ((0x28U == ((IData)(1U) 
					   + (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__px)))) {
				__Vdly__v__DOT__container__DOT__print_cycle__DOT__py 
				    = (0x3fU & ((IData)(1U) 
						+ (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__py)));
				__Vdly__v__DOT__container__DOT__print_cycle__DOT__px = 0U;
			    } else {
				__Vdly__v__DOT__container__DOT__print_cycle__DOT__px 
				    = (0x3fU & ((IData)(1U) 
						+ (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__px)));
			    }
			}
			__Vdly__v__DOT__container__DOT__print_cycle__DOT__l 
			    = (0x7fU & (IData)((vlTOPp->v__DOT__container__DOT__vertmat_q_b 
						>> 0x20U)));
			__Vdly__v__DOT__container__DOT__print_cycle__DOT__state = 5U;
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
		    if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
			if ((0x1eU == ((IData)(1U) 
				       + (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__py)))) {
			    __Vdly__v__DOT__container__DOT__print_cycle__DOT__py = 0U;
			    __Vdly__v__DOT__container__DOT__print_cycle__DOT__px = 0U;
			} else {
			    __Vdly__v__DOT__container__DOT__print_cycle__DOT__py 
				= (0x3fU & ((IData)(1U) 
					    + (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__py)));
			    __Vdly__v__DOT__container__DOT__print_cycle__DOT__px = 0U;
			}
			__Vdly__v__DOT__container__DOT__print_cycle__DOT__state = 4U;
		    } else {
			__Vdly__v__DOT__container__DOT__print_cycle__DOT__state 
			    = ((1U & (IData)((vlTOPp->v__DOT__container__DOT__vertmat_q_b 
					      >> 0x27U)))
			        ? 3U : 0U);
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
			__Vdly__v__DOT__container__DOT__print_cycle__DOT__k 
			    = vlTOPp->v__DOT__container__DOT__print_cycle__DOT__j;
			__Vdly__v__DOT__container__DOT__print_cycle__DOT__state = 2U;
		    } else {
			__Vdly__v__DOT__container__DOT__print_cycle__DOT__k = 0x7fU;
			if ((7U == ((IData)(1U) + (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__j)))) {
			    __Vdly__v__DOT__container__DOT__print_cycle__DOT__state = 9U;
			} else {
			    __Vdly__v__DOT__container__DOT__print_cycle__DOT__j 
				= (0x7fU & ((IData)(1U) 
					    + (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__j)));
			    __Vdly__v__DOT__container__DOT__print_cycle__DOT__state = 1U;
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at CycleDetect.sv:60
    if (vlTOPp->v__DOT__container__DOT__cycle_reset) {
	__Vdly__v__DOT__container__DOT__cycle_detect__DOT__i = 0U;
	__Vdly__v__DOT__container__DOT__cycle_detect__DOT__j = 0U;
	__Vdly__v__DOT__container__DOT__cycle_detect__DOT__k = 0x7fU;
	vlTOPp->v__DOT__container__DOT__cycle_done = 0U;
	__Vdly__v__DOT__container__DOT__cycle_detect__DOT__state = 0U;
    } else {
	if ((8U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
	    __Vdly__v__DOT__container__DOT__cycle_detect__DOT__state = 6U;
	} else {
	    if ((4U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
		if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
		    if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
			__Vdly__v__DOT__container__DOT__cycle_detect__DOT__state = 6U;
		    } else {
			vlTOPp->v__DOT__container__DOT__cycle_done = 1U;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
			__Vdly__v__DOT__container__DOT__cycle_detect__DOT__state = 0U;
		    } else {
			__Vdly__v__DOT__container__DOT__cycle_detect__DOT__l 
			    = (0x7fU & (IData)((vlTOPp->v__DOT__container__DOT__vertmat_q_b 
						>> 0x20U)));
			__Vdly__v__DOT__container__DOT__cycle_detect__DOT__state = 3U;
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
		    if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
			__Vdly__v__DOT__container__DOT__cycle_detect__DOT__state 
			    = (((IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__l) 
				== (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__k))
			        ? 5U : 4U);
		    } else {
			if (((0U != vlTOPp->v__DOT__container__DOT__adjmat_q) 
			     & VL_LTS_III(1,32,32, 
					  ((IData)(vlTOPp->v__DOT__container__DOT__vertmat_q_a) 
					   + vlTOPp->v__DOT__container__DOT__adjmat_q), (IData)(vlTOPp->v__DOT__container__DOT__vertmat_q_b)))) {
			    __Vdly__v__DOT__container__DOT__cycle_detect__DOT__l 
				= (0x7fU & (IData)(
						   (vlTOPp->v__DOT__container__DOT__vertmat_q_b 
						    >> 0x20U)));
			    __Vdly__v__DOT__container__DOT__cycle_detect__DOT__state = 3U;
			} else {
			    __Vdly__v__DOT__container__DOT__cycle_detect__DOT__state = 0U;
			}
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
			__Vdly__v__DOT__container__DOT__cycle_detect__DOT__k 
			    = vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j;
			__Vdly__v__DOT__container__DOT__cycle_detect__DOT__state = 2U;
		    } else {
			__Vdly__v__DOT__container__DOT__cycle_detect__DOT__k = 0x7fU;
			if (((7U == ((IData)(1U) + (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j))) 
			     & (7U == ((IData)(1U) 
				       + (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__i))))) {
			    __Vdly__v__DOT__container__DOT__cycle_detect__DOT__state = 6U;
			} else {
			    if ((7U == ((IData)(1U) 
					+ (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j)))) {
				__Vdly__v__DOT__container__DOT__cycle_detect__DOT__i 
				    = (0x7fU & ((IData)(1U) 
						+ (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__i)));
				__Vdly__v__DOT__container__DOT__cycle_detect__DOT__j = 0U;
				__Vdly__v__DOT__container__DOT__cycle_detect__DOT__state = 1U;
			    } else {
				__Vdly__v__DOT__container__DOT__cycle_detect__DOT__j 
				    = (0x7fU & ((IData)(1U) 
						+ (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j)));
				__Vdly__v__DOT__container__DOT__cycle_detect__DOT__state = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    vlTOPp->v__DOT__state = __Vdly__v__DOT__state;
    vlTOPp->v__DOT__next_state = __Vdly__v__DOT__next_state;
    vlTOPp->v__DOT__container__DOT__bellman_reset = __Vdly__v__DOT__container__DOT__bellman_reset;
    vlTOPp->v__DOT__container__DOT__bellman__DOT__state 
	= __Vdly__v__DOT__container__DOT__bellman__DOT__state;
    vlTOPp->v__DOT__container__DOT__bellman__DOT__k 
	= __Vdly__v__DOT__container__DOT__bellman__DOT__k;
    vlTOPp->v__DOT__container__DOT__bellman__DOT__j 
	= __Vdly__v__DOT__container__DOT__bellman__DOT__j;
    vlTOPp->v__DOT__container__DOT__bellman__DOT__i 
	= __Vdly__v__DOT__container__DOT__bellman__DOT__i;
    vlTOPp->v__DOT__container__DOT__print_reset = __Vdly__v__DOT__container__DOT__print_reset;
    vlTOPp->v__DOT__container__DOT__print_cycle__DOT__px 
	= __Vdly__v__DOT__container__DOT__print_cycle__DOT__px;
    vlTOPp->v__DOT__container__DOT__print_cycle__DOT__py 
	= __Vdly__v__DOT__container__DOT__print_cycle__DOT__py;
    vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state 
	= __Vdly__v__DOT__container__DOT__print_cycle__DOT__state;
    vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l 
	= __Vdly__v__DOT__container__DOT__print_cycle__DOT__l;
    vlTOPp->v__DOT__container__DOT__print_cycle__DOT__k 
	= __Vdly__v__DOT__container__DOT__print_cycle__DOT__k;
    vlTOPp->v__DOT__container__DOT__print_cycle__DOT__j 
	= __Vdly__v__DOT__container__DOT__print_cycle__DOT__j;
    vlTOPp->v__DOT__container__DOT__cycle_reset = __Vdly__v__DOT__container__DOT__cycle_reset;
    vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__k 
	= __Vdly__v__DOT__container__DOT__cycle_detect__DOT__k;
    vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__i 
	= __Vdly__v__DOT__container__DOT__cycle_detect__DOT__i;
    vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state 
	= __Vdly__v__DOT__container__DOT__cycle_detect__DOT__state;
    vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__l 
	= __Vdly__v__DOT__container__DOT__cycle_detect__DOT__l;
    vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j 
	= __Vdly__v__DOT__container__DOT__cycle_detect__DOT__j;
    vlTOPp->v__DOT__container__DOT__adjmat_q = ((0x2000U 
						 >= (IData)(vlTOPp->v__DOT__container__DOT__adjmat__DOT__addr_reg))
						 ? 
						vlTOPp->v__DOT__container__DOT__adjmat__DOT__ram
						[(IData)(vlTOPp->v__DOT__container__DOT__adjmat__DOT__addr_reg)]
						 : 0U);
    // ALWAYS at VertMat.sv:19
    if (vlTOPp->v__DOT__container__DOT__vertmat_we_a) {
	__Vdlyvval__v__DOT__container__DOT__vertmat__DOT__ram__v0 
	    = vlTOPp->v__DOT__container__DOT__vertmat_data_a;
	__Vdlyvset__v__DOT__container__DOT__vertmat__DOT__ram__v0 = 1U;
	__Vdlyvdim0__v__DOT__container__DOT__vertmat__DOT__ram__v0 
	    = (0x3fU & (IData)(vlTOPp->v__DOT__container__DOT__vertmat_addr_a));
	vlTOPp->v__DOT__container__DOT__vertmat_q_a 
	    = vlTOPp->v__DOT__container__DOT__vertmat_data_a;
    } else {
	vlTOPp->v__DOT__container__DOT__vertmat_q_a 
	    = vlTOPp->v__DOT__container__DOT__vertmat__DOT__ram
	    [(0x3fU & (IData)(vlTOPp->v__DOT__container__DOT__vertmat_addr_a))];
    }
    // ALWAYS at VertMat.sv:33
    if (vlTOPp->v__DOT__container__DOT__vertmat_we_b) {
	__Vdlyvval__v__DOT__container__DOT__vertmat__DOT__ram__v1 
	    = vlTOPp->v__DOT__container__DOT__vertmat_data_b;
	__Vdlyvset__v__DOT__container__DOT__vertmat__DOT__ram__v1 = 1U;
	__Vdlyvdim0__v__DOT__container__DOT__vertmat__DOT__ram__v1 
	    = (0x3fU & (IData)(vlTOPp->v__DOT__container__DOT__vertmat_addr_b));
	vlTOPp->v__DOT__container__DOT__vertmat_q_b 
	    = vlTOPp->v__DOT__container__DOT__vertmat_data_b;
    } else {
	vlTOPp->v__DOT__container__DOT__vertmat_q_b 
	    = vlTOPp->v__DOT__container__DOT__vertmat__DOT__ram
	    [(0x3fU & (IData)(vlTOPp->v__DOT__container__DOT__vertmat_addr_b))];
    }
    // ALWAYSPOST at VertMat.sv:23
    if (__Vdlyvset__v__DOT__container__DOT__vertmat__DOT__ram__v0) {
	vlTOPp->v__DOT__container__DOT__vertmat__DOT__ram[(IData)(__Vdlyvdim0__v__DOT__container__DOT__vertmat__DOT__ram__v0)] 
	    = __Vdlyvval__v__DOT__container__DOT__vertmat__DOT__ram__v0;
    }
    if (__Vdlyvset__v__DOT__container__DOT__vertmat__DOT__ram__v1) {
	vlTOPp->v__DOT__container__DOT__vertmat__DOT__ram[(IData)(__Vdlyvdim0__v__DOT__container__DOT__vertmat__DOT__ram__v1)] 
	    = __Vdlyvval__v__DOT__container__DOT__vertmat__DOT__ram__v1;
    }
    vlTOPp->test = (0x7fU & (IData)((vlTOPp->v__DOT__container__DOT__vertmat__DOT__ram
				     [2U] >> 0x20U)));
    // ALWAYS at CycleDetect.sv:30
    vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b = 0U;
    vlTOPp->v__DOT__container__DOT__cycle_vertmat_we_b = 0U;
    vlTOPp->v__DOT__container__DOT__cycle_vertmat_data_b = VL_ULL(0);
    if ((8U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
	vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b 
	    = vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j;
    } else {
	if ((4U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
	    if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
		vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b 
		    = vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j;
	    } else {
		if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
		    vlTOPp->v__DOT__container__DOT__cycle_vertmat_we_b = 0U;
		    vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j;
		} else {
		    vlTOPp->v__DOT__container__DOT__cycle_vertmat_we_b = 1U;
		    vlTOPp->v__DOT__container__DOT__cycle_vertmat_data_b 
			= (VL_ULL(0x8000000000) | (VL_ULL(0x7fffffffff) 
						   & vlTOPp->v__DOT__container__DOT__vertmat_q_b));
		    vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__l;
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
		if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
		    vlTOPp->v__DOT__container__DOT__cycle_vertmat_we_b = 0U;
		    vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__l;
		} else {
		    vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j;
		}
	    } else {
		vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b 
		    = vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j;
	    }
	}
    }
    // ALWAYS at PrintCycle.sv:23
    vlTOPp->frame_we = 0U;
    vlTOPp->frame_char = 0U;
    vlTOPp->v__DOT__container__DOT__print_vertmat_addr_b 
	= vlTOPp->v__DOT__container__DOT__print_cycle__DOT__j;
    vlTOPp->v__DOT__container__DOT__print_vertmat_data_b = VL_ULL(0);
    vlTOPp->v__DOT__container__DOT__print_vertmat_we_b = 0U;
    if ((1U & (~ ((IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state) 
		  >> 3U)))) {
	if ((4U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
	    if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
		if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
		    vlTOPp->v__DOT__container__DOT__print_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l;
		} else {
		    vlTOPp->v__DOT__container__DOT__print_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l;
		    if (((IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l) 
			 != (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__k))) {
			vlTOPp->frame_we = 1U;
			vlTOPp->frame_char = 0x25U;
		    }
		}
	    } else {
		if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
		    vlTOPp->v__DOT__container__DOT__print_vertmat_we_b = 0U;
		    vlTOPp->v__DOT__container__DOT__print_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l;
		    vlTOPp->frame_we = 1U;
		    vlTOPp->frame_char = (0x3fU & (
						   (0xaU 
						    > (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
						    ? (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l)
						    : 
						   ((0x3cU 
						     <= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
						     ? 
						    ((IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l) 
						     - (IData)(0x3cU))
						     : 
						    ((0x32U 
						      <= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
						      ? 
						     ((IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l) 
						      - (IData)(0x32U))
						      : 
						     ((0x28U 
						       <= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
						       ? 
						      ((IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l) 
						       - (IData)(0x28U))
						       : 
						      ((0x1eU 
							<= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
						        ? 
						       ((IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l) 
							- (IData)(0x1eU))
						        : 
						       ((0x14U 
							 <= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
							 ? 
							((IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l) 
							 - (IData)(0x14U))
							 : 
							((IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l) 
							 - (IData)(0xaU)))))))));
		} else {
		    vlTOPp->v__DOT__container__DOT__print_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l;
		    vlTOPp->v__DOT__container__DOT__print_vertmat_data_b 
			= (VL_ULL(0x7fffffffff) & vlTOPp->v__DOT__container__DOT__vertmat_q_b);
		    vlTOPp->v__DOT__container__DOT__print_vertmat_we_b = 1U;
		    vlTOPp->frame_we = 1U;
		    vlTOPp->frame_char = ((0xaU > (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
					   ? 0xaU : 
					  ((0x3cU <= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
					    ? 6U : 
					   ((0x32U 
					     <= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
					     ? 5U : 
					    ((0x28U 
					      <= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
					      ? 4U : 
					     ((0x1eU 
					       <= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
					       ? 3U
					       : ((0x14U 
						   <= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
						   ? 2U
						   : 1U))))));
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
		vlTOPp->v__DOT__container__DOT__print_vertmat_addr_b 
		    = vlTOPp->v__DOT__container__DOT__print_cycle__DOT__j;
	    }
	}
    }
}

void VFOREX::_initial__TOP__2(VFOREX__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFOREX::_initial__TOP__2\n"); );
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at PrintCycle.sv:19
    vlTOPp->v__DOT__container__DOT__print_cycle__DOT__py = 0x3fU;
}

void VFOREX::_settle__TOP__3(VFOREX__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFOREX::_settle__TOP__3\n"); );
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__container__DOT__adjmat_q = ((0x2000U 
						 >= (IData)(vlTOPp->v__DOT__container__DOT__adjmat__DOT__addr_reg))
						 ? 
						vlTOPp->v__DOT__container__DOT__adjmat__DOT__ram
						[(IData)(vlTOPp->v__DOT__container__DOT__adjmat__DOT__addr_reg)]
						 : 0U);
    vlTOPp->test = (0x7fU & (IData)((vlTOPp->v__DOT__container__DOT__vertmat__DOT__ram
				     [2U] >> 0x20U)));
    // ALWAYS at CycleDetect.sv:30
    vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b = 0U;
    vlTOPp->v__DOT__container__DOT__cycle_vertmat_we_b = 0U;
    vlTOPp->v__DOT__container__DOT__cycle_vertmat_data_b = VL_ULL(0);
    if ((8U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
	vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b 
	    = vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j;
    } else {
	if ((4U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
	    if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
		vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b 
		    = vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j;
	    } else {
		if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
		    vlTOPp->v__DOT__container__DOT__cycle_vertmat_we_b = 0U;
		    vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j;
		} else {
		    vlTOPp->v__DOT__container__DOT__cycle_vertmat_we_b = 1U;
		    vlTOPp->v__DOT__container__DOT__cycle_vertmat_data_b 
			= (VL_ULL(0x8000000000) | (VL_ULL(0x7fffffffff) 
						   & vlTOPp->v__DOT__container__DOT__vertmat_q_b));
		    vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__l;
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
		if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__state))) {
		    vlTOPp->v__DOT__container__DOT__cycle_vertmat_we_b = 0U;
		    vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__l;
		} else {
		    vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j;
		}
	    } else {
		vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b 
		    = vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j;
	    }
	}
    }
    // ALWAYS at PrintCycle.sv:23
    vlTOPp->frame_we = 0U;
    vlTOPp->frame_char = 0U;
    vlTOPp->v__DOT__container__DOT__print_vertmat_addr_b 
	= vlTOPp->v__DOT__container__DOT__print_cycle__DOT__j;
    vlTOPp->v__DOT__container__DOT__print_vertmat_data_b = VL_ULL(0);
    vlTOPp->v__DOT__container__DOT__print_vertmat_we_b = 0U;
    if ((1U & (~ ((IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state) 
		  >> 3U)))) {
	if ((4U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
	    if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
		if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
		    vlTOPp->v__DOT__container__DOT__print_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l;
		} else {
		    vlTOPp->v__DOT__container__DOT__print_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l;
		    if (((IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l) 
			 != (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__k))) {
			vlTOPp->frame_we = 1U;
			vlTOPp->frame_char = 0x25U;
		    }
		}
	    } else {
		if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
		    vlTOPp->v__DOT__container__DOT__print_vertmat_we_b = 0U;
		    vlTOPp->v__DOT__container__DOT__print_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l;
		    vlTOPp->frame_we = 1U;
		    vlTOPp->frame_char = (0x3fU & (
						   (0xaU 
						    > (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
						    ? (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l)
						    : 
						   ((0x3cU 
						     <= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
						     ? 
						    ((IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l) 
						     - (IData)(0x3cU))
						     : 
						    ((0x32U 
						      <= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
						      ? 
						     ((IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l) 
						      - (IData)(0x32U))
						      : 
						     ((0x28U 
						       <= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
						       ? 
						      ((IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l) 
						       - (IData)(0x28U))
						       : 
						      ((0x1eU 
							<= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
						        ? 
						       ((IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l) 
							- (IData)(0x1eU))
						        : 
						       ((0x14U 
							 <= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
							 ? 
							((IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l) 
							 - (IData)(0x14U))
							 : 
							((IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l) 
							 - (IData)(0xaU)))))))));
		} else {
		    vlTOPp->v__DOT__container__DOT__print_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l;
		    vlTOPp->v__DOT__container__DOT__print_vertmat_data_b 
			= (VL_ULL(0x7fffffffff) & vlTOPp->v__DOT__container__DOT__vertmat_q_b);
		    vlTOPp->v__DOT__container__DOT__print_vertmat_we_b = 1U;
		    vlTOPp->frame_we = 1U;
		    vlTOPp->frame_char = ((0xaU > (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
					   ? 0xaU : 
					  ((0x3cU <= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
					    ? 6U : 
					   ((0x32U 
					     <= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
					     ? 5U : 
					    ((0x28U 
					      <= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
					      ? 4U : 
					     ((0x1eU 
					       <= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
					       ? 3U
					       : ((0x14U 
						   <= (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__l))
						   ? 2U
						   : 1U))))));
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__print_cycle__DOT__state))) {
		vlTOPp->v__DOT__container__DOT__print_vertmat_addr_b 
		    = vlTOPp->v__DOT__container__DOT__print_cycle__DOT__j;
	    }
	}
    }
    // ALWAYS at Bellman.sv:33
    vlTOPp->v__DOT__container__DOT__vertmat_we_a = 0U;
    vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_a = 0U;
    vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_b = 0U;
    vlTOPp->v__DOT__container__DOT__vertmat_data_a = VL_ULL(0);
    vlTOPp->v__DOT__container__DOT__bellman_vertmat_we_b = 0U;
    vlTOPp->v__DOT__container__DOT__bellman_vertmat_data_b = VL_ULL(0);
    if ((1U & (~ ((IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__state) 
		  >> 3U)))) {
	if ((1U & (~ ((IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__state) 
		      >> 2U)))) {
	    if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__state))) {
		if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__state))) {
		    vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_a 
			= vlTOPp->v__DOT__container__DOT__bellman__DOT__i;
		    vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__bellman__DOT__j;
		    if (((0U != vlTOPp->v__DOT__container__DOT__adjmat_q) 
			 & VL_LTS_III(1,32,32, ((IData)(vlTOPp->v__DOT__container__DOT__vertmat_q_a) 
						+ vlTOPp->v__DOT__container__DOT__adjmat_q), (IData)(vlTOPp->v__DOT__container__DOT__vertmat_q_b)))) {
			vlTOPp->v__DOT__container__DOT__bellman_vertmat_we_b = 1U;
			vlTOPp->v__DOT__container__DOT__bellman_vertmat_data_b 
			    = (((QData)((IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__i)) 
				<< 0x20U) | (QData)((IData)(
							    ((IData)(vlTOPp->v__DOT__container__DOT__vertmat_q_a) 
							     + vlTOPp->v__DOT__container__DOT__adjmat_q))));
		    }
		} else {
		    vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_a 
			= vlTOPp->v__DOT__container__DOT__bellman__DOT__i;
		    vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__bellman__DOT__j;
		}
	    } else {
		if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__state))) {
		    vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_a 
			= vlTOPp->v__DOT__container__DOT__bellman__DOT__i;
		    vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__bellman__DOT__j;
		} else {
		    vlTOPp->v__DOT__container__DOT__vertmat_we_a = 1U;
		    vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_a 
			= vlTOPp->v__DOT__container__DOT__bellman__DOT__k;
		    if ((7U != ((IData)(1U) + (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__k)))) {
			vlTOPp->v__DOT__container__DOT__vertmat_data_a 
			    = ((0U == (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__k))
			        ? (VL_ULL(0xff00000000) 
				   & vlTOPp->v__DOT__container__DOT__vertmat_data_a)
			        : (VL_ULL(0x777fffff) 
				   | (VL_ULL(0xff00000000) 
				      & vlTOPp->v__DOT__container__DOT__vertmat_data_a)));
		    }
		}
	    }
	}
    }
}

void VFOREX::_sequent__TOP__4(VFOREX__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFOREX::_sequent__TOP__4\n"); );
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at Bellman.sv:33
    vlTOPp->v__DOT__container__DOT__vertmat_we_a = 0U;
    vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_a = 0U;
    vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_b = 0U;
    vlTOPp->v__DOT__container__DOT__vertmat_data_a = VL_ULL(0);
    vlTOPp->v__DOT__container__DOT__bellman_vertmat_we_b = 0U;
    vlTOPp->v__DOT__container__DOT__bellman_vertmat_data_b = VL_ULL(0);
    if ((1U & (~ ((IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__state) 
		  >> 3U)))) {
	if ((1U & (~ ((IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__state) 
		      >> 2U)))) {
	    if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__state))) {
		if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__state))) {
		    vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_a 
			= vlTOPp->v__DOT__container__DOT__bellman__DOT__i;
		    vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__bellman__DOT__j;
		    if (((0U != vlTOPp->v__DOT__container__DOT__adjmat_q) 
			 & VL_LTS_III(1,32,32, ((IData)(vlTOPp->v__DOT__container__DOT__vertmat_q_a) 
						+ vlTOPp->v__DOT__container__DOT__adjmat_q), (IData)(vlTOPp->v__DOT__container__DOT__vertmat_q_b)))) {
			vlTOPp->v__DOT__container__DOT__bellman_vertmat_we_b = 1U;
			vlTOPp->v__DOT__container__DOT__bellman_vertmat_data_b 
			    = (((QData)((IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__i)) 
				<< 0x20U) | (QData)((IData)(
							    ((IData)(vlTOPp->v__DOT__container__DOT__vertmat_q_a) 
							     + vlTOPp->v__DOT__container__DOT__adjmat_q))));
		    }
		} else {
		    vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_a 
			= vlTOPp->v__DOT__container__DOT__bellman__DOT__i;
		    vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__bellman__DOT__j;
		}
	    } else {
		if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__state))) {
		    vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_a 
			= vlTOPp->v__DOT__container__DOT__bellman__DOT__i;
		    vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_b 
			= vlTOPp->v__DOT__container__DOT__bellman__DOT__j;
		} else {
		    vlTOPp->v__DOT__container__DOT__vertmat_we_a = 1U;
		    vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_a 
			= vlTOPp->v__DOT__container__DOT__bellman__DOT__k;
		    if ((7U != ((IData)(1U) + (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__k)))) {
			vlTOPp->v__DOT__container__DOT__vertmat_data_a 
			    = ((0U == (IData)(vlTOPp->v__DOT__container__DOT__bellman__DOT__k))
			        ? (VL_ULL(0xff00000000) 
				   & vlTOPp->v__DOT__container__DOT__vertmat_data_a)
			        : (VL_ULL(0x777fffff) 
				   | (VL_ULL(0xff00000000) 
				      & vlTOPp->v__DOT__container__DOT__vertmat_data_a)));
		    }
		}
	    }
	}
    }
    // ALWAYS at Container.sv:105
    vlTOPp->v__DOT__container__DOT__adjmat_we = 0U;
    vlTOPp->v__DOT__container__DOT__adjmat_row_addr = 0U;
    vlTOPp->v__DOT__container__DOT__adjmat_col_addr = 0U;
    vlTOPp->v__DOT__container__DOT__adjmat_data = 0U;
    vlTOPp->v__DOT__container__DOT__vertmat_addr_a = 0U;
    vlTOPp->v__DOT__container__DOT__vertmat_addr_b = 0U;
    vlTOPp->v__DOT__container__DOT__vertmat_data_b = VL_ULL(0);
    vlTOPp->v__DOT__container__DOT__vertmat_we_b = 0U;
    if ((1U & (~ ((IData)(vlTOPp->v__DOT__container__DOT__state) 
		  >> 4U)))) {
	if ((1U & (~ ((IData)(vlTOPp->v__DOT__container__DOT__state) 
		      >> 3U)))) {
	    if ((4U & (IData)(vlTOPp->v__DOT__container__DOT__state))) {
		if ((1U & (~ ((IData)(vlTOPp->v__DOT__container__DOT__state) 
			      >> 1U)))) {
		    if ((1U & (~ (IData)(vlTOPp->v__DOT__container__DOT__state)))) {
			vlTOPp->v__DOT__container__DOT__vertmat_addr_b 
			    = vlTOPp->v__DOT__container__DOT__print_vertmat_addr_b;
			vlTOPp->v__DOT__container__DOT__vertmat_data_b 
			    = vlTOPp->v__DOT__container__DOT__print_vertmat_data_b;
			vlTOPp->v__DOT__container__DOT__vertmat_we_b 
			    = vlTOPp->v__DOT__container__DOT__print_vertmat_we_b;
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__state))) {
		    if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__state))) {
			vlTOPp->v__DOT__container__DOT__adjmat_row_addr 
			    = vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__i;
			vlTOPp->v__DOT__container__DOT__adjmat_col_addr 
			    = vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j;
			vlTOPp->v__DOT__container__DOT__vertmat_addr_a 
			    = vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__i;
			vlTOPp->v__DOT__container__DOT__vertmat_addr_b 
			    = vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b;
			vlTOPp->v__DOT__container__DOT__vertmat_data_b 
			    = vlTOPp->v__DOT__container__DOT__cycle_vertmat_data_b;
			vlTOPp->v__DOT__container__DOT__vertmat_we_b 
			    = vlTOPp->v__DOT__container__DOT__cycle_vertmat_we_b;
		    } else {
			vlTOPp->v__DOT__container__DOT__adjmat_we = 0U;
			vlTOPp->v__DOT__container__DOT__adjmat_row_addr 
			    = vlTOPp->v__DOT__container__DOT__bellman__DOT__i;
			vlTOPp->v__DOT__container__DOT__adjmat_col_addr 
			    = vlTOPp->v__DOT__container__DOT__bellman__DOT__j;
			vlTOPp->v__DOT__container__DOT__vertmat_addr_a 
			    = vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_a;
			vlTOPp->v__DOT__container__DOT__vertmat_addr_b 
			    = vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_b;
			vlTOPp->v__DOT__container__DOT__vertmat_data_b 
			    = vlTOPp->v__DOT__container__DOT__bellman_vertmat_data_b;
			vlTOPp->v__DOT__container__DOT__vertmat_we_b 
			    = vlTOPp->v__DOT__container__DOT__bellman_vertmat_we_b;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__state))) {
			vlTOPp->v__DOT__container__DOT__adjmat_we = 1U;
			vlTOPp->v__DOT__container__DOT__adjmat_data = 0U;
			vlTOPp->v__DOT__container__DOT__adjmat_row_addr 
			    = vlTOPp->v__DOT__u_dst;
			vlTOPp->v__DOT__container__DOT__adjmat_col_addr 
			    = vlTOPp->v__DOT__u_src;
		    } else {
			vlTOPp->v__DOT__container__DOT__adjmat_we = 1U;
			vlTOPp->v__DOT__container__DOT__adjmat_data 
			    = vlTOPp->v__DOT__u_e;
			vlTOPp->v__DOT__container__DOT__adjmat_row_addr 
			    = vlTOPp->v__DOT__u_src;
			vlTOPp->v__DOT__container__DOT__adjmat_col_addr 
			    = vlTOPp->v__DOT__u_dst;
		    }
		}
	    }
	}
    }
}

void VFOREX::_settle__TOP__5(VFOREX__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFOREX::_settle__TOP__5\n"); );
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at Container.sv:105
    vlTOPp->v__DOT__container__DOT__adjmat_we = 0U;
    vlTOPp->v__DOT__container__DOT__adjmat_row_addr = 0U;
    vlTOPp->v__DOT__container__DOT__adjmat_col_addr = 0U;
    vlTOPp->v__DOT__container__DOT__adjmat_data = 0U;
    vlTOPp->v__DOT__container__DOT__vertmat_addr_a = 0U;
    vlTOPp->v__DOT__container__DOT__vertmat_addr_b = 0U;
    vlTOPp->v__DOT__container__DOT__vertmat_data_b = VL_ULL(0);
    vlTOPp->v__DOT__container__DOT__vertmat_we_b = 0U;
    if ((1U & (~ ((IData)(vlTOPp->v__DOT__container__DOT__state) 
		  >> 4U)))) {
	if ((1U & (~ ((IData)(vlTOPp->v__DOT__container__DOT__state) 
		      >> 3U)))) {
	    if ((4U & (IData)(vlTOPp->v__DOT__container__DOT__state))) {
		if ((1U & (~ ((IData)(vlTOPp->v__DOT__container__DOT__state) 
			      >> 1U)))) {
		    if ((1U & (~ (IData)(vlTOPp->v__DOT__container__DOT__state)))) {
			vlTOPp->v__DOT__container__DOT__vertmat_addr_b 
			    = vlTOPp->v__DOT__container__DOT__print_vertmat_addr_b;
			vlTOPp->v__DOT__container__DOT__vertmat_data_b 
			    = vlTOPp->v__DOT__container__DOT__print_vertmat_data_b;
			vlTOPp->v__DOT__container__DOT__vertmat_we_b 
			    = vlTOPp->v__DOT__container__DOT__print_vertmat_we_b;
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->v__DOT__container__DOT__state))) {
		    if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__state))) {
			vlTOPp->v__DOT__container__DOT__adjmat_row_addr 
			    = vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__i;
			vlTOPp->v__DOT__container__DOT__adjmat_col_addr 
			    = vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__j;
			vlTOPp->v__DOT__container__DOT__vertmat_addr_a 
			    = vlTOPp->v__DOT__container__DOT__cycle_detect__DOT__i;
			vlTOPp->v__DOT__container__DOT__vertmat_addr_b 
			    = vlTOPp->v__DOT__container__DOT__cycle_vertmat_addr_b;
			vlTOPp->v__DOT__container__DOT__vertmat_data_b 
			    = vlTOPp->v__DOT__container__DOT__cycle_vertmat_data_b;
			vlTOPp->v__DOT__container__DOT__vertmat_we_b 
			    = vlTOPp->v__DOT__container__DOT__cycle_vertmat_we_b;
		    } else {
			vlTOPp->v__DOT__container__DOT__adjmat_we = 0U;
			vlTOPp->v__DOT__container__DOT__adjmat_row_addr 
			    = vlTOPp->v__DOT__container__DOT__bellman__DOT__i;
			vlTOPp->v__DOT__container__DOT__adjmat_col_addr 
			    = vlTOPp->v__DOT__container__DOT__bellman__DOT__j;
			vlTOPp->v__DOT__container__DOT__vertmat_addr_a 
			    = vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_a;
			vlTOPp->v__DOT__container__DOT__vertmat_addr_b 
			    = vlTOPp->v__DOT__container__DOT__bellman_vertmat_addr_b;
			vlTOPp->v__DOT__container__DOT__vertmat_data_b 
			    = vlTOPp->v__DOT__container__DOT__bellman_vertmat_data_b;
			vlTOPp->v__DOT__container__DOT__vertmat_we_b 
			    = vlTOPp->v__DOT__container__DOT__bellman_vertmat_we_b;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->v__DOT__container__DOT__state))) {
			vlTOPp->v__DOT__container__DOT__adjmat_we = 1U;
			vlTOPp->v__DOT__container__DOT__adjmat_data = 0U;
			vlTOPp->v__DOT__container__DOT__adjmat_row_addr 
			    = vlTOPp->v__DOT__u_dst;
			vlTOPp->v__DOT__container__DOT__adjmat_col_addr 
			    = vlTOPp->v__DOT__u_src;
		    } else {
			vlTOPp->v__DOT__container__DOT__adjmat_we = 1U;
			vlTOPp->v__DOT__container__DOT__adjmat_data 
			    = vlTOPp->v__DOT__u_e;
			vlTOPp->v__DOT__container__DOT__adjmat_row_addr 
			    = vlTOPp->v__DOT__u_src;
			vlTOPp->v__DOT__container__DOT__adjmat_col_addr 
			    = vlTOPp->v__DOT__u_dst;
		    }
		}
	    }
	}
    }
    vlTOPp->v__DOT__container__DOT__adjmat__DOT__addr 
	= (0x3fffU & (((IData)(7U) * (IData)(vlTOPp->v__DOT__container__DOT__adjmat_row_addr)) 
		      + (IData)(vlTOPp->v__DOT__container__DOT__adjmat_col_addr)));
}

void VFOREX::_sequent__TOP__6(VFOREX__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFOREX::_sequent__TOP__6\n"); );
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__container__DOT__adjmat__DOT__addr 
	= (0x3fffU & (((IData)(7U) * (IData)(vlTOPp->v__DOT__container__DOT__adjmat_row_addr)) 
		      + (IData)(vlTOPp->v__DOT__container__DOT__adjmat_col_addr)));
}

void VFOREX::_eval(VFOREX__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFOREX::_eval\n"); );
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
	vlTOPp->_sequent__TOP__4(vlSymsp);
	vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void VFOREX::_eval_initial(VFOREX__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFOREX::_eval_initial\n"); );
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

void VFOREX::final() {
    VL_DEBUG_IF(VL_PRINTF("    VFOREX::final\n"); );
    // Variables
    VFOREX__Syms* __restrict vlSymsp = this->__VlSymsp;
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VFOREX::_eval_settle(VFOREX__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFOREX::_eval_settle\n"); );
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlTOPp->_settle__TOP__5(vlSymsp);
}

QData VFOREX::_change_request(VFOREX__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFOREX::_change_request\n"); );
    VFOREX* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}
