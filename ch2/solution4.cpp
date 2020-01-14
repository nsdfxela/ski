#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

struct wrd 
{
    std::string str;
    std::string fp;
    std::map<char, int> d;
    wrd(const std::string &s) : str{ s } {
        for (int i = 0; i < s.length(); i++) {
            d[s[i]]++;
        }
        std::vector<int> frq;
        std::transform(d.begin(), d.end(), std::back_inserter(frq), [](std::pair<char, int> p) -> int { return p.second; });
        std::sort(frq.begin(), frq.end());
        fp.resize(frq.size());
        std::ostringstream os;
        for (int i = 0; i < frq.size(); i++) {
            os << frq[i];
        }
        fp = os.str();
    }
    
};

std::map<std::string, std::vector<wrd>> lc;


std::string solve(const std::vector<std::string> &src) {
   
    wrd w(src[0]);
    for (int i = 0; i < src.size(); i++) {
        
    }
    return "";
}

int main(void) {

#if defined(__GNUC__)
    std::istream &istr = std::cin;
#else
    std::ifstream istr(R"(D:\study\ski\ch2\test.txt)", std::ios::in);
#endif
    int wc;
    istr >> wc;
    std::string dict[1000];
    for (int i = 0; i < wc; i++) {
        istr >> dict[i];
        wrd w(dict[i]);
        lc[w.fp].push_back(w);
    }
    istr.ignore(1);

    while (istr) {
        std::string buf;
        std::getline(istr, buf);
        std::stringstream ss(buf);
        std::vector<std::string> vec;
        while (ss) {
            std::string w;
            ss >> w;
            vec.push_back(w);
        }
        std::cout << solve(vec);
        std::cout << '\n';
        
    }
    return 0;
}