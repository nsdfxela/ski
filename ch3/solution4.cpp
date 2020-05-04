#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>


const std::string KEY = "the quick brown fox jumps over the lazy dog";
std::string KEYfreq;
std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

std::string calcFreq(const std::string &origin) {
    int aiter=0;
    std::map<char, char> mp;
    std::ostringstream ss;

    for (int i = 0; i < origin.size(); i++) {
        if (origin[i] == ' ') {
            ss << ' ';
        } else if (mp.find(origin[i]) == mp.end()) {
            mp[origin[i]] = alphabet[aiter];
            ss << alphabet[aiter++];
        } else {
            ss << mp[origin[i]];
        }
    }
    return ss.str();
}

void solve(std::vector<std::string>& tc) {
    std::map<char, char> dct;
    for (int i = 0; i < tc.size(); i++) {
        std::string fp = calcFreq(tc[i]);
        if (fp == KEYfreq) {
            for (int j = 0; j < KEY.size(); j++) {
                dct[tc[i][j]] = KEY[j];
    
            }
            break;
        }
    }
    if (dct.size() != 27) {
        std::cout << "No solution." << std::endl;
    }
    for (int i = 0; i < tc.size(); i++) {
        if (i) std::cout << std::endl;
        for (int j = 0; j < tc[i].size(); j++) {
            std::cout << dct[tc[i][j]];
        }
    }

}

int main(void) {
#if __GNUC__
    std::istream& istr = std::cin;
#else 
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch3\test.txt)");
#endif
    KEYfreq = calcFreq(KEY);
    int tc;
    istr >> tc;
    istr.ignore(2);

    for (int i = 0; i < tc; i++) {
        std::string buffer;
        std::vector<std::string> testcase;
        do {
            std::getline(istr, buffer);
            if (!buffer.empty()) {
                testcase.push_back(buffer);
            }
        } while (!buffer.empty() && istr.good());
        if (i) 
            std::cout << std::endl << std::endl;
        solve(testcase);
    }

    return 0;
}