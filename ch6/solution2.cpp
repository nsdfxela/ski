#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void solve(int v) {


}

int main(void) {
#if __GNUC__
    istream& istr = cin;
#else
    ifstream istr(R"(C:\fedosin\repos\ski\ch6\test2.txt)");
#endif
    int N;
    istr >> N;
    for (int i = 0; i < N; i++) {
        int buf;
        istr >> buf;
        solve(buf);
    }
    return 0;
}