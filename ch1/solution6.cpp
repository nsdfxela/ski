#include <iostream>

#define L 1000
#define S 3
#define R 10

int mem [L][S];
int regs [10];
int *cur=nullptr;
void read_blocks(std::istream &istr) {
  
}
void clear_mem() {
  std::fill(regs, regs+R, 0);
  for(int i = 0; i < L; i++){
    for(int j = 0; j < S; j++) {
      mem [i][j] = 0;
    }
  }
  cur = mem[0];
}

int main(void) {
  std::istream &istr = std::cin;
  int n_of_blocks = 0;
  istr >> n_of_blocks;
  for(int i = 0; i < n_of_blocks; i++) {
    clear_mem();
    read_blocks(istr);
  }
  return 0;
}
	      
