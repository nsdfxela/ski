#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::string hor[50]; 

std::string rhor[50]; 
std::string vert[50]; 
std::string rvert[50];  

struct point { int r; int c; };

std::string mdiag[50]; point _mdiag[50][20];
std::string rmdiag[50]; point _rmdiag[50][20];

std::string sdiag[50]; point _sdiag[50][20];
std::string rsdiag[50]; point _rsdiag[50][20];

#define N 50

std::vector<point> search(const std::string& istr) {
    std::string str;
    str.resize(istr.size());
    std::transform(istr.begin(), istr.end(), str.begin(), [](char c) { return std::toupper(c); });
    std::vector<point> res;
    size_t pos;
    for (int i = 0; i < 50; i++) {
        pos = hor[i].find(str); 
        if (pos != std::string::npos) { res.push_back(point{ i, (int)pos }); }
        pos = rhor[i].find(str);
        if (pos != std::string::npos) { 
            res.push_back(point{ i, (int)(rhor->size() - pos - 1) }); }
        pos = vert[i].find(str);
        if (pos != std::string::npos) { res.push_back(point{ (int)pos, i }); }
        pos = rvert[i].find(str);
        if (pos != std::string::npos) { res.push_back(point{ (int)(rvert[i].size() - pos -1), i }); }
        pos = mdiag[i].find(str);
        if(pos != std::string::npos) { res.push_back( _mdiag[i][pos] ); }
        pos = rmdiag[i].find(str);
        if (pos != std::string::npos) { res.push_back(_rmdiag[i][pos]); }
        pos = sdiag[i].find(str);
        if (pos != std::string::npos) { res.push_back(_sdiag[i][pos]); }
        pos = rsdiag[i].find(str);
        if (pos != std::string::npos) { res.push_back(_rsdiag[i][pos]); }
    }
    return res;
}

void form(std::string grid[50], int R, int C ) {
    for (int i = 0; i < R; i++) {
        rhor[i].resize(C);
        std::copy(grid[i].rbegin(), grid[i].rend(), rhor[i].begin());
    }
    
    for (int i = 0; i < C; i++) {
        vert[i].resize(R);
        rvert[i].resize(R);
        for (int j = 0; j < R; j++) {
            vert[i][j] = grid[j][i];
        }
        std::copy(vert[i].rbegin(), vert[i].rend(), rvert[i].begin());
    }
    int Mn = R < C ? R : C;
    int mdc = 0;
    for (int offset = C-1; offset >=0; offset--) {
        std::stringstream ss;
        int cc = 0;
        for (int i = 0, j = 0; (i < R) && (j + offset < C); i++, j++) {
            ss << grid[i][j+offset];
            point p{ i , j + offset };
            _mdiag[mdc][cc++] = p;
            
        }
        mdiag[mdc].assign(ss.str());
        mdc++;
        
    }
    //mdiag
    for (int offset = 1; offset < R; offset++) {
        int cc = 0;
        std::stringstream ss;
        for (int i = 0, j = 0; (i < C) && (j + offset < R); i++, j++) {
            ss << grid[i + offset][j];
            point p{ i + offset , j};
            _mdiag[mdc][cc++] = p;
        }
        mdiag[mdc].assign(ss.str());
        mdc++;
    }

    for (int i = 0; i < mdc; i++) {
        rmdiag[i].resize(mdiag[i].size());
        int cc = 0;
        for (int j = mdiag[i].size() - 1; j >= 0; j--) {
            _rmdiag[i][cc] = _mdiag[i][j];
            rmdiag[i][cc++] = mdiag[i][j];
        }
    }

    //sdiag
    mdc = 0;
    for (int offset = 0; offset < R; offset++) {
        std::stringstream ss;
        int cc = 0;
        for (int i = 0, j = C-1; (i + offset < R) && (j >= 0); i++, j--) {
            ss << grid[i + offset][j];
            point p{ i + offset , j };
            _sdiag[mdc][cc++] = p;
        }
        sdiag[mdc].assign(ss.str());
        mdc++;
    }
    for (int offset = 1; offset < C; offset++) {
        std::stringstream ss;
        int cc = 0;

        for (int i = 0, j = C - 1; (i < R) && (j - offset >= 0); i++, j--) {
            ss << grid[i][j - offset];
            point p{ i , j - offset };
            _sdiag[mdc][cc++] = p;
        }
        sdiag[mdc].assign(ss.str());
        mdc++;
    }
    for (int i = 0; i < mdc; i++) {
        rsdiag[i].resize(sdiag[i].size());
        int cc = 0;
        for (int j = sdiag[i].size() - 1; j >= 0; j--) {
            _rsdiag[i][cc] = _sdiag[i][j];
            rsdiag[i][cc++] = sdiag[i][j];
        }
    }

}
int main(void) {
#if __GNUC__
    std::istream& istr = std::cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch3\test.txt)");
#endif
    int tc;
    istr >> tc;
    istr.ignore(1);
    for (int i = 0; i < tc; i++) {
        int m, n;
        istr >> m >> n;
        istr.ignore(1);
        //std::string grid[50];
        for (int i = 0; i < m; i++) {
            std::getline(istr, hor[i]);
            std::transform(std::begin(hor[i]), std::end(hor[i]), std::begin(hor[i]), [](char c) { return std::toupper(c); });
        }
        form(hor, m, n);
        
        int k;
        istr >> k;
        std::string words[20];
        istr.ignore(1);
        for (int i = 0; i < k; i++) {
            std::getline(istr, words[i]);
            std::vector<point> found = search(words[i]);
            std::sort(found.begin(), found.end(),
                [](const point& a, const point& b) {
                    if (a.r < b.r) {
                        return a.r < b.r;
                    }
                    else {
                        return a.c < b.c;
                    }
                });
            if (!found.empty()) {
                std::cout << found[0].r + 1 << " " << found[0].c + 1;
                if (i != k - 1) {
                    std::cout << std::endl;
                }
            }
        }
        std::cout << std::endl;
        
    }
    
    return 0;
}