#include <iostream>
#include "Datum.h"
#include "DatumVrijeme.h"

class Node{
    Datum val;
    Node* next;

    Node(const Datum& val,Node* next = nullptr):val(val),next(next){}

    friend class ListaDatuma;
};

class ListaDatuma{


    public:
        Node *head, *tail;
        ListaDatuma();
        ~ListaDatuma();
        ListaDatuma(const Datum&);
        ListaDatuma(const ListaDatuma&);

        void addFirst(const Datum&);
        void addLast(const Datum&);
        void ukloni(const Datum&);

        void print() const;

    private:
        void clearList(Node *head);

};

ListaDatuma::ListaDatuma(){
    this->head = nullptr;
    this->tail = nullptr;
}

ListaDatuma::ListaDatuma(const Datum& d){
    this->head = nullptr;
    this->tail = nullptr;

    this->addFirst(d);
}

void ListaDatuma::addFirst(const Datum& d){
    this->head = new Node(d,this->head);

    if(this->tail == nullptr){
        this->tail = this->head;
    }

}

void ListaDatuma::addLast(const Datum& d){
    if(this->head == nullptr){
        this->addFirst(d);
        return;
    }

    Node *newNode = new Node(d);
    this->tail->next = newNode;
    this->tail = newNode;

}


void ListaDatuma::print() const{
    for(Node* i = this->head; i != nullptr; i = i->next){
        i->val.print();
    }
}

ListaDatuma::~ListaDatuma(){

}

int main()
{
    int d,m,g;
    std::cin >> d >> m >> g;
    Datum d1(d,m,g);
    //d1.print();
    //std::cout<<d1.getDay()<<std::endl;
    //std::cout<<d1.getMonth()<<std::endl;
    //std::cout<<d1.getYear()<<std::endl;

    Datum d2 = d1.sljedeci();
    //d2.print();

    Datum d3 = d1.prethodni();
    //d3.print();

   // std::cout<<d1.brojDanaOdPocetkaGod()<<std::endl;

    //DatumVrijeme dv1(d1.getDay(),d1.getMonth(),d1.getYear(),12,58);
    //dv1.print();

    ListaDatuma l1;
    l1.addFirst(d1);
    l1.addFirst(d3);
    l1.addLast(d2);
    l1.print();
    return 0;
}
