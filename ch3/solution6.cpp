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
    int tb;
    istr >> tb;
    istr.ignore(2);
    for (int i = 0; i < tb; i++) {
        std::vector<int> files[144];
        std::string buffer;
        int c = 0;
        while (1) {
            std::getline(istr, buffer);
            if (!istr.good() || buffer.empty()) {
                break;
            }
            for (int j = 0; j < buffer.size(); j++) {
                if (buffer[j] == '1') files[c].push_back(1);
                else if (buffer[j] == '0') files[c].push_back(0);
                else break;
            }
            c++;

        }
    }
    return 0;
}