#include <iostream>
#include <fstream>
int main(void) {
#ifdef __GNUC__
	std::istream &istr = std::cin;
#else
	std::fstream istr(R"(D:\repos\ski\ch2\test.txt)");
#endif
	int nblocks;
	istr >> nblocks;
	std::cout << nblocks;

	return 0;
}