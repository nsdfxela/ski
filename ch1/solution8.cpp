#include <iostream>
#include <fstream>
#include <string>

char cand[20][80];
int votes[1000][3];
int ncand = 0;
 
void read_data(std::istream &istr) {
  std::string buf;
  //std::getline(istr, buf); //empty
  istr >> ncand;
  istr.ignore(1);
  for(int i= 0; i < ncand; i++){
    std::getline(istr, buf);
    strcpy(cand[i], buf.c_str());
    std::cout << cand[i] << std::endl;
  }
  int ctr = 0;
  while(istr >> votes[ctr][0] >> votes[ctr][1] >> votes[ctr][2]) {
    std::cout << votes[ctr][0] << votes[ctr][1] << votes[ctr][2];
  }
  istr.ignore(1);
  //  std::cout << ncand << std::endl;
  
}

int main (void) {
  std::ifstream istr ("test.txt", std::ios::in);
  int nblocks = 0;
  istr >> nblocks;
  
  for( int i = 0; i < nblocks; i++) {
    istr.ignore(1); //ignore empty line
    read_data(istr);
  }
  return 0;
}
