#include <iostream>
#include <fstream>
#include <string>

int numbers[3000];
int n;

bool read_data(std::istream &istr) 
{
    istr >> n;
    if (!istr) return false;
    for (int i = 0; i < n; i++) {
        istr >> numbers[i];
    }
    return true;
}

std::string solve() {
    int p = -1;
    for (int i = 0; i < n-1; i++) {
        int m = abs (numbers[i + 1] - numbers[i]);
        if (i && abs(m - p) != 1) {
            return "Not jolly";
        }
        if (!i && m != 1) {
            return "Not jolly";
        }
        p = m;
    }
    return "Jolly";
}

int main(void) {
    std::ifstream istr(R"(D:\study\ski\ch2\test.txt)", std::ios::in);
    while (read_data(istr)) {
        std::cout << solve() << std::endl;
    }

    return 0;
}