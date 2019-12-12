#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

char cand[20][80];
int votes[1000][3];
int ncand = 0;
 
void read_data(std::istream &istr) {
  std::string buf;
  istr >> ncand;
  istr.ignore();

  for(int i= 0; i < ncand; i++){
    std::getline(istr, buf);
    strcpy(cand[i], buf.c_str());
    //    std::cout << cand[i] << std::endl;
  }
  int ctr = 0;
  while(getline(istr, buf)) {
    if(buf == "") break;
    std::stringstream ss(buf);
    ss >> votes[ctr][0] >> votes[ctr][1] >> votes[ctr][2];
  }
}

int main (void) {
  std::ifstream istr ("test.txt", std::ios::in);
  int nblocks = 0;
  istr >> nblocks;
  istr.ignore(1); //ignore empty line
  for( int i = 0; i < nblocks; i++) {  
    read_data(istr);
  }
  return 0;
}
