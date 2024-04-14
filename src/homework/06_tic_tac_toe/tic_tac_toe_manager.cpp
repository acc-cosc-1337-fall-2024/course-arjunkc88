#include "tic_tac_toe_manager.h"

void tic_tac_toe_manager::save_game(const tic_tac_toe& b) {
    games.push_back(b);
    update_winner_count(b.get_winner());
}

void tic_tac_toe_manager::get_winner_total(int& o, int& x, int& t) const {
    o = o_win;
    x = x_win;
    t = ties;
}

void tic_tac_toe_manager::update_winner_count(const std::string& winner) {
    if (winner == "X") {
        x_win++;
    } else if (winner == "O") {
        o_win++;
    } else if (winner == "C") {
        ties++;
    }
}