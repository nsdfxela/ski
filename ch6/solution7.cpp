#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

const int NMAX = 2000000000;

void naiveGolomb() {
    static std::vector<int> G;
    if (!G.empty()) { return; }
    G.push_back(1);
    G.push_back(2);

    int ival = 2;

    for (; ival < NMAX; ival++) {
        for (int i = 0; i < G[ival-1]; i++) {
            G.push_back(ival);
        }
    }
}

void solve(int n) {

}

int main() {
    naiveGolomb();
#if __GNUC__
    std::istream &istr = std::cin;
#else
    std::string fp = R"(C:\fedosin\repos\ski\ch6\test7.txt)";
    std::ifstream istr(fp);
#endif
    int buf = -1;
    while (1) {
        istr >> buf;
        if (!buf) {
            break;
        }
        solve(buf);
    }
    
    return 0;
}