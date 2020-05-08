#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <set>

bool check(const std::string& var, const std::string &str, std::map<std::string, int> visited) {
    if (var.find(str) != 0) {
        return false;
    } else {
        auto it = visited.find(str);
        if (it == visited.end() || !it->second) {
            return false;
        } else {
            it->second --;
            //err here

            std::string complement = var.substr(str.size(), std::string::npos);
            auto it2 = visited.find(complement);
            if (it2 != visited.end() && it2->second > 0) {
                it2->second--;
                bool allchecked = true;
                for (auto it3 = visited.begin(); it3 != visited.end(); it3++) {
                    if (it3->second) {
                        allchecked = false;
                        bool good = check(var, it3->first, visited);
                        if (good) {
                            //std::cout << it->first << " " << it->second << std::endl;
                            return good;
                        }
                    }
                }
                
                return allchecked;
            }
            else {
                return false;
            }
        }
    }
}

void solve(std::string files[144], int c) {
    int totalLetters = 0;
    int letters = 0;
    std::map<int, std::vector<int>> mp;
    for (int i = 0; i < c; i++) {
        mp[files[i].size()].push_back(i);
        totalLetters += files[i].size();
    }
    letters = totalLetters / (c / 2);
    std::set<std::string> vars;

    for (int i = 0; i < c; i++) {
        auto matches = mp.find(letters - files[i].size());
        for (int j = 0; j < matches->second.size(); j++) {
            std::string var = files[i] + files[matches->second[j]];
            vars.insert(var);
        }
    }
    std::map<std::string, int> visited;
    for (int i = 0; i < c; i++) {
        visited[files[i]]++;
    }
    bool res = false;
    for (auto it = vars.begin(); it != vars.end(); it++) {
        for (int i = 0; i < c; i++)
        {
            res = check(*it, files[i], visited);
            if (res) {
                std::cout << *it << std::endl;
                return;
            }
        }
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
        if (i) std::cout << std::endl;
        std::string files[144];
        std::string buffer;
        int c = 0;
        while (istr.good()) {
            std::getline(istr, buffer);
            if (buffer.empty()) {
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