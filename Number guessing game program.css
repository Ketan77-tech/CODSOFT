#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

void startGame() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int playerGuess = 0;
    int numberOfTries = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    // Game loop
    while (playerGuess != secretNumber && numberOfTries < 3) {
        cout << "Enter your guess: ";
        cin >> playerGuess;

        if (cin.fail()) {
            cin.clear(); // clear the error flags
            cin.ignore(1000, '\n'); // discard invalid input
            cout << "Please enter a valid number." << endl;
            continue;
        }

        numberOfTries++;

        if (playerGuess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (playerGuess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << numberOfTries << " tries." << endl;
        }
    }

    if (playerGuess != secretNumber) {
        cout << "Sorry, you've used all 3 tries. The correct number was " << secretNumber << "." << endl;
    }
}

int main() {
    char playAgain;

    do {
        startGame();

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Goodbye." << endl;
    return 0;
}
