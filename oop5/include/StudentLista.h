#ifndef STUDENTLISTA_H
#define STUDENTLISTA_H

#include "Student.h"

class Node
{
        private:
        Student val;
        Node* next;

        Node(const Student& val, Node* next = nullptr):val(val),next(next){};
        Node():val(Student()),next(nullptr){};
        friend class StudentLista;
};

class StudentLista
{
    public:
        StudentLista();
        virtual ~StudentLista();
        StudentLista(const StudentLista& other);

        Node* Gethead() { return this->head; }
        int GetlistSize() { return listSize; }

        void addFirst(const Student&);
        void addLast(const Student&);
        void ukloni(int,int);

        void print() const;
        void sort();

    protected:

    private:
        Node* head;
        Node* tail;
        int listSize;
        bool exists(const Student&);
        Node* midList(Node*&);
        Node* mergeList(Node*&,Node*&);
        Node* mergeSort(Node*);
};

#endif // STUDENTLISTA_H
