#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>

int cnt = 0;
void basicHanoi(int n, int from, int to, int buffer) {
    if (!n) { return; }
    basicHanoi(n-1, from, buffer, to);
    std::cout << cnt++ << ": " <<  from << "->" << to << '\n';
    
    basicHanoi(n - 1, buffer, to, from);
}

void solve(int n) {


}

int main() {
    basicHanoi(8, 0, 2, 1);
#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch6\test6.txt)");
#endif

    int n;
    while (true) {
        istr >> n;
        if (!istr) {
            break;
        }
        solve(n);
    }

    return 0;
}