#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
 

struct sum {
    int val;
    int idx1, idx2;
};

bool check(vector<sum> &vvec, int idx, vector<int> terms) {
    if (idx >= vvec.size()) {
        return true;
    }
    if (vvec[idx].val != (terms[vvec[idx].idx1] + terms[vvec[idx].idx2])) {
        return false;
    }
    if (idx < vvec.size() - 2) {
        terms.push_back(vvec[idx + 1].val - terms[vvec[idx + 1].idx1]);
    }
    return check(vvec, idx+1, terms);
}

void solve(vector<sum> vvec, int n) {
    std::sort(vvec.begin(), vvec.end(), [](sum& s1, sum& s2) {return s1.val < s2.val; });
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            vvec[k].idx1 = i;
            vvec[k++].idx2 = j;
        }
    }
    int num = vvec[0].val / 2 + 1;
    for (int i = 1; i < num; i++) {
        int a = i;
        int b = vvec[0].val - a;
        vector<int> terms;
        terms.push_back(a);
        terms.push_back(b);
        if (check(vvec, 0, terms)) {
            
        }
    }
}
int main(void) {

#if __GNUC__
    std::istream& istr = cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch5\test.txt)");
#endif
    while (1) {
        int n;
        istr >> n;
        if (!istr.good()) {
            break;
        }
        int N = n * (n - 1) / 2;
        vector<sum> vvec;
        for (int i = 0; i < N; i++) {
            int buf;
            istr >> buf;
            sum s;
            s.val = buf;
            vvec.push_back(s);
        }
    
        solve(vvec, n);
    }

    return 0;
}