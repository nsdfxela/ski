#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

void solve(std::vector<int> &stk) {

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