#include <iostream>
#include <fstream>

double payments[1000];
int read_data(std::istream &stream, int &number){
  stream >> number;
  std::cout << number;
  for(int i = 0 ; i < number; i++) {
    stream >> payments[i];
    std::cout << payments[i] << " ";
  }
  return number;
}

int main(int argc, char ** argv) {
  std::ifstream istr ("test.txt", std::ios::in);
  int studs = 0;
  while(read_data(istr, studs)) {
    std::cout << studs;
  }
  

  return 0;
}
