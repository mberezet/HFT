#include <iostream>
#include <bitset>

#include "VBellman.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

#define INT_WIDTH 32
#define INDEX_WIDTH 7
#define WEIGHT_WIDTH 17
#define NODES 2
#define CYCLES 500

int make_edge(unsigned int src, unsigned int dest, signed int weight);
unsigned int reduce_signed_int_width(unsigned int val, int width);

int main(int argc, char **argv, char **env) {
  int i, j;
  int clk;
  unsigned int graph[NODES][NODES] = {{make_edge(0, 0, 0), make_edge(0, 1, 40)},
                                      {make_edge(0, 1, -30), make_edge(1, 1, 0)}};
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
  for (j = 0; j < NODES; j++) {
    for (j = 0; j < NODES; j++) {
      top->adjmat[i][j] = graph[i][j];
    }
  }
  std::cout << "RUNNING SIM\n";
  // run simulation for 500 clock periods
  for (i=0; i<CYCLES; i++) {
    // dump variables into VCD file and toggle clock
    for (clk=0; clk<2; clk++) {
      tfp->dump (2*i+clk);
      top->clk = !top->clk;
      top->eval ();
    }
    if (i % 100 == 0) { //Print every 100 clock periods
      std::cout << "Period " << i << " -------------\n";
      for (j = 0; j < NODES; j++) {
        std::cout << "Vert " << j << " : "<< (int)top->o_vertmat[j] << "\n";
      }
    }
    if (Verilated::gotFinish())  exit(0);
  }
  tfp->close();
  exit(0);
}

int make_edge(unsigned int src, unsigned int dest, signed int weight){
  int i = 0;
  src <<= (INT_WIDTH - INDEX_WIDTH)-1;
  dest <<= (INT_WIDTH - INDEX_WIDTH * 2)-1;
  weight = reduce_signed_int_width(weight, WEIGHT_WIDTH);
  std::string binary = std::bitset<32>(src + dest + weight).to_string();
  std::cout << "Edge: " << binary << "\n";
  return src + dest + weight;
}

unsigned int reduce_signed_int_width(unsigned int val, int width) {
    unsigned int l_mask = (0x01u << width) - 1;
    val &= l_mask;
    return val;
}
