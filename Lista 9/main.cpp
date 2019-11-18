#include "zad9.hpp"

using namespace struktury;
using namespace std;

int main(){
    bst<int> *test = new bst<int>();

    test->insert(5);
    test->insert(7);
    test->insert(4);
    test->insert(42);
    test->insert(3);

    std::cout << test->find(7) << '\n';

    delete test;
    return 0;
}