#include <iostream>
#include "Datum.h"
#include "DatumStack.h"

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
