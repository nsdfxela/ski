#include <iostream>
#include <fstream>

int main(void) {

#if defined(__GNUC__)
    std::istream &istr = std::cin;
#else
    std::ifstream istr(R"(D:\study\ski\ch2\test.txt)", std::ios::in);
#endif

    return 0;
}