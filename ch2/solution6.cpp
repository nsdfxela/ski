#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


std::vector<std::vector<std::string>> articles;
std::map<std::string, int> numbers;
void count() {
	for (int i = 0; i < articles.size(); i++) {
		for (int j = 0; j < articles[i].size(); j++) {
			bool isErdos = articles[i][j].find("Erdos") != std::string::npos;
		}
	}
}
void trim(std::string &str) {
	if (str[0] == ' ') {
		str = str.substr(1);
	}
}
void split_names(const std::string &in, std::vector<std::string> &vec) {
	std::string instr(in);
	size_t pos;
	do {
		std::string result;
		pos	= instr.find(',');
		pos = instr.find(',', pos+1);

		if (pos == std::string::npos) {
			trim(instr);
			vec.push_back(instr);
			break;
		}

		int startpos = 0;
		
		std::string found_name = instr.substr(0, pos);
		trim(found_name);
		vec.push_back(found_name);
		instr = instr.substr(pos+1);
 	} while (true);
	count();
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