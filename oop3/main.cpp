#include <iostream>
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

int DatumStack::stackSize() const{
    return this->velicina;
}

DatumStack::DatumStack(){
    this->head = nullptr;
    this->first = nullptr;
    this->velicina = 0;
}

void DatumStack::push(const Datum& d){
    if(this->head ==nullptr){
        this->head = new Node(d,this->head);
        if(this->first == nullptr)
            this->first = this->head;

        this->velicina +=1;
        return;
    }
    Node *newNode = new Node(d);
    this->first->next = newNode;
    this->first=newNode;
    this->velicina += 1;
}

void DatumStack::pop(){
    if(head == nullptr)
        return;
    std::cout<<"Popped: "<<std::endl;
    this->top();
    Node* prev = nullptr;
    for(Node* i = head; i->next != nullptr; i = i->next){
        prev = i;
    }
    delete first;
    prev->next = nullptr;
    this->first = prev;
    this->velicina-=1;
}

void DatumStack::top() const{
    this->first->val.print();
}

void DatumStack::print() const{
    for(Node* i = this->head; i != nullptr;i = i->next)
        i->val.print();
}

void DatumStack::clearList(Node *head){
    if(head == nullptr)
        return;
    clearList(head->next);
    delete head;
}
int main()
{
    int d,m,g;
    std::cin>>d>>m>>g;
    Datum d1(d,m,g);
    //d1.print();
    //2 std::cout<<d1.prosloDana();
    Datum d2 = d1.prethodniDan();
    //d2.print();

    Datum d3 = d1.naredniDan();
    //d3.print();

    //std::cout<<d3.compareTo(d2)<<std::endl;

    DatumStack st1;
    st1.push(d1);
    st1.push(d2);
    st1.push(d3);
    st1.print();
    std::cout<<st1.stackSize()<<std::endl;

    st1.pop();
    std::cout<<"After pop: "<<std::endl;
    st1.print();
    //std::cout<<st1.stackSize()<<std::endl;
    return 0;
}
