#include <fstream>
#include <string>
#include <iostream>
#include <vector>


int main(void) {

#if __GNUC__
    std::istream& istr = std::cin;
#else 
    std::ifstream istr (R"("C:\fedosin\repos\ski\ch4\test.txt")");
#endif

    return 0;
}