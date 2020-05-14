#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

void solve(const std::vector<std::string>& data, const std::vector<int> canDeleteEndl) {

    int ossSize = 0;
    std::ostringstream oss;
    for (int i = 0; i < data.size(); i++) {
        std::ostringstream word;
        for (int j = 0; j < data[i].size(); j++) {
            if (data[i][j] == ' ' ) {
                if (word.str().size()) {
                    if (oss.str().size() + word.str().size() >= 72) {
                        std::cout << oss.str() << std::endl;
                        oss.swap(std::ostringstream());
                    }
                    oss << word.str();
                    word.swap(std::ostringstream());
                }
                if (oss.str().size() + 1 >= 72) {
                    std::cout << oss.str() << std::endl;
                    oss.swap(std::ostringstream());
                }
                oss << ' ';
            }
            else {
                word << data[i][j];
            }
        }
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