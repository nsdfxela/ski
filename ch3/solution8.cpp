#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

void solve(const std::vector<std::string>& data, const std::vector<int> canDeleteEndl) {

    std::ostringstream oss;
    int ossSize = 0;
    for (int i = 0; i < data.size(); i++) {
        std::string s;
        s = data[i];

        std::istringstream sstr(s);
        std::string buffer;
        int leadingSpaces = 0;
        auto lpc = -1;
        for (int c = 0; c < s.size(); c++) {
            if (s[c] == ' ') {
                lpc++;
                continue;
            }
            break;
        }

        while (1) {
            if (lpc) {
                for (int i = 0; i < lpc; i++) {
                    if (oss.str().size() > 72) {
                        std::cout << oss.str() << std::endl;
                        std::swap(oss, std::ostringstream());
                        ossSize = 0;
                    }
                    oss << ' ';
                    ossSize++;
                }
                lpc = 0;
            }
            if (!sstr.good()) { //this is line end
                if (!canDeleteEndl[i]) {
                    std::cout << oss.str() << std::endl;
                    std::swap(oss, std::ostringstream());
                    ossSize = 0;
                }
                break;
            }
            std::getline(sstr, buffer, ' ');
            if (buffer.empty()) {
                continue;
            }
            
            if (ossSize + buffer.size() < 72) {
                if (ossSize) {
                    oss << ' ';
                    ossSize++;
                }
                oss << buffer;
                ossSize += buffer.size();
            } else {
                std::cout << oss.str() << std::endl;
                oss.swap(std::ostringstream());
                oss << buffer;
                ossSize = buffer.size();
            }
            
        }
    }
}

void checkEndl(const std::vector<std::string>& data, std::vector<int> &canDeleteEndl) {
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