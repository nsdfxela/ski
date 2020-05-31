#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

struct turt {
    std::string name;
    int order = 0;
};

typedef std::vector<turt> turtles;
void solve(turtles& o, turtles &w) {

}
int main(void) {
#if __GNUC__
    std::istream& istr = std::cin;
#else 
    std::fstream istr(R"(C:\fedosin\repos\ski\ch4\test.txt)");
#endif
    int tc;
    istr >> tc;
    for (int i = 0; i < tc; i++) {
        int num;
        istr >> num;
        turtles Torigin, Twanna;
        istr.ignore();
        std::map<std::string, int> tmap;
        for (int j = 0; j < num; j++) {
            turt t;
            std::getline(istr, t.name);
            Torigin.push_back(t);
            tmap[t.name] = j;
        }
        for (int j = 0; j < num; j++) {
            turt t;
            std::getline(istr, t.name);
            t.order = j;
            Torigin [tmap[t.name]].order = j;
            Twanna.push_back(t);
        }
        solve(Torigin, Twanna);

    }

    return 0;
}