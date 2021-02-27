#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

//a^n mod n == a
//17 : 4 ^ 17 mod 17 == 4 
//4^1 mod 17 = 4
//4^2 mod 17 = 16
//4^4 mod 17 = 16*16 mod 17 = 1
//4^8 mod 17 = 1 mod 17
//4^16 mod 17 = 1 mod 17 = 1
//4^17 mod 17 = 4^16 * 4^1 mod 17 = 4
void checkKM(int a, int n) {
    std::unordered_map<int, int> results;

    int cur = a % n;
    results[1] = cur;
    int pw = 2;
    for (; pw < n; pw *= 2) {
        cur = (cur * cur) % n;
        results[pw] = cur;
    }
    int leftover = n - pw / 2;
    std::vector<int> l;
    for (int i = leftover; i >= 1; i--) {
        if (results.find(i) != results.end()) {
            leftover -= i;
            l.push_back(results[i]);
        }
    }
}
void solve(int v) {
    for (int i = 3; i < v; i++) {
        checkKM(i, v);
    }
}
int main(void) {
    checkKM(4, 17);
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