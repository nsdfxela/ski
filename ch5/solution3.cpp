#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main(void) {

#if __GNUC__
    std::istream& istr = cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch5\test.txt)");
#endif

    return 0;

}