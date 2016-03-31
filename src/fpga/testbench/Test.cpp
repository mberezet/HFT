#include <iostream>
#include <bitset>

#define INT_WIDTH 32
#define INDEX_WIDTH 7
#define WEIGHT_WIDTH 17

int make_edge(unsigned int src, unsigned int dest, signed int weight);
unsigned int reduce_signed_int_width(unsigned int val, int width);

int main(int argc, char **argv, char **env) {
  make_edge(1, 3, 40);
  return 0;
}

int make_edge(unsigned int src, unsigned int dest, signed int weight){
  int i = 0;
  src <<= (INT_WIDTH - INDEX_WIDTH)-1;
  dest <<= (INT_WIDTH - INDEX_WIDTH * 2)-1;
  weight = reduce_signed_int_width(weight, WEIGHT_WIDTH);
  std::string binary = std::bitset<32>(src + dest + weight).to_string();
  std::cout<<binary<<"\n";
  return src + dest + weight;
}

unsigned int reduce_signed_int_width(unsigned int val, int width) {
    unsigned int l_mask = (0x01u << width) - 1;
    val &= l_mask;
    return val;
}
