#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>

/*2.8.8 Uva 10149 Yahtzee*/

int uniques(int *arr, int val) {
    std::map<int, int> mp;
    for (int i = 0; i < 5; i++)
        mp[arr[i]]++;
    if (std::any_of(mp.begin(), mp.end(), [val](std::pair<int, int> v) { return v.second == val; })) {
        return std::accumulate(arr, arr + 5, 0);
    }
    else {
        return 0;
    }
}

struct p_ord {
    int idx;
    int val;
    p_ord() {
        idx = 0;
        val = 0;
    }
    p_ord(int v) : val{ v } {

    }
    bool operator==(int other) {
        return val == other;
    }
};

void solve(int game[13][5]) {
    p_ord table[13][13];
    for (int i = 0; i < 13; i++) { //iterate over throws
        table[i][0] = std::count(std::begin(game[i]), std::end(game[i]), 1);
        table[i][1] = std::count(std::begin(game[i]), std::end(game[i]), 2);
        table[i][2] = std::count(std::begin(game[i]), std::end(game[i]), 3);
        table[i][3] = std::count(std::begin(game[i]), std::end(game[i]), 4);
        table[i][4] = std::count(std::begin(game[i]), std::end(game[i]), 5);
        table[i][5] = std::count(std::begin(game[i]), std::end(game[i]), 6);
        table[i][6] = std::accumulate(std::begin(game[i]), std::end(game[i]), 0);
        table[i][7] = uniques(game[i], 3);
        table[i][8] = uniques(game[i], 4);
        int u5 = uniques(game[i], 4);
        table[i][9] = u5 ? 50 : 0;

        std::vector<int> street{1,2,3,4,5,6};
        /*std::sort(std::begin(game[i]), std::end(game[i]));        */

        int str_cnt = std::count(table[i], table[i]+5, 1);
        if (str_cnt == 4) { 
            table[i][10] = 25; 
            table[i][11] = 0;
        }
        else if (str_cnt == 5) {
            table[i][10] = 25;
            table[i][11] = 35;
        }
        else {
            table[i][10] = 0;
            table[i][11] = 0;
        }

        if (uniques(game[i], 3) && uniques(game[i], 2)) {
            table[i][12] = 40;
        }
        else {
            table[i][12] = 0;
        }
        for (int k = 0; k < 13; k++) {
            table[i][k].idx = k;
        }
        std::sort(table[i], table[i] + 13, [](p_ord &p1, p_ord &p2) { return p1.val > p2.val; });
    }


    std::cout << "done";
}


void clear(int game[13][5]) {
    for (int i = 0; i < 13; i++) {
        memset(game[i], 0, 5 * sizeof(int));
    }
}
int main(int arch, char **argv) {

#if __GNUC__
    std::istream &istr = std::cin;
#else 
    std::ifstream istr(R"(D:\study\ski\ch2\test.txt)");
#endif

    int game[13][5];
    clear(game);
    std::string buf;
    int iter = 0;
    while (true) {
        std::getline(istr, buf);
        if (buf.empty()) { break; }
        
        std::stringstream ss(buf);
        for (int i = 0; i < 5; i++) {
            ss >> game[iter][i];
        }

        ++iter;
        iter %= 13;
        if (!iter) {
            solve(game);
            clear(game);
        }
    }


    return 0;
}