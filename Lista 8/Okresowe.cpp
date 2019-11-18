#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

string IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}

bool Test(string *n_ans,int *reszty, int ostatnia)
{
    int i=0;
    if (reszty[ostatnia]== 0) return true;
    if (i==ostatnia) return false;
    while (i<ostatnia)
    {
        if (reszty[i]==reszty[ostatnia])
        {
            &n_ans->insert(i,"(");
            &n_ans->insert(ostatnia+1,")");
            &n_ans->erase(ostatnia+2);
            return true;
        }
        i++;
    }
    return false;
}

string Okresowy(int l, int m)
{
    int r=0;
    int reszty[1000];

    int temp =l/m;
    string ans ="", n_ans="";
    ans= ans + IntToString(temp) + ".";

    l= l - (temp*m);
    bool test = false;

    while (!test)
    {
        if (l>m)
        {
            temp = l/m;
            n_ans= n_ans + IntToString(temp);
            l=l-(temp*m);
        }
        l= l*10;
        reszty[r]=l;
        test=Test(&n_ans,reszty,r-1);
        r++;
    }
    return ans+ n_ans;
}

int main()
{
   int licz=64223;
   int mian=99990;
    string wynik = "";
    wynik= Okresowy(licz,mian);
    cout<<endl<<licz<<"/"<<mian<<"= "<<wynik;

    licz=55013;
    mian=9000;
    wynik = "";
    wynik= Okresowy(licz,mian);
    cout<<endl<<licz<<"/"<<mian<<"= "<<wynik;

    licz=1;
    mian=3;
    wynik = "";
    wynik= Okresowy(licz,mian);
    cout<<endl<<licz<<"/"<<mian<<"= "<<wynik;
    return 0;
}
