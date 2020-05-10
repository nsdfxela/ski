#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>

bool doublets(const std::string& str1, const std::string& str2) {
    if (str1.size() != str2.size()) {
        return false;
    }
    int res = 0;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[i]) {
            res++;
            if (res > 1) {
                return false;
            }
        } 
    }
    return res == 1;
}

#include <queue>
#include <set>
bool bfs(int a, int b, int *path, std::vector<std::string> dict) {
    std::queue<int> q;
    q.push(a);
    std::set<int> visited;
    while (!q.empty()) {
        int e = q.front();
        q.pop();
        if (e == b) {
            return true;
        }
        visited.insert(e);
        for (int i = 0; i < dict.size(); i++) {
            if (doublets(dict[i], dict[e]) && visited.find(i) == visited.end()) {
                q.push(i);
                visited.insert(i);
                path[i] = e;
            }
        }
    }
    return false;
}

int main(void) {

#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch3\test.txt)");
#endif
    std::vector<std::string> odict, dict;
    while (1) {
        std::string buf;
        std::getline(istr, buf);
        if (!istr.good() || buf.empty()) {
            break;
        }
        odict.push_back(buf);
    }
    std::string str1, str2;
    int tc = 0;
    while (istr.good()) {
        dict = odict;
        istr >> str1 >> str2;
        dict.push_back(str1);
        dict.push_back(str2);
        if (istr.good()) {
            if (tc++) {
                std::cout << std::endl;
            }
            int* path = new int[dict.size()];
            memset(path, -1, dict.size() * sizeof(int));
            int s = dict.size() - 2;
            int t = dict.size() - 1;
            bool foundPath = bfs(s, t, path, dict);
            if (!foundPath) {
                std::cout << "No solution." << std::endl;
                continue;
            }
            int cur = path[t];
            std::vector<int> vpath;
            vpath.push_back(t);

            do {
                vpath.push_back(cur);
                cur = path[cur];
            } while (cur > 0);
            for (auto it = vpath.rbegin(); it != vpath.rend(); it++) {
                std::cout << dict[*it] << std::endl;
            }
            
        }
    }

    return 0;
}