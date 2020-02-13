#include <iostream>
#include <string>
#include <fstream>

#define CT 52
#define SUITS 4
#define VALUES 13

int tricks[100][CT];
int ntricks;

int cards [CT];
int p_cards[CT];
void cpyCards() {
    std::copy(std::begin(cards), std::end(cards), std::begin(p_cards));
}

std::string vnames[]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
std::string snames[]{"Clubs", "Diamonds", "Hearts", "Spades" };
void printCard(int card) {
    int suit = card / 100;
    int val = card % 100;
    std::cout << vnames[val] << " of " << snames[suit] << std::endl;
}
void fillCards() {
    for (int i = 0; i < SUITS; i++) {
        for (int j = 0; j < VALUES; j++) {
            cards[i * VALUES + j] = (i * 100) + j;
            
        }
    }
    cpyCards();
}
void handleShuffle(int *shuffle) {
    for (int i = 0; i < CT; i++) {
        /*std::swap(cards[i], cards[shuffle[i]-1]);*/
        cards[i] = p_cards[shuffle[i] - 1];
    }
    cpyCards();
}
void handle_block(std::istream &istr) 
{
	istr >> ntricks;

	for (int i = 0; i < ntricks; i++) {
		for (int j = 0; j < CT; j++) {
			istr >> tricks[i][j];
		}
	}
	istr.ignore();

	std::string buf;
    int tricksSeen[100];
    int nt = 0;
	do {
		std::getline(istr, buf);
		if (buf.empty() || !istr) {
			break;
		}
        tricksSeen[nt++] = std::stoi(buf, nullptr, 10);
		
	} while (1);
	//solution
    fillCards();
    for (int i = 0; i < nt; i++) {
        handleShuffle(tricks[tricksSeen[i]-1]);
    }

}

int main(void) {

#if defined (__GNUC__)
	std::istream &istr = std::cin;
#else
	std::string file = R"(D:\study\ski\ch2\test.txt)";
	std::ifstream istr(file, std::ios::in);
#endif

	int ntb = 0;
	istr >> ntb;
    istr.ignore();
    for (int i = 0; i < ntb; i++) {
        fillCards();
        handle_block(istr);
        for (int j = 0; j < CT; j++) {
            printCard(cards[i*VALUES + j]);
        }
        std::cout << std::endl;
    }
	return 0;
}