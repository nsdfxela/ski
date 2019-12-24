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

int flash(const int * crds, int size) {
    if (size == 1) return true;
    int ors = crds[0] % 10;
    for (int i = 1; i < size; i++) {
        if ((crds[i] % 10) != ors) {
            return -1;
        }
    }
    return crds[size-1];
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

int street(const int *crds, int size) {
	for (int i = 1; i < size; i++) {
		if(crds[i]/10 - crds[i - 1]/10 == 1) continue;
		else { return -1; }
	}
	return crds[size-1];
}


#define TWO_PAIRS 3
#define PAIR 2
#define HIGH 1
#define IS(c) (c!=-1)
int detect_comb(const int *crds, int size, int * strongest_card, int * weakest_card) {
	int str = street(crds, size);
	int fl = flash(crds, size);
    *weakest_card = -1; // only needed in two pairs
	//street flash
	if (IS(str) && IS(fl)) { 
		*strongest_card = fl;
		return 9;
	} 

	//carre
	*strongest_card = same_cards(crds, size, 4);
	if (IS(*strongest_card)) { return 8; }

	//full house
	int pair = same_cards(crds, size, 2);
	if (IS(pair)) { 
		*strongest_card = same_cards(crds, size, 3);
		if (IS(*strongest_card)) {
			return 7;
		}
	}

	//flash
	*strongest_card = flash(crds, size);
	if (IS(*strongest_card)) { return 6; }
	
    //street
	*strongest_card = street(crds, size);
	if (IS(*strongest_card)) { return 5; }
    
    //set
	*strongest_card = same_cards(crds, size, 3);
	if (IS(*strongest_card)) { return 4; }
    
    //two pairs
    auto mp = get_map(crds, size);
    int pair1 = -1, pair2 = -1;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it->second == 2) {
            if (!IS(pair1)) { pair1 = it->first; }
            else if(!IS(pair2)) { pair2 = it->first; }
        }
    }
    if ( IS(pair1) && IS(pair2) ) {
        *strongest_card = std::max(pair1, pair2)*10;
        *weakest_card = std::min(pair1, pair2)*10;
        return 3;
    } else if (IS(pair1)) { //one pair
        *strongest_card = pair1;
        return 2;
    } else if (IS(pair2)) {
        *strongest_card = pair2;
        return 2;
    }

    *strongest_card = crds[size-1];
    return 1;
}

int hands[2][5];

void blackw() {
    std::cout << "Black wins." << std::endl;
}
void tie() {
    std::cout << "Tie." << std::endl;
}
void whitew() {
    std::cout << "White wins." << std::endl;
}
bool process_line(std::istream &istr) {
	for (int h = 0; h < 2; h++) {
		for (int i = 0; i < 5; i++) {
			std::string buf;
			istr >> buf;
			if (!istr) return false;
			hands[h][i] = rank(buf[0], buf[1]);
			//std::cout << hands[h][i] << " ";
		}
		std::sort(hands[h], hands[h] + 5);
        
	}

    int leftStr = -1, rightStr = -1;
    int leftWeak = -1, rightWeak = -1;
    int leftComb = detect_comb(&hands[0][0], 5, &leftStr, &leftWeak);
    int rightComb = detect_comb(&hands[1][0], 5, &rightStr, &rightWeak);
    leftStr /= 10;
    rightStr /= 10;
    leftWeak /= 10;
    rightWeak /= 10;
    if (leftComb > rightComb) {
        blackw();
    }
    else if (leftComb > rightComb) {
        whitew();
    }
    else {
        
        if (leftStr > rightStr) {
            blackw();
        }
        else if (leftStr < rightStr) {
            whitew();
        }
        else {            
            if (leftComb == TWO_PAIRS) {
                if (leftWeak > rightWeak) {
                    blackw();
                }
                else if (leftWeak < rightWeak) {
                    whitew();
                }
                else {
                    leftComb = HIGH;
                }
            }

            if (leftComb == HIGH || leftComb == PAIR) {
                int *black = &hands[0][4];
                int *white = &hands[1][4];
                bool found = false;
                for (int i = 0; i <= 4 && !found; i++) {
                    int b = *(black - i)/10;
                    int w = *(white - i)/10;
                    if (b > w) {
                        blackw();
                        found = true;
                    }
                    else if (w > b) {
                        whitew();
                        found = true;
                    }
                }
                if (!found) {
                    tie();
                }
                
            } else {
                tie();
            }
        }
    }

    /*printf("\n left : combination %d card: %d \n", leftComb, leftStr);
    printf("\n right : combination %d card: %d \n", rightComb, rightStr);*/
	/*std::cout <<  " cards: "  << same_cards(hands[0], 5, 3);
	std::cout << " cards: " << same_cards(hands[0], 5, 2);*/
	return true;
}

int main(void) {
#if defined (__GNUC__)
    std::istream &istr = std::cin;
#else
    std::ifstream istr(R"(D:\study\ski\ch2\test.txt)", std::ios::in);
#endif
	while (process_line(istr)) {
		//std::cout << std::endl;

	}
    return 0;
}
