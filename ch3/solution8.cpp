#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

void solve(const std::vector<std::string>& data) {
    for (int i = 0; i < data.size(); i++) {
        std::istringstream sstr(data[i]);
        std::string buffer;
        std::getline(sstr, buffer, ' ');

    }
}

int main(void){

#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch3\test.txt)");
#endif
    std::vector<std::string> data;
    while (1) {
        std::string buffer;
        std::getline(istr, buffer);
        if (!istr.good()) {
            break;
        }
        data.push_back(buffer);
        solve(data);
    }
    return 0;
}