#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


//3 1 2 5 5
//1 3 2 5 5
//2 3 1 5 5
//3 2 1 5 5
//1 2 3 5 5
//
//3 1 2 5 5
//2 1 3 5 5
//1 2 3 5 5

void flip(std::vector<int>& stk, int idx) {
    std::reverse(stk.begin(), stk.begin() + (stk.size() - idx + 1));
}



void solve(std::vector<int> &stk) {
    flip(stk, 1);
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