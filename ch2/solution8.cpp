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
int fordFulkerson(int G[nr][nc], int s, int t, int flow[nr][nc]) {
    int Gr[nr][nc];        

    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            Gr[i][j] = G[i][j];
            flow[i][j] = 0;
        }
    }

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
            flow[path[idx]][idx] += minFlow;
            flow[idx][path[idx]] -= minFlow;

            Gr[path[idx]][idx] -= minFlow;
            Gr[idx][path[idx]] += minFlow;
            idx = path[idx];
        } while (idx);
        totalFlow += minFlow;
    }
    return totalFlow;
}

template <int nr, int nc>
int maxBipartile(int G[nr][nc], int resultGraph[nr][nc]) {
    const int N = nr * 2 + 2;
    int nG[N][N];
    int nResultGraph[N][N];
     for (int i = 0; i < N; i++) {
        //nG[i] = new int [N];
        memset(nG[i], 0, sizeof(int) * N);
       /* for (int j = 0; j < N; j++) {
            std::cout << nG[i][j] << " ";
        }*/
    }
    for (int i = 0; i < nr; i++) {
        memcpy(nG[i+1] + (N - nr - 1), G[i], nr * sizeof(int));         
    }
    for (int i = 0; i < nr; i++) {
        nG[0][i+1] = 1;
        nG[nr + i + 1][N - 1] = 1;
    }

    std::cout << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << nG[i][j] << " ";
        }
        std::cout << std::endl;
    }
    int r = fordFulkerson<N, N>(nG, 0, N - 1, nResultGraph);
    for (int i = 0; i < nr; i++) {
        memcpy(resultGraph[i], nResultGraph[i + 1] + (N - nr - 1), nr * sizeof(int));
    }
    return r;
}


template<int nr, int nc>
void alternatings(int z, int G[nr][nc], int maxMatching[nr][nc], int visited[nr][nc]) {
    for (int i = 0; i < nc; i++) {
        if (G[z][i] && !visited[z][i]) {
            visited[z][i] = 1;
            for (int j = 0; j < nr; j++) {
                if (maxMatching[j][i] && !visited[j][i]) {
                    visited[j][i] = 1;
                    alternatings<nr, nc>(j, G, maxMatching, visited);
                }
             }
        }
    }
}

#include <set>
#include <iterator>
template<int nr, int nc>
std::vector<int> minVertexCover(int G[nr][nc], int maxMatching[nr][nc]) {
    std::vector<int> result;

    std::vector <int> zeros;
    for (int i = 0; i < nr; i++) {
        bool iszero = true;
        for (int j = 0; j < nc && iszero; j++) {
            if (maxMatching[i][j]) {
                iszero = false;
            }
        }
        if (iszero) {
            zeros.push_back(i);
        }
    }


    int visited[nr][nc];
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            visited[i][j] = 0;
        }
    }

    std::set<int> Z;
    for (int i = 0; i < zeros.size(); i++) {
        Z.insert(zeros[i]);
        alternatings<nr, nc>(zeros[i], G, maxMatching, visited);
    }
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            if (visited[i][j]) {
                Z.insert(i);
                Z.insert(j+nc);
            }            
        }
    }
    std::set<int> L, R;
    for (int i = 0; i < nr; i++) {
        L.insert(i);
        R.insert(i + nr);
    }
    std::set<int> p1, p2, p;
    std::set_difference(L.begin(), L.end(), Z.begin(), Z.end(), std::inserter(p1, p1.begin()));
    std::set_intersection(R.begin(), R.end(), Z.begin(), Z.end(), std::inserter( p2, p2.begin()));
    std::set_union(p1.begin(), p1.end(), p2.begin(), p2.end(), std::inserter(p, p.begin()));
    
    return result;
}

template<int nr, int nc>
//ROWS are games, COLS are value of a game at J position
void hungarian(int m [nr][nc]) {
    int mc[nr][nc];
    for (int i = 0; i < nr; i++) 
        for (int j = 0; j < nc; j++) {
            mc[i][j] = m[i][j];
        }
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

    //loop
    int mc0[nr][nc];
    
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++)
        {
            if (m[i][j]) {
                mc0[i][j] = mc[i][j] ? 0 : 1;
            }
            else {
                mc0[i][j] = 0;
            }
        }
    }

    int bpMatching[nr][nc];
    //Find the maximum matching using only 0-weight edges
    int mbp = maxBipartile<nr, nc>(mc0, bpMatching);
    if (mbp == nr) {
        //If it is perfect, then the problem is solved. Otherwise find the minimum vertex cover V (for the subgraph with 0-weight edges only)

    }
    else {
        int D = 0;
        std::vector <int> mvc = minVertexCover<nr, nc>(mc0, bpMatching);
        for (int i = 0; i < nr; i++)
            for (int i = 0; i < nr; i++) {
                {

                }
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

    /*int graph[6][6] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
    };
    std::cout << fordFulkerson<6,6>(graph, 0, 5);

    int graphBp3[3][3] = { {1, 1, 1},
                          {1, 0, 0},
                          {0, 1, 1},
    };
    std::cout << maxBipartile<3, 3>(graphBp3);


    int graphBp[6][6] = { {0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {1, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 1}
    };
    std::cout << maxBipartile<6, 6>(graphBp);*/

    
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

    //konig_test
    int graph[5][5] = { {1, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 1, 1, 1, 0},
                        {0, 0, 1, 0, 0},
                        {0, 1, 1, 0, 1}
    };
    int graphM[5][5] ={ {1, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 1}
    };

    int graphT[5][5] = { {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
    };
    minVertexCover<5,5>(graph, graphM);

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