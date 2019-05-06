#include <iostream>
#include <sstream>
#include  "list.h"

template<class T>
std::string valueToString(T value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

element::element(int v) {
    this->value = v;
    this->next = nullptr;
    this->previous = nullptr;
}

element::~element() = default;


List::List() {
    std::cout << "Inicjalizuję listę!" << std::endl;
    this->head = nullptr;
    this->tail = nullptr;
}

element *List::add(int a) {
    auto *temp = new element(a);
    if (this->tail == nullptr) {//empty list
        temp->next = nullptr;
        temp->previous = nullptr;
        head = temp;
        tail = temp;
    } else {
        temp->next = nullptr;
        temp->previous = tail;
        tail->next = temp;
        tail = temp;

    }
    return temp;
}

List::~List() {
    element *x = head;
    while (x->next != nullptr) {
        x = x->next;
        delete x->previous;
    }
    delete x;
    head = nullptr;
    tail = nullptr;

}

void List::removeList() {
    std::cout << "Usuwam listę!" << std::endl;
    delete this;
}

void List::showRightToLeft() {
    element *x = tail;
    while (x->previous != nullptr) {
        std::cout << valueToString(x->value) + ", ";
        x = x->previous;
    }
    std::cout << valueToString(x->value) + "." << std::endl;
}

void List::showLeftToRight() {
    element *x = head;
    while (x->next != nullptr) {
        std::cout << valueToString(x->value) + ", ";
        x = x->next;
    }
    std::cout << valueToString(x->value) + "." << std::endl;

}
