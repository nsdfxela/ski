#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
//10127	Ones
using namespace std;

void solve(long long T) {   
    long long mod = 1%T;
    int counter = 1;
    while (mod) {
        mod = (mod * 10 + 1) % T;
        counter++;
    };
    std::cout << counter << std::endl;
}

int main(void) {
#if __GNUC__
    istream& istr = cin;
#else
    ifstream istr(R"(C:\fedosin\repos\ski\ch5\test.txt)");
#endif
    while (1) {
        long long n;
        istr >> n;
        if (!istr.good()) {
            break;
        }
        solve(n);
    }
    return 0;
}