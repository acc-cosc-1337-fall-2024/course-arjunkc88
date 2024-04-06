#include "tic_tac_toe.h"
#include <iostream>

void TicTacToe::start_game(std::string first_player) {
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position) {
    if(position >= 1 && position <= 9 && pegs[position - 1] == " ") {
        pegs[position - 1] = player;
        if(!game_over()) {
            set_next_player();
        }
    }
}

bool TicTacToe::game_over() {
    if(check_row_win() || check_column_win() || check_diagonal_win()) {
        set_winner();
        return true;
    } else if(check_board_full()) {
        winner = "C";
        return true;
    }
    return false;
}

std::string TicTacToe::get_player() const {
    return player;
}

void TicTacToe::display_board() const {
    std::cout << "\n";
    std::cout << " " << pegs[0] << " | " << pegs[1] << " | " << pegs[2] << "\n";
    std::cout << "-----------\n";
    std::cout << " " << pegs[3] << " | " << pegs[4] << " | " << pegs[5] << "\n";
    std::cout << "-----------\n";
    std::cout << " " << pegs[6] << " | " << pegs[7] << " | " << pegs[8] << "\n";
    std::cout << "\n";
}

std::string TicTacToe::get_winner() const {
    return winner;
}

bool TicTacToe::check_column_win() {
    for(int i = 0; i < 3; ++i) {
        if(pegs[i] != " " && pegs[i] == pegs[i+3] && pegs[i+3] == pegs[i+6]) {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_row_win() {
    for(int i = 0; i < 9; i += 3) {
        if(pegs[i] != " " && pegs[i] == pegs[i+1] && pegs[i+1] == pegs[i+2]) {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_diagonal_win() {
    return (pegs[0] != " " && pegs[0] == pegs[4] && pegs[4] == pegs[8]) || 
           (pegs[2] != " " && pegs[2] == pegs[4] && pegs[4] == pegs[6]);
}

void TicTacToe::set_winner() {
    winner = player == "X" ? "O" : "X";
}

void TicTacToe::set_next_player() {
    player = (player == "X") ? "O" : "X";
}

bool TicTacToe::check_board_full() const {
    for(auto& peg : pegs) {
        if(peg == " ") {
            return false;
        }
    }
    return true;
}

void TicTacToe::clear_board() {
    pegs = std::vector<std::string>(9, " ");
}
