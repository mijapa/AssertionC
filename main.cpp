#include <iostream>
#include <fstream>
#include <string>
#include "list.h"

#define NDEBUG
#include <cassert>


using namespace std;

int main(int argc, char *argv[]) {
    string filename = argv[1];
    double min = atof(argv[2]);
    double max = atof(argv[3]);
    double value;
    string str;
    auto fb = new filebuf();
    fb->open(filename, ios::in);
    assert(fb->is_open());
    istream file(fb);
    List *list = new List();
    assert(list != nullptr);
    while (!file.eof()) {
        if (isdigit(file.peek())) {
            file >> value;
            assert(value >= min);
            assert(value <= max);
            if (value >= min && value <= max)
                list->add(value);
            else cout << "poza zakresem" << endl;
        } else {
            cout << "nie liczba" << endl;
            file.ignore();
        }
    }
    fb->close();
    list->showRightToLeft();
    list->showLeftToRight();
    list->removeList();
    return 0;
}
