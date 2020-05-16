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
        std::vector<int> tcase;
        while (1) {
            int val;
            ss >> val;
            tcase.push_back(val);
            if (!ss.good()) {
                break;
            }
        }
        solve(tcase);
        
    }

    return 0;
}