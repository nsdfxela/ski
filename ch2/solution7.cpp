#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <cstring>

void read_block(std::istream &istr) {
	int exercies[100][9];
	for (int i = 0; i < 100; i++) {
		memset(exercies[i], 0, sizeof(int)*9);
	}
	std::string buf;
	std::set<int> prtsp;
	while (true) {
		std::getline(istr, buf);
		if (buf.empty()) { break; }
		std::stringstream ss(buf);
		int participant, ex, time;
		char L;
		ss >> participant >> ex >> time >> L;
		
		if (L == 'C') {
			exercies[participant][ex - 1] *= -1;
			exercies[participant][ex - 1] += time;
			prtsp.insert(participant);
		}
		else if (L == 'I') {
			exercies[participant][ex - 1] -= 20;
			prtsp.insert(participant);
		}

		
		//>> exercise >> time >> L;

		//std::cout << buf << std::endl;
	}

	for (auto &p : prtsp) {
		std::cout << p << " ";
		int count = 0;
		int time = 0;
		for (int i = 0; i < 9; i++) {
			if (exercies[p][i] > 0) {
				++count;
				time += exercies[p][i];
			}
		}
		std::cout << count << " " << time << std::endl;
	}
}

int main(void) {
#ifdef __GNUC__
	std::istream &istr = std::cin;
#else
	//std::fstream istr(R"(C:\FUNHOUSE\Skiena-20191022\solutions\ch2\test.txt)");
    std::fstream istr(R"(D:\study\ski\ch2\test.txt)");
#endif
	int nblocks;
	istr >> nblocks;

	istr.ignore(2);
	for (int i = 0; i < nblocks; i++) {
		read_block(istr);
		std::cout << std::endl;
	}

	return 0;
}