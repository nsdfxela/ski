#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


void solve(std::vector<int>& v) {


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