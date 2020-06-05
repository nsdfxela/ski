#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void solve(int n) {

}

int main(void) {

#if __GNUC__
    std::istream& istr = cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch5\test.txt)");
#endif
    int n;
    while (1) {
        istr >> n;
        if (!istr.good()) {
            break;
        }
        solve(n);
    }
    return 0;

}