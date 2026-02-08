#include <iostream>
#include "notifikaattori.h"

using namespace std;

int main()
{
    Notifikaattori n;

    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);

    n.tulosta();
    n.postita("message 1");

    n.poista(&b);
    n.tulosta();

    n.postita("message 2");

    return 0;
}
