#include "StudentLista.h"
#include "Student.h"
#include <iostream>
StudentLista::StudentLista()
{
    //ctor
    this->head = nullptr;
    this->tail = nullptr;
    this->listSize = 0;
}

StudentLista::~StudentLista()
{
    //dtor
}

StudentLista::StudentLista(const StudentLista& other)
{
    //copy ctor
}

bool StudentLista::exists(const Student& d){
    Node* curr = this->Gethead();
    while(curr!=nullptr){
        if(curr->val.getGodina() == d.getGodina() && curr->val.getInd() == d.getInd())
            return true;
        curr=curr->next;
    }
    return false;
}

void StudentLista::addFirst(const Student& d){
    if(exists(d)){
        std::cout<<"Student sa ovim indeksom postoji"<<std::endl;
        return;
    }

    this->head = new Node(d,this->head);

    if(this->tail == nullptr){
        this->tail = this->head;
    }
    this->listSize+=1;
}

void StudentLista::addLast(const Student& d){
    if(exists(d)){
        std::cout<<"Student sa ovim indeksom postoji"<<std::endl;
        return;
    }

    if(this->head == nullptr){
        this->addFirst(d);
        return;
    }

    Node* newNode = new Node(d);
    this->tail->next = newNode;
    this->tail=newNode;
    this->listSize+=1;
}

void StudentLista::ukloni(int ind,int god){
    Node* prev = nullptr;
    Node* curr = this->Gethead();

    while(curr!= nullptr && (curr->val.getGodina()!=god && curr->val.getInd()!=ind)){
        prev = curr;
        curr = curr->next;
    }

    if(curr == nullptr)
        return;
    if(prev == nullptr){
        this->head = this->head->next;
        this->listSize-=1;
        return;
    }
    else{
        prev->next = curr->next;
        delete curr;
        this->listSize-=1;
        return;
    }
}

Node* StudentLista::midList(Node*& head){
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

Node* StudentLista::mergeList(Node*& left,Node*& right){
    Node* res = new Node;
    Node* temp = res;
    while(left!=nullptr && right!=nullptr){
        if(left->val.getOcjena() < right->val.getOcjena()){
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


Node* StudentLista::mergeSort(Node* head){
    //if(izbor != 2 || izbor!= 1)
    //{
     //   std::cout<<"Opcije su 1 za redjanje po uspjehu"<<std::endl;
      //  std::cout<<"I 2 za redjanje po indeksu"<<std::endl;
      //  exit(1);
    //}
    if(head == nullptr || head->next == nullptr)
        return head;

    Node* left = head;
    Node* right = midList(head);
    Node* temp = right->next;
    right->next = nullptr;

    right = temp;
    left = mergeSort(head);
    right = mergeSort(right);

    //if(izbor == 1)
        return mergeList(left,right);
}

void StudentLista::sort(){
    this->head = mergeSort(this->head);
}


void StudentLista::print() const{
    for(Node* it = this->head;it!=nullptr; it = it->next)
        it->val.print();
    std::cout<<std::endl;
}

