//
// Created by cjnga on 2/5/2024.
//
#include "game.h"
#include <iostream>
using std::cout;
using std::endl;


Game::Game() {
    srand(time(nullptr));
    _num[0] = rand() % 10;

    for (int i = 1; i < 4; i++) {
        bool distinct;
        do {
            distinct = true;
            _num[i] = rand() % 10;

            for (int j = 0; j < i; j++) {
                if (_num[i] == _num[j]) {
                    distinct = false;
                    break;
                }
            }

        } while (!distinct);
    }

}

bool Game::Guess(const string& userGuess) {
    _guesses++;
    int rightPlace = 0, rightNum = 0;
    int* guess = new int[4];
    for (int i = 0; i < 4; i++) {
        guess[i] = stoi(userGuess.substr(i, 1));
    }
    for (int i = 0; i < 4; i++) {
        int n = guess[i];
        if (_num[i] == n) {
            rightPlace++;
            rightNum++;
        } else {
            for (int j = 0; j < 4; j++) {
                if (n == _num[j]) {
                    rightNum++;
                }
            }
        }
    }

    if (rightPlace == 4) {
        cout << "You guessed it in " << _guesses << " guesses!" << endl;
        return true;
    } else {
        cout << rightNum << " digits are correct, " << rightPlace << " digits are in the right place." << endl;
        return false;
    }


}

bool Game::IsValidGuess(string userGuess) const {
    if (userGuess.length() != 4) {
        return false;
    }
    for (int i = 0; i < 4; i++) {
        if (!isdigit(userGuess.at(i))){
            return false;
        }
    }

    return true;

}

void Game::Print() const {
    for (int i = 0; i < 4; i++) {
        cout << _num[i] << endl;
    }
}

int Game::GetGuesses() const {
    return _guesses;
}

int Game::RightNum(const int solverGuess[], unsigned int size = 4) {
    int rn = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (solverGuess[i] == _num[j]){
                rn++;
            }
        }
    }
    return rn;
}

int Game::RightPlace(const int solverGuess[], unsigned int size = 4) {
    int rp = 0;
    for (int i = 0; i < size; i++) {
        if (solverGuess[i] == _num[i]) {
            rp++;
        }
    }
    return rp;
}