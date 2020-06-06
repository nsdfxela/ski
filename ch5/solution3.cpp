#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

void solve(int n) {
    int d = n, c = 0;
    do {
        d = d / 10;
        c++;
    } while (d);
    for (int k = c + 1; k < 1000000000; k++) {
        double log210 = log2(10);
        double log2n = log2(n);
        double log2np1 = log2(n+1);

        int lower = ceil(log2n + k * log210 );
        int upper = floor(log2np1 + k * log210);
        for (int l = lower; l < upper+1; l++) {
            std::cout << l << std::endl;
            return;
        }
    }
}

int main(void) {

#if __GNUC__
    std::istream& istr = cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch5\test.txt)");
#endif
    int n;
    while (1) {
        istr >> n;
        if (!istr.good()) {
            break;
        }
        solve(n);
        
    }
    return 0;

}