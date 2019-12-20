#include <iostream>
#include <string>
#include <fstream>

std::string suits = "CDHS";
std::string cards = "23456789TJQKA";

int rank(char value, char suit) {
    for (int i = 0; i < suits.length(); i++) {
        for (int j = 0; j < cards.length(); j++) {
            if (suits[i] == suit && cards[j] == value) {
                return i * 10 + j;
            }
        }
    }
}

bool flash(int * crds, int size) {
    if (size == 1) return true;
    int ors = crds[0] % 10;
    for (int i = 1; i < size; i++) {
        if ((crds[i] % 10) != ors) {
            return false;
        }
    }
    return true;
}

bool street(int *crds, int size) {

}

int main(void) {
#if defined (__GNUC__)
    std::istream &istr = std::cin;
#else
    std::ifstream istr(R"(D:\study\ski\ch2\test.txt)", std::ios::in);
#endif
    
    for (int i = 0; i < 10; i++) {
        std::string buf;
        istr >> buf;
        std::cout << rank(buf[0], buf[1])  << " ";
    }
    return 0;
}