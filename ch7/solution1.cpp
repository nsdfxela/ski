#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <set>

// 10110 - Light, more light
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=35&page=show_problem&problem=1051

typedef unsigned long int mint;

void solve(mint v) {
    auto sceil = (mint)ceill(std::sqrt(v));
    if (sceil*sceil == v)
    {
        std::cout << "yes";
    }
    else {
        std::cout << "no";
    }
    std::cout << '\n';

}

    //1 yes 
    //1 2 no
    //1 3 no
    //1 2 4 yes
    //1 5 no
    //1 2 3 6 no
    //1 7 no
    //1 2 4 8 no
    //1 3 9 yes
    //1 2 5 10 no
    //1 11 no
    //1 2 3 4 6 12 no
    //1 13 no
    //1 2 7 14 no
    //1 3 5 15 no
    //1 2 4 8 16 yes
    //1 17 no
    //1 2 3 6 9 18 no
    //1 19 no
    //1 2 4 5 10 20 no
    //1 3 7 21 no
    //1 11 22 no
    //1 23 no
    //1 2 3 4 6 8 12 24 no
    //1 5 25 yes

int main(void) {
    //solve(2147483648ul);
    //solve(8);
    /*solve(4);*/

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