#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include <sstream>


struct tme {
    static tme parse(const std::string &str) {
        tme t;
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
    tme time;
    std::string type;
    int pos;
};
typedef std::vector<photo> photos;

void solve(photos& ph) {

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
            if (!istr.good() || buffer.empty()) {
                break;
            }
            ph.push_back(photo::parse(buffer));
        }
        solve(ph);

    }

    return 0;
}