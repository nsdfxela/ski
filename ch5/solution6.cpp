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
typedef map<string, val> P;
void mult() {

}

P operator * (P& p1, P& p2) {
    P p;
    for (auto it = p1.begin(); it != p1.end(); it++) {
        for (auto it2 = p2.begin(); it2 != p2.end(); it2++) {
            auto v = it->second * it2->second;
            if (p.find(v.to_str()) == p.end()) {
                p[v.to_str()] = v;
            }
            else {
                p[v.to_str()].coeff += v.coeff;
            }
        }
    }
    return p;
}

void solve(const vector<int>&monom, int n) {
    P m;
    for (int i = 0; i < monom.size(); i++) {
        val v;
        v.powers[i] = 1;
        v.coeff = 1;
        m[v.to_str()] = v;
    }
    P res = m;
    for (int i = 0; i < n-1; i++) {
        res = res * m;
    }

    val monom_val;
    for (int i = 0; i < monom.size(); i++) {
        if (monom[i]) {
            monom_val.powers[i] = monom[i];
        }
    }
    std::cout << res[monom_val.to_str()].coeff << std::endl;
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