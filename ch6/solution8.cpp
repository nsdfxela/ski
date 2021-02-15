#include <iostream>
#include <string>
#include <fstream>
#include <vector>

/* 846 - Steps */
/* https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=34&page=show_problem&problem=787 */

void solve(int a, int b) {

}

//1 2 3 4 3 2 1  1 - 17, 7
//1 2 3 3 3 2 1  1 - 16, 7
//1 2 3 3 2 2 1  1 - 15, 7
//1 2 3 3 2 1 1  1 - 14, 7
//1 2 3 3 2 1    1 - 13, 6
//1 2 3 2 2 1    1 - 12, 6
//1 2 3 2 1 1    1 - 11, 6
//1 2 3 2 1      1 - 10, 5
//1 2 2 2 1      1 - 9, 5
//1 2 2 1 1      1 - 8, 5
//1 2 2 1        1 - 7, 4
//1 2 1 1        1 - 6, 4
//1 2 1          1 - 5, 3
//1 1 1          1 - 4, 3
//1 1            1 - 3, 2
//1              1 - 2, 1
//
//1 1 2 2 3 3 4

int main(void) {
#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch6\test8.txt)");
#endif
    int num; 
    istr >> num;
    istr.ignore(1);
    for (int i = 0; i < num; i++) {
        int a, b;
        istr >> a >> b;
        solve(a, b);
    }
    return 0;
}