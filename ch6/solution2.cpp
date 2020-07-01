#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

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
            ai = a.val[a.length() - i-1] - '0';
        }
        int bi = 0;
        if (i < b.length()) {
            bi = b.val[b.length() - i-1] - '0';
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
    } else if (b.length() < a.length()) {
        return false;
    }
    for (int i = 0; i < a.length(); i++) {
        if(a.val[i] > b.val[i]) return false;
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
        if (idxs >=0 && idxs < s.length()) {
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
            char rc = ((r + rem) % 10  + '0');
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


longint fact(longint x) {
    if(x.val == "0") return longint( "1");
    if (x.val == "1") return longint("1");
    if (x.val == "2") return longint("2");

    
    longint sp ("1");
    longint one ("1");
    longint res ("1");
    do {
        res = mult(res, sp);
        sp = add(sp, one);
    } while (sp.val != x.val);
    res = mult(res, sp);
    return res;
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
            res.push_back(n+'0');
            d.clear();    
            d = v.val;
        } else {
            res.push_back('0');
        }
    }
    
    return trimz(res);
}

longint fact(longint from, longint to) {
    longint res("1");
    from = add(from, longint("1"));
    while (from.val != to.val) {
        res = mult(res, from);
        from = add(from, longint("1"));
    }
    res = mult(res, from);
    return res;
}

longint Cnk(longint n, longint k) {
    
    return  div(fact(sub(n,k), n), fact(k));
    //return div(fact(n), mult(fact(k), fact(sub(n, k))));
}

void solve(const string &v) {
    if (v == "0") {
        cout << "1" << endl;
        return;
    }
    if (v == "1") {
        cout << v << endl;
        return;
    }
    if (v == "2") {
        cout << v << endl;
        return;
    }
    if (v == "3") {
        cout << "4" << endl;
        return;
    }

    longint cn2 = Cnk(v, longint("2"));
    longint cn4 = Cnk(v, longint("4"));
    longint one ("1");

    longint result = add(one, cn2);
    result = add(result, cn4);
    cout << result.val << endl;
}

int main(void) {

    /*longint a = "15015";
    longint b("15", 1);
    longint c = div(a, b);*/

   /* longint a = "20";
    longint b("2", 1);
    longint c = div(a, b);*/

    /*longint a = "2798944";
    longint b("188", 1);
    longint c = div(a, b);*/
   
   /* longint a = "199";
    longint b ("2", 1);
    longint c = add(a, b);
    longint d = Cnk(longint("120"), longint("4"));*/
#if __GNUC__
    istream& istr = cin;
#else
    ifstream istr(R"(C:\fedosin\repos\ski\ch6\test2.txt)");
#endif
    int N;
    istr >> N;
    for (int i = 0; i < N; i++) {
        string buf;
        istr >> buf;
        solve(buf);
    }
    return 0;
}