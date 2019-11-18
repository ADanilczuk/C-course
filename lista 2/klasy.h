p#ifndef klasy
#define klasy

#include <stdexcept>
#include <cmath>

class wektor{
public:
    const double dx;
    const double dy;

    wektor()=default;

    wektor( double dx2, double dy2):dx(dx2),dy(dy2){};

    wektor( const wektor & wektor2):dx(wektor2.dx),dy(wektor2.dy){};

    //usuniecie przypisania kopiujacego
    wektor& operator = (const wektor&) = delete;

};



class punkt {
public:
    const double x;
    const double y;

    punkt()=default;

    //konstruktor ze wspó³rzêdnymi
    punkt(double x2, double y2):x(x2), y(y2){};

    //konstruktor z innym punktem i wektorem
    punkt(double x2, double y2, wektor u):x(x2+u.dx),y(y2+u.dy){};

    //konstruktor kopiuj¹cy
    punkt(const punkt & punkt2):x(punkt2.x),y(punkt2.y){};


    punkt& operator= (const punkt&)= delete;
};



class prosta{
private:
    double a;
    double b;
    double c;

    void normalizuj(){
        double dl=std::sqrt(this->a*this->a+this->b*this->b);
        this->a/=dl;
        this->b/=dl;
        this->c/=dl;
    }

public:
    double get_a() const { //ten const nalezy dopisac tez we wszystkich pozostalych funkcjach w ktorych przekazywane dane nie zmieniaja wartosci
        return this->a;
    }

    double get_b() const {
        return this->b;
    }

    double get_c() const {
        return this->c;
    }

    prosta(): a(1.0), b(0.0), c(0.0) {}
//= delete
    //konstruktor z para punktów
    prosta(double x1, double y1, double x2, double y2){
        this->a= y1-y2;
        this->b= x2-x1;
        this->c= (x1*y2)- (x2*y1);
        normalizuj();
    }

    //konstuktor z wektorem
    prosta(const wektor &u){
        this->a= u.dx;
        this->b= u.dy;
        this->c= -(u.dx*u.dx + u.dy*u.dy);
        normalizuj();
    }

    //konstruktor z podanymi wspólczynnikami prostej
    prosta(double a_, double b_, double c_){
        if (a_== 0 && b_==0) throw std::invalid_argument("Wspolczynniki przy x i y nie moga jednoczesnie byc 0");
        else
        {
            this->a= a_;
            this->b= b_;
            this->c= c_;
            normalizuj();
        }
    }

     wektor zloz(const wektor &v, const wektor &u) const //dopisujesz tez "const" i dajesz "&" przed nazwami przekazywanych argumentow (powinno byc w wiekszosci funkcji)
    {
        double x,y;
        x=v.dx+u.dx;
        y=v.dy+u.dy;
        double dlugosc= std::sqrt(x*x+y*y);
        x/=dlugosc;
        y/=dlugosc;
        return wektor(x,y);
    }

    //konstruktor z porsta i wektorem
    prosta(prosta k, const wektor &v){
        double dlugosc= std:: sqrt(v.dx*v.dx + v.dy+v.dy);
        wektor temp= zloz(wektor(-k.get_a(),k.get_a()), wektor(v.dx/dlugosc,v.dy/dlugosc));
        this->a=temp.dy;
        this->b=-temp.dx;
        this->c=-(this->a*v.dx+this->b*v.dy);
        normalizuj();
    }


    bool czy_prostopadly(wektor u, prosta l){
        if (u.dx==l.get_a() && u.dy==l.get_b()) return true;
        return false;
    }

    bool czy_rownolegly(wektor u, prosta l){
        if (u.dx==-l.get_b()&&u.dy==l.get_a()) return true;
        return false;
    }

    bool czy_na_prostej( punkt p,prosta l){
        if (-(l.get_a()*p.x+l.get_c())==p.y) return true;
        return false;
    }
};



bool czy_prostopadle( prosta l, prosta k)
{
    return (l.get_a()/l.get_b() * k.get_a()/k.get_b()== -1);
}

bool czy_rownolegle(prosta l, prosta k)
{
    if (l.get_a()/l.get_b() == k.get_a()/k.get_b()) return true;
    return false;
}

punkt przeciecie( prosta l, prosta k)
{
    double x,y,a1,a2,b1,b2,c1,c2;
    if (czy_rownolegle(l,k))
        throw std::invalid_argument("proste nie przecinaja sie");
    a1=l.prosta::get_a();
    a2=k.prosta::get_a();
    b1=l.prosta::get_b();
    b2=k.prosta::get_b();
    c1=l.prosta::get_c();
    c2=k.prosta::get_c();
    x= (((c2/b2) - (a1/b1))/ ((a1/b1) - (a2/b2)));
    y= ((a1*x +c1)/b1);
    return punkt(x,y);
}

void wyswietl_punkt(punkt a)
{
    std::cout<<"X= "<<a.x<<" Y= "<<a.y;
}

void wyswietl_prosta(prosta a)
{
    std::cout<<a.get_a()<<"x +"<<a.get_b()<<"y +"<<a.get_c();
}

void wyswietl_wektor(wektor a)
{
    std::cout<<"=( "<<a.dx<<" ,"<<a.dy<<" )";
}
#endif // klasy
