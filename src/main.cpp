#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
#include "game.h"   // ← pull in all our helper functions

int main() {

    // ─── STEP 1: Generate a random secret number ───────────────────────
    srand(time(0));                        // Seed the random generator with current time
    int secretNumber = rand() % 100 + 1;  // Random number between 1 and 100
    int guess = 0;
    int attempts = 0;

    std::cout << "================================\n";
    std::cout << "   Welcome to Number Guessing!  \n";
    std::cout << "================================\n";
    std::cout << "I'm thinking of a number between 1 and 100.\n";
    std::cout << "Can you guess it?\n\n";

    // ─── STEP 4: while loop — keep going until correct ─────────────────
    while (guess != secretNumber) {

        // ─── STEP 2: Get input from the user ───────────────────────────
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;                        // STEP 5: count each attempt

        // ─── STEP 3: if-else logic to give hints ───────────────────────
        if (guess < 1 || guess > 100) {
            std::cout << "⚠️  Please enter a number between 1 and 100.\n\n";
            attempts--;                    // Don't count invalid guesses
        } else if (guess < secretNumber) {
            std::cout << "📉 Too low! Try higher.\n\n";
        } else if (guess > secretNumber) {
            std::cout << "📈 Too high! Try lower.\n\n";
        } else {
            std::cout << "✅ Correct! The number was " << secretNumber << ".\n";
            std::cout << "🎉 You got it in " << attempts << " attempts!\n";
        }
    }

    // ─── STEP 6: Final polish — performance message ────────────────────
    std::cout << "\n--- Game Over ---\n";
    if (attempts <= 5) {
        std::cout << "🏆 Outstanding! You're a natural.\n";
    } else if (attempts <= 10) {
        std::cout << "👍 Good job! Keep practicing.\n";
    } else {
        std::cout << "💪 Keep going — you'll get faster!\n";
    }

    return 0;
}
