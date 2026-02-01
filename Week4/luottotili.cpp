#include "luottotili.h"


Luottotili::Luottotili(string nimi, double raja): Pankkitili(nimi)
{
    luottoRaja = raja;
    cout<<"making luottotili in "<<omistaja<<" with "<<luottoRaja<<endl;
}

double Luottotili::getBalance()
{
    return luottoRaja;
}

bool Luottotili::deposit(double amount)
{
    if (amount > 0 && luottoRaja >= 0) {
        luottoRaja = luottoRaja+amount;
        return true;
    }
    return false;
}

bool Luottotili::withdraw(double amount)
{
    if (amount > 0 && luottoRaja <= luottoRaja) {
        luottoRaja =luottoRaja- amount;
        return true;
    }
    return false;
}
