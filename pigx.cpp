// pig.cpp
// Taha Zeeshan
// 01/29/2022

#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

void validNumber(int& number);
void validOption(int& number);
void welcomeMessage();
void startGame(int& numberPlayers, string names[]);
void diceRoll(int& dice);
void rollTurn(float turnPoints[], int);

int main(){
    int diceVal = 1;
    int numberPlayers = 0;
    int x = 0;
    bool playOn = true;
    float *turnPoints = nullptr;
    float *grandPoints = nullptr;
    string *playerNames = nullptr;

    void welcomeMessage();
        
    cout << "Enter number of players: ";
    validNumber(numberPlayers);
    
    playerNames = new string[numberPlayers];
    turnPoints = new float[numberPlayers];
    grandPoints = new float[numberPlayers];
    
    for(int i = 0; i < numberPlayers; i++)
        {
        cout << "Enter name " << (i + 1) << ": ";
        getline(cin >> ws, playerNames[i]);
        }
    
    for(int i = 0; i < numberPlayers; i++)
        {
            grandPoints[i] = 0;
        }
    
    cout << "Time to play!\n";
    
    
    
    while(playOn == true){
        int option = 1;
        
        cout << endl;
        cout << playerNames[x] << " turn\n";
        
        cout << "1.Roll\n" << "2.Hold\n" << "3.Quit\n";
        validOption(option);

        
        if (option == 1){
            diceRoll(diceVal);
            
            cout << "dice: " << diceVal;
            cout << endl;
            
            if(diceVal > 1)
            turnPoints[x] = turnPoints[x]+diceVal;
            
            cout << playerNames[x] << " turn points: " << turnPoints[x];
            cout << endl;
            
        }
        
        if (option == 2){
            
            grandPoints[x] = grandPoints[x] + turnPoints[x];
            
           
            if (grandPoints[x] > 100){
                cout << playerNames[x] << "has reached 100 points!\n";
                cout << "CONGRAGULAIONS YOU WIN\n";
                playOn = false;
            }
        }
        if (option == 3){
            playOn = false;
        }
        
        for(int i = 0; i < numberPlayers; i++)
            {
            cout << "Player " << playerNames[i] << " grand score: " << grandPoints[i];
            cout << endl;
            }
        
        x++;
        
        if(x >= numberPlayers)
            x = 0;
    }
    
    cout << "AI Score:";
    }


void validNumber(int& number){
    bool invalidResponse = true;

    while(invalidResponse){

        cin >> number;

        if(cin.fail()){
                cin.clear();
                cin.ignore();
        }
        else if (number > 0){
            invalidResponse = false;
        }
        if (invalidResponse){
            cout << "\ninvalid input, enter a valid number: ";
        }
    }
}
void validOption(int& number){
    bool invalidResponse = true;

    while(invalidResponse){

        cin >> number;

        if(cin.fail()){
                cin.clear();
                cin.ignore();
        }
        else if (number > 0 && number < 4){
            invalidResponse = false;
        }
        if (invalidResponse){
            cout << "\ninvalid input, enter a number 1-3: ";
        }
    }
}

void welcomeMessage(){
    cout << "Welcome to my the Pig Game!\n";
}

void diceRoll(int& dice){
    
    srand (time(NULL));
    
    dice = rand() % 6 + 1;
}


