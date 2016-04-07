#include <iostream>
#include <bitset>
#include <stdio.h>

#include "VContainer.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

#define WORD_WIDTH 32
#define PRED_WIDTH 32
#define WEIGHT_WIDTH 32

#define NODES 6
#define CYCLES 1001
#define PRINT_CYCLE 50

int extend_signed_int_width(unsigned int val, unsigned int width);
unsigned int lower_half_int(unsigned long in, int bits);
unsigned int upper_half_int(unsigned long in, int bits);
std::string binary_to_string(long in);

int main(int argc, char **argv, char **env) {
  int i, j;
  int clk;
  int graph[NODES][NODES] = {{0, -2, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 3},
                             {0, 0, 0, -4, 0, 0},
                             {0, 0, 0, 0, -3, 0},
                             {0, 0, 4, 0, 0, 0},
                             {-2, 0, 1, 0, 0, 0}};
  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  VContainer* top = new VContainer;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("Container.vcd");
  // initialize simulation inputs
  top->clk = 1;
  top->src = 0; //Source to start at
  top->reset = 1;
  for (i = 0; i < NODES; i++) {
    for (j = 0; j < NODES; j++) {
      top->adjmat[i][j] = graph[i][j];
    }
  }
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
    if (i % PRINT_CYCLE == 0 && i > 235 && i < CYCLES) { //Print every 100 clock periods
      std::cout << "Period " << i << " -------------\n";
      std::cout << "Test" << " : "<< binary_to_string((int)top->test) << "\n";
      //std::cout << "Test2" << " : "<< binary_to_string((int)top->test2) << "\n";
      std::cout << "Done" << " : "<< (int)top->done << "\n";
      for (j = 0; j < NODES; j++) {
        //unsigned int lower_half = lower_half_int((long)top->vertmat[j], WEIGHT_WIDTH);
        unsigned int upper_half = upper_half_int((unsigned long)top->vertmat[j], 0);
        std::cout << "Vert " << j << " [Pred: " << upper_half << ", Weight: " << (int)top->vertmat[j] << "]\n";
        std::cout << "Cycle "<< " [Pred: " << (int)top->o_vertmat[j] << "]\n";
      }
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
