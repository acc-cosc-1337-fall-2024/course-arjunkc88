//cpp
#include "tic_tac_toe.h"
#include <iostream>


bool TicTacToe::game_over() {
    return check_board_full();
}

void TicTacToe::start_game(std::string first_player) {
    if (first_player != "X" && first_player != "O") {
        std::cout << "Invalid player. Starting with 'X'." << std::endl;
        player = "X";
    } else {
        player = first_player;
    }
    clear_board();
}

void TicTacToe::mark_board(int position) {
    if (position < 1 || position > 9 || pegs[position - 1] != " ") {
        std::cout << "Invalid move. Try again." << std::endl;
        return;
    }
    pegs[position - 1] = player;
    set_next_player();
}

std::string TicTacToe::get_player() const {
    return player;
}

void TicTacToe::display_board() const {
    std::cout << "\n";
    for (int i = 0; i < 9; i++) {
        std::cout << " " << pegs[i] << " ";
        if (i % 3 == 2) std::cout << "\n";
    }
    std::cout << "\n";
}

void TicTacToe::set_next_player() {
    player = (player == "X") ? "O" : "X";
}

bool TicTacToe::check_board_full() {
    for (const auto& peg : pegs) {
        if (peg == " ") return false;
    }
    return true;
}

void TicTacToe::clear_board() {
    pegs = std::vector<std::string>(9, " ");
}