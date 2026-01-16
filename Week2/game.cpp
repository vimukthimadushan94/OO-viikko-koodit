#include "game.h"
#include <iostream>
using namespace std;

Game::Game(int maxNum) {
    maxNumber=maxNum;
    cout << "GAME CONSTRUCTOR: object initialized with "<<maxNum<<" as a maximum value"<<endl;
}

Game::~Game()
{
    cout<<"GAME DESTRUCTOR: object cleared from stack window.."<<endl;
}


void Game::play()
{
    std::srand(time(0));
    int gameStatus=0;
    numberOfGuesses=0;

    randomNumber = rand() % maxNumber;
    if(randomNumber==0){
        randomNumber = 1;
    }

    do{
        gameStatus=1;
        cout << "Give your guess between 1-"<<maxNumber << endl;
        cin >> playerGuess;
        numberOfGuesses++;

        if(playerGuess>randomNumber){
            cout << "Your guess is too big" << endl;
        }else if(playerGuess<randomNumber){
            cout << "Your guess is too small" << endl;
        }else{
            gameStatus = 0;
            cout << "Your quest is right ="<< randomNumber << endl;
            cout << "You quesed the right answer = "<< playerGuess << " with "<<numberOfGuesses<<" quesses"<<endl;
        }
    }while(gameStatus==1);



}


