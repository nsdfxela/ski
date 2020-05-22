#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

void solve(std::vector<int> &vec) {
    std::sort(vec.begin(), vec.end());

}

//1
//3
//4
//15
//99

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
        std::vector<int> vec;
        int n;
        istr >> n;
        vec.reserve(n);
        for (int j = 0; j < n; j++) {
            int m;
            istr >> m;
            vec.push_back(m);
        }
        solve(vec);
        istr.ignore();
    }


    return 0;
}