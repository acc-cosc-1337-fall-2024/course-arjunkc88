#include "tic_tac_toe_manager.h"

// Saves a game to the historical log and updates the win/tie counts.
void tic_tac_toe_manager::save_game(const tic_tac_toe& game) {
    games.push_back(game); // Save the game to the history
    update_winner_count(game.get_winner()); // Update counts based on the game's outcome
}

// Retrieves the total wins for each player and the number of ties.
void tic_tac_toe_manager::get_winner_total(int& o, int& x, int& t) const {
    o = o_win; // Total wins for 'O'
    x = x_win; // Total wins for 'X'
    t = ties;  // Total ties
}

// Updates the win or tie counts based on the winner of a game.
void tic_tac_toe_manager::update_winner_count(const std::string& winner) {
    if (winner == "X") {
        x_win++; // Increment 'X' win count
    } else if (winner == "O") {
        o_win++; // Increment 'O' win count
    } else if (winner == "C") {
        ties++;  // Increment tie count
    }
    // Consider adding an else clause to handle unexpected input
}
