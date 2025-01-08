#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>

class Client
{
    public:
        Client();
        Client(std::string,std::string,int,int);
        virtual ~Client();

        std::string Getime() { return ime; }
        void Setime(std::string val) { ime = val; }

        std::string Getprezime() { return prezime; }
        void Setprezime(std::string val) { prezime = val; }

        int Gethh() { return hh; }
        void Sethh(int);

        int Getmm() { return mm; }
        void Setmm(int);

        float vrijemeCekanja(int,int) const;
        void print() const;
        void printTime(int,int) const;

        int compareTo(int,int);

    protected:

    private:
        std::string ime;
        std::string prezime;
        int hh;
        int mm;
};

#endif // CLIENT_H
