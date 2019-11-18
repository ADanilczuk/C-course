#include "classes.hpp"

using namespace std;

std::string to_string(double val)
{
    std::stringstream temp;
    temp << val;
    return temp.str();
}

std::vector<std::pair<std::string,double> > Zmienna::zmienne;

Zmienna::Zmienna(std::string nazwa) : Wyrazenie(std::string("s")), nazwa(nazwa) {}
void Zmienna::wstaw(std::string nazwa,double war)
{
    std::pair<std::string,double> temp (nazwa,war);
    Zmienna::zmienne.push_back(temp);
}

void Zmienna::zmien(std::string nazwa,double war)
{
    int i = 0;
    while(zmienne[i].first != nazwa) i++;
    zmienne[i].second=war;
}

double Zmienna::oblicz() const
{
    int i = 0;
    while(zmienne[i].first != nazwa) i++;
    return zmienne[i].second;
}

std::string Zmienna::opis() const
{
    return nazwa;
}

Liczba::Liczba(double war) : Wyrazenie(std::string("s")), wartosc(war) {}
double Liczba::oblicz() const
{
    return wartosc;
}

std::string Liczba::opis() const
{
    return to_string(wartosc);
}

Stala::Stala() : Wyrazenie(std::string("s")) {}

pi::pi() : wartosc(3.14), Stala() {}
double pi::oblicz() const
{
    return wartosc;
}

std::string pi::opis() const
{
     return to_string(wartosc);
}


e::e() : wartosc(2.71), Stala() {}
double e::oblicz() const
{
    return wartosc;
}

std::string e::opis() const
{
     return to_string(wartosc);
}


fi::fi() : wartosc(1.61), Stala() {}
double fi::oblicz() const
{
    return wartosc;
}

std::string fi::opis() const
{
    return to_string(wartosc);
}

