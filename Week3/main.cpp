#include <iostream>
#include "chef.h"
#include "italianchef.h"
using namespace std;

int main()
{
    string inputPassword;

    Chef chef("Gordon");
    int saladAine=11;
    int soupAine=14;
    cout<<"Chef "<<chef.getName()<<" with "<<saladAine<<" items can make salad "<<chef.makeSalade(saladAine)<<" portions"<<endl;
    cout<<"Chef "<<chef.getName()<<" with "<<soupAine<<" items can make soup "<<chef.makeSoup(soupAine)<<" portions"<<endl;

    cout<<""<<endl;

    ItalianChef ItalianChef("Mario");
    int ic_saladAine=9;
    cout<<"Chef "<<ItalianChef.getName()<<" with "<<ic_saladAine<<" items can make salad "<<ItalianChef.makeSalade(ic_saladAine)<<" portions"<<endl;

    cout<<"Enter password for make pizza.."<<endl;
    cin>>inputPassword;

    int flour=12;
    int water=12;
    ItalianChef.askSecret(inputPassword,flour,water);

    return 0;
}
