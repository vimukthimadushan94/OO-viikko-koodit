#include <iostream>
#include "asiakas.h"
using namespace std;

int main()
{
    Asiakas customer("Aapeli",1000.00);
    cout << customer.getNimi() << endl;
    customer.talletus(500);
    customer.talletus(200);
    customer.nosto(100);
    customer.luotonNosto(800);
    customer.luotonNosto(100);
    customer.luotonMaksu(300);
    customer.showSaldo();

    Asiakas customer2("Bertta",1000.00);
    cout << customer2.getNimi() << endl;
    customer2.talletus(500);
    customer2.nosto(100);
    customer2.luotonNosto(400);
    customer2.luotonMaksu(100);
    customer2.showSaldo();

    customer2.tiliSiirto(50,customer);
    customer.showSaldo();
    customer2.showSaldo();
    return 0;
}
