
#include <iostream>
#include <fstream>

#define M 100
#define N 100
char field [M][N];

void print_field(int m, int n, int order){
  std::cout << "Field #" << order << ":" << std::endl;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++){
      std::cout << field[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void read_field(std::istream &istr,  int &m, int &n) {
  istr >> m >> n;
  //std::cout << m << " " << n << std::endl;
  for(int i = 0; i < m; i++) {
    for(int j = 0 ; j < n; j++){
      char c;
      istr >> c;
      field[i][j] = c;
    }
  }
}

void safe_set(int i, int j, int m, int n) {
  if(i >= 0 && i < m && j >= 0 && j < n) {
    if(field[i][j] == '.') {field[i][j] = '1';}
    else if (field[i][j] >= '0' && field [i][j] <= '7') {field[i][j] ++;}
  }
}

void calculate_field(int m, int n) {
  for(int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if(field[i][j] == '*') {
	safe_set(i-1,j-1,m,n);
	safe_set(i-1,j  ,m,n);
	safe_set(i-1,j+1,m,n);
	safe_set(i  ,j-1,m,n);
	safe_set(i  ,j+1,m,n);
	safe_set(i+1,j-1,m,n);
	safe_set(i+1,j  ,m,n);
	safe_set(i+1,j+1,m,n);
      } else if(field[i][j] == '.') {
	field[i][j] = '0';
      }
    }
  }
}
int main (int argc, char **argv) {

  int m=0, n=0;
  int order = 0;
  std::ifstream istr ("test.txt", std::ios::in);

  do{
    read_field(istr, m, n);
    if(!m) break;
    calculate_field(m,n);
    print_field(m, n, ++order);
    std::cout << std::endl;
  } while(true);
  return 0;
}
