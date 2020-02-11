#include <iostream>
#include <string>
#include <fstream>

#define CT 52
int tricks[100][CT];
int ntricks;

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
	do {
		std::getline(istr, buf);
		if (buf.empty() || !istr) {
			break;
		}
		int ntrick = std::stoi(buf, nullptr, 10);
		
	} while (1);
	
}

int main(void) {

#if defined (__GNUC__)
	std::istream &istr = std::cin;
#else
	std::string file = R"(D:\repos\ski\ch2\test.txt)";
	std::ifstream istr(file, std::ios::in);
#endif

	int ntb = 0;
	istr >> ntb;
	istr.ignore();
	for (int i = 0; i < ntb; i++) {

		handle_block(istr);
	}

	return 0;
}