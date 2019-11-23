#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#define L 1000
#define S 3
#define Rn 10

int mem [L][S];
int regs [10];
int cur=0;
void read_block(std::istream &istr) {
  std::string ln;
  bool block_started = false;
  while(getline(istr, ln)){
    //std::cout << ln << std::endl;
    if(ln == "") {
      if(block_started)
	return;
      else continue;
    }
    else {block_started = true;}
    std::stringstream ss(ln);
    int data;
    ss >> data;
    mem[cur][0] = data/100;
    mem[cur][1] = (data-mem[cur][0]*100)/10;
    mem[cur][2] = data%10;
    cur++;
  }
}

void p_debug(int count = -1)
{
  int lim = count < 0 ? L : count;
  for(int i = 0; i < lim; i++) {
    std::cout << mem[i][0] << mem[i][1] << mem[i][2] << std::endl;
  }
}

void clear_mem() {

  std::fill(regs, regs+Rn, 0);
  for(int i = 0; i < L; i++){
    for(int j = 0; j < S; j++) {
      mem [i][j] = 0;
    }
  }
  cur = 0;
}

inline int& M(int p){ return  mem[cur][p];}
inline int& R(int p) {return regs[p];}
inline int& PTR(int r, int i) {
  int addr = R(r);
  return mem[addr][i];
}

inline void OF(int &val) {
  val %= 1000;
}

void decomp (int v, int res[3]) {
     res[0] = v / 100;
     res[1] = (v - res[0]*100) / 10;
     res[2] = v - res[0]*100 - res[1]*10;
}

bool is_end(){
  //  std::cout << mem[cur][0] << mem[cur][1] << mem[cur][2] << "\n ISEND";
  return mem[cur][0] == 1 && mem[cur][1] == 0 && mem[cur][2] == 0;
}



void exec_cmd() {
  switch(M(0))
  {
  case 2: R(M(1)) = M(2); OF(R(M(1)));  break;
  case 3: R(M(1)) += M(2); OF(R(M(1))); break;
  case 4: R(M(1)) *= M(2); OF(R(M(1))); break;
  case 5: R(M(1)) = R(M(2)); OF(R(M(1)));  break;
  case 6: R(M(1)) += R(M(2)); OF(R(M(1))); break;
  case 7: R(M(1)) *= R(M(2)); OF(R(M(1))); break;
  case 8: R(M(1)) = PTR(M(2), 0)*100 +
                    PTR(M(2), 1)*10 +
                    PTR(M(2), 2)*1;
    OF(R(M(1)));
    break;
  case 9: {
    int valsToSet [3];
    int targetAddr = R(M(2));
    OF(targetAddr);
    decomp(R(M(1)), valsToSet);
    mem[targetAddr][0] = valsToSet[0];
    mem[targetAddr][1] = valsToSet[1];
    mem[targetAddr][2] = valsToSet[2];
  }
  break;
  case 0: {
    if(R(M(2))) {
      int cellAddr = R(M(1));
      OF(cellAddr);
      cur = cellAddr-1; //will be incremented as usual so -1
    }
  }
  break;
  default: break;
  }
}

void p_debug2(){
  std::cout << "Register values: ";
  for(int i = 0; i < Rn; i++){
    int val = R(i);
    std:: cout << "R" << i << " " << val << " ";
  }
  std::cout << std::endl;
}

int commands_executed = 0;
void exec_programm(){
  do{
    exec_cmd();
    commands_executed++;
    //    p_debug2();
    cur++;
  } while (!is_end());
}

int main(void) {

    //  std::istream &istr = std::cin;
  std::ifstream ifstr ("test.txt", std::ios::in);   std::istream &istr = ifstr;
  int n_of_blocks = 0;
  istr >> n_of_blocks;
  for(int i = 0; i < n_of_blocks; i++) {
    clear_mem();
    read_block(istr);
    cur = 0;
    commands_executed = 0;
    exec_programm();
	std::cout << commands_executed+1 << std::endl;
	std::cout << std::endl;
  }
  
  //  p_debug(30);
  return 0;
}
	      
