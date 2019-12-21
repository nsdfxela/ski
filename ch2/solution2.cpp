#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
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

std::map<int, int> get_map(const int *crds, int size) {
	std::map<int, int> result;
	for (int i = 0; i < size; i++) {
		result[crds[i] / 10] ++;
	}
	return result;
}

int same_cards(const int *crds, int size, int numberOfSameCards) {
	auto mp = get_map(crds, size);
	auto cr = std::find_if(mp.begin(), mp.end(), [&numberOfSameCards](const std::pair<int, int> &v) {
		return v.second == numberOfSameCards;
	});
	if (cr == mp.end()) { return -1; }
	else return cr->first;
}

bool street(const int *crds, int size) {
	bool result = true;
	for (int i = 1; i < size; i++) {
		if(crds[i]/10 - crds[i - 1]/10 == 1) continue;
		else { return false; }
	}
	return true;
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
	
	std::cout <<  " cards: "  << same_cards(hands[0], 5, 3);
	std::cout << " cards: " << same_cards(hands[0], 5, 2);
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
