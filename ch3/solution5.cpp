#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main(void) {

#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch3\test.txt)");
#endif

    std::string buffer;
    while (true) {
        std::vector<std::string> sol;
        std::vector<std::string> ans;
        
        std::getline(istr, buffer);
        if (buffer == "0") break;
        std::stringstream ss(buffer);
        int c1;
        ss >> c1;
        ss.clear();
        for (int i = 0; i < c1; i++) {
            std::getline(istr, buffer);
            sol.push_back(buffer);
        }
        int c2;
        istr >> c2;
        istr.ignore();
        for (int i = 0; i < c2; i++) {
            std::getline(istr, buffer);
            ans.push_back(buffer);
        }
    }

    return 0;
}