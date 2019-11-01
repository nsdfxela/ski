#include <iostream>
#include <cmath>
#include <numeric>
#include <fstream>
#include <iomanip>

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

double calculate_int(int n) {
  if(!n) return 0.0;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum+=(int)(payments[i]*100.0);
  }
  return 0.0;
}

double calculate(int n) {
  if(!n) return 0.0;
  double sum = std::accumulate(payments, payments + n, 0.0);
  double avg = std::round(sum / n * 100.0) / 100.0;
  //  std::cout << avg << std::endl;

  double msum = std::accumulate(payments, payments + n, 0.0,[avg](double lower_sum, double element){
					    if(element > avg)
					      return lower_sum + (element - avg);
					    else
					      return lower_sum;
					  });
  double lsum = std::accumulate(payments, payments + n, 0.0,[avg](double lower_sum, double element){
					    if(element < avg)
					      return lower_sum + (avg-element);
					    else
					      return lower_sum;
					  });

  //  std::cout <<"ls: " << lsum << std::endl;
  return lsum < msum ? lsum : msum;
  
  
}

int main(int argc, char ** argv) {
  
  //  std::ifstream istr ("test.txt", std::ios::in);
  int studs = 0;
  std::cout <<   std::setprecision(2) << std::fixed;

  while(read_data(std::cin, studs)) {
    std::cout << '$' << calculate(studs) << std::endl;
    //    std::cout << studs;
  }
  

  return 0;
}
