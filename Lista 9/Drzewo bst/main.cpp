#include "zad9.hpp"

using namespace struktury;
using namespace std;

int main(){

    bst<int> *t = new bst<int>();

    t->insert_(5);
    t->insert_(7);
    cout<<t->get_r();
    t->insert_(8);

    std::cout << " Alcia "<<endl;
    std::cout<<t<< '\n';

    delete t;
    return 0;
}
