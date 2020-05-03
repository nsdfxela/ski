#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>

void solve(const std::string& a, const std::string& b, std::vector<char> &sol) {
    std::map<char, int> amap, bmap;
    std::set<char> aset, bset;
    for (int i = 0; i < a.size(); i++) {
        amap[a[i]]++;
        aset.insert(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        bmap[b[i]]++;
        bset.insert(b[i]);
    }
    
    std::set <char> inter;
    std::set_intersection(aset.begin(), aset.end(), bset.begin(), bset.end(), std::inserter(inter, inter.begin()));
    for (auto it = inter.begin(); it != inter.end(); it++) {
        int n = std::min(amap[*it], bmap[*it]);
        for (int i = 0; i < n; i++) {
            sol.push_back(*it);
        }
    }

    std::sort(sol.begin(), sol.end());
}

int main(void) {

#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch3\test.txt)");
#endif
    

    while (1) {
        std::string a, b;
        std::getline(istr, a);
        std::getline(istr, b);
        std::vector<char> solution;
        solve(a, b, solution);
        for (int i = 0; i < solution.size(); i++) {
            std::cout << solution[i];
        }
        if (!istr.good()) { break; }
        std::cout << "\n";
    }

    return 0;
}