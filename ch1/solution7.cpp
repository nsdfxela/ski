#include <iostream>
#include <fstream>
#include <string>

const int N = 8;
char chess_board [N][N];


bool read8(std::istream &istr) {

  bool is_empty = true;
  for(int i = 0; i < N;i++){
    for(int j =0; j < N; j++) {
      istr >> chess_board[i][j];
      std::cout << chess_board[i][j];
      is_empty = is_empty && (chess_board[i][j] == '.');
    }
    std::cout << '\n';
  }
  std::cout << '\n';
  return !is_empty;
}
int main(void) {

  //  std::istream &istr = std::cin;
  std::fstream istr ("test.txt", std::ios::in);
  std::string ln;
  while(read8(istr)){
    
  }

  return 0;
}
