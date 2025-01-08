#ifndef TEMPERATURALISTA_H
#define TEMPERATURALISTA_H
#include "Temperatura.h"
class Node{
    Temperatura val;
    Node* next;

    Node(const Temperatura& val,Node* next = nullptr):val(val),next(next){};
    Node():val(Temperatura()),next(nullptr){};

    friend class TemperaturaLista;
};
class TemperaturaLista
{
    public:
        TemperaturaLista();
        virtual ~TemperaturaLista();

        int GetlistSize() { return listSize; }

        void addFirst(const Temperatura&);
        void addLast(const Temperatura&);
        void ukloni(int,char,char);
        void print();

        void sort();

    protected:

    private:
        Node* head;
        int listSize;
        Node* midList(Node*&);
        Node* mergeList(Node*&,Node*&);
        Node* mergeSort(Node*);
};

#endif // TEMPERATURALISTA_H
