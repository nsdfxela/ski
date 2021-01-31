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
    //std::cout << cnt++ << ": " <<  from << "->" << to << '\n';
    cnt++;
    basicHanoi(n - 1, buffer, to, from);
}

void advancedHanoi(int k, int n, int from, int to, int buffer, int buffer2) {
    if (!n) { return; }
    advancedHanoi(k, n-1, from,  buffer, buffer2, to);
    basicHanoi(n - k, from, to, buffer2);
    cnt++;
    //std::cout << cnt++ << ": " << from << "->" << to << '\n';
    advancedHanoi(k, n-1, buffer, to, from, buffer2);
}

void solve(int n) {


}

int main() {
    //basicHanoi(8, 0, 2, 1);
    advancedHanoi(2, 8, 0, 1, 2, 3);
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