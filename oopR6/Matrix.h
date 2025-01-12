#ifndef MATRIX_H
#define MATRIX_H
#include "Array.h"

class Matrix
{
    public:
        Matrix();
        Matrix(int,int);
        Matrix(const Matrix&);
        int& operator()(int,int);
        Matrix& operator*(Matrix&);
        operator float();
        Matrix suma(int k);
        void print();

        virtual ~Matrix();

    protected:

    private:
        Array* data;
        int n;
        int m;
};

#endif // MATRIX_H
