#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

struct val {
    map<int, int> powers;
    int coeff = 0;
    string to_str() {
        std::stringstream ss;
        for (auto it = powers.begin(); it != powers.end(); it++) {
            ss << "x" << it->first << "^(" << it->second << ")";
        }
        return ss.str();
    }
};

val operator *(val &v1, val&v2) {
    val v;
    for (auto it = v1.powers.begin(); it != v1.powers.end(); it++) {
        v.powers[it->first] = it->second;
    }
    for (auto it = v2.powers.begin(); it != v2.powers.end(); it++) {
        v.powers[it->first] += it->second;
    }
    v.coeff = v1.coeff * v2.coeff;
    return v;
}


void solve(const vector<int>&poly, int n) {
    map<string, val> m;
    for (int i = 0; i < poly.size(); i++) {
        val v;
        v.powers[i] = 1;
        v.coeff = 1;
        m[v.to_str()] = v;
    }

    map<string, val> m2;
    for (auto it = m.begin(); it != m.end(); it++) {
        for (auto it2 = m.begin(); it2 != m.end(); it2++) {
            auto v = it->second * it2->second;
            if (m2.find(v.to_str()) == m2.end()) {
                m2[v.to_str()] = v;
            }
            else {
                m2[v.to_str()].coeff += v.coeff;
            }
        }
    }
}

int main(void) {
#if __GNUC__
    istream& istr = cin;
#else
    ifstream istr(R"(C:\fedosin\repos\ski\ch5\test.txt)");
#endif
    while (1) {
        int n, k;
        istr >> n >> k;
        if (!istr.good()) {
            break;
        }
        int intb;
        vector<int> poly;
        for (int i = 0; i < k; i++) {
            istr >> intb;
            poly.push_back(intb);
        }
        solve(poly, n);
    }

    return 0;
}