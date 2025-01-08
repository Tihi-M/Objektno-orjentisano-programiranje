#include "TemperaturaLista.h"
#include <iostream>
#include "Temperatura.h"
TemperaturaLista::TemperaturaLista()
{
    this->head = nullptr;
    this->listSize = 0;
    //ctor
}

TemperaturaLista::~TemperaturaLista()
{
    //dtor
}

void TemperaturaLista::addFirst(const Temperatura& t){
    this->head = new Node(t,this->head);
    this->listSize+=1;
}

void TemperaturaLista::addLast(const Temperatura& t){
    Node* temp = this->head;
    while(temp->next != nullptr)
        temp = temp->next;

    Node* newNode=new Node;
    newNode->next = nullptr;
    newNode->val=t;
    temp->next = newNode;
    this->listSize += 1;
}

void TemperaturaLista::ukloni(int s,char z,char j){
    Temperatura t(s,z,j);
    Node* temp = this->head;
    Node* prev = nullptr;
    while(temp!=nullptr && t.compareTo(temp->val) != 0){
        prev = temp;
        temp = temp->next;
    }
    if(temp == nullptr)
        return;
    if(prev == nullptr){
        this->listSize-=1;
        this->head = this->head->next;
        return;
    }
    else{
        prev->next = temp->next;
        delete temp;
        this->listSize-=1;
        return;
    }
}

Node* TemperaturaLista::midList(Node*& head){
    if(head == nullptr)
        return head;
    Node* temp = nullptr;
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next !=nullptr){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    return temp;
}

Node* TemperaturaLista::mergeList(Node*& left,Node*& right){
    Node* res = new Node;
    Node* temp = res;
    while(left!=nullptr && right!=nullptr){
        if(left->val.compareTo(right->val) == -1){
                temp->next = left;
                left = left->next;
        }
        else{
            temp->next = right;
            right=right->next;
        }
        temp = temp->next;
    }
    if(left != nullptr)
        temp->next = left;
    if(right != nullptr)
        temp->next = right;

    return res->next;
}

Node* TemperaturaLista::mergeSort(Node* head){
    if(head == nullptr || head->next == nullptr)
        return head;

    Node* left = head;
    Node* right = midList(head);
    Node* temp = right->next;
    right->next = nullptr;
    right = temp;

    left = mergeSort(head);
    right = mergeSort(right);

    return mergeList(left,right);
}

void TemperaturaLista::sort(){
    this->head = mergeSort(this->head);
}

void TemperaturaLista::print(){
    for(Node* it = this->head;it != nullptr; it = it->next){
        it->val.print();
    }
    std::cout<<std::endl;
}
