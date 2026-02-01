#include "pankkitili.h"

Pankkitili::Pankkitili(string omis)
{
    omistaja=omis;
    cout<<"Bank account opening under bank "<<omistaja<<endl;
}

double Pankkitili::getBalance()
{
    return saldo;
}

bool Pankkitili::deposit(double amount)
{
    if(amount>0){
        saldo = saldo+amount;
        return true;
    }else{
        return false;
    }
}

bool Pankkitili::withdraw(double amount)
{
    if(amount<=saldo){
        saldo= saldo-amount;
        return true;
    }else{
        return false;
    }
}
