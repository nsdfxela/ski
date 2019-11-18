#include <iostream>
#include <string>
#include <fstream>

#define L 1000
#define S 3
#define R 10

int mem [L][S];
int regs [10];
int *cur=nullptr;
void read_blocks(std::istream &istr) {
  std::string ln;
  while(getline(istr, ln)){
    if(ln == "") std::cout << "empty ";
    std::cout << ln << std::endl;

  }
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
  //  std::istream &istr = std::cin;
  std::ifstream ifstr ("test.txt", std::ios::in);   std::istream &istr = ifstr;
  int n_of_blocks = 0;
  istr >> n_of_blocks;
  for(int i = 0; i < n_of_blocks; i++) {
    clear_mem();
    read_blocks(istr);
  }
  return 0;
}
	      
