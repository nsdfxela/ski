#include <iostream>
#include <fstream>
#include <string>

char cand[20][80];
void read_data(std::istream &istr) {
  std::string buf;
  std::getline(istr, buf); //empty
  int ncand = 0;
  istr >> ncand;
  std::cout << ncand << std::endl;
  
}

int main (void) {
  std::ifstream istr ("test.txt", std::ios::in);
  int nblocks = 0;
  istr >> nblocks;
  for( int i = 0; i < nblocks; i++) {
    read_data(istr);
  }
  return 0;
}
