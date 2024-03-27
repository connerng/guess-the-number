//
// Created by cjnga on 2/23/2024.
//
#include "game.cpp"
#include <vector>
using std::vector;
#ifndef GUESS_THE_NUMBER_SOLVER_H
#define GUESS_THE_NUMBER_SOLVER_H

class Solver {
private:
    int _guessCount;
    int _guess[4];
    void RandomGuess(vector<int> possible);
public:
    Solver();
    int Solve(Game g);

};

#endif //GUESS_THE_NUMBER_SOLVER_H
