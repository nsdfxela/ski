#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

struct ord {
    int days;
    int fine;
    int idx;
};

typedef std::vector<ord> ords;

/*
1 2
2 5
10 1

1 1
*/

int getFine(ords& O) {
    int tf = 0;
    int days = 0;

    for (int i = 0; i < O.size(); i++) {
        tf += days * O[i].fine;
        days += O[i].days;
    }
    return tf;
}

bool eqFrq(int e1, int d1, int e2, int d2) {
    return (e1 * d2 == e2 * d1);
}

void solve(ords& O) {
    
    std::sort(O.begin(), O.end(), [](ord& o1, ord& o2) {
        if (eqFrq(o1.fine, o1.days, o2.fine, o2.days)) {
            return std::to_string(o1.idx) < std::to_string(o2.idx);
        }
        return (float)o1.fine / o1.days > (float)o2.fine / o2.days;
    });
    int thirdWay = getFine(O);
    for (int i = 0; i < O.size(); i++) {
        if (i) {
            std::cout << ' ';
        }
        std::cout << O[i].idx;
    }
    std::cout << std::endl;
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
            c.idx = j + 1;
            o.push_back(c);
        }
        solve(o);

    }

    return 0;
}