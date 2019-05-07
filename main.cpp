#include <iostream>
#include <fstream>
#include <string>
#include "list.h"

//#define NDEBUG

#include <cassert>

void fromFileToList(double min, double max, std::istream &basicIstream, List *list);


using namespace std;

int main(int argc, char *argv[]) {
    string filename = argv[1];
    char *p;
    double min = strtod(argv[2], &p);
    assert(*p == 0);
    if (*p) {// conversion failed because the input wasn't a number
        cout << "Podany zakres jest nieprawidłowy, kończę działanie!";
        return 1;
    }
    assert(*p == 0);
    double max = strtod(argv[3], &p);

    if (*p) {// conversion failed because the input wasn't a number
        cout << "Podany zakres jest nieprawidłowy, kończę działanie!";
        return 1;
    }
    auto fb = new filebuf();
    fb->open(filename, ios::in);
    assert(fb->is_open());
    if (!fb->is_open()) {
        cout << "Nie udało się otworzyć wskazanego pliku, kończę działanie!";
        return 1;
    }
    istream basicIstream(fb);
    List *list = new List();
    assert(list != nullptr);

    fromFileToList(min, max, basicIstream, list);

    fb->close();
    list->showRightToLeft();
    list->showLeftToRight();
    list->removeList();
    return 0;
}

void fromFileToList(double min, double max, istream &basicIstream, List *list) {
    double value;
    while (!basicIstream.eof()) {
        assert(isdigit(basicIstream.peek()));
        if (isdigit(basicIstream.peek())) {
            basicIstream >> value;
            assert(value >= min);
            assert(value <= max);
            if (value >= min && value <= max)
                list->add(value);
            else cout << "poza zakresem" << endl;
        } else {
            cout << "nie liczba" << endl;
            basicIstream.ignore();
        }
    }
}
