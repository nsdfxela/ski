#include <iostream>
#include <fstream>
#include <string>
#include <set>

int numbers[3000];
int n;
std::set<int> s;

bool read_data(std::istream &istr) 
{
    s.clear();
    istr >> n;
    if (!istr) return false;
    for (int i = 0; i < n; i++) {
        istr >> numbers[i];
    }
    return true;
}
#define NJ "Not jolly"
#define J "Jolly"
std::string solve() {
    int p = -1;
    for (int i = 0; i < n-1; i++) {
        int m = abs (numbers[i + 1] - numbers[i]);
        /*if (i && abs(m - p) != 1) {
            return "Not jolly";
        }*/
        s.insert(m);
        p = m;
    }

    for (int i = 1; i <= n-1; i++) {
        if (s.find(i) == s.end()) {
            return NJ;
        }
    }
    return J;
}

int main(void) {
    //std::istream &istr = std::cin;
    std::ifstream istr(R"(D:\study\ski\ch2\test.txt)", std::ios::in);
    while (read_data(istr)) {
        std::cout << solve() << std::endl;
    }

    return 0;
}