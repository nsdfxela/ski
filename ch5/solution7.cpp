#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

//10077 - The Stern - Brocot Number System

using namespace std;


struct f {
    int n;
    int d;
    f(int num, int den) :n{ num }, d{ den } { }
    f* left = nullptr, * right = nullptr;
    void set_left(int num, int den) { left = new f(num, den); }
    void set_right(int num, int den) { right = new f(num, den); }
    ~f() {
        if (left) delete left;
        if (right) delete right;
    }
};
bool operator < (const f& f1, const f& f2) { return (f1.n * f2.d < f1.d* f2.n); }
bool operator ==(const f& f1, const  f& f2) { return (f1.n * f2.d == f1.d * f2.n); }
f operator + (const f& f1, const f& f2) { return f(f1.n + f2.n, f1.d + f2.d); }
void solve(const f& r, const f& s) {
    if (s == f(1, 1)) {
        return;
    }
    if (s == r) { return; }
    if (s < r) {
        f new_root = *r.left + r;
        new_root.set_left(r.left->n, r.left->d);
        new_root.set_right(r.n, r.d);
        cout << "L";
        solve(new_root, s);
    }
    else {
        f new_root = *r.right + r;
        new_root.set_left(r.n, r.d);
        new_root.set_right(r.right->n, r.right->d);
        cout << "R";
        solve(new_root, s);
    }
}

int main(void) {
#if __GNUC__
    std::istream& istr = cin;
#else
    std::ifstream istr(R"(C:\fedosin\repos\ski\ch5\test.txt)");
#endif
    while (1) {
        int num, den;
        istr >> num >> den;
        if (!istr.good()) { break; }
        else {
            f s(num, den);
            f root(1, 1);
            root.set_left(0, 1);
            root.set_right(1, 0);
            solve(root, s);
            cout << endl;
        }
    }
    return 0;
}