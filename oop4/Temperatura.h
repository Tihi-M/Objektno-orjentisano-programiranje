#ifndef TEMPERATURA_H
#define TEMPERATURA_H

class Temperatura{
    private:
        int stepen;
        char znak;
        char jedinica;
        int trueVal() const;
    public:
        void setS(int);
        void setZ(char);
        void setJ(char);
        int getS() const;
        char getZ() const;
        char getJ() const;
        Temperatura();
        Temperatura(int,char,char);
        void convertToCelsius();
        void convertToFarenheit();
        int compareTo(const Temperatura&);
        void print() const;
};

#endif // TEMPERATURA_H
