#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void solve(int k, int d) {

}
int main(int argc, char**argv) {

#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr (R"(C:\fedosin\repos\ski\ch6\test5.txt)");
#endif
    int k, d;
    while (true) {
        istr >> k >> d;
        if (!istr) { break; }
        solve(k, d);
    }

    return 0;
}