#include <iostream>
#include <sstream>
#include  "list.h"

#define NDEBUG

#include <cassert>

template<class T>
std::string valueToString(T value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

element::element(double v) {
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

element *List::add(double a) {
    auto *temp = new element(a);
    assert(temp != nullptr);
    if (this->tail == nullptr) {//empty list
        temp->next = nullptr;
        temp->previous = nullptr;
        head = temp;
        tail = temp;
    } else {//list has elements
        element *x = head;
        while (x != nullptr && x->value < a)
            x = x->next;
        if (x == nullptr) {//insert after tail
            temp->next = nullptr;
            temp->previous = tail;
            tail->next = temp;
            tail = temp;
        } else {//add before x
            temp->next = x;
            temp->previous = x->previous;
            if (x->previous != nullptr)//x has previous
                x->previous->next = temp;
            else //x is head
                head = temp;
            x->previous = temp;
        }
    }
    return temp;
}

List::~List() {
    element *x;
    while (head != nullptr) {
        x = head->next;
        delete head;
        head = x;
    }
    head = nullptr;
    tail = nullptr;

}

void List::removeList() {
    std::cout << "Usuwam listę!" << std::endl;
    delete this;
}

void List::showRightToLeft() {
    std::cout << "Od prawej do lewej: ";
    element *x = tail;
    while (x->previous != nullptr) {
        std::cout << valueToString(x->value) + ", ";
        x = x->previous;
    }
    std::cout << valueToString(x->value) + "." << std::endl;
}

void List::showLeftToRight() {
    std::cout << "Od lewej do prawej: ";
    element *x = head;
    while (x->next != nullptr) {
        std::cout << valueToString(x->value) + ", ";
        x = x->next;
    }
    std::cout << valueToString(x->value) + "." << std::endl;

}
