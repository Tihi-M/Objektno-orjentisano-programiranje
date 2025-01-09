#include "UgaoLista.h"
#include <iostream>
UgaoLista::UgaoLista()
{
    this->head = nullptr;
    this->listSize = 0;
}

UgaoLista::~UgaoLista()
{
    //dtor
}

void UgaoLista::addFirst(const Ugao& u1){
    Node* newNode = new Node;
    newNode->val = u1;
    newNode->next = this->head;
    this->head = newNode;
    this->listSize++;
}

void UgaoLista::addLast(const Ugao& u1){
    if(this->head == nullptr)
    {
        this->addFirst(u1);
        return;
    }
    Node* temp = this->head;
    while(temp->next != nullptr)
        temp = temp->next;
    Node* newNode = new Node;
    newNode->val = u1;
    newNode->next = nullptr;
    temp->next = newNode;
    this->listSize+=1;
}

void UgaoLista::ukloni(const Ugao& u2){
    Node* temp = this->head;
    Node* prev = nullptr;
    while(temp != nullptr && temp->val.compareTo(u2) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == nullptr)
        return;
    if(prev == nullptr){
        this->head = this->head->next;
        this->listSize-=1;
        return;
    }
    else{
        prev->next = temp->next;
        this->listSize-=1;
    }
}

void UgaoLista::print() const{
    Node* temp = this->head;
    while(temp!=nullptr){
        temp->val.print();
        temp = temp->next;
    }
    std::cout<<std::endl;
}

Node* UgaoLista::midList(Node*& head){
    if(head == nullptr)
        return head;
    Node* temp = nullptr;
    Node* slow = head;
    Node* fast = head;

    while(fast!=nullptr && fast->next!=nullptr){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    return temp;
}

Node* UgaoLista::mergeList(Node*& left,Node*& right){
    Node* res = new Node;
    Node* temp = res;
    while(left != nullptr && right != nullptr){
        if(left->val.compareTo(right->val) == -1){
            temp->next = left;
            left = left->next;
        }
        else{
            temp->next = right;
            right = right->next;

        }
        temp = temp->next;
    }
    if(left!=nullptr)
        temp->next = left;
    if(right!=nullptr)
        temp->next = right;
    return res->next;
}

Node* UgaoLista::mergeSort(Node*& head){
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

void UgaoLista::sort(){
    this->head = mergeSort(head);
}

void UgaoLista::prosijecnaVrijednost() const{
    Ugao sum;
    Node* temp = this->head;
    while(temp!=nullptr){
        sum=sum+temp->val;
        temp=temp->next;
    }

    sum.Setsec(sum.Getsec()/this->listSize);
    sum.Setmin(sum.Getmin()/this->listSize);
    sum.Setstep(sum.Getstep()/this->listSize);

    sum.print();
}
