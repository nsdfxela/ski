#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>


struct hour {
    static hour parse(const std::string& str) {
        hour res;
        std::stringstream ss(str);
        ss >> res.h;
        ss.ignore();
        ss >> res.m;
        return res;
    }
    int h;
    int m;
};

struct app {
    hour start;
    hour end;
    std::string val;
};

typedef std::vector<app> day;

void solve(day &d) {

}

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
        day apps;
        for (int i = 0; i < napp; i++) {
            std::getline(istr, buffer);
            std::string stime = buffer.substr(0, 5);
            std::string etime = buffer.substr(6, 5);
            std::string app_str = buffer.substr(12);
            app a;
            a.start = hour::parse(stime);
            a.end = hour::parse(etime);
            a.val = app_str;
            apps.push_back(a);
        }
        solve(apps);
    }
    return 0;
}