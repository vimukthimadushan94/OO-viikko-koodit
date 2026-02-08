#include "notifikaattori.h"

Notifikaattori::Notifikaattori() {
    cout<<"Luodaan notifikaattori"<<endl;
}

void Notifikaattori::lisaa(Seuraaja *seuraaja)
{
    cout<<"Notifikaattori lisaa seuraajan "<<seuraaja->getNimi()<<endl;
    seuraaja->next=seuraajat;
    seuraajat=seuraaja;
}

void Notifikaattori::poista(Seuraaja *ref)
{
    Seuraaja* current = seuraajat;
    Seuraaja* previous = NULL;

    while (current != NULL) {
        if (current == ref) {
            if (previous == NULL) {
                seuraajat = current->next;
            }
            else {
                previous->next = current->next;
            }
            break;
        }

        previous = current;
        current = current->next;
    }

}

void Notifikaattori::tulosta()
{
    cout<<"Notifikaattori seuraajat: "<<endl;
    Seuraaja *temp=seuraajat;

    while(temp!=NULL){
        cout<<"Seuraaja "<<temp->getNimi()<<endl;
        temp = temp->next;
    }
}

void Notifikaattori::postita(string message)
{
    Seuraaja *temp=seuraajat;

    while(temp!=NULL){
        temp->paivitys(message);
        temp = temp->next;
    }
}
