#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

std::ostringstream oss;

std::string trim(const std::string& str, int tr = 1) {
    std::string res = str;
    int idx = res.size()-1;
    while (idx >= 0 && res[idx] == ' ') {
        idx--;
    }
    res = res.substr(0, idx+1);

    if (!tr) {
        return res;
    }
    idx = 0;
    while (idx < res.size() && res[idx] == ' ') {
        idx++;
    }
    return res.substr(idx);
}

void solve(const std::vector<std::string>& data, const std::vector<int> canDeleteEndl) {

}

void checkEndl(const std::vector<std::string>& data, std::vector<int>& canDeleteEndl) {
    for (int i = 0; i < data.size(); i++) {
        int result = 0;
        for (int j = 0; j < data[i].size(); j++) {
            if (data[i][j] != ' ') {
                result = 1;
                break;
            }
        }
        canDeleteEndl.push_back(result);
    }
    for (int i = 0; i < canDeleteEndl.size(); i++) {
        if (canDeleteEndl[i] && (i + 1 < canDeleteEndl.size())) {
            if (data[i + 1][0] == ' ' || data[i + 1].empty()) {
                canDeleteEndl[i] = 0;
            }
        }
    }
}

int main(void){

#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch3\test.txt)");
#endif
    std::vector<std::string> data;
    std::vector<int> canDeleteEndl;
    while (1) {
        std::string buffer;
        std::getline(istr, buffer);
        if (!istr.good()) {
            break;
        }
        data.push_back(buffer);
    }
    checkEndl(data, canDeleteEndl);
    solve(data, canDeleteEndl);
    return 0;
}