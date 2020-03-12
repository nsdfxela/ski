#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
/*2.8.8 Uva 10149 Yahtzee*/


void solve(int game[13][5]) {

}



int main(int arch, char **argv) {

#if __GNUC__
    std::istream &istr = std::cin;
#else 
    std::ifstream istr(R"(D:\study\ski\ch2\test.txt)");
#endif

    int game[13][5];
    for (int i = 0; i < 13; i++) {
        memset(game[i], 0, 5 * sizeof(int));
    }
    std::string buf;
    int iter = 0;
    while (true) {
        std::getline(istr, buf);
        if (buf.empty()) { break; }
        
        std::stringstream ss(buf);
        for (int i = 0; i < 5; i++) {
            ss >> game[iter][i];
        }

        ++iter;
        iter %= 13;
        if (!iter) {
            solve(game);
        }
    }


    return 0;
}