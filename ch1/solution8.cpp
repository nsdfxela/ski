#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

char cand[20][80];
int votes[1000][20];
int ncand = 0;
int nvotes = 0;
 
void read_data(std::istream &istr) {
  std::string buf;
  istr >> ncand;
  istr.ignore();

  for(int i= 0; i < ncand; i++){
    std::getline(istr, buf);
    strcpy(cand[i], buf.c_str());
    //    std::cout << cand[i] << std::endl;
  }
  
  while(getline(istr, buf)) {
    if(buf == "") break;
    std::stringstream ss(buf);
    for(int i = 0; i < ncand; i++){
      ss >> votes[nvotes++][i];
    }
  }
}
void nullall(){
  ncand = 0;
  nvotes = 0;
}

std::string get_winner(int level){
  int vc[ncand];
  memset(vc, 0, sizeof vc);
  for(int i = 0; i < nvotes; i++) {
      vc[votes[i][level]-1]++;
  }

  for(int i =0;i < ncand;i++){
    std::cout << vc[i] << " ";
  }
  std::cout << std::endl;
  return "";
}

int main (void) {
  std::ifstream istr ("test.txt", std::ios::in);
  int nblocks = 0;
  istr >> nblocks;
  istr.ignore(1); //ignore empty line
  for( int i = 0; i < nblocks; i++) {  
    read_data(istr);
    std::cout << get_winner(0);
    nullall();
  }
  return 0;
}
