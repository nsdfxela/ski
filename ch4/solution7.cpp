#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

/*10152	ShellSort*/
struct turt {
    std::string name;
    int order = 0;
};

bool operator < (const turt& t1, const turt& t2) {
    return t1.order > t2.order;
}

#include <set>
typedef std::vector<turt> turtles;
std::map<int, int> order_to_pos;
void solve(turtles& o, turtles &w) {
    if (w.empty()) {
        return;
    }
    int last = w.back().order;
    std::set<int> fr;
    while (last > 0 && order_to_pos[last - 1] < order_to_pos[last]) {
        fr.insert(last);
        last = last - 1;
    }
    fr.insert(last);
    turtles res;
    for (int i = 0; i < o.size(); i++) {
        if (fr.find(o[i].order) == fr.end()) {
            res.push_back(o[i]);
        }
    }
    std::sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i].name << std::endl;
    }
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
        if (i) {
            std::cout << std::endl;
        }
        int num;
        std::map<std::string, int> tmap;
        istr >> num;
        turtles Torigin, Twanna;
        istr.ignore();
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
            Torigin[tmap[t.name]].order = j;
            order_to_pos[j] = tmap[t.name];
            Twanna.push_back(t);
        }
        solve(Torigin, Twanna);
        tmap.clear();
        order_to_pos.clear();
    }
    std::cout << std::endl;
    return 0;
}