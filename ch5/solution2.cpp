#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

//10018	Reverse and Add

using namespace std;
string strfy(unsigned long v) {
    stringstream ss;
    ss << v;
    string s;
    return ss.str();
}
long destrfy(const string &str) {
    stringstream ss(str);
    unsigned long v;
    ss >> v;
    return v;
}

bool ispoly(unsigned long v) {
    auto s = strfy(v);
    int j;
    for (int i = 0; i < s.size(); i++) {
        j = s.size() - 1 - i;
        if (j <= i) {
            break;
        }
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

string reverse_s(string& str) {
    string res = str;
    std::reverse(res.begin(), res.end());
    return res;
}
long reverse_l(unsigned long n) {
    string s = strfy(n);
    return destrfy(reverse_s(s));
}

void solve(unsigned long v) {
    unsigned long v1 = v;
    int counter = 0;

    if (ispoly(v1)) {
        std::cout << counter << " " << v << std::endl;
        return;
    }
    for (int i = 0; i < 1000; i++) {
        unsigned long v2 = reverse_l(v1);
        unsigned long p = v1 + v2;
        counter++;
        if (!ispoly(p)) {
            
            v1 = p;
        } else {
            std::cout << counter << " " << p << std::endl;
            return;
        }
    }
}
int main(void) {
#if __GNUC__
    istream& istr = cin;
#else
    ifstream istr(R"(C:\fedosin\repos\ski\ch5\test.txt)");
#endif

    int tc;
    istr >> tc;
    for (int i = 0; i < tc; i++) {
        unsigned long v;
        istr >> v;
        solve(v);
    }
    return 0;
}