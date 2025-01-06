#include <iostream>
#include "Skup.h"

Skup::Skup():cap(0),pop(0){
}

int Skup::setSize() const{
    return cap;
}

Skup::Skup(int x):cap(1),pop(1){
    data = new int[1];
    data[0]=x;
}
Skup::Skup(int *data_,int len):cap(len),pop(len){
    data = new int[len];
    for(int i = 0; i < len;i++)
            data[i] = data_[i];

    bubbleSort(this->data,this->pop);
}

void Skup::bubbleSort(int* data, int pop){
    for(int i = 0; i < pop-1;i++){
        bool swapped = false;
        for(int j = 0; j < pop-1-i;j++)
            if(data[j]  > data[j+1]){
                std::swap(data[j],data[j+1]);
                swapped = true;
            }
        if(!swapped)
            break;
    }
}

void Skup::print() const{
    for(int i = 0; i < pop;i++)
        std::cout<<data[i]<<" ";
    std::cout<<std::endl;
}

void Skup::setData(int *data) {;
    for(int i = 0; i < this->pop ;i++)
        this->data[i] = data[i];
}

void Skup::setPop(int x){
    this->pop = x;
}

void Skup::setCap(int x){
    this->cap = x;
}


Skup Skup::unija(const Skup& s) const{
    Skup res;
    int *data_ = new int[this->pop+s.pop];

    int i = 0;
    int j = 0;
    int e = 0;

    while(i<this->pop && j < s.pop){
        if(this->data[i] < s.data[j]){
            data_[e] = this->data[i];
            i++;
        }
        else if(this->data[i] > s.data[j]){
            data_[e] = s.data[j];
            j++;
            }
            else{
                data_[e] = s.data[j];
                j++;
                i++;
            }
        e++;
    }

    if(i < this->pop){
        while(i < this->pop){
            data_[e] = this->data[i];
            i++;
            e++;
        }
    }
    if(j < s.pop){
        while(j < s.pop){
            data_[e] = s.data[j];
            j++;
            e++;
        }
    }

    res.data = data_;
    res.cap = this->pop + s.pop;
    res.pop = e;
    return res;
}

int Skup::findPos(int x) const{
    for(int i = 0; i < this->pop;i++)
        if(this->data[i] == x)
        return i;
    return -1;
}

void Skup::delEl(int x){
    if(pop == 0)
        return;
    int i=findPos(x);
    std::cout<<"Pronadjen: "<<i<<std::endl;
    if(i != -1){
        int *data = new int[pop-1];
        for(int j = 0;j < pop-1;j++)
            if(j != i)
                data[j] = this->data[j];
        this->pop = pop-1;
        delete this->data;
        this->data = data;
    }
}

Skup Skup::presjek(const Skup& s) const{
    Skup res;
    int *data = new int[this->pop + s.pop];

    int i = 0;
    int j = 0;
    int e = 0;
    while(i < this->pop && j < s.pop){
        if(this->data[i] == s.data[j])
        {
            data[e] = this->data[i];
            e++;
        }
        i++;
        j++;
    }

    res.pop =
    res.pop = e;
    res.data = data;
    return res;
}

Skup& Skup::razlika(const Skup& s){
    Skup res;

    int *data = new int[this->pop];
    int e = 0;
    int i = 0;

    while(i<this->pop){
        bool duplicate = false;
        for(int j = 0; j < s.pop;j++)
            if(s.data[j] == this->data[i])
                {
                    duplicate = true;
                    break;
                }
        if(!duplicate){
            data[e] = this->data[i];
            e++;
        }
        i++;
    }
    delete[] this->data;
    this->data = data;
    this->cap = e;
    this->pop = e;
    return *this;
}


Skup::~Skup(){
}
