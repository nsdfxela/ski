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
  //  std::cout << chess_board[i][j];
  if(chess_board[i][j] != '.') {
    field[i][j] = 1;
    return false;
  }
  field[i][j] = 1;
  return true;
}

bool s_nsafe(int field[N][N], int i, int j) {
  //  if(i < 0 || i > N -1) return false;
  //if(j < 0 || j > N -1) return false;
  //field[i][j] = 1;
  return true;
}



#define WHITE +1
#define BLACK -1
#define BLOCKED(bw) (bw == -1 ? blocked_B : blocked_W)
void pawn(int i, int j, int bow) {
  s_safe(BLOCKED(bow), i + bow, j-1);
  s_safe(BLOCKED(bow), i + bow, j+1);
}


#define ITER_I for (int i = 0; i < N; i++)
#define ITER_J for (int j = 0; j < N; j++)
void rook(int ii, int jj, int bw) {
  s_nsafe(BLOCKED(bw), ii, jj);
  for(int i = ii+1; i < N; i++) {if(!s_safe(BLOCKED(bw), i, jj)) break;}
  for(int i = ii-1; i >= 0; i--) {if(!s_safe(BLOCKED(bw), i, jj)) break;}
  for(int j = jj+1; j < N; j++) {if(!s_safe(BLOCKED(bw), ii, j)) break;}
  for(int j = jj-1; j >= 0; j--) {if(!s_safe(BLOCKED(bw), ii, j)) break;}

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
  bool d1 = true;
  bool d2 = true;
  s_nsafe(BLOCKED(bw), ii, jj);

  int i = ii;
  int j = jj;
  while(s_safe(BLOCKED(bw), --i, --j));
  i = ii; j = jj;
  while(s_safe(BLOCKED(bw), ++i, ++j));
  i = ii; j = jj;
  while(s_safe(BLOCKED(bw), --i, ++j));
  i = ii; j = jj;
  while(s_safe(BLOCKED(bw), ++i, --j));
}

void queen(int ii, int jj, int bw){
  bishop(ii, jj, bw);
  rook(ii, jj, bw);
}

void king(int ii, int jj, int bw) {
  for(int i = ii - 1; i <= ii + 1; i++){
      for(int j = jj - 1; j <= jj + 1; j++){
	s_safe(BLOCKED(bw), i, j);
      }
  }
  BLOCKED(bw)[ii][jj] = 0;

}

void knight(int ii, int jj, int bw) {
  s_nsafe(BLOCKED(bw), ii, jj);
  s_safe(BLOCKED(bw), ii + 1, jj -2);
  s_safe(BLOCKED(bw), ii + 1, jj +2);
  s_safe(BLOCKED(bw), ii - 1, jj -2);
  s_safe(BLOCKED(bw), ii - 1, jj +2);

  s_safe(BLOCKED(bw), ii + 2, jj -1);
  s_safe(BLOCKED(bw), ii + 2, jj +1);
  s_safe(BLOCKED(bw), ii - 2, jj -1);
  s_safe(BLOCKED(bw), ii - 2, jj +1);
  
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

 	  case 'K': king(i, j, BLACK); break;
	  case 'k': king(i, j, WHITE); break;

  	  case 'N': knight(i, j, BLACK); break;
	  case 'n': knight(i, j, WHITE); break;
	  }

	}
    }
}

bool is_check(int blocked[N][N], int kx, int ky){
  for(int i = -1; i <=1; i++)
  {
    int nx = kx + i;
    for(int j = -1; j <=1; j++){
      int ny = ky + j;
      if(nx >= 0 && nx <N && ny>=0 && ny <N && (j || i)){
	//	std::cout << nx << " " << ny <<  " " << blocked[nx][ny]<<  " \n";
	if(blocked[ny][nx] == 0) return false;
      }
    }
  }
  return true;
  
}

int main(void) {

  //  std::istream &istr = std::cin;
  std::fstream istr ("test.txt", std::ios::in);
  std::string ln;
  int d = 1;
  while(read8(istr)){
    clear_pos();
    get_b_pos();
    bool wic = is_check(blocked_W, w_k_pos_x, w_k_pos_y);
    bool bic = is_check(blocked_B, b_k_pos_x, b_k_pos_y);
        d_print_field(blocked_W);
        d_print_field(blocked_B);
    bool c = wic || bic;

    
    std::cout << "Game #" << d++ << ": ";
    if(!c) {std::cout  << "no";}
    else{
      if(wic) std::cout << "white";
      else std::cout << "black";
    }
    std::cout << " king is in check. \n";
    /*    std::cout << "black check " << is_check(blocked_B, b_k_pos_x, b_k_pos_y) << std::endl;
	  std::cout << "white check " << is_check(blocked_W, w_k_pos_x, w_k_pos_y) << std::endl;*/
    
  }

  return 0;
}
