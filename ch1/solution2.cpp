#include <iostream>
#include <fstream>
int main (int argc, char **argv) {
  std::ifstream istr ("test.txt", std::ios::in);
  int input = 14;
  istr >> input;
  std::cout << input;
  return 0;
}
