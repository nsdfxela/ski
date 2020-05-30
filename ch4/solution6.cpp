#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

/*Uv 10138*/

struct tme {
    int get_min() const {
        return min + h * 60 + d * 24 * 60;
    }
    std::string _str;
    static tme parse(const std::string &str) {
        tme t;
        t._str = str;
        std::stringstream ss(str);
        ss >> t.M; 
        ss.ignore();
        ss >> t.d;
        ss.ignore();
        ss >> t.h;
        ss.ignore();
        ss >> t.min;
        return t;
    }
    int M, d, h, min;
};

struct photo {
    bool visisted = false;
    static photo parse(const std::string str) {
        photo np;
        std::stringstream ss(str);
        std::string buf;
        std::getline(ss, buf, ' ');
        np.plt = buf;
        std::getline(ss, buf, ' ');
        np.time = tme::parse(buf);
        std::getline(ss, buf, ' ');
        np.type = buf;
        ss >> np.pos;
        return np;
    }
    std::string plt;
    std::string type;
    tme time;
    int pos;
};


bool operator < (const tme& t1, const tme& t2) {
    return t1.get_min() < t2.get_min();
}

bool operator < (const photo &p1, const photo &p2) {
    if (p1.plt < p2.plt) {
        return true;
    } else if (p1.plt > p2.plt) {
        return false;
    }
    else {
        return p1.time < p2.time;
    }
}

typedef std::vector<photo> photos;
#include <map>
std::map<std::string, int> M;
void solve(std::vector<int> &pr, photos& ph) {
    std::sort(ph.begin(), ph.end());
    for (int i = 0; i < ph.size(); i++) {
        if (ph[i].visisted) {
            continue;
        }
        auto sp = i;
        if (ph[sp].type == "enter") {
            continue;
        }
        int fp = -1;
        for (int j = sp-1; j >= 0; j--) {
            if (ph[j].plt == ph[sp].plt &&
                ph[j].type == "enter") {
                fp = j;
                ph[j].visisted = true;
                break;
            }
            else if (ph[j].plt != ph[sp].plt) {
                break;
            }
            else if (ph[j].type == "exit") {
                break;
            }
        }
        if (fp < 0) {
            continue;
        }
        int distance = std::abs(ph[sp].pos - ph[fp].pos);
        int price = pr[ph[fp].time.h];
        int total = price * distance + 100;
        
        M[ph[fp].plt] += total;
    }
    for (auto it = M.begin(); it != M.end(); it++) {
        int total = it->second + 200;
        int cents = total % 100;
        std::string s_cents;
        if (cents < 10) {
            s_cents = '0';
        }
        s_cents += std::to_string(cents);
        std::cout << it->first << ' ' << '$' << total / 100 << '.' << s_cents << std::endl;
    }
    M.clear();
    
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
            std::cout << std::endl;
        }
        std::vector<int> pr;
        photos ph;
        pr.reserve(24);
        for (int j = 0; j < 24; j++) {
            int h;
            istr >> h;
            pr.push_back(h);
        }
        std::string buffer;
        istr.ignore();
        while (1) {
            std::getline(istr, buffer);
            if (buffer.empty()) {
                break;
            }
            ph.push_back(photo::parse(buffer));
            if (!istr.good()) {
                break;
            }
        }
        solve(pr, ph);
    }

    return 0;
}