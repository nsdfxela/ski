#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


std::vector<std::vector<std::string>> articles;
std::map<std::string, int> numbers;
#define UNKNOWN 10000

int get_level(std::string &name) {
	if (name.find("Erdos") != std::string::npos) {
		return 0;
	}
	else
	{
		if (numbers.count(name)) {
			return numbers[name];
		}
		else {
			numbers[name] = UNKNOWN;
			return numbers[name];
		}
	}
}
int get_level(int article) {
	int level = UNKNOWN;
	for (int i = 0; i < articles[article].size(); i++) {
		int artlevel = get_level(articles[article][i]);
		if (artlevel < level) {
			level = artlevel;
		}
	}
	return level;
}

void set_level(int article, int level) {
	for (int i = 0; i < articles[article].size(); i++) {
		if (get_level(articles[article][i]) > level) {
			numbers[articles[article][i]] = level;
		}
	}
}

void count() {
	int level = 1;
	bool level_found;
	do {
		level_found = false;
		for (int i = 0; i < articles.size(); i++) {
			for (int j = 0; j < articles[i].size(); j++) {
				if (get_level(i) == level - 1) {
					set_level(i, level);
					level_found = true;
				}
			}
		}
		++level;
	} while (level_found);
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
}

void handle_scenario(std::istream &istr, int n_scenario) {
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
	count();
	std::cout << "Scenario " << n_scenario << std::endl;
	buf.clear();

	for (int j = 0; j < nn; j++) {
		std::getline(istr, buf);
		int res = numbers[buf];
		std::cout << buf << " ";
		if (res == UNKNOWN) {
			std::cout << "infinity";
		}
		else {
			std::cout << res;
		}
		std::cout << std::endl;
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
		handle_scenario(istr, i+1);
		
	}

 	return 0;
}