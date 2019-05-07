#include <iostream>
#include <fstream>
#include <string>
#include "list.h"

#define NDEBUG

void fromFileToList(double min, double max, std::istream &file, List *list);

#include <cassert>


using namespace std;

int main(int argc, char *argv[]) {
    string filename = argv[1];
    double min = atof(argv[2]);
    double max = atof(argv[3]);
    string str;
    auto fb = new filebuf();
    fb->open(filename, ios::in);
    assert(fb->is_open());
    if (!fb->is_open()) {
        cout << "Nie udało się otworzyć wskazanego pliku, kończę działanie";
        return 1;
    }
    istream file(fb);
    List *list = new List();
    assert(list != nullptr);

    fromFileToList(min, max, file, list);

    fb->close();
    list->showRightToLeft();
    list->showLeftToRight();
    list->removeList();
    return 0;
}

void fromFileToList(double min, double max, istream &file, List *list) {
    double value;
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
}
