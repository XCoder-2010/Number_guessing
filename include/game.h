#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>

// ─── CONSTANTS ────────────────────────────────────────────────────────────────
const int MIN_NUMBER = 1;
const int MAX_NUMBER = 100;

// ─── STEP 1: Random number generation ────────────────────────────────────────
int generateSecretNumber() {
    srand(time(0));
    return rand() % MAX_NUMBER + MIN_NUMBER;
}

// ─── STEP 2 & 3: Validate input and give hints ───────────────────────────────
bool isValidGuess(int guess) {
    return guess >= MIN_NUMBER && guess <= MAX_NUMBER;
}

std::string getHint(int guess, int secretNumber) {
    if (guess < secretNumber) {
        return "📉 Too low! Try higher.";
    } else if (guess > secretNumber) {
        return "📈 Too high! Try lower.";
    } else {
        return "✅ Correct!";
    }
}

// ─── STEP 5: Performance message based on attempts ───────────────────────────
std::string getPerformanceMessage(int attempts) {
    if (attempts <= 5) {
        return "🏆 Outstanding! You're a natural.";
    } else if (attempts <= 10) {
        return "👍 Good job! Keep practicing.";
    } else {
        return "💪 Keep going — you'll get faster!";
    }
}

// ─── STEP 6: Display welcome banner ──────────────────────────────────────────
void displayWelcome() {
    std::cout << "================================\n";
    std::cout << "   Welcome to Number Guessing!  \n";
    std::cout << "================================\n";
    std::cout << "I'm thinking of a number between "
              << MIN_NUMBER << " and " << MAX_NUMBER << ".\n";
    std::cout << "Can you guess it?\n\n";
}

#endif // GAME_H
