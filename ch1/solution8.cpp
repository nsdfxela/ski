#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>

char cand[20][80];
int votes[1000][20];
int ncand = 0;
int nvotes = 0;
int cand_el[20];

int vlim=0; 
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

  vlim = (int)floor(nvotes / 2.0f);
  //  std::cout << "vlim is " << vlim << std::endl;
}
void nullall(){
  ncand = 0;
  nvotes = 0;
  memset(cand_el, 0, sizeof cand_el);
}

std::string get_winner(int level){
  int vc[ncand];
  memset(vc, 0, sizeof vc);
  // std::cout << "nvotes is " << nvotes << std::endl;
  // std::cout << "ncand is " << ncand << std::endl;

  for(int i = 0; i < nvotes; i++) {
    int llev = level;
    int c =0;
    do
    {
      if(llev == ncand) {
	//	break;
      }
       c = votes[i][llev++];
    }
    while(cand_el[c-1]);
    vc[c-1]++;
       //    std::cout << "c-1 is " << (c-1) << " vc s is " << ncand << std::endl;
  }

  int lidx = 0;
  while(cand_el[lidx])lidx++;
  
  int midx = 0;
  while(cand_el[midx])midx++;
  /*  for(int i =0; i < ncand; i++) {
  //perc[i] = vc[i] / (float)nvotes;
    std::cout << vc[i] << " " ;
    }*/

  for(int i =0;i < ncand;i++) {
    if(!cand_el[i]) {
    if(vc[i] < vc[lidx]){
      lidx = i;
    }
    if(vc[i] > vc[midx]) {
      midx = i;
    }
    }
  }

  //DEBUG
  /*    for(int i = 0; i < ncand; i++){
      std::cout << vc[i] << " ";
      }*/
    //    std::cout << "dbg " << vc[midx] << " " << vc[lidx] << std::endl;
  if(vc[midx] >= vlim || vc[midx] == vc[lidx]){
    std::string result;
    for(int i = 0; i < ncand; i++){
      //      std::cout << vc [i] << "\n";
      if(vc[i] == vc[midx]){
	result += cand[i];
	result.append("\n");
      }
    }
    return result;
  } else {
    for(int i = 0; i < ncand; i++){
      //      std::cout << vc [i] << "\n";
      if(vc[i] == vc[lidx]){
	cand_el[i] = 1;
      }
    }

    /*for(int i = 0 ; i < ncand; i++){
      std::cout << cand_el[i] << " ";
      }*/
    //    std::cout << std::endl;
    return "";
  }
}

int main (void) {
  std::ifstream istr ("test.txt", std::ios::in);
//std::istream &istr = std::cin;
  int nblocks = 0;
  istr >> nblocks;
  istr.ignore(1); //ignore empty line
  for( int i = 0; i < nblocks; i++) {

    read_data(istr);

    std::string w = "";
    do{

    w = get_winner(0);
    //std::cout << w << std::endl;
    } while (w == "");
    std::cout << w << std::endl;

    nullall();

  }
  return 0;
}
