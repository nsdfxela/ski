#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;
int countd(long long int n) {
    long long int d = n, c = 0;
    do {
        d = d / 10;
        c++;
    } while (d);
    return c;
}
void solve(int n) {
    int c = countd(n);
    int mc = c + 1;
    long long int md = n;
    for (int i = 0; i < mc; i++) { md *= 10; }
    int minp = ceil(log2(md));
    long long int p = (long long int)1 << minp;
    int E = minp;
    while (1) {
        int cd = countd(p) - c;
        long long int D = pow(10, cd);
        long long int rem = p % D;
        if (p - rem == n * D) {
            std::cout << E << '\n';
            break;
        }
        else {
            p = p << 1;
            E++;
            if (E == 64) {
                cout << "no power of 2\n";
                return;
            }
        }
    }

}

int main(void) {

#if __GNUC__
    std::istream& istr = cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch5\test.txt)");
#endif
    int n;
    while (1) {
        istr >> n;
        if (!istr.good()) {
            break;
        }
        solve(n);
    }
    return 0;

}