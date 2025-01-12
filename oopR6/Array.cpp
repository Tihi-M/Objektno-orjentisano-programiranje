#include "Array.h"
#include <iostream>

Array::Array()
{
    this->m = 0;
    this->data = nullptr;
}


Array::Array(int m)
{
    this->m = m;
    this->data = new int[m];
    for(int i = 0;i < m;i++)
        this->data[i] = 0;
}

void Array::operator=(const Array& a){
    this->m = a.m;
    this->data = new int[this->m];

    for(int i = 0; i < this->m;i++)
        this->data[i] = a.data[i];
}

Array::~Array()
{
    delete[] this->data;
}

Array& Array::operator+=(const Array& a){
    int* novi = new int[this->m + a.m];
    int j = 0;
    for(int i = 0; i < this->m;i++){
        novi[j] = this->data[i];
        j++;
    }
    for(int i = 0;i < a.m;i++){
        novi[j] = a.data[i];
        j++;
    }
    delete[] this->data;
    this->data = novi;
    this->m += a.m;

    return *this;
}

void Array::setElem(int pos,int value) {
    if(pos<0)
        throw NevalidniIndeksi();
    if(pos >= this->m)
        throw NevalidniIndeksi();
    else this->data[pos] = value;
}

void Array::print(){
    for(int i =0; i < this->m ;i++)
        std::cout<<this->data[i]<< " ";
    std::cout<<std::endl;
}
