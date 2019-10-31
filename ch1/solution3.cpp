#include <iostream>
#include <numeric>
#include <fstream>

double payments[1000];
int read_data(std::istream &stream, int &number){

  stream >> number;
  //std::cout << number;
  for(int i = 0 ; i < number; i++) {
    stream >> payments[i];
    //    std::cout << payments[i] << " ";
  }
  return number;
}

void calculate(int n) {
  if(!n) return;
  double sum = std::accumulate(payments, payments + n, 0.0);
  double avg = sum / n;
  std::cout << avg << std::endl;

  double lsum = std::accumulate(payments, payments + n, 0.0,[avg](double lower_sum, double element){
					    if(element < avg)
					      return lower_sum + (avg - element);
					    else
					      return lower_sum;
					  });
  std::cout <<"ls: " << lsum << std::endl;
  
  
}

int main(int argc, char ** argv) {
  
  std::ifstream istr ("test.txt", std::ios::in);
  int studs = 0;
  while(read_data(istr, studs)) {
    calculate(studs);
    //    std::cout << studs;
  }
  

  return 0;
}
