#include "asiakas.h"

Asiakas::Asiakas(string nimi, double rajaLuotto)
{
    this->nimi=nimi;
    kayttotili = new Pankkitili(nimi);
    luottotili = new Luottotili(nimi, rajaLuotto);
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout<<"Kayttotilin saldo "<<kayttotili->getBalance()<<endl;
    cout<<"Luottotilin saldo "<<luottotili->getBalance()<<endl;
}

bool Asiakas::talletus(double depositAmount)
{
    return kayttotili->deposit(depositAmount);
}

bool Asiakas::nosto(double amount)
{
    return kayttotili->withdraw(amount);
}

bool Asiakas::luotonMaksu(double amount)
{
    return luottotili->deposit(amount);
}

bool Asiakas::luotonNosto(double amount)
{
    return luottotili->withdraw(amount);
}

bool Asiakas::tiliSiirto(double amount, Asiakas &asiakas)
{
    if(amount<=kayttotili->getBalance()){
        nosto(amount);
        asiakas.talletus(amount);
        return true;
    }else{
        return false;
    }
}
