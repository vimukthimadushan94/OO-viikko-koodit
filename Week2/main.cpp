#include <iostream>
#include "game.h"
using namespace std;

int main()
{
    int maxNumber;
    cout<<"Enter Max Number: "<<endl;
    cin >> maxNumber;
    Game game(maxNumber);
    game.play();

    return 0;
}
