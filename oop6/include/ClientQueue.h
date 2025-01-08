#ifndef CLIENTQUEUE_H
#define CLIENTQUEUE_H
#include "Client.h"

class Node{
    Client val;
    Node* next;

    Node(const Client& val, Node* next = nullptr):val(val),next(next){};
    Node():val(Client()),next(nullptr){};

    friend class ClientQueue;
};

class ClientQueue
{
    public:
        ClientQueue();
        virtual ~ClientQueue();

        int GetqueueSize() { return queueSize; };
        void push(const Client&);
        void pop();
        void top();
        void sort();
        float average(int,int) const;
        void print();
    protected:

    private:
        Node* head;
        Node* tail;
        int queueSize;
        Node* midList(Node*&);
        Node* mergeSort(Node*);
        Node* mergeList(Node*&,Node*&);
};

#endif // CLIENTQUEUE_H
