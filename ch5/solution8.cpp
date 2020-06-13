#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void solve(vector<int>& ns) {


}

int main(void) {

#if __GNUC__
    std::istream& istr = cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch5\test.txt)");
#endif
    while (1) {
        int n;
        istr >> n;
        if (!istr.good()) {
            break;
        }
        int N = n * (n - 1) / 2;
        vector<int> ns;
        for (int i = 0; i < N; i++) {
            int buf;
            istr >> buf;
            ns.push_back(buf);
        }
        solve(ns);
    }

    return 0;
}