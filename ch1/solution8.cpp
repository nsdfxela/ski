#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

char cand[20][80];
int votes[1000][20];
int ncand = 0;
int nvotes = 0;
int cand_el[20];
float perc[20];
 
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
      ss >> votes[nvotes][i];
    }
    nvotes++;
  }
}
void nullall(){
  ncand = 0;
  nvotes = 0;
  memset(cand_el, 0, sizeof cand_el);
}

std::string get_winner(int level){
  int vc[ncand];
  memset(vc, 0, sizeof vc);
  for(int i = 0; i < nvotes; i++) {
    int llev = level;
    int c =0;
    do
    {
       c = votes[i][llev++];
    }
    while(cand_el[c]);
    vc[c-1]++;
  }

  int lidx = 0;
  int midx = 0;
  for(int i =0; i < ncand; i++) {
    perc[i] = vc[i] / (float)nvotes;
  }

  for(int i =0;i < ncand;i++){
    if(vc[i] < vc[lidx]){
      lidx = i;
    }
    if(vc[i] > midx) {
      midx = i;
    }
  }

  for(int i = 0; i < ncand; i++){
    std::cout << perc[i] << " ";
  }
  
  if(vc[midx] > 50.0f){
    return cand[midx];
  } else {
    cand_el[lidx] = 1;
    return "";
  }
  /*  for(int i =0;i < ncand;i++){
    std::cout << perc[i]  << " ";
  }
  std::cout << std::endl;
  return "";*/
}

int main (void) {
  std::ifstream istr ("test.txt", std::ios::in);
  int nblocks = 0;
  istr >> nblocks;
  istr.ignore(1); //ignore empty line
  for( int i = 0; i < nblocks; i++) {  
    read_data(istr);
    std::string w = "";
    do{
    w = get_winner(0);
    std::cout << w << std::endl;
    } while (w == "");

    nullall();
  }
  return 0;
}
