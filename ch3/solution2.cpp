#include <iostream>
#include <fstream>
#include <string>

int main(void) {
#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch3\test.txt)");
#endif
    std::string buffer;
    std::getline(istr, buffer);


    
    return 0;
}