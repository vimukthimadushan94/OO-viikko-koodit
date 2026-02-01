#include <iostream>
#include "asiakas.h"
using namespace std;

int main()
{
    Asiakas customer("Aapeli",1000.00);
    cout << customer.getNimi() << endl;
    customer.talletus(500);
    customer.nosto(100);
    customer.luotonNosto(800);
    customer.luotonMaksu(100);
    customer.showSaldo();
    return 0;
}
