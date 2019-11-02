#include <iostream>
#include <fstream>
#include <string>
int read_data(int &s, int &n, std::istream &st) {
  st >> s;
  st >> n;
  return s;
}


void print_data(const std::string &data, int s) {
  for(int i = 0; i < data.size(); i++) {
    std::cout << data[i];
  }
}

int main (void) {
  int s = 0, n = 0;
  std::ifstream fstr ("test.txt", std::ios::in);
  while(read_data(s, n, fstr)){
    //    std::cout << s << std::endl;
    std::string strn = std::to_string(n);
    print_data(strn, s);
  }
  return 0;
}
