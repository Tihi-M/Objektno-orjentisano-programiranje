#ifndef UGAOLISTA_H
#define UGAOLISTA_H
#include "Ugao.h"

class Node{
    Ugao val;
    Node* next;

    Node(const Ugao& val,Node* bext = nullptr):val(val),next(next){};
    Node():val(Ugao()),next(nullptr){};

    friend class UgaoLista;

};

class UgaoLista
{
    public:
        UgaoLista();
        virtual ~UgaoLista();

        int GetlistSize() { return listSize; }
        void addFirst(const Ugao&);
        void addLast(const Ugao&);
        void ukloni(const Ugao&);
        void sort();
        void prosijecnaVrijednost()const;
        void print() const;
    protected:

    private:
        Node* head;
        int listSize;
        Node* midList(Node*& head);
        Node* mergeList(Node*& left,Node*& right);
        Node* mergeSort(Node*& head);
};

#endif // UGAOLISTA_H
