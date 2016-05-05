#include <iostream>
#include <bitset>
#include <stdio.h>

#include "VFOREX.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

#define WORD_WIDTH 32
#define PRED_WIDTH 7
#define WEIGHT_WIDTH 32

#define NODES 4
#define CYCLES 550
#define PRINT_CYCLE 5

int extend_signed_int_width(unsigned int val, unsigned int width);
unsigned int lower_half_int(unsigned long in, int bits);
unsigned int upper_half_int(unsigned long in, int bits);
unsigned int src_dst(unsigned int src, unsigned int dst);
std::string binary_to_string(long in);

int main(int argc, char **argv, char **env) {
  int i, j;
  int clk;
  int old_char = 0;
  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  VFOREX* top = new VFOREX;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("Container.vcd");
  // initialize simulation inputs
  top->clk = 1;
  top->reset = 1;
  std::cout << "\nRUNNING SIM\n";
  // run simulation for 500 clock periods
  for (i=0; i<CYCLES; i++) {
    // dump variables into VCD file and toggle clock
    for (clk=0; clk<2; clk++) {
      tfp->dump (2*i+clk);
      top->clk = !top->clk;
      top->eval ();
    }
    top->reset = 0;
    if (/*old_char != (int)top->frame_char &&*/ i > 542/*i % PRINT_CYCLE == 0 && i > 235 && i < CYCLES*/) { //Print every 100 clock periods
    //if((int)top->test) {
    //if(i % 1 == 0 && i > 614){
    //if((old_char || (int)top->test == 8008) && i > 615) {
      std::cout << "Period " << i << " -------------\n";
      //std::cout << "Char: " << (int)top->frame_char << " " <<
      //  (int)top->test << " => " << (int)top->test1 << " Edge: " << (int)top->test2 << "\n";
      std::cout << "Char: " << (int)top->frame_char <<
        " Test: "<< (int)top->test <<
        " Test1: "<< (int)top->test1 <<
        " Test2: " << (int)top->test2 << "\n";
      old_char = 1;
      int l, k;
    }
    top->write = 0;
    top->chipselect = 0;
    switch (i) {
      case 0:
        top->write = 1;
        top->chipselect = 1;
        top->writedata = src_dst(0, 1);
        top->address = 0;
        break;
      case 5:
        top->write = 1;
        top->chipselect = 1;
        top->writedata = 2;
        top->address = 1;
        break;
      case 200:
        top->write = 1;
        top->chipselect = 1;
        top->writedata = src_dst(1, 2);
        top->address = 0;
        break;
      case 205:
        top->write = 1;
        top->chipselect = 1;
        top->writedata = 1;
        top->address = 1;
        break;
      case 300:
        top->write = 1;
        top->chipselect = 1;
        top->writedata = src_dst(2, 3);
        top->address = 0;
        break;
      case 305:
        top->write = 1;
        top->chipselect = 1;
        top->writedata = 3;
        top->address = 1;
        break;
      case 400:
        top->write = 1;
        top->chipselect = 1;
        top->writedata = src_dst(3, 1);
        top->address = 0;
        break;
      case 405:
        top->write = 1;
        top->chipselect = 1;
        top->writedata = -9;
        top->address = 1;
        break;
    }

    if (Verilated::gotFinish())  exit(0);
  }
  tfp->close();
  exit(0);
}

int extend_signed_int_width(unsigned int val, unsigned int width) {
  int i;
  int mask = ~0;
  int tmp = val >> (width-1);
  if ((tmp & 1) == 0) return val;
  mask <<= width;
  return val | mask;
}

std::string binary_to_string(long in) {
  std::string binary = std::bitset<WORD_WIDTH>(in).to_string();
  return binary;
}

unsigned int lower_half_int(unsigned long in, int bits) {
  int i;
  int mask = 0;
  for(i = 0; i < bits; i++) {
    mask |= 1;
    if (i < bits - 1) mask <<= 1;
  }
  return in & mask;
}
unsigned int upper_half_int(unsigned long in, int bits) {
  return (unsigned int)(in >> (WORD_WIDTH-bits));
}

unsigned int src_dst(unsigned int src, unsigned int dst){
  return (src << PRED_WIDTH) | dst;
}
