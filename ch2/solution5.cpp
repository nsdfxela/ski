#include <iostream>
#include <string>
#include <fstream>


void handle_block() 
{

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

	for (int i = 0; i < ntb; i++) {

		handle_block();
	}

	return 0;
}