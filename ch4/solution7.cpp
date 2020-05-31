#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>


struct turt {
    std::string name;
    int order = 0;
    turt* next = nullptr;
    turt* prev = nullptr;
};

struct turtles {
    void clear(turt* t) {
        if (!t) {
            return;
        }
        auto prev = t->prev;
        delete t;
        clear(prev);
    }
    ~turtles() {
        clear(tail);
    }
    turt* head = nullptr;
    turt* tail = nullptr;
    turt* find(int order) {
        turt* res = head;
        while (res) {
            if (res->order == order) {
                break;
            }
            res = res->next;
        }
        return res;
    }
    void print() {
        turt* t = head;
        while (t) {
            std::cout << t->order << ' ';
            t = t->next;
        }
        std::cout << std::endl;
    }
    void go_head(turt* t) {
        if (t == head) {
            return;
        }
        t->prev->next = t->next;
        t->next->prev = t->prev;
        t->prev = nullptr;
        t->next = head;
        head->prev = t;
        head = t;
    }
    void push_back(turt* t) {
        if (tail) {
            tail->next = t;
            t->prev = tail;
            tail = t;
        } else {
            head = t;
            tail = t;
        }
    }
};

void resort(turtles& T, turt* t, std::vector<std::string> &moved) {
    //T.print();
    for (int i = t->order-1; i >= 0; i--) {
        auto found = T.find(i);
        if (found != T.head) {
            T.go_head(found);
            moved.push_back(found->name);
        }
    }
    //T.print();
}

void solve(turtles& o, turtles &w) {
    turt* ot = o.head;
    turt* ow = w.head;
    std::vector<std::string> solution;
    while (ot && ow) {
        if (ot->order != ow->order) {
            resort(o, ot, solution);
            ot = o.head;
            ow = w.head;
            continue;
        }
        ot = ot->next;
        ow = ow->next;
    }
    for (int i = 0; i < solution.size(); i++) {
        std::cout << solution[i] << std::endl;
    }

}

int main(void) {
#if __GNUC__
    std::istream& istr = std::cin;
#else 
    std::fstream istr(R"(C:\fedosin\repos\ski\ch4\test.txt)");
#endif
    int tc;
    istr >> tc;
    for (int i = 0; i < tc; i++) {
        if (tc) {
            std::cout << std::endl;
        }
        int num;
        std::map<std::string, turt*> tmap;
        istr >> num;
        turtles Torigin, Twanna;
        istr.ignore();
        for (int j = 0; j < num; j++) {
            turt* t = new turt;
            std::getline(istr, t->name);
            Torigin.push_back(t);
            tmap[t->name] = t;
        }
        for (int j = 0; j < num; j++) {
            turt* t = new turt();;
            std::getline(istr, t->name);
            t->order = j;
            tmap[t->name]->order = j;
            Twanna.push_back(t);
        }
        solve(Torigin, Twanna);
    }

    return 0;
}