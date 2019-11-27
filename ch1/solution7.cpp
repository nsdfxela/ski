#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

const int N = 8;
char chess_board [N][N];
int blocked_W [N][N];
int blocked_B [N][N];


int w_k_pos_x = -1;
int w_k_pos_y = -1;
int b_k_pos_x = -1;
int b_k_pos_y = -1;



bool read8(std::istream &istr) {

  bool is_empty = true;
  for(int i = 0; i < N;i++){
    for(int j =0; j < N; j++) {
      istr >> chess_board[i][j];
      //std::cout << chess_board[i][j];
      is_empty = is_empty && (chess_board[i][j] == '.');
      if(chess_board[i][j] == 'k') {
	b_k_pos_x = j;
	b_k_pos_y = i;
	//std::cout << "k " << i << j << std::endl;
      }
      if(chess_board[i][j] == 'K') {
	//std::cout << "K " << i << j << std::endl;
	w_k_pos_x = j;
	w_k_pos_y = i;
      }
    }
    //    std::cout << '\n';
  }
  //  std::cout << '\n';
  return !is_empty;
}

void clear_pos() {
  for(int i = 0; i < N;i++){
    std::fill(blocked_W[i], blocked_W[i]+N, 0);
    std::fill(blocked_B[i], blocked_B[i]+N, 0);
  }
  
}

bool s_safe(int  field [N][N], int i, int j){
  if(i < 0 || i > N -1) return false;
  if(j < 0 || j > N -1) return false;
  field[i][j] = 1;
  return true;
}


#define WHITE +1
#define BLACK -1
#define BLOCKED(bw) (bw == -1 ? blocked_B : blocked_W)
void pawn(int i, int j, int bow) {
  //  s_safe(blocked_W, i-1, j-1);
  //  s_safe(blocked_W, i-1, j+1);
  s_safe(BLOCKED(bow), i + bow, j-1);
  s_safe(BLOCKED(bow), i + bow, j+1);
}


#define ITER_I for (int i = 0; i < N; i++)
#define ITER_J for (int j = 0; j < N; j++)
void rook(int ii, int jj, int bw) {
  ITER_I
    {
      s_safe(BLOCKED(bw), i, jj);
    }
  ITER_J
    {
      s_safe(BLOCKED(bw), ii, j);
    }
}

template <class T>
void d_print_field(T f[8][8]) {
  ITER_I
    {
      ITER_J
	{
	  std::cout << f[i][j];
	}
      std::cout << std::endl;
    }
  std::cout << std::endl;
}

void bishop(int ii, int jj, int bw){
  for(int m = 0; m < N; m++){
    int j = jj - ii + m;
    int n = N - m;
    s_safe(BLOCKED(bw), m, j); //x increasing, y increasing
    s_safe(BLOCKED(bw), n-1, j-1); //x increasing, y decreasing
  }

}

void queen(int ii, int jj, int bw){
  bishop(ii, jj, bw);
  rook(ii, jj, bw);
}

//get blocked positions
void get_b_pos(){
  ITER_I
    {
      ITER_J
	{
	  switch (chess_board[i][j]) {
	  case 'p': pawn(i, j, WHITE); break;
	  case 'P': pawn(i, j, BLACK); break;

	  case 'r': rook(i, j, WHITE); break;
	  case 'R': rook(i, j, BLACK); break;

	  case 'B': bishop(i, j, BLACK); break;
	  case 'b': bishop(i, j, WHITE); break;

	  case 'Q': queen(i, j, BLACK); break;
	  case 'q': queen(i, j, WHITE); break;
	  }

	}
    }
}

int main(void) {

  //  std::istream &istr = std::cin;
  std::fstream istr ("test.txt", std::ios::in);
  std::string ln;
  while(read8(istr)){
    clear_pos();
    get_b_pos();
    d_print_field(blocked_W);
    d_print_field(blocked_B);
    
  }

  return 0;
}
