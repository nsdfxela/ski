#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

typedef std::map<char, char> alphabet;
template <typename T>
struct list_el
{
    T el;
    list_el<T> *nxt = nullptr;
    list_el(T &e) {
        el = e;
    }
};
template <typename T>
struct list {
    list_el<T> *head = nullptr;
    list_el<T> *tail = nullptr;

    void add(T &e) {
        list_el<T> *elt = new list_el<T>(e);
        if (tail) {
            tail->nxt = elt;
            tail = elt;
        }
        else {
            head = elt;
            tail = elt;            
        }
    }

    void clear(list_el<T> *el) {
        if (el->nxt) {
            clear(el->nxt);
            
        }
        delete el;
    }
    ~list() {
        clear(head);
        head = nullptr;
        tail = nullptr;
    }
};
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
		else {
			auto decd = std::find_if(a.begin(), a.end(),
				[&](std::pair<char, char> p) { return p.second == dct.str[i]; });
			if (decd != a.end()) {
				return false;
			}
		}
    }
    //dct matches enc with respect to a. let's fill 'a'
    for (int i = 0; i < dct.str.length(); i++) {
        a[enc.str[i]] = dct.str[i];
    }
    return true;
}
std::string success(const list<std::string> &src, alphabet &a) {
    std::stringstream ss;
    list_el <std::string> *el = src.head;
    while (el) {
        for (int i = 0; i < el->el.size(); i++) {
            ss << a[el->el[i]];
        }
        if (el->nxt) {
            ss << " ";
        }
        el = el->nxt;
    }
    return ss.str();
}

std::string fail(const list<std::string> &src) {
	std::stringstream ss;
    list_el <std::string> *el = src.head;
    while (el)
    {
        for (int i = 0; i < el->el.size(); i++) {
            ss << '*';
        }
        if (el->nxt) {
            ss << " ";
        }
        el = el->nxt;
    }
	return ss.str();
}

bool solve(list_el<std::string> e, alphabet &a) {
    wrd w0(e.el);
    auto pairs = lc.find(w0.fp);
    if (pairs == lc.end()) return false;
    bool is_solved = false;
    for (int i = 0; i < pairs->second.size(); i++) {
        alphabet _a = a;
        if (translate(w0, pairs->second[i], _a)) {
            if (e.nxt) {
                is_solved = solve(*e.nxt, _a);
            }
            else {
                is_solved = true;
            }
        }
        if (is_solved) { 
            std::swap(a, _a); 
            break;
        } 
    }   
    return is_solved;
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
        if (!istr) return 0;
        std::stringstream ss(buf);
        //std::vector<std::string> vec;
        list<std::string> lst;
        while (ss) {
            std::string w;
            ss >> w;
            if (ss) {
                lst.add(w);
            }
        }
        alphabet a;
        if (solve(*lst.head, a)) {
            std::cout << success(lst, a);
        }
        else {
            std::cout << fail(lst);
        }

        std::cout << '\n';
        
    }
    return 0;
} 