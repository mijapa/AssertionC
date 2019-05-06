#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED


struct element {
    double value;
    element *next;
    element *previous;

    explicit element(double v);

    ~element();
};

class List {
private:
    element *head;
    element *tail;

public:
    List();

    virtual ~List();

    element *add(double a);

    void removeList();

    void showRightToLeft();

    void showLeftToRight();

};

#endif // LIST_H_INCLUDED
