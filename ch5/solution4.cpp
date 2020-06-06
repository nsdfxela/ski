#include <cmath>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
#if __GNUC__
    istream& istr = cin;
#else
    ifstream istr(R"(C:\fedosin\repos\ski\ch5\test.txt)");
#endif

    return 0;
}