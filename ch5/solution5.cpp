#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;
const string winners[2] = {"Stan wins","Ollie wins"};
void solve(int n) {
    long long t = 1;
    int step = 0;
    while (t < n) {
        if (step) { t *= 2; }
        else { t *= 9; }
        step = !step;
    }
    int w1 = !step;
    t = 1;
    step = 0;
    while (t < n) {
        if (step) { t *= 9; }
        else { t *= 2; }
        step = !step;
    }
    int w2 = !step;
    std::cout << winners[w1 * w2] << std::endl;
}

int main(void) {
#if __GNUC__
    istream& istr = cin;
#else
    ifstream istr(R"(C:\fedosin\repos\ski\ch5\test.txt)");
#endif
    while (1) {
        int n;
        istr >> n;
        if (!istr.good()) {
            break;
        }
        solve(n);
    }
    return 0;
}