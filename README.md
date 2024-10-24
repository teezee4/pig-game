# pig-game
Overview

This repository contains two implementations of the classic Pig Dice Game written in C++. Pig is a simple turn-based game where players aim to reach 100 points by rolling a six-sided die. A roll of 1 resets the turn's points, and players must decide when to "hold" and bank their points or risk losing them with another roll. Both implementations include human and computer players.

Game Implementations:

1. Single-Player vs AI Pig Game (pig.cpp)
This version of Pig allows the user to compete against the computer. The player rolls the dice, aiming to accumulate points without rolling a 1. After the player finishes their turn, the AI takes its turn using a simple strategy.

Features:

Single Player vs AI: Compete against a computer that strategically decides when to hold based on its dice roll.
Dynamic Dice Rolls: Roll a virtual six-sided die, accumulate points, and decide whether to roll again or hold.
AI Behavior: The AI will hold if its dice roll is below 4, otherwise, it will continue rolling until it decides to hold or loses points with a roll of 1.
Random Number Generator: A randomNumber() function to generate a random lucky number for the player.
High Score Tracking: The game tracks and displays the highest score achieved during the session.


2. Multiplayer Pig Game (pig_multiplayer.cpp)
This version supports multiple players, allowing several people to compete against each other in turns. Each player rolls the dice and decides when to hold or continue their turn. The first player to reach 100 points wins the game.

Features:

Multiplayer Support: Play with as many players as desired by specifying the number of players at the start of the game.
Turn-Based Gameplay: Players take turns rolling the die and accumulating points.
Dice Roll Function: Simulates the roll of a six-sided die for each player.
Input Validation: Robust input handling for player actions and number of players.

How to Play
Roll the Dice: Players can choose to roll the dice during their turn. Rolling a 2-6 adds that number to the player's turn score. Rolling a 1 resets their turn score to 0 and ends their turn.
Hold: Players can choose to hold, banking their turn score and adding it to their total score.
Winning: The first player (or the AI) to reach 100 points wins the game.
