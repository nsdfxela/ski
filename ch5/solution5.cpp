#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

void solve(int n) {

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