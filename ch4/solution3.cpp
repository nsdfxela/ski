#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <climits>


void solve(std::vector<int> &vec) {
    std::sort(vec.begin(), vec.end());
    std::vector<int> otherSide;
    std::stringstream ss;
    int sum = 0;
    int min = vec.front();
    int c1 = 0; int c2 = 0;
    while (!vec.empty()) {
        if (!otherSide.empty()) {
            auto ob = otherSide.begin();
            vec.push_back(*ob);
            ss << *ob << std::endl;
            sum += *(ob);
            otherSide.erase(ob);

            auto c1i = std::find(vec.begin(), vec.end(), c1);
            if (c1i != vec.end() && vec.size() > 3) {
                auto c2i = std::find(vec.begin(), vec.end(), c2);
                if (c2i != vec.end()) {
                    sum += *c1i;
                    otherSide.push_back(*c2i);
                    sum += *c2i;
                    ss << c1 << ' ' << c2 << std::endl << c1 << std::endl;
                    vec.erase(c2i);
                }
            }
        }
        auto iter = vec.begin();
        if (!c1) { c1 = *iter; }
        otherSide.push_back(*iter);
        int s1 = INT_MIN, s2 = INT_MIN;
        ss << *(iter); 
        s1 = *(iter);
        if (iter + 1 != vec.end()) {
            ss << ' ' << *(iter + 1);
            s2 = *(iter + 1);
            if (!c2) { c2 = *(iter + 1); }
            otherSide.push_back(*(iter + 1));
            vec.erase(iter + 1);
            vec.erase(iter);
        }
        else {
            vec.erase(iter);
        }
        sum += std::max(s1, s2);
        ss << std::endl;
        std::sort(otherSide.begin(), otherSide.end());        
    }
    std::cout << sum << '\n' << ss.str();
}

//1
//30
//31
//32
//15
//99

/*
1
2
5
10*/

/*
1 5
1
1 10
1
1 2*/


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
        std::vector<int> vec;
        int n;
        istr >> n;
        vec.reserve(n);
        for (int j = 0; j < n; j++) {
            int m;
            istr >> m;
            vec.push_back(m);
        }
        solve(vec);
        istr.ignore();
    }


    return 0;
}