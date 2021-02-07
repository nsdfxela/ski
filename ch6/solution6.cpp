#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

/*
    Long arithmetics is copy-pasted from previous exercise solutions (and extended here)
*/
////// Long arithmetics starts here \/
//////////////////////////////////////////
string trimz(string a) {
    auto pos = a.find_first_not_of('0');
    if (pos == string::npos) {
        return "0";
    }
    else {
        return a.substr(pos);
    }
}

struct longint {
public:
    string val = "";
    int sign = 1;
    int length() const {
        return val.length();
    }
    longint() {

    }
    longint(const std::string& v, int s = 1) : val{ v }, sign{ s } {

    }
    longint(int intv) {
        std::stringstream ss;
        ss << intv;
        std::string strv = ss.str();
        int sgn = 1;
        if (strv.size() && strv[0] == '-') {
            sgn = -1;
            strv = strv.erase(0, 1);
        }
        val = strv;
        sign = sgn;
    }
    bool operator!()
    {
        return !(val.empty() || val == "0");
    }
};

longint add(const longint& a, const longint& b) {
    int s = a.length() > b.length() ? a.length() : b.length();
    vector<char> res;
    int rem = 0;
    for (int i = 0; i < s; i++) {
        int ai = 0;
        if (i < a.length()) {
            ai = a.val[a.length() - i - 1] - '0';
        }
        int bi = 0;
        if (i < b.length()) {
            bi = b.val[b.length() - i - 1] - '0';
        }

        int c = ai + bi + rem;
        res.push_back(c % 10 + '0');
        rem = c / 10;
    }
    res.push_back(rem + '0');
    reverse(res.begin(), res.end());
    res.push_back('\0');


    longint result;
    result.val = res.data();
    return trimz(result.val);
}

bool long_less(longint a, longint b) {
    a = trimz(a.val);
    b = trimz(b.val);
    if (a.length() < b.length()) {
        return true;
    }
    else if (b.length() < a.length()) {
        return false;
    }
    for (int i = 0; i < a.length(); i++) {
        if (a.val[i] > b.val[i]) return false;
        if (a.val[i] < b.val[i]) return true;
    }
    return false;
}

longint sub(longint a, longint b) {
    bool a_lesser_than_b = long_less(a, b);
    longint s = a_lesser_than_b ? a : b;
    longint l = a_lesser_than_b ? b : a;
    string resstr;
    for (int i = 0; i < l.length(); i++) {
        int idxl = l.length() - 1 - i;
        int idxs = s.length() - 1 - i;
        int ln = l.val[idxl] - '0';
        int sn = 0;
        if (idxs >= 0 && idxs < s.length()) {
            sn = s.val[idxs] - '0';
        }
        if (ln < sn) {
            l.val[idxl - 1] --;
            ln += 10;
        }
        resstr.push_back((ln - sn) + '0');
    }
    reverse(resstr.begin(), resstr.end());
    auto pos = resstr.find_first_not_of('0');
    if (pos == string::npos) {
        return longint("0");
    }
    return longint(resstr.substr(pos));
}

longint mult(const longint& a, const longint& b)
{
    string k1 = a.val + " " + b.val;
    string k2 = b.val + " " + a.val;

    int r;
    int zeros = 0;
    longint total;
    total.val = "0";
    for (int j = b.length() - 1; j >= 0; j--) {
        longint sr;

        int rem = 0;
        for (int i = a.length() - 1; i >= 0; i--) {
            r = (a.val[i] - '0') * (b.val[j] - '0');
            char rc = ((r + rem) % 10 + '0');
            rem = (r + rem) / 10;
            sr.val.push_back(rc);
        }
        if (rem) {
            sr.val.push_back(rem + '0');
        }
        std::reverse(sr.val.begin(), sr.val.end());
        for (int k = 0; k < zeros; k++) {
            sr.val.push_back('0');
        }
        zeros++;
        total = add(total, sr);
    }
    return total;
}

longint div(longint a, longint b) {
    string d = "";
    string res;
    for (int i = 0; i < a.length(); i++) {
        if (d.empty() && a.val[i] == '0') {
            res.push_back('0');
            continue;
        }
        d.push_back(a.val[i]);
        if (!long_less(d, b)) {
            longint v = d;
            int n = 0;
            do {
                v = sub(v, b);
                n++;
            } while (!long_less(v, b));
            res.push_back(n + '0');
            d.clear();
            d = v.val;
        }
        else {
            res.push_back('0');
        }
    }

    return trimz(res);
}



longint operator+(longint& a, longint& b) {
    longint res = add(a, b);
    return res;
}

bool operator<(const longint& a, const longint& b) {
    return long_less(a, b);
}

bool operator==(const longint& a, const longint& b) {
    return (a.sign == b.sign) && (a.val == b.val);
}

bool operator<=(const longint& a, const longint& b) {
    return (a < b) || (a == b);
}

longint longpow(longint n, longint pow)
{
    if (pow == 0) { return 1; }
    longint res = n;
    for (longint i = 1; i < pow; i = add(i, 1)) {
        res = mult(res, n);
    }
    return res;
}

longint factorial(const longint& n) {
    longint a = 1;
    longint res = 1;
    while (a <= n) {
        res = mult(res, a);
        a = add(a, 1);
    }
    return res;
}

std::ostream& operator<< (std::ostream& st, const longint& n) {
    return st << n.val;
}

////// Long arithmetics ends here /\
//////////////////////////////////////////


int cnt = 0;
void basicHanoi(int n, int from, int to, int buffer) {
    if (!n) { return; }
    basicHanoi(n-1, from, buffer, to);
    //std::cout << cnt++ << ": " <<  from << "->" << to << '\n';
    cnt++;
    basicHanoi(n - 1, buffer, to, from);
}



std::vector<longint> D(10001);

longint advancedHanoi(int n, int k)
{
    if (D[n].sign > 0) { return D[n]; }

    longint ah = advancedHanoi(k, k);
    
    return mult(ah, 2) + sub(longpow(2, sub(n, k)), 1);
}

longint advancedHanoi(int n)
{
    if (D[n].sign > 0) { return D[n]; }

    longint minval("", -1);
    for (int k = 1; k < n; k++) {
        auto h = advancedHanoi(n, k);
        if (minval.val == "" || h < minval) {
            minval = h;
        }
    }
    D[n] = minval;
    return minval;
}

void solve(int n) {


}

int main() {
    longint m1;
    m1.sign = -1;
    m1.val = "1";
    std::fill(D.begin(), D.end(), m1);
    D[0] = 0;
    D[1] = 1;
    D[2] = 3;
    D[3] = 5;

    
    for (int i = 1; i < 10000; i++) {
        std:cout << sub(advancedHanoi(i), advancedHanoi(i-1)) << '\n';
    }
#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch6\test6.txt)");
#endif

    int n;
    while (true) {
        istr >> n;
        if (!istr) {
            break;
        }
        solve(n);
    }

    return 0;
}