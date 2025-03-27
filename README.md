# Tic-Tac-Toe Game Console (C++)

## Description

This project allows two players to play Tic-Tac-Toe, or a single player to play against a simple CPU opponent, all within a console interface.

## Prerequisites

* A C++ compiler (e.g., GCC, Clang, MSVC)
* Standard C++ library
* `conio.h` (for `_getch()` and `system("cls")`). Note: `conio.h` is not a standard C++ library and may not be available on all systems. It is commonly found on Windows systems.

## Usage

1.  Compile the source code or run the executable.
2.  Upon execution, press 's' to start the game.
3.  Choose game mode:
    * '1' for Player vs CPU.
    * '2' for Player vs Player.
    * '3' to quit.
4.  Players take turns entering numbers from 1 to 9, corresponding to the Tic-Tac-Toe grid positions.
5.  The game displays the board after each move.
6.  The game announces the winner or a draw when the game ends.
7.  The program asks if you want to play again ('y' for yes, 'n' for no).

## Notes Regarding `conio.h`

* The use of `conio.h` is not recommended for cross-platform development. It is a non-standard header file that is primarily available on Windows.
* If you are developing on a non-Windows platform (e.g., Linux, macOS), you will need to replace `_getch()` and `system("cls")` with alternative methods.
* For `_getch()`, you can use libraries like `ncurses` (for Linux/macOS) or implement your own non-blocking input function.
* For `system("cls")`, you can use terminal control sequences or platform-specific methods to clear the console.
* Consider using more cross-platform methods for input and console clearing if you want to make your game more portable.

## Author

@plozdev

Have fun :>
