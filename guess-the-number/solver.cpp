//
// Created by cjnga on 2/23/2024.
//
#include "solver.h"
#include <vector>
using std::vector;

Solver::Solver() : _guessCount(0){}

int Solver::Solve(Game g) {
    bool solved = false;
    vector<int> possible = {};
    int final[4] = {0};
    bool rightPlaces[4] = {false};
    int rn = 0, rp =0;
    while (!solved) {
        this->RandomGuess(possible);
        rn = g.RightNum(_guess);
        rp = g.RightPlace(_guess);
        if (rp == 4) {
            solved = true;
        }
        if (rn > 0) {
            bool poss = false;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; i < possible.size(); j++) {
                    if (_guess[i] == possible.at(j)) {
                        poss = true;
                    }
                }
                if (!poss) {
                    possible.push_back(_guess[i]);
                }
            }
        }
        if (rn == 0) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < possible.size(); j++) {
                    if (_guess[i] == possible.at(j)) {
                        possible.erase(possible.begin() + j);
                    }
                }
            }
        }
    }
    return _guessCount;
}

void Solver::RandomGuess(vector<int> possible) {
    srand(time(nullptr));
    for (int i = 1; i < 4; i++) {
        bool distinct;
        do {
            distinct = true;
            _guess[i] = rand() % 10;

            for (int j = 0; j < i; j++) {
                if (_guess[i] == _guess[j]) {
                    distinct = false;
                    break;
                }
            }
            for (int k = 0; k < possible.size(); k++) {
                if (_guess[i] == possible.at(k)) {
                    distinct = false;
                    break;
                }

            }

        } while (!distinct);
    }
}