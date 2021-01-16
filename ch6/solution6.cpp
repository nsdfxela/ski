#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>

void solve(int n) {


}

int main() {

#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch6\test6.txt)");
#endif

    int n;
    while (true) {
        istr >> n;
        if (!istr) {
            break;
        }
        solve(n);
    }

    return 0;
}