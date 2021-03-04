#include <iostream>
#include <fstream>
#include <string>

//10104 - Euclid Problem
//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=10457

void solve(int a, int b) {

}

int main(void) {
#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr (R"(C:\fedosin\repos\ski\ch7\test3.txt)");
#endif
    int a, b;
    while (1) {
        istr >> a >> b;
        if (!istr.good()) {
            break;
        }
        solve(a, b);
    }
    return 0;
}