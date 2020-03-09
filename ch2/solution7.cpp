#include <iostream>
#include <string>
#include <fstream>


struct entry {
	int participant, exercise, time, L;
};
void read_block(std::istream &istr) {
	
	std::string buf;
	while (true) {
		std::getline(istr, buf);
		if (buf.empty()) { break; }
		
		//istr >> participant >> exercise >> time >> L;

		//std::cout << buf << std::endl;
	}
}

int main(void) {
#ifdef __GNUC__
	std::istream &istr = std::cin;
#else
	std::fstream istr(R"(D:\repos\ski\ch2\test.txt)");
#endif
	int nblocks;
	istr >> nblocks;

	istr.ignore(2);
	for (int i = 0; i < nblocks; i++) {
		read_block(istr);
	}

	return 0;
}