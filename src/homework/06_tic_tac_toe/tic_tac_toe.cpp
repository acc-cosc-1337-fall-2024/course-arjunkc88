
#include "tic_tac_toe.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Constructor implementation
TicTacToe::TicTacToe(int size) : pegs(size * size, " ") {}

// Member functions implementation
void TicTacToe::start_game(std::string first_player) {
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position) {
    if (position >= 1 && position <= pegs.size() && pegs[position - 1] == " ") {
        pegs[position - 1] = player;
        if (!game_over()) {
            set_next_player();
        }
    }
}

bool TicTacToe::game_over() {
    if (check_row_win() || check_column_win() || check_diagonal_win()) {
        set_winner();
        return true;
    } else if (check_board_full()) {
        winner = "C";
        return true;
    }
    return false;
}

std::string TicTacToe::get_player() const {
    return player;
}

// void TicTacToe::display_board() const {
//     int size = static_cast<int>(std::sqrt(pegs.size()));
//     for (int i = 0; i < pegs.size(); i += size) {
//         std::cout << pegs[i] << " | " << pegs[i + 1] << " | " << pegs[i + 2] << "\n";
//         if (i < pegs.size() - size) // Only display line if not last line
//             std::cout << "-----------\n";
//     }
//     std::cout << "\n";
// }
void TicTacToe::display_board() const {
    int size = static_cast<int>(std::sqrt(pegs.size())); // Determine board size from vector size
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            std::cout << pegs[row * size + col];
            if (col < size - 1) {
                std::cout << " | ";
            }
        }
        std::cout << "\n";
        if (row < size - 1) {
            std::cout << std::string(size * 4 - 1, '-') << "\n"; // Adjust the separator length based on board size
        }
    }
    std::cout << "\n";
}


std::string TicTacToe::get_winner() const {
    return winner;
}

// Protected virtual member functions for check wins
bool TicTacToe::check_column_win() {
    int size = static_cast<int>(std::sqrt(pegs.size()));
    for (int i = 0; i < size; ++i) {
        if (pegs[i] != " " && pegs[i] == pegs[i + size] && pegs[i + size] == pegs[i + 2 * size]) {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_row_win() {
    int size = static_cast<int>(std::sqrt(pegs.size()));
    for (int i = 0; i < pegs.size(); i += size) {
        if (pegs[i] != " " && pegs[i] == pegs[i + 1] && pegs[i + 1] == pegs[i + 2]) {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_diagonal_win() {
    int size = static_cast<int>(std::sqrt(pegs.size()));
    return (pegs[0] != " " && pegs[0] == pegs[size + 1] && pegs[size + 1] == pegs[2 * size]) ||
           (pegs[size - 1] != " " && pegs[size - 1] == pegs[size] && pegs[size] == pegs[size + 1]);
}

// Private member functions
void TicTacToe::set_winner() {
    if (check_row_win() || check_column_win() || check_diagonal_win()) {
        winner = player;
    } else {
        winner = "C"; // C for Cat's game (tie)
    }
}

void TicTacToe::set_next_player() {
    player = (player == "X") ? "O" : "X";
}

bool TicTacToe::check_board_full() const {
    for (const auto& peg : pegs) {
        if (peg == " ") {
            return false;
        }
    }
    return true;
}

void TicTacToe::clear_board() {
    std::fill(pegs.begin(), pegs.end(), " ");
}

std::ostream& operator<<(std::ostream& out, const TicTacToe& game) {
    game.display_board();
    return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& game) {
    for (auto& peg : game.pegs) {
        in >> peg;
    }
    return in;
}