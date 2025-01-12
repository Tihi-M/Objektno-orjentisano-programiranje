#ifndef OCJENA_H
#define OCJENA_H


class Ocjena
{
    public:
        Ocjena();
        Ocjena(int,int);
        virtual ~Ocjena();

        int Getvrijednost() const { return vrijednost; }
        void Setvrijednost(int);
        int GetidPredmeta() const { return idPredmeta; }
        void SetidPredmeta(int);
    protected:

    private:
        int vrijednost;
        int idPredmeta;
};

#endif // OCJENA_H
