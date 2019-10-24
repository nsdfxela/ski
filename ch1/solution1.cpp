#include <iostream>
#include <vector>


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
//  std::cout << count(22);
    int maxElement = 0;
  while(std::cin >> i >> j) {
//    std::cout << i << " " << j;
    for(int t = i; t <= j; t++) {
      //      std::cout << t << " " << count(t) << std::endl;
      int ct = count(t);
      if(ct > maxElement) {
	maxElement = ct;
      }
    }
    std::cout << i << " " << j << " " << maxElement << std::endl;
    maxElement = 0;
  }
  
  return 0;
}
