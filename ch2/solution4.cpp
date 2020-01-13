#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

int main(void) {

#if defined(__GNUC__)
    std::istream &istr = std::cin;
#else
    std::ifstream istr(R"(D:\study\ski\ch2\test.txt)", std::ios::in);
#endif
    int wc;
    istr >> wc;
    std::string dict[1000];
    std::map<char, int> lc;
    for (int i = 0; i < wc; i++) {
        istr >> dict[i];
        for (int j = 0; j < dict[i].length(); j++) {
            lc[dict[i][j]] ++;
        }
    }
    istr.ignore(1);
    while (istr) {
        std::string buf;
        std::getline(istr, buf);
        std::stringstream ss(buf);
        while (ss) {
            std::string w;
            ss >> w;
            std::cout << w << " ";
        }
        std::cout << '\n';
        
    }
    return 0;
}