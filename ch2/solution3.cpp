#include <iostream>
#include <fstream>

int days, parts;
int hars[100];

void read_block(std::istream &istr) {
	istr >> days;
	istr >> parts;
	for (int i = 0; i < parts; i++) {
		istr >> hars[i];
	}
}

int get_hartals() {
	int res = 0;
	int party_cnt [100];
	for (int i = 0; i < days; i++) {
		int hartal = 0;
		for (int p = 0; p < parts; p++) {
			int d = (i + 1);
			if (d % hars[p] == 0) {
				if (d % 7 != 6 && d % 7 != 0) {
					hartal = 1;
				}
			}
			//party_cnt[p]++;
		}
		res += hartal;
	}
	return res;
}

int main(void) {

#if defined (_GNUC_)
	std::istream &istr = std::cin;
#else
	std::fstream istr(R"(D:\repos\ski\ch2\test.txt)", std::ios::in);
#endif
	int nblocks;
	istr >> nblocks;
	for (int i = 0; i < nblocks; i++) {
		read_block(istr);
		std::cout << get_hartals() << std::endl;
	}
	return 0;
}