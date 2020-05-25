#include <iostream>
#include <fstream>
#include <vector>


struct ord {
    int days;
    int fine;
};

typedef std::vector<ord> ords;

void solve(ords& O) {

}

int main(void) {

#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch4\test.txt)");
#endif
    int tc;
    istr >> tc;
    istr.ignore();
    for (int i = 0; i < tc; i++) {
        int nords;
        istr >> nords;
        ords o;

        for (int j = 0; j < nords; j++) {
            ord c;
            istr >> c.days;
            istr >> c.fine;
            o.push_back(c);
        }
        solve(o);

    }

    return 0;
}