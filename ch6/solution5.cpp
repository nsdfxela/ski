#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void solve(int k, int d) {

}
int main(int argc, char**argv) {

    std::ifstream istr (R"(C:\fedosin\repos\ski\ch6\test5.txt)");
    
    int k, d;
    while (true) {
        istr >> k >> d;
        if (!istr) { break; }
        solve(k, d);
    }

    return 0;
}