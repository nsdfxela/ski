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
    istr.ignore(1);
    for (int i = 0; i < tc; i++) {
        int m, n;
        istr >> m >> n;
        istr.ignore(1);
        std::string grid[50];
        for (int i = 0; i < m; i++) {
            std::string buffer;
            std::getline(istr, grid[i]);
        }
        int k;
        istr >> k;
        std::string words[20];
        istr.ignore(1);
        for (int i = 0; i < k; i++) {
            std::getline(istr, words[i]);
        }
    }
    

    


    
    return 0;
}