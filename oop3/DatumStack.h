#ifndef DATUMSTACK_H
#define DATUMSTACK_H
#include "Datum.h"
class Node{
    private:
        Datum val;
        Node* next;
    public:
        Node(const Datum& val, Node* next = nullptr):val(val),next(next){};

        friend class DatumStack;
};

class DatumStack{
    private:
        Node *head,*first;
        int velicina;
    public:
        DatumStack();
        void push(const Datum&);
        void pop();
        void top() const;
        void print() const;
        int stackSize() const;
        void clearList(Node *head);
};


#endif // DATUMSTACK_H
