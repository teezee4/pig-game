// pig.cpp
// Taha Zeeshan
// 01/29/2022

#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <ctime>


using namespace std;

//function prototypes
void validOption(int& number);
void welcomeMessage();
void D6(int& dice);
int randomNumber(int low, int high);

int main(){
    int diceVal = 1;        //value of dice roll
    int turnPoints = 0;     //players points in a turn
    int grandPoints = 0;    //player overall points
    int aiturnScore = 0;    //computer points in a turn
    int aigrandPoints = 0;  //computer overall points
    int top = 0;            //high score variable
    int *highScore;         //pointer to store high score
    bool playOn = true;
    bool aiPlay = true;
    string playerName;
    
    highScore = &top;       //assigning pointer to variable
    
    srand(44);

    welcomeMessage();
    
    cout << "please type your name: ";
    getline(cin >> ws, playerName);
    
    // random use of randNumber function
    int o = randomNumber(1, 100);
    
    cout << "\nYour lucky number today is " << o;
    cout << endl;
    cout << "Time to play!\n";
    
    // will keep going until 100 points is reached or option 3 is selected
    while(playOn == true){
        int option = 1;     // variable for option user chooses
        
        cout << endl;
        
        cout << "1.Roll" << endl;
        cout << "2.Hold\n" << "3.Quit\n";
        
        // Function called for only valid input
        validOption(option);
        
        // when option 1 is chosen
        if (option == 1){
            //to roll dice
            D6(diceVal);
            
            // tells value of roll
            cout << "dice: " << diceVal;
            cout << endl;
            
            // gain turn points if roll is over 1
            if(diceVal > 1){
                turnPoints += diceVal;
            }
            else{
                turnPoints = 0;
            }
                
            cout << playerName << " turn points are: " << turnPoints << endl;
        }
        
        // when option 2 is chosen
        if (option == 2){
            
            //turn points get added on to the grand points and then reset
            grandPoints = grandPoints + turnPoints;
            turnPoints = 0;
            
            if(grandPoints > top)
                *highScore = grandPoints;
            
            // When player manages to reach 100 points to win
            if (grandPoints >= 100){
                cout << playerName << "has reached 100 points!\n";
                cout << "CONGRAGULAIONS YOU WIN\n";
                playOn = false;
            }
        }
        
        // when option 3 is chosen
        if (option == 3){
            
            //ends the game
            playOn = false;
        }
            // Display Turn Stats
            cout << "Player " << playerName << " grand points: " << grandPoints;
            cout << endl;
            cout << "computer grand points: " << aigrandPoints;
            cout << endl;
        
        // Starts the computers turn
        if (turnPoints == 0 && option != 3){
            aiPlay = true;
            
            while(aiPlay == true){
                // to roll dice
                D6(diceVal);
            
                // tells what computer rolled
                cout << "\ncomputer roll result: " << diceVal;
                cout << endl;
                
                // gives turn points if roll over 1
                if(diceVal > 1){
                    aiturnScore = aiturnScore + diceVal;
                }
                else{
                    aiturnScore = 0;
                }
                
                // Display Turn Stats
                cout << "computers score for this turn: " << aiturnScore << endl;
                cout << "Computers grand points: " << aigrandPoints << endl;
                cout << "Player " << playerName << " Grand points: " << grandPoints;
                cout << endl;
                cout << endl;
            
            //if roll under 4 then computer holds
            if(diceVal < 4){
                
                cout << "computer holds";
                cout << endl;
                
                //turn points added to computer grand points
                aigrandPoints = aigrandPoints + aiturnScore;
                aiturnScore = 0;
                
                //if the computer reaches 100 first
                if (aigrandPoints >= 100){
                    cout << "Computer has reached 100 points!\n";
                    cout << "YOU LOSE\n";
                    playOn = false;
                }
                //ends computers turn
                aiPlay = false;
            }
                        
        }
            cout << "computer grand points: " << aigrandPoints << endl;
            cout << "Player " << playerName << " grand points: " << grandPoints << endl;
        }
    }
    // Display High Score
    cout << "the high score ever: " << *highScore;
}

// Bulletproof Menu
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

// Program Greeting Function
void welcomeMessage(){
    
    cout << "Welcome to the Pig Game!\n";
}

void D6(int& dice){
    
    dice = (rand() % 6) + 1;
}

int randomNumber(int low, int high){
    
    if(low < 1 || high > 100 || low > high)
        return -1;
    
    // finds random number between hi and lo values
    int random = rand() % (high - low + 1) + low;
    
    // Protect RandomNumber() output
    if (random > 100 || random < 1)
        return -2;
    
    return random;
}
