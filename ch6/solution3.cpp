#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
/*uva 10198*/

/*
    Long arithmetics is copy-pasted from previous exercise solution

*/
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
    int length() {
        return val.length();
    }
    longint() {

    }
    longint(const std::string& v, int s = 1) : val{ v }, sign{ s } {

    }
};

longint add(longint a, longint b) {
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

longint mult(longint a, longint b)
{
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

vector<longint> vec;
void fill() {
    vec.reserve(1001);
    vec.emplace_back("2");
    vec.emplace_back("5");
    vec.emplace_back("13");
    for (int i = vec.size(); i < 1001; i++) {
        longint nv = vec[i - 1] + vec[i - 3];
        nv = nv + vec[i - 2];
        nv = nv + vec[i - 1];
        vec.push_back(nv);
    }
}

void solve(int n) {
    if (vec.empty()) {
        fill();
    }
    std::cout << vec[n - 1].val << endl;
}

int main(void) {
#if __GNUC__
    istream& istr = cin;
#else
    ifstream istr(R"(C:\fedosin\repos\ski\ch6\test3.txt)");
#endif
    while (true)
    {
        int n;
        istr >> n;
        if (!istr.good()) {
            break;
        }
        solve(n);
        
    }
    return 0;
}