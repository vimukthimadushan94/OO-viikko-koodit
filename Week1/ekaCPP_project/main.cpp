#include <iostream>
using namespace std;

int main(){
    std::srand(time(0));
    int randNumber;
    int inputNumber;
    int gameStatus=0;

    randNumber = rand() % 20;


    do{
        //cout << randNumber << endl;
        gameStatus=1;
        cout << "Enter Gussed Number: " << endl;
        cin >> inputNumber;

        if(inputNumber>randNumber){
            cout << "liian suuri" << endl;
        }else if(inputNumber<randNumber){
            cout << "liian pieni" << endl;
        }else{
            gameStatus = 0;
            cout << "oikein" << endl;
        }
    }while(gameStatus==1);
}
