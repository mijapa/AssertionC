#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED


struct element {
    int value;
    element *next;
    element *previous;

    explicit element(int v);

    ~element();
};

class List {
private:
    element *head;
    element *tail;

public:
    List();

    virtual ~List();

    element *add(int a);

    void removeList();

    void showRightToLeft();

    void showLeftToRight();

};

#endif // LIST_H_INCLUDED
