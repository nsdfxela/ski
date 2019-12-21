#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
std::string suits = "CDHS";
std::string cards = "23456789TJQKA";

int rank(char value, char suit) {
    for (int i = 0; i < suits.length(); i++) {
        for (int j = 0; j < cards.length(); j++) {
            if (suits[i] == suit && cards[j] == value) {
                return j * 10 + i;
            }
        }
    }
    return 0;
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
	bool result = true;
	for (int i = 1; i < size; i++) {
		if(crds[i] - crds[i - 1] == 1) continue;
		else { return false; }
	}
}
int hands[2][5];


bool process_line(std::istream &istr) {
	for (int h = 0; h < 2; h++) {
		for (int i = 0; i < 5; i++) {
			std::string buf;
			istr >> buf;
			if (!istr) return false;
			hands[h][i] = rank(buf[0], buf[1]);

			std::cout << hands[h][i] << " ";
		}
		std::sort(hands[h], hands[h] + 5);
	}
	
	std::cout <<  flash(hands[0], 5);
	return true;
}

int main(void) {
#if defined (__GNUC__)
    std::istream &istr = std::cin;
#else
    std::ifstream istr(R"(C:\FUNHOUSE\Skiena-20191022\solutions\ch2\test.txt)", std::ios::in);
#endif
	while (process_line(istr)) {
		std::cout << std::endl;

	}
    return 0;
}
