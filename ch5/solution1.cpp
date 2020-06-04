#include <iostream>
#include <fstream>
#include <string>


using namespace std;
void solve(const string& d1, const string& s2) {

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