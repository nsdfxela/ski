#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
//10202	Pairsumonious Numbers	Accepted
using namespace std;

typedef vector<int> inp;
int find_sorted(inp &in, int val) {
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == val) {
            return i;
        }
        else if (in[i] > val) {
            return -1;
        }
    }
    return -1;
}

bool check(inp cvvec, vector<int>& terms) {
    for (int i = 0; i < terms.size(); i++) {
        for (int j = i+1; j < terms.size(); j++) {
            int f = find_sorted(cvvec, terms[i] + terms[j]);
            if (f < 0) 
                return false;
            cvvec.erase(cvvec.begin() + f);
        }
    }
    return true;
}
bool check(inp cvvec, vector<int> &terms, int i, int j, int n, inp &origin) {
    if (check(origin, terms)) {
        if (terms.size() == n) {
            for (int l = 0; l < terms.size(); l++) {
                if (l) std::cout << " ";
                std::cout << terms[l];
            }
            std::cout << "\n";
            return true;
        }
    }
    else {
        return false;
    }
    //auto found = std::find(cvvec.begin(), cvvec.end(), terms[i] + terms[j]);
    int found = find_sorted(cvvec, terms[i] + terms[j]);
    if (found < 0) { return false; }
    
    cvvec.erase(cvvec.begin() + found);
    
    if (++j >= n) {
        i++;
        j = i + 1;
    }

    if (terms.size() < n) {
        for (int _i = 0; _i < cvvec.size(); _i++) {
            int newVal = cvvec[_i] - terms[i];
           
            auto t = terms;
            t.push_back(newVal);
            if (check(cvvec, t, i, j, n, origin)) {
                return true;
            }
        }
    } else {
        return check(origin, terms);
    }
    return false;
}

void solve(inp vvec, int n) {
    std::sort(vvec.begin(), vvec.end());
    int k = 0;
    
    int num = vvec[0] / 2;
    
    if (!num) num = vvec[0];
    num = num < 0 ? num - 1 : num + 1;
    
    int a, b, c;
    bool res = false;
    
    for (int i = abs(vvec[0]); i >= -abs(vvec[0]); i--) {
        a = i;
        b = vvec[0] - a;
        c = vvec[1] - a;
        vector<int> terms;
        terms.reserve(n);
        terms.push_back(a);
        terms.push_back(b);
        terms.push_back(c);

        //std::sort(terms.begin(), terms.end());
        
        inp cvvec;
        set <int>ch;
        std::copy(vvec.begin() + (terms.size()-2), vvec.end(), std::back_inserter(cvvec));
        if (check(cvvec, terms, 0, terms.size() - 1, n, vvec)) {
            res = true;
            break;
        }
    }
    if (!res) {
        std::cout << "Impossible\n";
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


