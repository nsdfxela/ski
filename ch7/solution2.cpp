#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>


//10006	Carmichael Numbers
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=947

//a^n mod n == a
//17 : 4 ^ 17 mod 17 == 4 
//4^1 mod 17 = 4
//4^2 mod 17 = 16
//4^4 mod 17 = 16*16 mod 17 = 1
//4^8 mod 17 = 1 mod 17
//4^16 mod 17 = 1 mod 17 = 1
//4^17 mod 17 = 4^16 * 4^1 mod 17 = 4

//246^1729 mod 1729 == 246
//246^1 mod 1729 = 246
//246^2 mod 1729 = 1
//246^4 mod 1729 = 1
//246^8 mod 1729 = 1
//246^16 mod 1729 = 1
//...
//246^1024 mod 1729 = 1
//246^1024 * 246^705 = 246^512*246^128*246^64*246^1
bool isprime(int v) {
    if (v == 2)return true;
    int l = ceil(std::sqrt(v));
    for (int i = 2; i < l; i++) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}



int checkKM(int a, int n, std::map<int, int> &results) {
    unsigned int cur = a % n;
    results[1] = cur;
    int pw = 2;
    for (; pw < n; pw *= 2) {
        cur = (cur * cur) % (unsigned int)n;
        results[pw] = cur;
    }
    int leftover = n - pw / 2;
    std::vector<int> l;
    unsigned int res = cur;
    //for (int i = leftover; i >= 1; i--) {
    for(auto it = results.rbegin(); it != results.rend() && leftover; it++){
        int f = it->first;
        int s = it->second;
        while (leftover >= f) {
            leftover -= f;
            l.push_back(s);
        }

        //if (results.find(i) != results.end() && leftover >= i) {
        //    leftover -= i;
        //    l.push_back(results[i]);
        //}
        //else {
        //   // std::cout << "err!";
        //}
    }
    for (int i = 0; i < l.size(); i++) {
        res = res * l[i]%n;
    }
    return res%n;
}

//NOTE:
//CM numbers are always non-prime, so we can skip all the prime numbers
void solve(int v) {
    bool prm = isprime(v);
    if (prm) {
        std::cout << v << " is normal.\n";
        return;
    }
    int i = 3;
    bool c = false;
    std::map<int, int> che;
    for (; i < v; i++) {
        che.clear();
        int r = checkKM(i, v, che);
        if (r == i) {
            c = true;
        }
        else {
            c = false;
            break;
        }
    }
    if (c) {
        std::cout << "The number " << v << " is a Carmichael number.\n";
    }
    else {
        std::cout << v << " is normal.\n";
    }
}
int main(void) {
   // checkKM(4, 17);
    //solve(62745);
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