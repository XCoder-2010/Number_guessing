cmake_minimum_required(VERSION 3.10)

# ─── PROJECT INFO ─────────────────────────────────────────────────────────────
project(NumberGuessingGame VERSION 1.0)

# ─── C++ STANDARD ─────────────────────────────────────────────────────────────
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ─── INCLUDE DIRECTORIES ──────────────────────────────────────────────────────
include_directories(include)        # tells CMake where to find game.h

# ─── EXECUTABLE ───────────────────────────────────────────────────────────────
add_executable(game src/main.cpp)   # compiles main.cpp into an executable called "game"

# ─── COMPILER WARNINGS (good practice) ───────────────────────────────────────
target_compile_options(game PRIVATE
    -Wall        # enable all standard warnings
    -Wextra      # enable extra warnings
    -Wpedantic   # enforce strict ISO C++ compliance
)
