#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

//UVa 10049	Self - describing Sequence

const int NMAX = 2000000000;

struct seq {
    int val;
    int from;
    int to;
};

std::unordered_map<int, int> M;
static std::vector<seq> G;

void naiveGolomb2() {
    M.reserve(680000);
    G.push_back(seq{ 1, 1, 1 });
    G.push_back(seq{ 2, 2, 3 });

    int curPos = 3;
    int I = G.size() - 1;
    while (G.back().to < NMAX) {
        for (int i = I; i < G.size(); i++) {
            if (curPos >= G[i].from && curPos <= G[i].to) {
                I = i;
                seq s;
                s.from = G.back().to + 1;
                s.to = s.from + G[i].val - 1;
                s.val = curPos;
                G.push_back(s);
                //M[s.to] = G.size() - 1;
                curPos++;
                break;
            }
        }
    }

}


void naiveGolomb() {
    std::vector<int> theG;

    if (!theG.empty()) { return; }
    theG.push_back(1);
    theG.push_back(2);

    int ival = 2;

    for (; ival < NMAX; ival++) {
        for (int i = 0; i < theG[ival-1]; i++) {
            theG.push_back(ival);
        }
    }
}

void solve(int n) {
    for (int i = 0; i < G.size(); i++) {
        if (n >= G[i].from && n <= G[i].to) {
            std::cout << G[i].val << '\n';
        }
    }
    /*for (int i = n; i >= 0; i--) {
        if (curPos >= G[i].from && curPos <= G[i].to) {
        }
    }*/
}

int main() {
    naiveGolomb2();
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