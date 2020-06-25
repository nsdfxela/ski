#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

string add(string a, string b) {
    int s = a.length() > b.length() ? a.length() : b.length();
    vector<char> res;
    int rem = 0;
    for (int i = 0; i < s; i++) {
        int ai = 0;
        if (i < a.length()) {
            ai = a[a.length() - i-1] - '0';
        }
        int bi = 0;
        if (i < b.length()) {
            bi = b[b.length() - i-1] - '0';
        }
        
        int c = ai + bi + rem;
        res.push_back(c % 10 + '0');
        rem = c / 10;
    }
    reverse(res.begin(), res.end());
    res.push_back('\0');
    string result(res.data());
    return result;
}
string mult(string a, string b)
{
    int r;
    int zeros = 0;
    string total = "0";
    for (int j = b.length() - 1; j >= 0; j--) {
        string sr;

        int rem = 0;
        for (int i = a.length() - 1; i >= 0; i--) {
            r = (a[i] - '0') * (b[j] - '0');
            char rc = ((r + rem) % 10  + '0');
            rem = (r + rem) / 10;
            sr.push_back(rc);
        }
        if (rem) {
            sr.push_back(rem + '0');
        }
        std::reverse(sr.begin(), sr.end());
        for (int k = 0; k < zeros; k++) {
            sr.push_back('0');
        }
        zeros++;
        total = add(total, sr);
    }
    return total;

}
string fact(string x) {
    return "";

}
string Cnk(string n, int k) {

    return "";
}

void solve(const string &v) {


}

int main(void) {
    string a = "547";
    string b = "999";
    string c = mult(a, b);
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