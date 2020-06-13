#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(void) {

#if __GNUC__
    std::istream& istr = cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch5\test.txt)");
#endif

    return 0;
}