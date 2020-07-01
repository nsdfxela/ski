#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void solve(int n) {

}

int main(void) {
    /*uva 10198*/
#if __GNUC__
    istream& istr = cin;
#else
    ifstream istr (R"(C:\fedosin\repos\ski\ch6\test3.txt)");
#endif
    while (true)
    {
        int n;
        istr >> n;
        if (!istr.good()) {
            break;
        }
        solve(n);
    }
    return 0;
}