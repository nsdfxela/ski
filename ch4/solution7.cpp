#include <iostream>
#include <string>
#include <fstream>


int main(void) {
#if __GNUC__
    std::istream& istr = std::cin;
#else 
    std::fstream istr(R"(C:\fedosin\repos\ski\ch4\test.txt)");
#endif
    return 0;
}