#include <iostream>
#include <fstream>
#include <string>

//bool read8
int main(void) {

  //  std::istream &istr = std::cin;
  std::fstream istr ("test.txt", std::ios::in);
  std::string ln;
  while(getline(istr, ln)){
    std::cout << ln << std::endl;
  }
  return 0;
}
