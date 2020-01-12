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
	}
	return 0;
}