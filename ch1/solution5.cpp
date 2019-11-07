#include <iostream>
#include <fstream>

void read_command(std::istream &strm) {
  char cmd;
  strm >> cmd;
  switch(cmd){
  case 'I' : std::cout << 'I';
  default: break;
  }
}

int main (void) {
  std::ifstream ifstr ("test.txt", std::ios::in);
  read_command(ifstr);
  return 0;
}
