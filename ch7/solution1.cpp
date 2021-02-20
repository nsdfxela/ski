#include <iostream>
#include <vector>
#include <fstream>

// 10110 - Light, more light
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=35&page=show_problem&problem=1051

typedef unsigned long int mint;

void solve(mint v) {


}
int main(void) {

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