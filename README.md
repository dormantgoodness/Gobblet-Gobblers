# Tic-Tac-Toe Variant (C++)

## Overview
This is a C++ implementation of a Tic-Tac-Toe variant that incorporates different piece sizes for two players: Red and Yellow. The game allows players to place pieces of different sizes on a 3x3 board, following a set of rules regarding placement and piece stacking.

## Features
- A 3x3 grid game board.
- Two players: Red and Yellow.
- Each player has three sizes of pieces: Small, Medium, and Large.
- Players place their pieces on the board according to specific rules.
- A win condition checker to determine when a player has won.
- Board display functionality.
- Validation of moves to prevent invalid placements.
- Undo functionality

## Classes and Methods
### `Board` Class
The `Board` class handles the core functionality of the game, including:
- **`displayBoard()`**: Prints the current state of the game board.
- **`getCount(string player, char size)`**: Retrieves the remaining pieces of a given size for a player.
- **`setValid(bool value)`**: Sets the validity status of a move.
- **`getValid()`**: Returns whether the last move was valid.
- **`getWinCheck()`**: Returns whether a player has won.
- **`checkSquare(string player, string square, string sizes, string space, string location)`**: Validates a move and places a piece if valid.
- **`decreasingCount(string player, string size)`**: Decreases the count of available pieces for a player after a valid move.
- **`checkWins()`**: Checks if a player has won based on the board state.

## Undo Functionality
- Players can undo their last move by entering u.
- The board will revert to the previous state before the last move.
- If the board is empty, undoing is not allowed.
- The turn will switch back to the previous player after an undo.

## Exiting the Game
- Enter q at any time to quit the game.

## Future Improvements
- Implement a user interface (console-based or graphical).
- Improve the AI for a single-player mode.
- Add more robust input validation.
- Refactor code for better readability and maintainability.


## Contributions
Pull requests and suggestions are welcome! Feel free to submit issues or enhancements.

