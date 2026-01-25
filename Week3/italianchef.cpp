#include "italianchef.h"
#include <bits/stdc++.h>


ItalianChef::ItalianChef(string Icname): Chef(Icname)
{
    cout<<"ItalianChef "<<Icname<<" construktori."<<endl;
}

ItalianChef::~ItalianChef()
{
    cout<<"ItalianChef "<<chefName<<" destruktori."<<endl;
}

bool ItalianChef::askSecret(string inputPassword, int flour, int water)
{
    string str1(password);
    string str2(inputPassword);

    if ((str1.compare(str2)) == 0){
        makepizza(flour,water);
        return true;
    }else{
        cout<<"Password Wrong..Try Again."<<endl;
        return false;
    }
}

int ItalianChef::makepizza(int flour, int water)
{
    cout<<"Password OK..piizaa making"<<endl;
    int potions=0;
    int tulos=0;
    int combine_qnt = std::min(flour,water);
    do{
        if(tulos>=5){
            potions++;
        }
        tulos=tulos+5;
    }while(tulos<=combine_qnt);

    cout<<"Chef "<<chefName<<" with "<<flour<<" flour and "<<water<<" water can make "<<potions<<" pizzas."<<endl;

    return potions;
}
