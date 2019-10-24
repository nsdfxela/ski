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
    std::vector <int> results;
  while(std::cin >> i >> j) {
//    std::cout << i << " " << j;
    for(int t = i; t <= j; t++) {
      //      std::cout << t << " " << count(t) << std::endl;
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
        std::cout << results[idx] << " " << results[idx+1] << " " << results[idx+2] << std::endl;

  }
  
  return 0;
}
