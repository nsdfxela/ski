#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

struct total_result {
    int w = 0;
    int t = 0;
    int l = 0;

    int scored = 0;
    int missed = 0;
    int points = 0;
    std::string team_name;
    int ssdiff = 0;
    int total_games = 0;
};
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
    std::map<std::string, total_result> teams;
    std::vector<game> games;

};

bool lessLex(const std::string &s1, const std::string &s2) {
    std::string s1u, s2u;
    s1u.resize(s1.size());
    s2u.resize(s2.size());

    std::transform(s1.begin(), s1.end(), s1u.begin(), ::toupper);
    std::transform(s2.begin(), s2.end(), s2u.begin(), ::toupper);

    return s1u < s2u;
}

bool operator < (total_result &t1, total_result& t2) {
    if (t1.points == t2.points) {
        if (t1.w == t2.w) {
            if (t1.ssdiff == t2.ssdiff) {
                if (t1.scored == t2.scored) {
                    if (t1.total_games == t2.total_games) {
                        return lessLex(t1.team_name, t2.team_name);
                    }
                    else { return t1.total_games > t2.total_games; }
                }
                else { return t1.scored < t2.scored; }
            }
            else { return t1.ssdiff < t2.ssdiff; }
        }
        else { return t1.w < t2.w; }
    } 
    else { return t1.points < t2.points; }
}

void solve(tournament& t) {
    for (int i = 0; i < t.games.size(); i++) {
        t.teams[t.games[i].t1].total_games++;
        t.teams[t.games[i].t2].total_games++;

        t.teams[t.games[i].t1].scored += t.games[i].s1;
        t.teams[t.games[i].t2].scored += t.games[i].s2;
        t.teams[t.games[i].t1].missed += t.games[i].s2;
        t.teams[t.games[i].t2].missed += t.games[i].s1;
        
        t.teams[t.games[i].t1].w += (int)(t.games[i].s1 > t.games[i].s2);
        t.teams[t.games[i].t2].w += (int)(t.games[i].s2 > t.games[i].s1);
        t.teams[t.games[i].t1].l += (int)(t.games[i].s1 < t.games[i].s2);
        t.teams[t.games[i].t2].l += (int)(t.games[i].s2 < t.games[i].s1);
        t.teams[t.games[i].t1].t += (int)(t.games[i].s1 == t.games[i].s2);
        t.teams[t.games[i].t2].t += (int)(t.games[i].s2 == t.games[i].s1);
    }

    std::vector<total_result> tr;
    tr.reserve(t.teams.size());
    for (auto it = t.teams.begin(); it != t.teams.end(); it++){
        it->second.points = it->second.w * 3 + it->second.t;
        it->second.ssdiff = it->second.scored - it->second.missed;
        tr.push_back(it->second);
    }
    std::sort(tr.begin(), tr.end());
    int rank = 1;
    for (int i = tr.size()-1; i >= 0; i--) {
        total_result& R = tr[i];
        printf("%s\n", t.name.c_str());
        printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", rank++, R.team_name.c_str(), R.points, R.total_games, R.w, R.t, R.l, R.ssdiff, R.scored, R.missed);
    }
}

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
        if (i) {
            printf("\n");
        }
        tournament t;
        std::getline(istr, t.name);
        int nt;
        istr >> nt;
        istr.ignore();
        for (int j = 0; j < nt; j++) {            
            std::string buffer;
            std::getline(istr, buffer);
            t.teams[buffer] = total_result{};
            t.teams[buffer].team_name = buffer;
        }
        int ng;
        istr >> ng;
        istr.ignore();
        for (int j = 0; j < ng; j++) {
            std::string buffer;
            std::getline(istr, buffer);
            t.games.push_back(game::parse(buffer));
        }
        solve(t);
    }
    return 0;
}