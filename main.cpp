#include <iostream>
#include <fstream>
#include <string>
#include "list.h"
#include <cassert>


using namespace std;

int ignoreWhiteMarks(istream &in) {
    int howMany = 0;
    while (in.peek() == 10 || in.peek() == 32)
        in.ignore();
    return howMany;
}

int main() {
    int value;
    string str;
    auto fb = new filebuf();
    fb->open("file.txt", ios::in);
    istream file(fb);
    List *list = new List();
    while (!file.eof()) {
        file >> value;
        list->add(value);
    }
    fb->close();

    list->showRightToLeft();
    list->showLeftToRight();
    list->removeList();
    return 0;
}
