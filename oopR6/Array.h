#ifndef ARRAY_H
#define ARRAY_H

class ArrayEx
{
public:
    const char* what() const noexcept{
        return "Greska(array)";
    }

};

class NevalidniIndeksi : public ArrayEx{
public:
    const char* what() const noexcept
    {
        return "indeksi nisu validno zadati";
    }
};

class Array
{
    public:
        Array();
        Array(int);
        virtual ~Array();

        void operator=(const Array&);
        Array& operator+=(const Array&);
        void setElem(int pos,int val);

        void print();
        friend class Matrix;
    protected:
        int* data;
        int m;
};

#endif // ARRAY_H
