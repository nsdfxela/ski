#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <cstring>
#include <algorithm>
#include <vector>

struct result {
    int id;
    int count;
    int time;
};

void read_block(std::istream &istr) {
	int exercies[101][9];
	for (int i = 0; i < 101; i++) {
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
            if (exercies[participant][ex - 1] <= 0) {
                exercies[participant][ex - 1] *= -1;
                exercies[participant][ex - 1] += time;
                prtsp.insert(participant);
            }
		}
		else if (L == 'I') {
            if (exercies[participant][ex - 1] <= 0) {
                exercies[participant][ex - 1] -= 20;
                prtsp.insert(participant);
            }
        }
        else {
            prtsp.insert(participant);
        }

		
		//>> exercise >> time >> L;

		//std::cout << buf << std::endl;
	}

    std::vector<result> vec;
	for (auto &p : prtsp) {
		
		int count = 0;
		int time = 0;
		for (int i = 0; i < 9; i++) {
			if (exercies[p][i] > 0) {
				++count;
				time += exercies[p][i];
			}
		}
        result r;
        r.count = count;
        r.time = time;
        r.id = p;
        vec.push_back(r);        
	}
    std::sort(vec.begin(), vec.end(), [](result &r1, result &r2) { 
        if (r1.count == r2.count) {
            if (r1.time == r2.time) {
                return r1.id < r2.id;
            }
            else {
                return r1.time < r2.time;
            }
        }
        else {
            return r1.count > r2.count;
        }
    });
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i].id << " " << vec[i].count << " " << vec[i].time << std::endl;
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
        if (i != nblocks - 1) {
            std::cout << std::endl;
        }
	}

	return 0;
}