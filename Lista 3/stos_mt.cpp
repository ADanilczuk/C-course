#include "stos_hd.h"
#include <iostream>

Stos::Stos() : pojemnosc(1), ilosc(0)
{
    stos = new string[1];
}

Stos::Stos(int poj): pojemnosc(poj), ilosc(0)
{
    stos = new string[poj];
}

Stos::Stos(initializer_list<string> listy): pojemnosc(listy.size), ilosc(0)
{
    stos = new string[listy.size];

    for(auto s : listy)
    {
        wloz(s);
        ilosc++;
    }
}

string Stos::sprawdz()
{
    if(ilosc== 0) throw std::range_error("Stos jest pusty, nie mam co wyswietlic");
    return stos[ilosc-1];
}

void Stos::wloz(string st)
{
    if(pojemnosc == ilosc) throw std::range_error("Stos jest juz zapelniony");
    stos[ilosc] = st;
    ilosc++;
}


string Stos::sciagnij()
{
    if(ilosc == 0) throw std::range_error("Stos jest juz pusty");
    ilosc--;
    return stos[ilosc];
}

