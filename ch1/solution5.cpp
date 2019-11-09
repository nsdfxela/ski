#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

char ** image = nullptr;
int M=-1, N=-1;

void S(std::istream &st) {
  std::string file_name;
  st >> file_name;
  std::cout << file_name << std::endl;
  for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
      	std::cout << image[i][j];
      }
      std::cout << std::endl;
  }
}
void I(std::istream &st) {
  int m, n; //m - columns n -rows
  st >> m >> n;
  image = new char*[n];
  M = m; N = n;
  for(int i = 0; i < n; i++){
    image[i]=new char [m];
    std::fill(image[i], image[i]+m, 'O');
  }

			    
}

char read_command(std::istream &strm) {
  char cmd;
  strm >> cmd;
  std::cout << cmd << std::endl;
  switch(cmd){
  case 'I' : I(strm); break;
  case 'S' : S(strm); break;
  default:
    std::string tmp;
    std::getline(strm, tmp);
    break;
  }
  return cmd;
}

int main (void) {
  std::ifstream ifstr ("test.txt", std::ios::in);
  while(read_command(ifstr)!='X');
  return 0;
}
