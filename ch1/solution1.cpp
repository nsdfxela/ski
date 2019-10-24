#include <iostream>
#include <vector>
#include <fstream>


int count(int n) {
  int nn = n;
  int cnt = 0;
  while(nn > 1) {
    if(nn % 2 == 0){
      nn/=2;
      cnt++;
    } else {
      nn = nn * 3 + 1;
      cnt++;
    }
 //    std::cout << nn << std::endl;
  }
  return cnt+1;
}

int main(void) {
  int i,j;
    int maxElement = 0;
    std::vector <int> results;
    /*#if 0
    std::ifstream istr ("test.txt", std::ios::in);
    while(istr >> i >> j) {
    #elif*/
    while(std::cin >> i >> j){
      //#endif
    for(int t = i; t <= j; t++) {
      int ct = count(t);
      if(ct > maxElement) {
	maxElement = ct;
      }
    }
    results.push_back(i);
    results.push_back(j);
    results.push_back(maxElement);
    }
    maxElement = 0;
        for(int idx = 0; idx < results.size(); idx+=3){
	  if(idx) std::cout << std::endl;
	  std::cout << results[idx] << " " << results[idx+1] << " " << results[idx+2];
	}
  
  return 0;
}
