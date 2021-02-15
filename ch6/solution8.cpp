#include <iostream>
#include <string>
#include <fstream>
#include <vector>

/* 846 - Steps */
/* https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=34&page=show_problem&problem=787 */

void solve(int a, int b) {

}

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