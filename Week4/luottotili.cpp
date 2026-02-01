#include "luottotili.h"


Luottotili::Luottotili(string nimi, double raja): Pankkitili(nimi)
{
    luottoRaja = raja;
    cout<<"making luottotili in "<<omistaja<<" with "<<luottoRaja<<endl;
}

bool Luottotili::deposit(double amount)
{
    if (amount > 0 && saldo - amount >= 0) {
        saldo -= amount;
        return true;
    }
    return false;
}

bool Luottotili::withdraw(double amount)
{
    if (amount > 0 && saldo + amount <= luottoRaja) {
        saldo += amount;
        return true;
    }
    return false;
}
