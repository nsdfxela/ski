#include <iostream>
#include <string>
#include <fstream>
#include <map>
/*UV 10082*/
struct point { int Line; int Idx; };
std::map<char, point> mp;
std::string keyboard[]{
    "`1234567890-=", 
    R"(QWERTYUIOP[]\)",
    "ASDFGHJKL;'",
    "ZXCVBNM,./",
    " "
};

void solve(const std::string& str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            std::cout << ' ';
        }
        else {
            auto it = mp.find(str[i]);
            std::cout << keyboard[it->second.Line][it->second.Idx];
        }
        
    }    
}

int main(void) {
#ifdef __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch3\test.txt)");
#endif
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < keyboard[i].size(); j++) {
            point p;
            p.Idx = j - 1;
            p.Line = i;
            mp[keyboard[i][j]] = p;
        }
    }
    std::string buf;
    bool first = true;
    while (istr.good()) {
        if (!first) {
            std::cout << std::endl;
        }
        std::getline(istr, buf);       
        solve(buf);
        first = false;
    }
    
    return 0;
}