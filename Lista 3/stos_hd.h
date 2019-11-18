#ifndef stos_hd
#define stos_hd

#include <string>


using namespace std;

class Stos
{
private:
    int pojemnosc;
    int ilosc;
    string *stos;

public:
    Stos();
    Stos(int);
    Stos(initializer_list<string>);
    Stos(Stos&&);
    Stos(const Stos&);


    string sprawdz();
    void wloz(string);
    string sciagnij();

    ~Stos(){delete [] stos;}

};
#endif // stos_hd
