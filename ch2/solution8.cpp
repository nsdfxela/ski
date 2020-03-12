#include <iostream>
#include <fstream>

/*2.8.8 Uva 10149 Yahtzee*/

int main(int arch, char **argv) {

#if __GNUC__
    std::ifstream istr(R"(D:\study\ski\ch2\test.txt)");
#else 
    std::istream &istr = std::cin;
#endif



    return 0;
}