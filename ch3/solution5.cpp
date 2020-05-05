#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

std::set<char> digits{ '0', '1', '2', '3', '4', '5', '6', '7','8','9' };


int checkPe(std::string &s, std::string& a) {
    std::vector<int> vs, va;
    for (int j = 0; j < s.size(); j++) {    
        if (digits.find(s[j]) != digits.end()) {
            vs.push_back((int)s[j] - 48);
        }
    }

    for (int j = 0; j < a.size(); j++) {
        if (digits.find(a[j]) != digits.end()) {
            va.push_back((int)a[j] - 48);
        }
    }

    if (vs.size() == va.size() && std::equal(vs.begin(), vs.end(), va.begin())) {
        return 1;
    }
    else {
        return 2;
    }
}
int solve(std::vector<std::string>& s, std::vector<std::string>& a) {
    int result = 0;
    //0 accepted 1 presentation 2 error
    if (a.size() != s.size()) {
        std::stringstream ssa, sss;
        for (int i = 0; i < a.size(); i++) {
            ssa << a[i];
        }
        for (int i = 0; i < s.size(); i++) {
            sss << s[i];
        }
        std::string ssas = ssa.str();
        std::string ssss = sss.str();
        return checkPe(ssas, ssss);
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != a[i]) {
            std::stringstream ssa, sss;
            for (int _i = 0; _i < a.size(); _i++) {
                ssa << a[_i];
            }
            for (int _i = 0; _i < s.size(); _i++) {
                sss << s[_i];
            }
            std::string ssas = ssa.str();
            std::string ssss = sss.str();

            return checkPe(ssas, ssss);
        }
        
    }
    return result;
}

int main(void) {

#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch3\test.txt)");
#endif

    std::string buffer;
    int run = 0;
    while (true) {
        std::vector<std::string> sol;
        std::vector<std::string> ans;
        
        std::getline(istr, buffer);
        if (!istr.good() || buffer == "0") break;
        std::stringstream ss(buffer);
        int c1;
        ss >> c1;
        ss.clear();
        for (int i = 0; i < c1; i++) {
            std::getline(istr, buffer);
            sol.push_back(buffer);
        }
        int c2;
        istr >> c2;
        istr.ignore();
        for (int i = 0; i < c2; i++) {
            std::getline(istr, buffer);
            ans.push_back(buffer);
        }
        int result = solve(sol, ans);
        std::cout << "Run #" << ++run << ": ";
        switch (result) {
        case 0:
            std::cout << "Accepted";
            break;
        case 1:
            std::cout << "Presentation Error";
            break;
        case 2:
            std::cout << "Wrong Answer";
            break;
        }
        std::cout << std::endl;
    }

    return 0;
}