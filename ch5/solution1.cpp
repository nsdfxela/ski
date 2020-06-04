#include <iostream>
#include <fstream>
#include <string>


using namespace std;
void solve(const string& d1, const string& d2) {
    int o = 0;
    int res = 0;
    for (int i = 0; ; i++) {
        int i1 = d1.size() - 1 - i;
        int i2 = d2.size() - 1 - i;
        if (i1 < 0 && i2 < 0) {
            break;
        }
        int v1 = i1 < 0 ? 0: d1[i1] - '0';
        int v2 = i2 < 0 ? 0: d2[i2] - '0';
        int sum = v1 + v2 + o;
        o = sum / 10;
        if (o) { res++; }
    }
    if (!res) {
        std::cout << "No carry operation.\n";
    }
    else if (res == 1) {
        std::cout << "1 carry operation.\n";
    }
    else {
        std::cout << res << " carry operations.\n";
    }
}
int main(void) {
#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch5\test.txt)");
#endif
    std::string buf, buf1, buf2;
    
    do {
        std::getline(istr, buf);
        if (buf == "0 0") {
            break;
        }
        auto pos = buf.find(' ');
        buf1 = buf.substr(0, pos);
        buf2 = buf.substr(pos+1);
        solve(buf1, buf2);
    } while (1);
    return 0;
}