#include <iostream>
#include "klasy.h"

using namespace std;

int main()
{
    double x,y,a,b,c;

    try{
        cout << "Podaj wektor u " << endl<<"x= ";
        cin>>x;
        cout<<"y= ";
        cin>>y;
        wektor u(x,y);
        cout<<endl<<"Oto u po wpisaniu wspolrzednych"<<endl;
        wyswietl_wektor(u);

        cout <<endl<< "Podaj prosta k " << endl<<"A= ";
        cin>>a;
        cout<<"B= ";
        cin>>b;
        cout<<"C= ";
        cin>>c;
        prosta k(a,b,c);
        cout<<endl<<"\nOto prosta k po wpisaniu wspolrzednych"<<endl;
        wyswietl_prosta(k);


        cout << "Podaj wspolrzedne punktu P" << endl<<"X= ";
        cin>>x;
        cout<<"Y= ";
        cin>>y;
        punkt p(x,y);
        cout<<"\nOto punkt p po wpisaniu wspolrzednych"<<endl;
        wyswietl_punkt(p);

        cout<<"\n\n";
        cout<<"Punkt p po przesunieciu o wektor u ma wspolrzedne ";
        wyswietl_punkt(punkt(p.x, p.y, u));

        if (k.czy_prostopadly(u,k))
            cout<<"\nWektor u jest prostopadly do prostej k"<<endl;
        else
            cout<<"\nWektor u nie jest prostopadly do prostej k"<<endl;

         if (k.czy_rownolegly(u,k))
            cout<<"Wektor u jest rownolegly do prostej k"<<endl;
        else
            cout<<"Wektor u nie jest rownolegly do prostej k"<<endl;

         if (k.czy_na_prostej(p,k))
            cout<<"\nPunkt p le¿y na prostej k"<<endl;
        else
            cout<<"\nPunkt p nie le¿y na prostej k"<<endl;


        cout << "Podaj wspolrzedne punktu T" << endl<<"X= ";
        cin>>x;
        cout<<"Y= ";
        cin>>y;
        punkt t(x,y);

        cout<<"Prosta i przechodzaca przez punkty P i T jest postaci: ";
        prosta i(p.x, p.y, t.x, t.y);
        wyswietl_prosta(i);

        cout<<"\nProsta przechodzaca przez punkt oddalony od pocz¹tku uk³adu wspó³rzêdnych przez wektor u i prostopadla do niego ";
        prosta j(u);
        wyswietl_prosta(j);

        if (czy_prostopadle(k,i))
            cout<<"\nProsta k jest prostopadla do prostej i"<<endl;
        else
            cout<<"\nProsta k nie jest prostopadla do prostej i"<<endl;

        if (czy_rownolegle(k,i))
            cout<<"\nProsta k jest rownolegla do prostej i"<<endl;
        else
            cout<<"\nProsta k nie jest rownolegla do prostej i"<<endl;

        cout<<"Punkt przeciecia prostej k z prosta i ma wspolrzedne: ";
        punkt o=przeciecie(k,i);
        wyswietl_punkt(o);
}
catch(invalid_argument &ala) {cout<<ala.what();}
    return 0;
}
