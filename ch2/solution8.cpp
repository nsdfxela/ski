#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <vector>

/*2.8.8 Uva 10149 Yahtzee*/

int GAME[13][13]; //The Game

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
        return;
    }
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
        memset(nG[i], 0, sizeof(int) * N);
    }
    for (int i = 0; i < nr; i++) {
        memcpy(nG[i+1] + (N - nr - 1), G[i], nr * sizeof(int));         
    }
    for (int i = 0; i < nr; i++) {
        nG[0][i+1] = 1;
        nG[nr + i + 1][N - 1] = 1;
    }

    /*std::cout << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << nG[i][j] << " ";
        }
        std::cout << std::endl;
    }*/
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
std::set<int> minVertexCover(int G[nr][nc], int maxMatching[nr][nc]) {
    std::set<int> result;

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
    std::set_union(p1.begin(), p1.end(), p2.begin(), p2.end(), std::inserter(result, result.begin()));
    return result;
}

template<int nr, int nc>
//ROWS are games, COLS are value of a game at J position
void hungarian(int m [nr][nc], int solution[nr][nc], int offset=0) {
    int mc[nr][nc];
    int MAX_M = INT_MIN;

    //generating MAX task from MIN
    for (int i = offset; i < nr; i++)
        for (int j = offset; j < nc; j++) {
            if (m[i][j] > MAX_M) {
                MAX_M = m[i][j];
            }
        }

    for (int i = 0; i < nr; i++) 
        for (int j = 0; j < nc; j++) {
            mc[i][j] = MAX_M - m[i][j];
            solution[i][j] = 0;
        }
    for (int i = 0; i < nr; i++) {
        int min = INT_MAX;
        //searching for min
        for (int j = 0; j < nc; j++) {
            if (m[i + offset][j + offset] < min) {
                min = m[i + offset][j + offset];
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
    bool solved = false;
    do {
        int mc0[nr][nc];

        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++)
            {
                if (mc[i][j]) {
                    mc0[i][j] = 0;
                }
                else {
                    mc0[i][j] = 1;
                }
            }
        }

        int bpMatching[nr][nc];
        //Find the maximum matching using only 0-weight edges
        int mbp = maxBipartile<nr, nc>(mc0, bpMatching);
        if (mbp == nr) {
            //If it is perfect, then the problem is solved. Otherwise find the minimum vertex cover V (for the subgraph with 0-weight edges only)
            solved = true;
            for (int i = 0; i < nr; i++)
                for (int j = 0; j < nc; j++) {                 
                    solution[i][j] = bpMatching[i][j];
                }
        }
        else {
            int D = INT_MAX;

            std::set <int> mvc = minVertexCover<nr, nc>(mc0, bpMatching);
            //searching for min delta
            for (int i = 0; i < nr; i++) {
                for (int j = 0; j < nc; j++) {
                    int _j = j + nc;
                    bool ifound = (std::find(mvc.begin(), mvc.end(), i) != mvc.end());
                    bool jfound = (std::find(mvc.begin(), mvc.end(), _j) != mvc.end());
                    if (ifound || jfound) { continue; }
                    if (mc[i][j] < D) {
                        D = mc[i][j];
                    }
                }
            }

            for (int i = 0; i < nr; i++)
                for (int j = 0; j < nc; j++) {
                    {
                        int _j = j + nc;
                        bool ifound = (std::find(mvc.begin(), mvc.end(), i) != mvc.end());
                        bool jfound = (std::find(mvc.begin(), mvc.end(), _j) != mvc.end());
                        if (!ifound && !jfound) {
                            mc[i][j] -= D;
                        }
                        else if (ifound && jfound) {
                            mc[i][j] += D;
                        }
                        else if (ifound || jfound) {

                        }

                    }
                }
        }
    } while (!solved);
    //std::cout << "Solved!";
}

void recGen(std::vector<std::vector<int>> &res, int fix, int n, int k, std::vector<int> current) {
    
    current.push_back(fix);

    if (current.size() == k) {
        res.push_back(current);
        return;
    }

    for (int i = fix+1; i < n; i++) {
        recGen(res, i, n, k, current);
    }
}
std::vector<std::vector<int>> generateCombination(int n, int k)
{
    std::vector<std::vector<int>> result;
    for (int i = 0; i < n - k + 1; i++)
    {
        recGen(result, i, n, k, std::vector<int>());
    }
    return result;
}

template <int nc>
void getResult(int res[nc], int offset = 0, std::vector<int> *order = nullptr) {
    int solution[nc][nc];
    int tc[nc][nc];
    if (order) {        
        for (int i = 0; i < order->size(); i++) {
            memcpy(tc[i], GAME[order->operator[](i)] + offset, nc * sizeof(int));
        }
        hungarian<nc, nc>(tc, solution);
    }
    else {
        for (int i = 0; i < nc; i++) {
            memcpy(tc[i], GAME[i]+offset, nc * sizeof(int));
        }
        hungarian<nc, nc>(tc, solution);
    }
        
    for (int i = 0; i < nc; i++) {
        for (int j = 0; j < nc; j++) {
            if (solution[i][j]) {
                res[j] = tc[i][j];
                break;
            }
        }
    }
}

void solve(int game[13][5], std::vector<int> &finalSolution) {    
    for (int i = 0; i < 13; i++) { //iterate over throws
        GAME[i][0] = std::count(std::begin(game[i]), std::end(game[i]), 1) * 1;
        GAME[i][1] = std::count(std::begin(game[i]), std::end(game[i]), 2) * 2;
        GAME[i][2] = std::count(std::begin(game[i]), std::end(game[i]), 3) * 3;
        GAME[i][3] = std::count(std::begin(game[i]), std::end(game[i]), 4) * 4;
        GAME[i][4] = std::count(std::begin(game[i]), std::end(game[i]), 5) * 5;
        GAME[i][5] = std::count(std::begin(game[i]), std::end(game[i]), 6) * 6;
        GAME[i][6] = std::accumulate(std::begin(game[i]), std::end(game[i]), 0);
        GAME[i][7] = uniques(game[i], 3);
        GAME[i][8] = uniques(game[i], 4);
        int u5 = uniques(game[i], 5);
        GAME[i][9] = u5 ? 50 : 0;

        std::vector<int> street{1,2,3,4,5,6};
        int streetChecker[4];
        for (int k = 1; k < 5; k++) {
            streetChecker[k-1] = GAME[i][k] - GAME[i][k - 1];

        }
        int str_cnt = std::count(streetChecker, streetChecker +4, 1);
        if (str_cnt == 3) { 
            GAME[i][10] = 25; 
            GAME[i][11] = 0;
        }
        else if (str_cnt == 4) {
            GAME[i][10] = 25;
            GAME[i][11] = 35;
        }
        else {
            GAME[i][10] = 0;
            GAME[i][11] = 0;
        }

        if (uniques(game[i], 3) && uniques(game[i], 2)) {
            GAME[i][12] = 40;
        }
        else {
            GAME[i][12] = 0;
        }
    }
    
    int solution[13][13];
    int res1[13];
    getResult<13>(res1, 0);
    int first6 = std::accumulate(res1, res1 + 6, 0);
    int sum13 = std::accumulate(res1, res1 + 13, 0);

    if (first6 >= 63) {
        //we are done!
        std::copy(res1, res1 + 13, std::back_inserter(finalSolution));
        finalSolution.push_back(35);
        finalSolution.push_back(sum13 + 35);
    }
    else
    {
        std::vector<int> betterSolution;
        //handling fines
        //searching for all combinations for 1st 6 possible categories
        auto com6 = generateCombination(13, 6);
        int results[1716][6];
        
        std::set<int> all;
        for (int i = 0; i < 13; i++) { all.insert(i); }
        for (int i = 0; i < com6.size(); i++) {
            getResult<6>(results[i], 0, &com6[i]);
            int sum6 = std::accumulate(results[i], results[i] + 6, 0);
            if (sum6 >= 63) {
                std::set<int> f1;
                std::copy(com6[i].begin(), com6[i].end(), std::inserter(f1, f1.begin()));
                std::vector<int> inv;
                std::set_difference(all.begin(), all.end(), f1.begin(), f1.end(), std::back_inserter(inv));
                int invRes[7];
                getResult<7>(invRes, 6, &inv);
                int sum7 = std::accumulate(invRes, invRes + 7, 0);
                if (sum6 + sum7 + 35 > sum13) {
                    sum13 = sum6 + sum7 + 35;
                    betterSolution.clear();
                    std::copy(results[i], results[i] + 6, std::back_inserter(betterSolution));
                    std::copy(invRes, invRes + 7, std::back_inserter(betterSolution));
                }
            }
        }

        if(!betterSolution.empty()) { 
            std::swap(finalSolution, betterSolution);
            finalSolution.push_back(35);
            finalSolution.push_back(sum13);
        }
        else {
            std::copy(res1, res1 + 13, std::back_inserter(finalSolution));
            finalSolution.push_back(sum13);
        }
    }
    //std::cout << "done";
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


    //simple hungarian test
    /*int tt[3][3];
    tt[0][0] = 1;
    tt[0][1] = 4;
    tt[0][2] = 5;
    tt[1][0] = 5;
    tt[1][1] = 7;
    tt[1][2] = 6;
    tt[2][0] = 5;
    tt[2][1] = 8;
    tt[2][2] = 8;
    int sol[3][3];
    hungarian<3, 3>(tt, sol);*/

    //konig_test
    /*int graph[5][5] = { {1, 0, 1, 0, 0},
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
    minVertexCover<5,5>(graph, graphM);*/

#if __GNUC__
    std::istream &istr = std::cin;
#else 
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
            std::vector<int> theSolution;
            solve(game, theSolution);
            for (int i = 0; i < theSolution.size(); i++) {
                std::cout << theSolution[i];
                if (i != theSolution.size() - 1) {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
            clear(game);
        }
    }
    return 0;
}