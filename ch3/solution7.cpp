#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int distance(const std::string& str1, const std::string& str2) {
    int sz = str1.size() < str2.size() ? str1.size() : str2.size();
    int res = 0;
    for (int i = 0; i < sz; i++) {
        if (str1[i] != str2[i]) {
            res++;
        } 
        if (res > 1) {
            res = 100;
        }
    }
    return res;
}
std::vector<std::string> dict;
void solve(const std::string& str1, const std::string& str2) {
    int ds = dict.size();
    int** tbl;
    tbl = new int* [ds];
    for (int i = 0; i < ds; i++) {
        tbl[i] = new int[ds];
        memset(tbl[i], 0, ds * sizeof(int));
    }
    for (int i = 0; i < ds; i++) {
        for (int j = 0; j < ds; j++) {
            tbl[i][j] = distance(dict[i], dict[j]);
            std::cout << tbl[i][j] << "   ";
        }

        std::cout << std::endl;
    }

    for (int i = 0; i < ds; i++) {
        delete [] tbl[i];
    }
    delete[] tbl;
}

int main(void) {

#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch3\test.txt)");
#endif
    while (1) {
        std::string buf;
        std::getline(istr, buf);
        if (!istr.good() || buf.empty()) {
            break;
        }
        dict.push_back(buf);
    }
    std::string str1, str2;
    while (istr.good()) {
        istr >> str1 >> str2;
        if (istr.good()) {
            solve(str1, str2);
        }
    }

    return 0;
}