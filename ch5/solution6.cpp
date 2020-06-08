#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void solve(const vector<int>&poly, int n) {

}

int main(void) {
#if __GNUC__
    istream& istr = cin;
#else
    ifstream istr(R"(C:\fedosin\repos\ski\ch5\test.txt)");
#endif
    while (1) {
        int n, k;
        istr >> n >> k;
        if (!istr.good()) {
            break;
        }
        int intb;
        vector<int> poly;
        for (int i = 0; i < k; i++) {
            istr >> intb;
            poly.push_back(intb);
        }
        solve(poly, n);
    }

    return 0;
}