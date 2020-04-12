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

void traverse(int idx, int counter) {
    static int n = 0;
    std::cout << n++ << std::endl;
    if (counter == 12) {
        //std::cout << std::endl;
        return;
    }
    //std::cout << idx << " ";
    for (int i = 0; i < 13; i++) {
        traverse(i, counter+1);

    }
}

#include <queue>
template <int nr, int nc>
bool findPath(int G[nr][nc], int path[nr], int s, int t) {
    std::queue<int> q;
    q.push(s);
    int visited[nr];    
    memset(visited, 0, sizeof(int) * nr);
    int current = s;
    visited[current] = 1;
    while (current != t) {
        if (q.empty()) {
            return false;
        }
        current = q.front();
        q.pop();
        
        for (int i = 0; i < nr; i++) {
            if (G[current][i] && !visited[i]) {
                q.push(i);
                visited[i] = 1;
                path[i] = current;
            }
        }
        
    }
    return true;
    /*int idx = nr - 1;
    std::cout << "Path is : " << idx << " ";
    do {
        
        idx = path[idx];
        std::cout << idx << " ";
    } while (idx);*/    
}

template <int nr, int nc>
int fordFulkerson(int G[nr][nc], int s, int t) {
    auto Gr = G;
    int path[nr];
    memset(path, 0, nr * sizeof(int));
    int totalFlow = 0;
    while (findPath<nr, nc>(Gr, path, s, t)) {
        int idx = t;
        int minFlow = INT_MAX;
        do {
            minFlow = std::min(Gr[path[idx]][idx], minFlow);
            idx = path[idx];            
        } while (idx);
        idx = t;
        do {
            Gr[path[idx]][idx] -= minFlow;
            Gr[idx][path[idx]] += minFlow;
            idx = path[idx];
        } while (idx);
        totalFlow += minFlow;
    }
    return totalFlow;
}

template <int nr, int nc>
int maxBipartile(int G[nr][nc]) {
    int nG[nr+2][nc+2];
    for (int i = 1; i < nr + 1; i++) {
        for (int j = 1; j < nc + 1; j++) {
            nG[i][j] = G[i - 1][j - 1];
        }
    }
    
    for (int i = 0; i < nr+2; i++) {
        nG[i][0] = 0;  nG[0][i] = 0;
        nG[i][nr + 1] = 0; nG[nr + 1][i] = 0;
    }
    return 0;
}

template<int nr, int nc>
//ROWS are games, COLS are value of a game at J position
void hungarian(int m [nr][nc]) {
    auto mc = m;
   /* int nr = 13;
    int nc = 13;*/
    for (int i = 0; i < nr; i++) {
        int min = INT_MAX;
        //searching for min
        for (int j = 0; j < nc; j++) {
            if (m[i][j] < min) {
                min = m[i][j];
            }
        }
        for (int j = 0; j < nc; j++) {
            mc[i][j] -= min;
        }
    }

    for (int j = 0; j < nc; j++) {
        int min = INT_MAX;
        for (int i = 0; i < nr; i++) {
            if (mc[i][j] < min) {
                min = mc[i][j];
            }
        }

        for (int i = 0; i < nr; i++) {
            mc[i][j] -= min;
        }
    }


}

void solve(int game[13][5]) {
    int table[13][13];
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
        
        //std::sort(table[i], table[i] + 13);
    }


    std::cout << "done";
    hungarian<13, 13>(table);
    /*for (int i = 0; i < 13; i++) {
        traverse(i, -1);
    }*/
    
}



void clear(int game[13][5]) {
    for (int i = 0; i < 13; i++) {
        memset(game[i], 0, 5 * sizeof(int));
    }
}
int main(int arch, char **argv) {

    int graph[6][6] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
    };
    std::cout << fordFulkerson<6,6>(graph, 0, 5);
    int graphBp[6][6] = { {0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {1, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 1}
    };
    std::cout << maxBipartile<6, 6>(graphBp);

    return 0;
    int tt[3][3];
    tt[0][0] = 1;
    tt[0][1] = 4;
    tt[0][2] = 5;
    tt[1][0] = 5;
    tt[1][1] = 7;
    tt[1][2] = 6;
    tt[2][0] = 5;
    tt[2][1] = 8;
    tt[2][2] = 8;
    hungarian<3, 3>(tt);

#if __GNUC__
    std::istream &istr = std::cin;
#else 
	//std::fstream istr(R"(C:\FUNHOUSE\Skiena-20191022\solutions\ch2\test.txt)");
    //std::ifstream istr(R"(D:\study\ski\ch2\test.txt)");
    std::fstream istr(R"(C:\fedosin\repos\ski\ch2\test.txt)");

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