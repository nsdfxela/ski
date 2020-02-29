#include <iostream>
#include <fstream>
#include <string>
#include <vector>


std::vector<std::vector<std::string>> articles;

void split_names(const std::string &in, std::vector<std::string> &vec) {
	std::string instr(in);
	size_t pos;
	do {
		pos	= in.find(',');

	} while (pos != std::string::npos);
}

void handle_scenario(std::istream &istr) {
	articles.clear();
	int nart, nn;
	istr >> nart >> nn;
	istr.ignore();
	std::string buf;
	for (int i = 0; i < nart; i++) {
		std::getline(istr, buf);
		size_t sp1 = buf.find(':');
		buf = buf.substr(0, sp1);

		std::vector<std::string> article;
		split_names(buf, article);
		articles.push_back(article);
	}
}

int main(void) {

#ifdef  __GNUC__
	std::istream &istr = std:cin;
#else
	std::ifstream istr(R"(D:\repos\ski\ch2\test.txt)");
#endif //  __GNUC__

	int nsc = 0, nart = 0, nnames = 0;
	istr >> nsc;

	for (int i = 0; i < nsc; i++) {
		handle_scenario(istr);
	}

 	return 0;
}