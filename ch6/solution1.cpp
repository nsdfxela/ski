#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
bool _less(string& a, string& b) {
    if (a.size() < b.size()) {
        return true;
    }
    else if (b.size() < a.size()) {
        return false;
    }
    else {
        for (int i = a.size() - 1; i >= 0; i --) {
            if (a[i] - '0' < b[i] - '0') {
                return true;
            }
            else if (a[i] - '0' > b[i] - '0') {
                return false;

            }
        }
    }
    return false;
}
string sum(string& a, string& b) {
    int ls = a.size() > b.size() ? a.size() : b.size();
    
    vector<char> vres;
    vres.reserve(2 * ls);
    int rem = 0;
    for (int i = 0; i < ls; i++) {
        int idxa = a.size() - 1 - i;
        int idxb = b.size() - 1 - i;
        int pa = idxa < 0 ? 0 : a[idxa] - '0';
        int pb = idxb < 0 ? 0 : b[idxb] - '0';
        int c = (pa + pb + rem)%10;
        rem = (pa + pb + rem) / 10;
        vres.push_back(c + '0');
    }
    if(rem){ vres.push_back(rem + '0'); }
    reverse(vres.begin(), vres.end());
    vres.push_back('\0');
    string res(vres.data());
    return res;
}
void inc(string& a) {
    string one = "1";
    string nv = sum(a, one);
    swap(a, nv);
}

#include <set>
void solve(string &a, string &b) {
    set<string> S;
    string na = "1";
    string nb = "1";
    string nc = sum(na, nb);
    while (_less(nc, b)) {

        S.insert(nc);
        na = nb;
        nb = nc;
        nc = sum(na, nb);
    };
}

int main(void) {

#if __GNUC__
    istream& istr = cin;

#else
    ifstream istr(R"(C:\fedosin\repos\ski\ch6\test1.txt)");
#endif
    string a, b;
    while (1) {
        istr >> a >> b;
        if (a == "0" && b == "0") {
            break;
        }
        solve(a, b);
    }

    return 0;
}