//
// Created by cjnga on 2/5/2024.
//

#ifndef GUESS_THE_NUMBER_GAME_H
#define GUESS_THE_NUMBER_GAME_H
#include <string>
using std::string;

class Game {
public:
    Game ();
    bool Guess (const string& userGuess);
    int RightNum (const int solverGuess[], unsigned int size);
    int RightPlace (const int solverGuess[], unsigned int size);
    bool IsValidGuess (string userGuess) const;
    void Print() const;
    int GetGuesses() const;
private:
    int* _num = new int[4];
    int _guesses = 0;
};




#endif //GUESS_THE_NUMBER_GAME_H
