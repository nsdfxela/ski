#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>


std::string trim(const std::string& str, int leftTrim = 1) {
    std::string res = str;
    int idx = res.size()-1;
    while (idx >= 0 && res[idx] == ' ') {
        idx--;
    }
    res = res.substr(0, idx+1);

    if (!leftTrim) {
        return res;
    }
    idx = 0;
    while (idx < res.size() && res[idx] == ' ') {
        idx++;
    }
    return res.substr(idx);
}

std::ostringstream oss;
std::vector<int> canDeleteEndl;
bool fits(int s) {
    return (oss.str().size() + s <= 72);
}

void dump(int tr = 0) {
    auto s = trim(oss.str(), tr);
    std::cout << s << std::endl;
    std::swap(oss, std::ostringstream());
}
void handleWord(std::ostringstream &word, int idx) {
    std::string w = word.str();
    if (w.size()) {
        if (w.size() >= 72) { //one long word per line rule
            dump();
            oss << w;
            std::swap(word, std::ostringstream());
            return;
        }
        if (!fits(w.size())) {
            dump();
        }
        oss << word.str();
        std::swap(word, std::ostringstream());
    }
}

void solve(std::vector<std::string>& data) {
    std::ostringstream word;
    for (int i = 0; i < data.size(); i++) {
        data[i] = trim(data[i], 0);
        for (int j = 0; j < data[i].size(); j++) {
            if (data[i][j] == ' ') {
                handleWord(word, i);
                if (fits(1)) {
                    oss << ' ';
                } else {
                    dump();
                }
            } else {
                word << data[i][j];
            }
        }
        //line finished 
        if (!canDeleteEndl[i]) {
            handleWord(word, i);
            dump(1);
        } else {
            handleWord(word, i);
            if (fits(1)) {
                oss << ' ';
            }
        }
        ////
    }
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
    while (1) {
        std::string buffer;
        std::getline(istr, buffer);
        if (!istr.good()) {
            break;
        }
        data.push_back(buffer);
    }
    checkEndl(data, canDeleteEndl);
    solve(data);
    return 0;
}