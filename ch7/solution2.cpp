#include <iostream>
#include <fstream>
#include <vector>
#include <string>


void solve(int v) {


}
int main(void) {
#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch7\test2.txt)");
#endif
    int buf=0;
    do {
        istr >> buf;
        if (!buf) { break; }
        solve(buf);
    } while (1);

    return 0;
}