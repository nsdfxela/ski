#include <iostream>
#include <fstream>
#include <string>

std::string hor[50];
std::string rhor[50];
std::string vert[50];
std::string rvert[50];

std::string mdiag[50];
std::string rmdiag[50];

std::string sdiag[50];
std::string rsdiag[50];

#define N 50
void form(std::string grid[50], int R, int C ) {
    for (int i = 0; i < N; i++) {
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
        int cc = 0;
        mdiag[mdc].resize(Mn);
        for (int i = 0, j = 0; (i < R) && (j + offset < C); i++, j++) {
            mdiag[mdc][cc++] = grid[i][j+offset];
        }
        mdc++;
        
    }
    for (int offset = 1; offset < R; offset++) {
        int cc = 0;
        mdiag[mdc].resize(Mn);
        for (int i = 0, j = 0; (i < R) && (j + offset < R); i++, j++) {
            mdiag[mdc][cc++] = grid[i + offset][j];
        }
        mdc++;
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
            std::string buffer;
            std::getline(istr, hor[i]);
        }
        form(hor, m, n);
        int k;
        istr >> k;
        std::string words[20];
        istr.ignore(1);
        for (int i = 0; i < k; i++) {
            std::getline(istr, words[i]);
        }
    }
    

    


    
    return 0;
}