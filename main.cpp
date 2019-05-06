#include <iostream>
#include <fstream>
#include <string>
#include "list.h"


using namespace std;

/**
 * Funkcja ignoruje napotkane białe znaki w strumieniu
 * zwraca liczbę usuniętych znaków z strumienia
 */
int ignoreWhiteMarks(istream &in) {
    int howMany = 0;
    while (in.peek() == 10 || in.peek() == 32)
        in.ignore();
    return howMany;
}

int main() {
    int value;
    char what;
    string str;
    auto fb = new filebuf();
    fb->open("file.txt", ios::in);
    istream plik(fb);
    List *list = new List();
    while (!plik.eof()) {
        ignoreWhiteMarks(plik);
        what = plik.peek(); //podgl�damy co jest w strumieniu
        if (isdigit(what)) {
            plik >> value;
            cout << "Liczba: " << value << endl;
            list->add(value);
        } else {
            plik >> str;
            cout << "Nie liczba: " << str << ";" << endl;
        }
    }
    fb->close();

    list->showRightToLeft();
    list->showLeftToRight();
    list->removeList();
    return 0;
}
