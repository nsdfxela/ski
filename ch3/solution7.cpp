#include <iostream>
#include <string>
#include <fstream>
#include <set>

std::set<std::string> dict;
void solve(const std::string& str1, const std::string& str2) {


}

int main(void) {

#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch3\test.txt)");
#endif
    while (1) {
        std::string buf;
        std::getline(istr, buf);
        if (!istr.good() || buf.empty()) {
            break;
        }
        dict.insert(buf);
    }
    std::string str1, str2;
    while (istr.good()) {
        istr >> str1 >> str2;
        if (istr.good()) {
            solve(str1, str2);
        }
    }

    return 0;
}