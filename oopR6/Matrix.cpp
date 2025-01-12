#include "Matrix.h"
#include "Array.h"
#include <iostream>


Matrix::Matrix()
{
    //ctor
}

Matrix::Matrix(int n,int m){
    this->n =n;
    this->m =m;

    this->data = new Array[this->n];

    for(int i = 0;i < this->n;i++){
        this->data[i].m=m;
        this->data[i].data = new int[m];
        for(int j = 0;j < this->m;j++)
            this->data[i].data[j] = 0;
    }
}

int& Matrix::operator()(int n,int m){
    return this->data[n].data[m];
}

Matrix::Matrix(const Matrix& c){
    this->m = c.m;
    this->n = c.n;
    this->data = new Array[this->n];

    for(int i = 0;i < this->n;i++)
    {
        this->data[i].m = m;
        this->data[i].data = new int[m];
        for(int j = 0;j < this->m;j++)
            this->data[i].data[j] = c.data[i].data[j];
    }
}

Matrix& Matrix::operator*(Matrix& a){
    Matrix* res = new Matrix(this->n,a.m);

    for(int i = 0;i < this->n;i++){
        for(int j = 0;j < a.m;j++){
            int temp = 0;
            for(int k = 0;k < a.n;k++)
                temp += (*this)(i,k)*a(k,j);

        (*res)(i,j) = temp;
        }
    }
    return *res;
}

Matrix::operator float(){
    float suma = 0;
    float broj = 0;

    for(int i =0; i < this->n ;i++){
        for(int j =0;j < this->m;j++){
            if(i > j){
                suma+=(*this)(i,j);
                broj++;
            }
        }
    }

    float rez = suma / broj;
    return rez;
}

Matrix Matrix::suma(int k){
    int broj_vrsta = 0;
    for(int i = 0;i  < this->n;i++){
        int sum = 0;
        for(int j = 0;j < this->m;j++)
            sum+=(*this)(i,j);
        if(sum > k)
            broj_vrsta++;
    }

    Matrix* nova = new Matrix(broj_vrsta,this->m);
    int a = 0;

    for(int i = 0; i < this->n;i++){
        int sum = 0;
        for(int j = 0;j < this->m;j++)
            sum += (*this)(i,j);

        if(sum > k){
            for(int l = 0;l < this->m;l++)
                (*nova)(a,l) = (*this)(i,l);

            a++;

        }
    }
    return (*nova);
}

void Matrix::print(){
    for(int i = 0;i < this->n;i++){
        for(int j =0; j < this->m;j++)
            std::cout<<(*this)(i,j)<<" ";
        std::cout<<std::endl;
    }
}

Matrix::~Matrix()
{
    //dtor
}
