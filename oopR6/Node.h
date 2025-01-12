#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
    public:
        Node(T v):value(v),left(0),right(0){}
        Node& operator +=(T a);
        T minValue();

    protected:

    private:
        T value;
        Node* left;
        Node* right;
};
#include "Node.cpp"

#endif // NODE_H
