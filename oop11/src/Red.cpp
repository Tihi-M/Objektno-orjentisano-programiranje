#ifndef RED_CPP
#define RED_CPP

#include "Red.h"
#include <iostream>

template<class T>
Red<T>::Red(int n)
{
    this->data = new T[n];
    this->cap=n;
    this->pop=0;
}

template<class T>
Red<T>::Red(const Red<T>& r){
    this->data = new T[r.cap];
    this->cap = r.cap;
    this->pop = r.pop;

    for(int i=0;i < this->pop;i++)
        this->data[i] = r.data[i];
}

template<class T>
Red<T>& Red<T>::operator=(const Red<T>& r){
    if(&r == this){
        return *this;

    }
    delete[] this->data;

    this->data = new T[r.cap];
    this->cap = r.cap;
    this->pop = r.pop;

    for(int i = 0; i < this->pop;i++)
        this->data[i] = r.data[i];

    return *this;
}

template<class T>
T& Red<T>::operator[](int i){
    if(i < 0 || i >= pop){
        std::cout<<"Indeks van opsega"<<std::endl;
        exit(1);
    }
    return this->data[i];
}

template<class T>
Red<T>& Red<T>::operator+=(T obj){
    if(this->pop == this->cap){
        std::cout<<"Red je pun"<<std::endl;
        exit(2);
    }
    this->data[this->pop++] = obj;
    return *this;
}

template<class T>
T Red<T>::popp(){
    if(this->pop == 0){
        std::cout<<"red je prazan"<<std::endl;
        exit(3);

    }
    T ret = data[0];
}
#endif
