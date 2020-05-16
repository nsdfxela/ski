#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

void solve(std::vector<int>& v) {
    int res = 0;
    std::sort(v.begin(), v.end());
    if (v.size() % 2 == 0) {
        res = v[v.size() / 2];
    }
    else {
        int i = v.size() / 2;
        res = v[i];
    }
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += std::abs(v[i] - res);
    }
    std::cout << sum << std::endl;
}

int main(void) {

#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch4\test.txt)");
#endif
    int tc;
    istr >> tc;
    istr.ignore();
    for (int i = 0; i < tc; i++) {
        std::string buf;
        std::getline(istr, buf);
        std::stringstream ss(buf);
        int num;
        ss >> num;
        std::vector<int> tcase;
        for (int j = 0; j < num; j++) {
            int r;
            ss >> r;
            tcase.push_back(r);
        }
        solve(tcase);
        
    }

    return 0;
}