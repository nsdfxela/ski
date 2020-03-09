#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>

struct entry {
	/*entry(int part, std::istream &istr) : participant{ part } {
		istr >> solved >> time;
	}*/
	int participant, solved, time;	
};
std::map<int, entry> entries;

void read_block(std::istream &istr) {
	
	std::string buf;
	while (true) {
		std::getline(istr, buf);
		if (buf.empty()) { break; }
		std::stringstream ss(buf);
		int participant, solved, time;
		char L;
		ss >> participant >> solved >> time >> L;
		if (L == 'C') {
			entries[participant].solved++;
			entries[participant].time += time;
		}
		else if (L == 'I') {
			entries[participant].time += 20;
		}
		//>> exercise >> time >> L;

		//std::cout << buf << std::endl;
	}
}

int main(void) {
#ifdef __GNUC__
	std::istream &istr = std::cin;
#else
	std::fstream istr(R"(C:\FUNHOUSE\Skiena-20191022\solutions\ch2\test.txt)");
#endif
	int nblocks;
	istr >> nblocks;

	istr.ignore(2);
	for (int i = 0; i < nblocks; i++) {
		read_block(istr);
	}

	return 0;
}