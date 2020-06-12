#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

struct val {  
    int powers[12];
    long long int hash = 0;
    val() {
        memset(powers, 0, sizeof(int) * 12);
    }
    val(int s) {
        memset(powers, 0, sizeof(int) * 12);
        for (int i = 0; i < s; i++) {
            hash += pow((long long int)10, (long long int)i);
            powers[i] = 1;
        }
    }
    int coeff = 0;
    
};
int S[12];
val operator *(val &v1, val&v2) {
    val v;
    memcpy(v.powers, v1.powers, sizeof(int) * 12);
    for(int i = 0; i < 12; i++){
        v.powers[i] += v2.powers[i];
    }
    v.hash = v1.hash + v2.hash;
    v.coeff = v1.coeff * v2.coeff;
    return v;
}
typedef unordered_map<long long int, val> P;

#include <cassert>
P multiply (P& p1, P& p2, vector<int> monom) {
    P p;
    for (auto it = p1.begin(); it != p1.end(); it++) {
        for (auto it2 = p2.begin(); it2 != p2.end(); it2++) {
            auto v = it->second * it2->second;
            bool omit = false;
            for (int k = 0; k < monom.size(); k++) {
                if (v.powers[k] > monom[k]) {
                    omit = true;
                    break;
                }
            }
            if (omit) { 
                continue;
            }
            long long key = v.hash;
            assert(v.hash > 0);
            
            val &vf = p[key];
            v.coeff += vf.coeff;
            swap(vf, v);

            /*if (pv == p.end()) {
                p[key] = v;
            }
            else {
                p[key].coeff += v.coeff;
            }*/
        }
    }
    return p;
}

void solve(const vector<int>&monom, int n) {
    P m;

    for (int i = 0; i < monom.size(); i++) {
        val v;
        v.powers[i] = 1;
        v.hash = pow(10, i);
        v.coeff = 1;
        m[v.hash] = v;
    }
    P res = m;
    for (int i = 0; i < n-1; i++) {
        res = multiply(res, m, monom);
    }

    long long int searching_monom_val=0;
    for (int i = 0; i < monom.size(); i++) {
        if (monom[i]) {
            searching_monom_val += monom[i] * pow(10, i);
        }
        
    }
    std::cout << res[searching_monom_val].coeff << std::endl;
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