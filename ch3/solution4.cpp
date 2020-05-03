#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

const std::string KEY = "the quick brown fox jumps over the lazy dog";
std::map<char, int> KEY_FP;

std::map<char, int> getFingerPrint(const std::string &str) {
    std::map<char, int> fp;
    for (int j = 0; j < str.size(); j++) {
        fp[str[j]]++;
    }
    return fp;
}

bool equal(const std::map<char, int> &a, const std::map<char, int> &b) {
    if (a.size() != b.size()) {
        return false;
    }
    std::vector<int> avals, bvals;
    for (auto it : a) {
        avals.push_back(it.second);
    }
    for (auto it : b) {
        bvals.push_back(it.second);
    }
    std::sort(avals.begin(), avals.end());
    std::sort(bvals.begin(), bvals.end());
    return std::equal(avals.begin(), avals.end(), bvals.begin());
}

void solve(std::vector<std::string>& tc) {
    std::vector< std::map<char, int>> fps;
    std::vector<bool> potentialKeys;
    for (int i = 0; i < tc.size(); i++) {
        auto fp = getFingerPrint(tc[i]);
        fps.push_back(fp);
        potentialKeys.push_back(equal(fp, KEY_FP));
    }
}

int main(void) {
#if __GNUC__
    std::istream& istr = std::cin;
#else 
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch3\test.txt)");
#endif
    KEY_FP = getFingerPrint(KEY);
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
        solve(testcase);
    }

    return 0;
}