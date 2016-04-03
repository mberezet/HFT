#include <iostream>
#include <bitset>

#include "VBellman.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

#define INT_WIDTH 32
#define INDEX_WIDTH 7
#define WEIGHT_WIDTH 31
#define NODES 4
#define CYCLES 101
#define PRINT_CYCLE 10

int make_edge(signed int weight);
unsigned int reduce_signed_int_width(signed int val, int width);
int extend_signed_int_width(unsigned int val, unsigned int width);
unsigned int lower_half_int(int in, int bits);
unsigned int upper_half_int(int in, int bits);
std::string binary_to_string(int in);

int main(int argc, char **argv, char **env) {
  int i, j;
  int clk;
  unsigned int graph[NODES][NODES] = {{make_edge(0), make_edge(4), make_edge(3), make_edge(0)},
                                      {make_edge(0), make_edge(0), make_edge(0), make_edge(4)},
                                      {make_edge(0), make_edge(0), make_edge(0), make_edge(6)},
                                      {make_edge(0), make_edge(0), make_edge(0), make_edge(0)}};
  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  VBellman* top = new VBellman;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("Bellman.vcd");
  // initialize simulation inputs
  top->clk = 1;
  top->src = 1;
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
    if (i % PRINT_CYCLE == 0) { //Print every 100 clock periods
      std::cout << "Period " << i << " -------------\n";
      std::cout << "Test" << " : "<< binary_to_string((int)top->test) << "\n";
      for (j = 0; j < NODES; j++) {
        unsigned int lower_half = lower_half_int((unsigned int)top->vertmat[j], 25);
        unsigned int upper_half = upper_half_int((unsigned int)top->vertmat[j], 7);
        std::cout << "Vert " << j << " [Pred: " << upper_half << ", Weight: " << extend_signed_int_width(lower_half, 25) << "]\n";
      }
    }
    if (Verilated::gotFinish())  exit(0);
  }
  tfp->close();
  exit(0);
}

int make_edge(signed int weight) {
  int i = 0;
  weight = reduce_signed_int_width(weight, WEIGHT_WIDTH);
  return (1 << INT_WIDTH - 1) + weight;
}

unsigned int reduce_signed_int_width(signed int val, int width) {
    unsigned int l_mask = (0x01u << width) - 1;
    val &= l_mask;
    return val;
}

int extend_signed_int_width(unsigned int val, unsigned int width) {
  int i;
  int mask = ~0;
  int tmp = val >> width-1;
  if ((tmp & 1) == 0) return val;
  mask <<= width;
  return val | mask;
}

std::string binary_to_string(int in) {
  std::string binary = std::bitset<32>(in).to_string();
  return binary;
}

unsigned int lower_half_int(int in, int bits) {
  int i;
  int mask = 0;
  for(i = 0; i < bits; i++) {
    mask |= 1;
    if (i < bits - 1) mask <<= 1;
  }
  return in & mask;
}
unsigned int upper_half_int(int in, int bits) {
  return (unsigned int)in >> (INT_WIDTH-bits);
}
