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
    std::string st = oss.str();
    int lzer = 0;
    for (int i = 0; i < st.size(); i++) {
        if (st[i] == ' ') {
            lzer++;
        }
        else {
            break;
        }
    }

    return (oss.str().size() + s - lzer <= 72);
}

void dump(int tr = 1) {
    auto s = trim(oss.str(), tr);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '\t') {
            s[i] = ' ';
        }
    }
    std::cout << trim(s, 0) << std::endl;
    oss.str("");
    oss.clear();
}
void handleWord(std::ostringstream &word, int idx) {
    std::string w = word.str();
    if (w.size()) {
        if (w.size() >= 72) { //one long word per line rule
            if (oss.str().size()) {
                dump();
            }
            oss << w;
            word.str("");
            word.clear();
            return;
        }
        if (!fits(w.size())) {
            dump();
        }
        oss << word.str();
        word.str("");
        word.clear();
    }
}

void solve(std::vector<std::string>& data) {
    std::ostringstream word;
    for (int i = 0; i < data.size(); i++) {
        data[i] = trim(data[i], 0);
        bool leadingSpaces = true;
        for (int j = 0; j < data[i].size(); j++) {
            if (data[i][j] == ' ') {
                handleWord(word, i);
                if (fits(1)) {
                    oss << (leadingSpaces ? '\t' : ' ');
                } else {
                    leadingSpaces = false;
                    dump();
                }
            } else {
                leadingSpaces = false;
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
            if (!buffer.empty()) {
                data.push_back(buffer);
            }
            break;
        }
        data.push_back(buffer);
    }
    checkEndl(data, canDeleteEndl);
    solve(data);
    if (oss.str().size()) {
        dump();
    }
    return 0;
}