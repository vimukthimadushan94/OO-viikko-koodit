#include "seuraaja.h"


Seuraaja::Seuraaja(string f_nimi)
{
    nimi=f_nimi;
}

string Seuraaja::getNimi()
{
    return nimi;
}

void Seuraaja::paivitys(string message)
{
    cout<<"Seuraaja "<<this->nimi<<" sai viestin "<<message<<endl;
}
