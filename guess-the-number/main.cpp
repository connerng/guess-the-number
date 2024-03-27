#include <iostream>
#include "solver.cpp"
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

    bool keepPlaying;
    int gameCount = 0;
    int totalGuesses = 0;
    int bestScore = 0;
    double avgScore = 0.0;
    string ue;
    cout << "Welcome to Guess the Number" << endl;
    cout << "Press y to play" << endl;
    cin >> ue;
    if (ue == "y") {
        keepPlaying = true;
    } else {
        keepPlaying = false;
        Solver s;
        Game g;
        s.Solve(g);
    }

    while (keepPlaying) {
        Game g;
        gameCount++;

        string userEntry;
        bool win = false;
        cout << "Guess the 4-digit number!" << endl;

        while (!win) {

            cout << "Guess " << g.GetGuesses() + 1 << ": ";
            cin >> userEntry;
            if (!g.IsValidGuess(userEntry)) {
                cout << "Invalid entry" << endl;

            } else {
                win = g.Guess(userEntry);
                if (win) {
                    totalGuesses += g.GetGuesses();
                    if (gameCount == 1) {
                        bestScore = g.GetGuesses();
                    } else {
                        if (g.GetGuesses() < bestScore) {
                            bestScore = g.GetGuesses();
                        }
                    }

                    break;
                }
            }
        }

        string kp;
        cout << "Press y to play again: ";
        cin >> kp;
        if (!(kp == "y")) {
            break;
        }

    }

    cout << "Thanks for playing!" << endl;
    cout << "Games Played: " << gameCount << endl;
    cout << "Best Score: " << bestScore << endl;
    avgScore = (double)(totalGuesses / gameCount);
    cout << "Average Guesses per Game: " << avgScore << endl;







    return 0;
}
