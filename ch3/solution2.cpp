#include <iostream>
#include <fstream>
#include <string>

int main(void) {
#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch3\test.txt)");
#endif
    int tc;
    istr >> tc;
    for (int i = 0; i < tc; i++) {
        istr.ignore(1);
        int m, n;
        istr >> m >> n;
        istr.ignore(1);
        std::string grid[50];
        for (int i = 0; i < m; i++) {
            std::string buffer;
            std::getline(istr, grid[i]);
        }
    }
    

    


    
    return 0;
}