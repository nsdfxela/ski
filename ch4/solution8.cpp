#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct game {
    static game parse(const std::string& str) {
        auto p1 = str.find('#');
        game g;
        g.t1 = str.substr(0, p1);
        auto p2 = str.find('@', p1);
        std::string s1 = str.substr(p1+1, p2 - p1-1);
        auto p3 = str.find('#', p2);
        std::string s2 = str.substr(p2 + 1, p3 - p2 - 1);
        g.t2 = str.substr(p3+1);
        
        g.s1 = atoi(s1.c_str());
        g.s2 = atoi(s2.c_str());
        return g;
    }
    std::string t1, t2;
    int s1, s2;
};
struct tournament {
    std::string name;
    std::vector<std::string> teams;
    std::vector<game> games;
};
int main(void) {
#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch4\test.txt)");
#endif
    int tc;
    istr >> tc;
    istr.ignore();
    for (int i = 0; i < tc; i++) {
        tournament t;
        std::getline(istr, t.name);
        int nt;
        istr >> nt;
        istr.ignore();
        for (int j = 0; j < nt; j++) {
            std::string buffer;
            std::getline(istr, buffer);
            t.teams.push_back(buffer);
        }
        int ng;
        istr >> ng;
        istr.ignore();
        for (int j = 0; j < ng; j++) {
            std::string buffer;
            std::getline(istr, buffer);
            t.games.push_back(game::parse(buffer));
        }
    }
    return 0;
}