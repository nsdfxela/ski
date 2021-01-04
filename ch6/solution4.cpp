#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <unordered_map>


using namespace std;
unordered_map<int, int> mem;
int countCatalans(int n) {
    const int c0 = 1;
    if (!n ) { return c0; }
    if (mem.find(n) != mem.end()) 
    {
        return mem[n];
    }
    int res = 0;
    for (int k = 0; k <= n - 1; k++) {
        int a = countCatalans(k);
        int b = countCatalans(n-1-k);
        res += a * b;
    }
    mem[n] = res;
    return res;
}
void solve(int n, int d) {
    //n 2-300   
    //d 1-150
    

}
int main(void) {
    std::cout << countCatalans(300) << "\n";
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