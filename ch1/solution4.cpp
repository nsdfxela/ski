#include <iostream>
#include <fstream>
int read_data(int &s, int &n, std::istream &st) {
  st >> s;
  st >> n;
  return s;
}
int main (void) {
  int s = 0, n = 0;
  std::ifstream fstr ("test.txt", std::ios::in);
  while(read_data(s, n, fstr)){
    std::cout << s << std::endl;
  }
  return 0;
}
