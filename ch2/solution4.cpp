#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

typedef std::map<char, char> alphabet;

struct wrd 
{
    std::string str;
    std::string fp;
    std::map<char, int> d;
    wrd(const std::string &s) : str{ s } {
        for (int i = 0; i < s.length(); i++) {
            d[s[i]]++;
        }
        std::vector<int> frq;
        std::transform(d.begin(), d.end(), std::back_inserter(frq), [](std::pair<char, int> p) -> int { return p.second; });
        std::sort(frq.begin(), frq.end());
        fp.resize(frq.size());
        std::ostringstream os;
        for (int i = 0; i < frq.size(); i++) {
            os << frq[i];
        }
        fp = os.str();
    }
    
};

std::map<std::string, std::vector<wrd>> lc;

bool translate(wrd &enc, wrd &dct, alphabet &a) { 
    if (enc.fp != dct.fp) return false;
    std::string enc_s;
    for (int i = 0; i < enc.str.length(); i++) {
        auto decc = a.find(enc.str[i]);
        if (decc != a.end() ) {
            if (dct.str[i] != decc->second) {
                return false;
            }
        }
    }
    //dct matches enc with respect to a. let's fill 'a'
    for (int i = 0; i < dct.str.length(); i++) {
        a[enc.str[i]] = dct.str[i];
    }
}

std::string fail(const std::vector<std::string> &src) {
	return "****";
}

std::string solve(const std::vector<std::string> &src) {
    wrd w0(src[0]);
    auto pairs = lc.find(w0.fp);
	if (pairs == lc.end()) return fail(src);
    for (int i = 0; i < pairs->second.size(); i++) { //possible translations of 0 word
        bool match = true;
        alphabet a;
        translate(w0, pairs->second[i], a);
        for (int j = 1; j < src.size(); j++) { //words from 1 to n
            auto w1 = wrd(src[j]);
			auto ps = lc.find(w1.fp);
			bool translation_found = false;
			if (ps == lc.end()) return fail(src);
			else {
				for (int k = 0; k < ps->second.size(); k++) { //translations of k'th word
					translation_found = translate(w1, ps->second[k], a);
					if (translation_found) break;
				}
				if (translation_found) continue;
				else { break; }
			}
        }
		
    }
    return "";
}

int main(void) {

#if defined(__GNUC__)
    std::istream &istr = std::cin;
#else
    std::ifstream istr(R"(D:\repos\ski\ch2\test.txt)", std::ios::in);
#endif
    int wc;
    istr >> wc;
    std::string dict[1000];
    for (int i = 0; i < wc; i++) {
        istr >> dict[i];
        wrd w(dict[i]);
        lc[w.fp].push_back(w);
    }
    istr.ignore(1);

    while (istr) {
        std::string buf;
        std::getline(istr, buf);
        std::stringstream ss(buf);
        std::vector<std::string> vec;
        while (ss) {
            std::string w;
            ss >> w;
            vec.push_back(w);
        }
        std::cout << solve(vec);
        std::cout << '\n';
        
    }
    return 0;
} 