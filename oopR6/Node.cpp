#include "Node.h"
#include <iostream>

#ifndef NODE_CPP
#define NODE_CPP


template<class T>
Node<T>& Node<T>::operator+=(T a)
{
    if(a <= this->value){
        if(this->left == 0){
            Node<T>* temp = new Node(a);
            this->left = temp;
        }
        else
            *this->left += a;
    }
    else{
        if(this->right == 0){
            Node <T>* temp = new Node(a);
        this->right = temp;
        }
        else
            *this->right += a;
    }
    return *this;
}

template<class T>
T Node<T>::minValue(){
    if(this->left == 0)
        return this->value;
    else return (this->left)->minValue();

}

#endif // NODE_CPP
