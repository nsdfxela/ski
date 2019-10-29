#include <iostream>
#include <fstream>

#define M 100
#define N 100
char field [M][N];

void print_field(int m, int n){
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++){
      std::cout << field[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
int main (int argc, char **argv) {
  std::ifstream istr ("test.txt", std::ios::in);
  int m=0, n=0;
  istr >> m >> n;
  std::cout << m << " " << n << std::endl;
  for(int i = 0; i < m; i++) {
    for(int j = 0 ; j < n; j++){
      char c;
      istr >> c;
      field[i][j] = c;
    }
  }
  print_field(m, n);
  return 0;
}
