#include <iostream>
#include <string>
#include <fstream>
#include <vector>

/* 846 - Steps */
/* https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=34&page=show_problem&problem=787 */




struct lmt {
    unsigned long  from, to, val;
};
std::vector<lmt> D; 

const unsigned long MAXVAL = 2147483648ul;
void solve(int a, int b) {
    if (D.empty()) {
        D.push_back( lmt{ 2, 2, 1 } );
        D.push_back(lmt{ 3, 3, 2 });

        lmt pb;
        pb.val = 3;
        int count = 2;
        int cur = 2;
        while(D[D.size()-1].to < MAXVAL){
            
            pb.from = (D.end()-1)->to+1;
            pb.to = pb.from + cur-1;
            D.push_back(pb);
            pb.val++;
            if (--count == 0) {
                cur++;
                count = 2;
            }
        }
    }
    if (a == b) {
        std::cout << 0 << '\n';
        return;
    }
    int v = b - a + 1;
    for (int i = 0; i < D.size(); i++) {
        if (v >= D[i].from && v <= D[i].to) {
            std::cout << D[i].val << '\n';
            return;
        }
    }
}
//1 2 3 4 4 3 2 1  1 - 21, 8
//1 2 3 4 3 3 2 1  1 - 20, 8
//1 2 3 4 3 2 2 1  1 - 19, 8
//1 2 3 4 3 2 1 1  1 - 18, 8
//1 2 3 4 3 2 1    1 - 17, 7
//1 2 3 3 3 2 1    1 - 16, 7
//1 2 3 3 2 2 1    1 - 15, 7
//1 2 3 3 2 1 1    1 - 14, 7
//1 2 3 3 2 1      1 - 13, 6
//1 2 3 2 2 1      1 - 12, 6
//1 2 3 2 1 1      1 - 11, 6
//1 2 3 2 1        1 - 10, 5
//1 2 2 2 1        1 - 9, 5
//1 2 2 1 1        1 - 8, 5
//1 2 2 1          1 - 7, 4
//1 2 1 1          1 - 6, 4
//1 2 1            1 - 5, 3
//1 1 1            1 - 4, 3
//1 1              1 - 3, 2
//1                1 - 2, 1
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