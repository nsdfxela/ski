#include <fstream>
#include <string>
#include <iostream>
#include <vector>

struct hour {
    int h;
    int m;
};
struct app {
    hour start;
    hour end;
    std::string val;
};

int main(void) {

#if __GNUC__
    std::istream& istr = std::cin;
#else 
    std::ifstream istr (R"(C:\fedosin\repos\ski\ch4\test.txt)");
#endif
    while (1) {
        int napp;
        istr >> napp;
            if (!istr.good()) {
            break;
        }
        istr.ignore();
        std::string buffer;
        for (int i = 0; i < napp; i++) {
            std::getline(istr, buffer);
        }
       
    }
    return 0;
}