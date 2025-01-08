#include "ClientQueue.h"
#include "Client.h"
#include <iostream>
ClientQueue::ClientQueue()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->queueSize = 0;
}

ClientQueue::~ClientQueue()
{
    //dtor
}

void ClientQueue::push(const Client& c){
    Node* newNode = new Node(c,nullptr);

    if(this->head == nullptr ){
        this->head = newNode;
        this->tail = newNode;
        this->queueSize+=1;
        return;
    }
    this->tail->next = newNode;
    this->tail = newNode;
    this->queueSize+=1;
}

void ClientQueue::top(){
    this->tail->val.print();
    std::cout<<std::endl;
}

void ClientQueue::pop(){
    this->top();

    Node* prev = nullptr;
    Node* temp = this->head;
    while(temp->next != nullptr)
    {
        prev = temp;
        temp =temp->next;
    }

    prev->next=nullptr;
    delete temp;
    this->queueSize-=1;
}

float ClientQueue::average(int hh,int mm) const{
    float sum=0;
    Node* temp = this->head;
    while(temp != nullptr){
        sum+=temp->val.vrijemeCekanja(hh,mm);
        temp=temp->next;
    }

    return (sum/this->queueSize)/60;
}

Node* ClientQueue::midList(Node*& head){
    if(head == nullptr)
        return head;
    Node* temp = nullptr;
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return temp;
}

Node* ClientQueue::mergeList(Node*& left,Node*& right){
    Node* res = new Node;
    Node* temp = res;

    while(left != nullptr && right != nullptr){
        if(left->val.compareTo(right->val.Gethh(),right->val.Getmm()) == -1){
                temp->next = left;
                left = left->next;
           }
           else{
                temp->next = right;
                right = right->next;
           }
           temp = temp->next;
    }
    if(left != nullptr)
        temp->next = left;
    if(right != nullptr)
        temp->next = right;

    return res->next;
}

Node* ClientQueue::mergeSort(Node* head){
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

void ClientQueue::sort(){
    this->head = mergeSort(this->head);

}


void ClientQueue::print(){
    Node* temp = this->head;

    while(temp!=nullptr){
        temp->val.print();
        temp=temp->next;
    }
    std::cout<<std::endl;
}
