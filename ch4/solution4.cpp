#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

struct hour {
    static hour parse(const std::string& str) {
        hour res;
        std::stringstream ss(str);
        ss >> res.h;
        ss.ignore();
        ss >> res.m;
        return res;
    }
    hour(int hour, int minute) : h{ hour }, m{ minute } {

    }
    hour() {

    }
    int h;
    int m;
};
bool operator <(const hour& h1, const hour& h2) {
    if (h1.h == h2.h) {
        return (h1.m < h2.m);
    }
    else {
        return h1.h < h2.h;
    }
}

struct app {
    hour start;
    hour end;
    std::string val;
};

bool operator < (const app& a1, const app& a2) {
    return a1.end < a2.end;
}

hour operator - (const hour &h1, const hour& h2) {
    hour result;
    result.m = h1.m - h2.m;
    result.h = h1.h - h2.h;
    if (result.m < 0) {
        result.h--;
        result.m += 60;
    }
    return result;
}

typedef std::vector<app> day;

void solve(day &d) {
    std::sort(d.begin(), d.end());

    hour e{ 18, 0 };
    hour s{ 18, 0 };

    hour diff{ 0,0 };
    for (int i = d.size()-1; i >=0 ; i--) {
        auto ndiff = e - d[i].end;
        if (diff < ndiff) {
            diff = ndiff;
        }
        e = d[i].start;
    }
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