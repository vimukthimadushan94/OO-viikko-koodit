#include "chef.h"


Chef::Chef(string name)
{
    chefName = name;
    cout<<"Chef "<<chefName<<" Construktori"<<endl;
}

Chef::~Chef()
{
    cout<<"Chef "<<chefName<<" destruktori"<<endl;
}

string Chef::getName()
{
    return chefName;
}

int Chef::makeSalade(int aine)
{
    int potions=0;
    int tulos=0;
    do{
        if(tulos>=5){
            potions++;
        }
        tulos=tulos+5;
    }while(tulos<=aine);

    return potions;
}

int Chef::makeSoup(int aine)
{
    int potions=0;
    int tulos=0;
    do{
        if(tulos>=3){
            potions++;
        }
        tulos=tulos+3;
    }while(tulos<=aine);

    return potions;
}
