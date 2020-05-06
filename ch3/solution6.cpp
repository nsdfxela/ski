#include <iostream>
#include <string>
#include <vector>
#include <fstream>



int main(void) {
#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch3\test.txt)");
#endif

    return 0;
}