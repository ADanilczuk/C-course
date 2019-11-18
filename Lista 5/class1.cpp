#include "classes.hpp"
#include <ctime>

Data::Data()
{
    time_t rawtime;
    struct tm* timeinfo;
    time( &rawtime );
    timeinfo = localtime( &rawtime );

  day=timeinfo->tm_mday;
  month=timeinfo->tm_mon+1;
  year=timeinfo->tm_year+1900;
}

Data::Data(int d, int m, int y) : day(d), month(m), year(y){}

int Data::get_day()
{
    return this->day;
}

int Data::get_month()
{
    return this->month;
}

int Data::get_year ()
{
    return this->year;
}

bool Data::test_if_leap(Data& d)
{
     if (d.get_year()%4 == 0&&d.get_year()%100 != 0)
        return true;
     if (d.get_year()%400 == 0)
        return true;
     return false;
}


bool Data::operator<(Data& d2 )
{
    if (this->get_year()<d2.get_year()) return true;
    if (this->get_year()==d2.get_year())
      {
          if (this->get_month()<d2.get_month()) return true;
          if (this->get_month()==d2.get_month())
          {
              if (this->get_day()<d2.get_day()) return true;
          }
      }
    return false;
}

bool Data::test_if_correct(Data& d)
{
    int day= d.get_day();
    int month= d.get_month();
    Data d2=Data(15,10,1582);
    if(d<d2)
        return false;
    if (test_if_leap(d))
    {
        if (day<=dniwmiesiacach[1][month])
            return true;
        return false;
    }
    if (day<=dniwmiesiacach[0][month])
            return true;
        return false;
}

int Data::dniwmiesiacach[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31}, // lata zwyk³e
    {0,31,29,31,30,31,30,31,31,30,31,30,31} // lata przestêpne
    };

int Data::dniodpoczroku[2][13] = {
    {0,31,59,90,120,151,181,212,243,273,304,334,365}, // lata zwyk³e
    {0,31,60,91,121,152,182,213,244,274,305,335,366} // lata przestêpne
    };



int Data::how_many_days(Data& d)
{
    int ilosc=0;
    if (test_if_leap(d))
    {
        ilosc=dniodpoczroku[1][d.get_month()-1]+d.get_day();
    }
    else ilosc=dniodpoczroku[0][d.get_month()-1]+d.get_day();
    int extra= (((d.get_year()/4)-(d.get_year()/100)) + (d.get_year()/400));
    ilosc+=(extra*366)+((d.get_year()-extra)*365);
    return ilosc;
}

int Data::operator-(Data& d2)
{
    int i1=how_many_days(*this);
    int i2=how_many_days(d2);
    if (i1>i2)
        return i1-i2;
    return i2-i1;
}

void Data::operator++()
{
    if (test_if_leap(*this))
    {
        if (this->get_day()==(dniwmiesiacach[1][this->get_month()]))
        {
           if (this->get_month()==12)
           {
               this->day=1;
               this->month=1;
               this->year=this->get_year()+1;
           }
           else
           {
               this->day=1;
               this->month=this->get_month()+1;
           }
        }
        else
        {
            this->day=this->get_day()+1;
        }
    }
    else
    {
        if (this->get_day()==(dniwmiesiacach[0][this->get_month()]))
        {
           if (this->get_month()==12)
           {
               this->day=1;
               this->month=1;
               this->year=this->get_year()+1;
           }
           else
           {
               this->day=1;
               this->month=this->get_month()+1;
           }
        }
        else
        {
            this->day=this->get_day()+1;
        }
    }
}

void Data::operator--()
{
    if (this->get_day()==1)
    {
        if (this->get_month()==1)
        {
            this->day=31;
            this->month=12;
            this->year=this->get_year()-1;
        }
        else
        {
            if (test_if_leap(*this))
            {
                this->day=dniwmiesiacach[1][this->get_month()-1];
                this->month=this->get_month()-1;
            }
            else
            {
                this->day=dniwmiesiacach[0][this->get_month()-1];
                this->month=this->get_month()-1;
            }
        }
    }
    else
        this->day=this->get_day()-1;
}


void Data::operator+=(int days)
{
    int nday=this->get_day();
    int nmonth=this->get_month();
    while (days+nday>dniwmiesiacach[test_if_leap(*this)][nmonth])
    {
        days=days-dniwmiesiacach[test_if_leap(*this)][nmonth];
        nday=1;
        if (nmonth==12){ nmonth=1; this->year=this->get_year()+1;}
        else nmonth++;
    }
    nday=days+nday;
    this->day=nday;
    this->month=nmonth;
}


void Data::operator-=(int days)
{

    int nday=this->get_day();
    int nmonth=this->get_month();
    while (nday-days<1)
    {
        if (nmonth==1) {nmonth=12; this->year=this->get_year()-1;}
        else nmonth--;
        days=days-nday;
        nday=dniwmiesiacach[test_if_leap(*this)][nmonth];
    }
    nday=nday-days;
    this->day=nday;
    this->month=nmonth;
}
