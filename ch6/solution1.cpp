#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void solve(string &a, string &b) {

}

int main(void) {

#if __GNUC__
    istream& istr = cin;

#else
    ifstream istr(R"(C:\fedosin\repos\ski\ch6\test1.txt)");
#endif
    string a, b;
    while (1) {
        istr >> a >> b;
        if (a == "0" && b == "0") {
            break;
        }
        solve(a, b);
    }

    return 0;
}