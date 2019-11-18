#include "classes.hpp"

Wyrazenie::Wyrazenie(std::string typ) : typ(typ) {}

Operator1::Operator1(Wyrazenie *w,std::string typ) : Wyrazenie(typ), w1(w) {}
Operator2::Operator2(Wyrazenie *wyr1, Wyrazenie *wyr2, std::string typ) : Operator1(wyr1, typ), w2(wyr2) {}


Dodawanie::Dodawanie(Wyrazenie *w1, Wyrazenie *w2): Operator2(w1,w2,"d") {}
double Dodawanie::oblicz() const
{
    return w1->oblicz() + w2->oblicz();
}

std::string Dodawanie::opis() const
{
    return w1->opis() + "+" + w2->opis();
}

Odejmowanie::Odejmowanie(Wyrazenie *w1, Wyrazenie *w2): Operator2(w1,w2,"o") {}
double Odejmowanie::oblicz() const
{
    return w1->oblicz() - w2->oblicz();
}

std::string Odejmowanie::opis() const
{
    if (w2->typ == "o" || w2->typ == "d")
    {
        return w1->opis() + "-(" + w2->opis() + ")";
    }
    else
    {
         return w1->opis() + "-" + w2->opis();
    }
}

Mnozenie::Mnozenie(Wyrazenie *w1, Wyrazenie *w2): Operator2(w1,w2,"m"){}
double Mnozenie::oblicz() const
{
    return w1->oblicz() * w2->oblicz();
}

std::string Mnozenie::opis() const
{
    std::string s;
    if (w1->typ == "o" || w1->typ == "d")
    {
        s="(" + w1->opis() + ")*";
    }
    else
    {
         s= w1->opis() + "*";
    }
    if (w2->typ == "o" || w2->typ == "d")
    {
         s= s+ "(" + w2->opis() + ")";
    }
    else s= s+ w2->opis();
    return s;
}


Dzielenie::Dzielenie(Wyrazenie *w1, Wyrazenie *w2): Operator2(w1,w2,"dz"){}
double Dzielenie::oblicz() const
{
    return w1->oblicz() / w2->oblicz();
}

std::string Dzielenie::opis() const
{
    std::string s;
    if (w1->typ == "o" || w1->typ == "d")
    {
        s="(" + w1->opis() + ")/";
    }
    else
    {
         s= w1->opis() + "/";
    }
    if (w2->typ == "o" || w2->typ == "d")
    {
         s= s+ "(" + w2->opis() + ")";
    }
    else s= s+ w2->opis();
    return s;
}

Logarytm::Logarytm(Wyrazenie *w1, Wyrazenie *w2): Operator2(w1,w2,"l"){}
double Logarytm::oblicz() const
{
    return log(w2->oblicz()) / log(w1->oblicz());
}

std::string Logarytm::opis() const
{
    std::string s;
    if (w1->typ != "st")
        s= "log (" + w1->opis() + ")";
    else s= "log " + w1->opis();
    if (w2->typ != "st"&& w2->typ != "trg" && w2->typ != "bezw" )
        s= s+ " z (" + w1->opis() + ")";
    else s= s+ " z " + w1->opis();

    return s;
}

Modulo::Modulo(Wyrazenie *w1, Wyrazenie *w2): Operator2(w1,w2,"mod"){}
double Modulo::oblicz() const
{
    return fmod(w1->oblicz(), w2->oblicz());
}

std::string Modulo::opis() const
{
    std::string s;
    if ( w1->typ != "bezw" && w1->typ != "trg"&& w1->typ != "st")
        s= "(" + w1->opis() + ") mod";
    else s= w1->opis() + "mod";
    if (w2->typ != "bezw" && w2->typ != "trg" && w2->typ != "st")
        s= s + "(" + w2->opis() + ")";
    else s= s + w2->opis();
    return s;
}

Potega::Potega(Wyrazenie *w1, Wyrazenie *w2): Operator2(w1,w2,"pot"){}
double Potega::oblicz() const
{
    return pow(w1->oblicz(), w2->oblicz());
}

std::string Potega::opis() const
{
    std::string s;
    if (w1->typ != "bezw" && w1->typ != "trg"&& w1->typ != "st")
        s="(" + w1->opis() + ")^";
    else  s= w1->opis() + "^";
    if (w2->typ != "bezw" && w2->typ != "trg"&& w2->typ != "st")
        s= s + "(" + w2->opis() + ")";
    else s= s + w2->opis();
    return s;
}


//Jednoargumentowe
Sinus::Sinus(Wyrazenie *w) : Operator1(w,"trg"){}
double Sinus::oblicz() const
{
    return sin(w1->oblicz());
}

std::string Sinus::opis() const
{
    return "Sin(" + w1->opis() +")";
}


Cosinus::Cosinus(Wyrazenie *w) : Operator1(w,"trg"){}
double Cosinus::oblicz() const
{
    return cos(w1->oblicz());
}

std::string Cosinus::opis() const
{
    return "Cos(" + w1->opis() +")";
}

Ln::Ln(Wyrazenie *w) : Operator1(w,"trg"){}
double Ln::oblicz() const
{
    return log(w1->oblicz());
}

std::string Ln::opis() const
{
   return "ln(" + w1->opis() + ")";
}


Bezw::Bezw(Wyrazenie *w) : Operator1(w,"bezw"){}
double Bezw::oblicz() const
{
    if (w1->oblicz()<0)
        return (-1)*w1->oblicz();
    else return w1->oblicz();
}

std::string Bezw::opis() const
{
    return "|" + w1->opis() + "|";
}

Przeciw::Przeciw(Wyrazenie *w) : Operator1(w,"1ar"){}
double Przeciw::oblicz() const
{
        return (-1)*w1->oblicz();
}

std::string Przeciw::opis() const
{
    if (w1->typ == "d" || w1->typ == "o")
        return "(-1)*(" + w1->opis() + ")";
    else  return "(-1)*" + w1->opis();
}


Odwr::Odwr(Wyrazenie *w) :  Operator1(w,"1ar"){}
double Odwr::oblicz() const
{
    return 1/w1->oblicz();
}

std::string Odwr::opis() const
{
    if (w1->typ == "d" || w1->typ == "o")
    {
        return "1/(" + w1->opis() + ")";
    }
    return "1/" + w1->opis();
}






