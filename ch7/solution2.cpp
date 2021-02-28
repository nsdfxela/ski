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
int checkKM(int a, int n) {
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
    int res = cur;
    for (int i = leftover; i >= 1; i--) {
        if (results.find(i) != results.end() && leftover >= i) {
            leftover -= i;
            l.push_back(results[i]);
        }
        else {
           // std::cout << "err!";
        }
    }
    for (int i = 0; i < l.size(); i++) {
        res *= l[i];
    }
    return res%n;
}
void solve(int v) {
    int i = 3;
    bool c = false;
    for (; i < v; i++) {
        int r = checkKM(i, v);
        if (r != i) {
            c = true;
        }
        else {
            c = false;
            std::cout << v << " is normal.\n";
            break;
        }
    }
    if (c) {
        std::cout << "The number " << v << " Carmicheal normal.\n";
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