#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

//1 2 3 5 5
//3 1 2 5 5
//
//3 1 2 5 5
//1 3 2 5 5
//2 3 1 5 5
//3 2 1 5 5
//1 2 3 5 5
//
//3 4 1 2 5 5
//4 3 1 2 5 5
//2 1 3 4 5 5
//1 2 3 4 5 5
//Accepted!
void flip(std::vector<int>& stk, int idx) {
    std::reverse(stk.begin(), stk.begin() + (stk.size() - idx + 1));
}



void solve(std::vector<int> &stk) {
    std::vector<int> stks = stk;
    std::sort(stks.begin(), stks.end());
    for (int i = 0; i < stk.size(); i++) {
        if (i) {
            std::cout << ' ';
        }
        std::cout << stk[i];
    }
    std::cout << std::endl;
    for (int i = stk.size() - 1; i >= 0; i--) {
        if (stk[i] == stks[i]) {
            continue;
        } 
        int j;
        for (j = i; j >= 0; j--) {
            if (stk[j] == stks[i]) {
                flip(stk, stk.size() - j);
                if (j) {
                    std::cout << stk.size() - j << ' ';
                }
                
                flip(stk, stk.size() - i);
                std::cout << stk.size() - i << ' ';
                break;
            }
        }
    }
    std::cout << '0' << std::endl;
}

int main(void) {

#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch4\test.txt)");
#endif
    std::string buffer;
    while (1) {

        if (!istr.good()) {
            break;
        }
        std::getline(istr, buffer);
        if (!buffer.empty()) {
            std::stringstream ss(buffer);
            std::vector<int> s;
            while (ss.good()) {
                int b;
                ss >> b;
                s.push_back(b);
            }
            solve(s);
        } 
    }

    return 0;
}