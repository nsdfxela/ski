#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

void solve(std::string files[144], int c) {
    int totalLetters = 0;
    int letters = 0;
    int linksNeed = c / 2;
    std::map<int, std::vector<int>> mp;
    int bitmap[144];
    memset(bitmap, 0, sizeof(int) * 144);
    for (int i = 0; i < c; i++) {
        mp[files[i].size()].push_back(c);
        totalLetters += files[i].size();
    }
    letters = totalLetters / c * 2;
    std::map<int, int> mtch;
    for (int i = 0; i < c; i++) {
    }
}

int main(void) {
#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch3\test.txt)");
#endif
    int tb;
    istr >> tb;
    istr.ignore(2);
    for (int i = 0; i < tb; i++) {
        std::string files[144];
        std::string buffer;
        int c = 0;
        while (1) {
            std::getline(istr, buffer);
            if (!istr.good() || buffer.empty()) {
                break;
            }
            files[c] = buffer;
            c++;
            
        }
        if (c) {
            solve(files, c);
        }
    }
    return 0;
}