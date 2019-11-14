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

void L(std::istream &st) {
  char  c;
  int x, y;
  st >> x >> y >> c; //column, then row
  image[y-1][x-1] = c;
}

void V(std::istream &istr) {
  int x, y1, y2;
  char c;
  istr >> x >> y1 >> y2 >> c;
  for(int i = y1; i <= y2; i++){
    image[i-1][x-1] = c;
  }
}

void f(int x, int y, char ic, char c){
  static int ll = 0;

  if(x < 1 || x > M || y < 1 || y > N) {

    return;
  } //numeration from 0

  if(image[y-1][x-1] != ic) {return;}
  //    std::cout << ll++ << " ";
  //y -row
  //x - col
  //  std::cout << x << " " << y << " " << std::endl;
  image[y-1][x-1] = c;
  f(x+1, y , ic, c);
  f(x  , y-1, ic, c);
  f(x-1, y  , ic, c);
  f(x  , y+1 , ic, c);
}
void F(std::istream &st) {
  char  c;
  int x, y;
  st >> x >> y >> c; //column, then row
  //  std::cout << "F" << std::endl;
  f(x, y, image[y-1][x-1], c);
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

void H(std::istream &st) {
  int x1, x2, y;
  char c;
  st >> x1 >> x2 >> y;
  st >> c;

  for(int x = x1; x <=x2; x++) {
    image[y-1][x-1] = c;
  }
}

void C(std::istream &st) {
  if(image) {
    for(int i = 0; i < N; i++){
      delete [] image[i];
    }
    delete [] image;
  }
  for(int i = 0; i < N; i++){
    image[i]=new char [M];
    std::fill(image[i], image[i]+M, 'O');
  }
}

void K(std::istream &istr){
  int x1, x2, y1, y2;
  istr >> x1 >> x2 >> y1 >> y2;
  char c;
  istr >> c;
  for(int y = y1; y <= y2; y++){
    for(int x = x1; x <= x2; x++) {
      image[y-1][x-1] = c;
    }
  }
}

char read_command(std::istream &strm) {
  char cmd;
  strm >> cmd;
  //  std::cout << cmd << std::endl;
  switch(cmd){
  case 'I' : I(strm); break;
  case 'S' : S(strm); break;
  case 'L' : L(strm); break;
  case 'F' : F(strm); break;
  case 'V' : V(strm); break;
  case 'H' : H(strm); break;
  case 'C' : C(strm); break;
  case 'K' : K(strm); break;
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
