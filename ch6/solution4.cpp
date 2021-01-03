#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>


using namespace std;
int countCatalans(int n, int d, int maxd) {
    const int c0 = 1;
    if (!n || d >= maxd) { return c0; }
    int res = 0;
    for (int k = 0; k <= n - 1; k++) {
        int a=1, b=1;
        if (d < maxd-1)
        {
            a = countCatalans(k, d + 1, maxd);
            b = countCatalans(n - 1 - k, d + 1, maxd);
        }
        res += a * b;
    }
    return res;
}
void solve(int n, int d) {
    //n 2-300   
    //d 1-150
    

}
int main(void) {
    std::cout << countCatalans(300, 0, 150) << "\n";
#if __GNUC__
    istream& istr = cin;
#else
    ifstream istr(R"(C:\fedosin\repos\ski\ch6\test4.txt)");
#endif
    string buffer;
    while (1) {
        getline(istr, buffer);
        if (!istr.good()) {
            break;
        } 
        if (!buffer.empty()) {
            int n, d;
            stringstream ss(buffer);
            ss >> n >> d;
            solve(n,d);
        }
    }
    return 0;
}