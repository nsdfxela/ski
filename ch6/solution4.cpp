#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>


using namespace std;
void solve(int n, int d) {



}
int main(void) {
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