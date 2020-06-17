#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef vector<int> inp;
bool check(inp cvvec, vector<int> &terms, int i, int j, int n) {
    auto found = std::find(cvvec.begin(), cvvec.end(), terms[i] + terms[j]);
    if (found == cvvec.end()) {
        return false;
    }
    if (i == n - 2 && j == n - 1) {
        for (int l = 0; l < terms.size(); l++) {
            if (l) std::cout << " ";
            std::cout << terms[l];
        }
        std::cout << "\n";
        return true;
    }
    cvvec.erase(found);
    
    if (++j >= n) {
        i++;
        j = i + 1;
    }

    if (terms.size() < n) {
        for (int _i = 0; _i < cvvec.size(); _i++) {
            auto t = terms;
            t.push_back(cvvec[_i] - terms[i]);
            if (check(cvvec, t, i, j, n)) {
                return true;
            }
        }
    } else {
        return check(cvvec, terms, i, j, n);
    }
    return false;
}

void solve(inp vvec, int n) {
    std::sort(vvec.begin(), vvec.end());
    int k = 0;
    
    int num = vvec[0] / 2 + 1;
    int a, b, c;
    for (int i = 1; i <= num; i++) {
        a = i;
        b = vvec[0] - a;
        
        vector<int> terms;
        terms.push_back(a);
        terms.push_back(b);
        for (int j = 0; j < n - 3; j++) {
            terms.push_back(vvec[1 + j] - a);
        }
        
        
        inp cvvec;
        std::copy(vvec.begin() + (terms.size()-2), vvec.end(), std::back_inserter(cvvec));
        if (check(cvvec, terms, 0, terms.size() - 1, n)) {

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
        inp vvec;
        for (int i = 0; i < N; i++) {
            int buf;
            istr >> buf;
            vvec.push_back(buf);
        }
    
        solve(vvec, n);
    }

    return 0;
}


