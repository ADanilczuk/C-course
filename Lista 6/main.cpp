#include "classes.hpp"

using namespace std;


int main()
{

   Zmienna::wstaw("x", 2);
   cout<<"x"<<"=2"<<endl;
   Zmienna::wstaw("y", 5);
   cout<<"y"<<"=5"<<endl<<endl;

    Wyrazenie *test1 = new Dzielenie(
            new Mnozenie(
                    new Odejmowanie(
                                    new Zmienna("x"),
                                    new Liczba(1)),
                    new Zmienna("x")), new Liczba(2));
    cout << test1->opis() << '\n';
    cout <<"="<< test1->oblicz() << endl;

    Wyrazenie *test2 = new Dzielenie(new Dodawanie(
                                                    new Liczba(3),
                                                    new Liczba(5)),
                                    new Dodawanie(
                                                     new Liczba(2),
                                                     new Mnozenie(
                                                                     new Zmienna("x"),
                                                                     new Liczba(7))));
    cout << test2->opis() << '\n';
    cout <<"="<< test2->oblicz() << endl;

    Wyrazenie *test3 = new Odejmowanie(
            new Dodawanie(
                    new Liczba(2),
                    new Mnozenie(
                            new Zmienna("x"),
                            new Liczba(7))),
            new Dodawanie(
                    new Mnozenie(
                            new Zmienna("y"),
                            new Liczba(3)),
                    new Liczba(5)));
    cout << test3->opis() << '\n';
    cout <<"="<< test3->oblicz() << endl;

    Wyrazenie *test4 = new Dzielenie(
            new Cosinus(
                    new Mnozenie(
                            new Dodawanie(
                                    new Zmienna("x"),
                                    new Liczba(1)),
                            new Zmienna("x"))),
            new Potega(new Potega(
                    new Zmienna("x"),
                    new Liczba(2)), new Liczba (2)));
    cout << test4->opis() << '\n';
    cout <<"="<< test4->oblicz() << endl;
    cout <<endl;

    Wyrazenie *test6 = new Odwr(new Liczba(7));
    cout << test6->opis() << '\n';
    cout <<"="<< test6->oblicz() << endl;

    cout <<endl;


    Wyrazenie *test5 = new Liczba(7);
    cout << test5->opis() << '\n';
    cout <<"="<<test5->oblicz();

    return 0;
}
