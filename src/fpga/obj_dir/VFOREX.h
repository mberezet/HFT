// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VFOREX_H_
#define _VFOREX_H_

#include "verilated.h"
class VFOREX__Syms;
class VerilatedVcd;

//----------

VL_MODULE(VFOREX) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(write,0,0);
    VL_IN8(chipselect,0,0);
    VL_IN8(address,2,0);
    VL_OUT8(VGA_R,7,0);
    VL_OUT8(VGA_G,7,0);
    VL_OUT8(VGA_B,7,0);
    VL_OUT8(VGA_CLK,0,0);
    VL_OUT8(VGA_HS,0,0);
    VL_OUT8(VGA_VS,0,0);
    VL_OUT8(VGA_BLANK_n,0,0);
    VL_OUT8(VGA_SYNC_n,0,0);
    VL_OUT8(frame_we,0,0);
    VL_OUT8(frame_char,5,0);
    //char	__VpadToAlign15[1];
    VL_IN(writedata,31,0);
    VL_OUT(test,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(v__DOT__state,3,0);
    VL_SIG8(v__DOT__next_state,3,0);
    VL_SIG8(v__DOT__u_src,6,0);
    VL_SIG8(v__DOT__u_dst,6,0);
    VL_SIG8(v__DOT__container_done,0,0);
    VL_SIG8(v__DOT__container_reset,0,0);
    VL_SIG8(v__DOT__container__DOT__state,4,0);
    VL_SIG8(v__DOT__container__DOT__next_state,4,0);
    VL_SIG8(v__DOT__container__DOT__bellman_done,0,0);
    VL_SIG8(v__DOT__container__DOT__cycle_done,0,0);
    VL_SIG8(v__DOT__container__DOT__bellman_reset,0,0);
    VL_SIG8(v__DOT__container__DOT__cycle_reset,0,0);
    VL_SIG8(v__DOT__container__DOT__print_reset,0,0);
    VL_SIG8(v__DOT__container__DOT__print_done,0,0);
    VL_SIG8(v__DOT__container__DOT__vertmat_addr_a,6,0);
    VL_SIG8(v__DOT__container__DOT__vertmat_addr_b,6,0);
    VL_SIG8(v__DOT__container__DOT__vertmat_we_a,0,0);
    VL_SIG8(v__DOT__container__DOT__vertmat_we_b,0,0);
    VL_SIG8(v__DOT__container__DOT__adjmat_row_addr,6,0);
    VL_SIG8(v__DOT__container__DOT__adjmat_col_addr,6,0);
    VL_SIG8(v__DOT__container__DOT__adjmat_we,0,0);
    VL_SIG8(v__DOT__container__DOT__bellman_vertmat_addr_a,6,0);
    VL_SIG8(v__DOT__container__DOT__bellman_vertmat_addr_b,6,0);
    VL_SIG8(v__DOT__container__DOT__bellman_vertmat_we_b,0,0);
    VL_SIG8(v__DOT__container__DOT__cycle_vertmat_addr_b,6,0);
    VL_SIG8(v__DOT__container__DOT__cycle_vertmat_we_b,0,0);
    VL_SIG8(v__DOT__container__DOT__print_vertmat_addr_b,6,0);
    VL_SIG8(v__DOT__container__DOT__print_vertmat_we_b,0,0);
    VL_SIG8(v__DOT__container__DOT__bellman__DOT__state,3,0);
    VL_SIG8(v__DOT__container__DOT__bellman__DOT__i,6,0);
    VL_SIG8(v__DOT__container__DOT__bellman__DOT__j,6,0);
    VL_SIG8(v__DOT__container__DOT__bellman__DOT__k,6,0);
    VL_SIG8(v__DOT__container__DOT__cycle_detect__DOT__state,3,0);
    VL_SIG8(v__DOT__container__DOT__cycle_detect__DOT__i,6,0);
    VL_SIG8(v__DOT__container__DOT__cycle_detect__DOT__j,6,0);
    VL_SIG8(v__DOT__container__DOT__cycle_detect__DOT__k,6,0);
    VL_SIG8(v__DOT__container__DOT__cycle_detect__DOT__l,6,0);
    VL_SIG8(v__DOT__container__DOT__print_cycle__DOT__state,3,0);
    VL_SIG8(v__DOT__container__DOT__print_cycle__DOT__i,6,0);
    VL_SIG8(v__DOT__container__DOT__print_cycle__DOT__j,6,0);
    VL_SIG8(v__DOT__container__DOT__print_cycle__DOT__k,6,0);
    VL_SIG8(v__DOT__container__DOT__print_cycle__DOT__l,6,0);
    VL_SIG8(v__DOT__container__DOT__print_cycle__DOT__px,5,0);
    VL_SIG8(v__DOT__container__DOT__print_cycle__DOT__py,5,0);
    VL_SIG16(v__DOT__container__DOT__adjmat__DOT__addr,13,0);
    VL_SIG16(v__DOT__container__DOT__adjmat__DOT__addr_reg,13,0);
    VL_SIG(v__DOT__u_e,31,0);
    VL_SIG(v__DOT__container__DOT__adjmat_q,31,0);
    VL_SIG(v__DOT__container__DOT__adjmat_data,31,0);
    VL_SIG64(v__DOT__container__DOT__vertmat_q_a,39,0);
    VL_SIG64(v__DOT__container__DOT__vertmat_q_b,39,0);
    VL_SIG64(v__DOT__container__DOT__vertmat_data_a,39,0);
    VL_SIG64(v__DOT__container__DOT__vertmat_data_b,39,0);
    VL_SIG64(v__DOT__container__DOT__bellman_vertmat_data_b,39,0);
    VL_SIG64(v__DOT__container__DOT__cycle_vertmat_data_b,39,0);
    VL_SIG64(v__DOT__container__DOT__print_vertmat_data_b,39,0);
    VL_SIG64(v__DOT__container__DOT__vertmat__DOT__ram[64],39,0);
    VL_SIG(v__DOT__container__DOT__adjmat__DOT__ram[8193],31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    //char	__VpadToAlign33433[3];
    VL_SIG(v__DOT__container__DOT__adjmat__DOT____Vlvbound1,31,0);
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VFOREX__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VFOREX& operator= (const VFOREX&);	///< Copying not allowed
    VFOREX(const VFOREX&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VFOREX(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VFOREX();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VFOREX__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VFOREX__Syms* symsp, bool first);
  private:
    static QData	_change_request(VFOREX__Syms* __restrict vlSymsp);
  public:
    static void	_eval(VFOREX__Syms* __restrict vlSymsp);
    static void	_eval_initial(VFOREX__Syms* __restrict vlSymsp);
    static void	_eval_settle(VFOREX__Syms* __restrict vlSymsp);
    static void	_initial__TOP__2(VFOREX__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(VFOREX__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__4(VFOREX__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__6(VFOREX__Syms* __restrict vlSymsp);
    static void	_settle__TOP__3(VFOREX__Syms* __restrict vlSymsp);
    static void	_settle__TOP__5(VFOREX__Syms* __restrict vlSymsp);
    static void	traceChgThis(VFOREX__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__2(VFOREX__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__3(VFOREX__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__4(VFOREX__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis(VFOREX__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis__1(VFOREX__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis(VFOREX__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis__1(VFOREX__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
