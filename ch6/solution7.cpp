#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

void solve(int n) {

}

int main() {
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