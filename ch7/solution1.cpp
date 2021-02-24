#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <set>

// 10110 - Light, more light
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=35&page=show_problem&problem=1051

typedef unsigned long int mint;

void solve(mint v) {
    auto s = (mint)ceill(std::sqrt(v));
    std::set<mint> dvs;
    dvs.insert(1);
    int t = v;
    for (mint i = 2; i <= s && t != 1; i++) {
        while (t % i==0) {
            t = t / i;
            dvs.insert(i);
        }
    }
    if (v != 1)
    {
        dvs.insert(v);
    }
    if (dvs.size() % 2) {
        std::cout << "yes";
    }
    else {
        std::cout << "no";
    }
    std::cout << '\n';

}
int main(void) {
    solve(2147483648ul);
#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch7\test1.txt)");
#endif
    mint buf=0;
    do {
        istr >> buf;
        if (!buf) { break; }
        solve(buf);
    } while (1);
    return 0;
}