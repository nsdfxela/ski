#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <climits>


void solve(std::vector<int> &vec) {
    std::sort(vec.begin(), vec.end());
    std::stringstream ss;
    int sum = 0;
    while (vec.size() >= 4) {
        auto A = vec.begin();
        auto B = A + 1;
        auto a = vec.end()-1;
        auto b = a - 1;
        // A + a, A, A + b, A
        int str1 = *a + *A + *b + *A;
        //A + B, A, a + b, B
        int str2 = *B + *A + *b + *B;
        if (str1 < str2) {
            ss << *A << ' ' << *a << std::endl;
            ss << *A << std::endl;
            ss << *A << ' ' << *b << std::endl;
            vec.erase(a);
            vec.erase(b);
            sum += str1;
        } else {
            ss << *A << ' ' << *B << std::endl;
            ss << *A << std::endl;
            ss << *a << ' ' << *b << std::endl;
            ss << *B << std::endl;
            vec.erase(a);
            vec.erase(b);
            sum += str2;
        }
    }
    switch (vec.size()) {
    case 3:
        sum += vec[2];
        sum += vec[0];
        sum += vec[1];
        ss << vec[0] << ' ' << vec[2] << std::endl << vec[0] << std::endl;
        ss << vec[0] << ' ' << vec[1] << std::endl;
        break;
    case 2:
        sum += vec[1];
        ss << vec[0] << ' ' << vec[1] << std::endl;
        break;
    case 1:
        sum += vec[0];
        ss << vec[0] << std::endl;
        break;
    }

    std::cout << sum << std::endl << ss.str();
}

//1
//30
//31
//32
//15
//99

/*
1
2
5
10*/

/*
1 5
1
1 10
1
1 2*/


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
        if (i) {
            std::cout << std::endl;
        }
        std::vector<int> vec;
        int n;
        istr >> n;
        vec.reserve(n);
        for (int j = 0; j < n; j++) {
            int m;
            istr >> m;
            vec.push_back(m);
        }
        solve(vec);
        istr.ignore();
    }


    return 0;
}