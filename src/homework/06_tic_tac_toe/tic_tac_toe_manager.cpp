
#include "tic_tac_toe_manager.h"
#include <iostream>

// Corrected to match the declaration in tic_tac_toe_manager.h
void TicTacToeManager::save_game(std::unique_ptr<TicTacToe> game) {
    update_winner_count(game->get_winner());
    games.push_back(std::move(game));
}

void TicTacToeManager::get_winner_total(int& x, int& o, int& t) const {
    x = x_win;
    o = o_win;
    t = ties;
}

void TicTacToeManager::update_winner_count(const std::string& winner) {
    if (winner == "X") {
        x_win++;
    } else if (winner == "O") {
        o_win++;
    } else {
        ties++;
    }
}

void TicTacToeManager::display_games() const {
    for (const auto& game : games) {
        std::cout << *game << "\n"; // Assuming operator<< is overloaded for TicTacToe
    }
}
