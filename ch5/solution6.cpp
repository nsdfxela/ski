#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

int main(void) {
#if __GNUC__
    istream& istr = cin;
#else
    ifstream istr(R"(C:\fedosin\repos\ski\ch5\test.txt)");
#endif


    return 0;
}