 #include "tic_tac_toe.h"
 #include <iostream>
 


void tic_tac_toe::start_game(std::string first_player) {
    player = first_player;
    clear_board();
}

void tic_tac_toe::mark_board(int position) {
    if(position >= 1 && position <= 9 && pegs[position - 1] == " ") {
        pegs[position - 1] = player;
        if(!game_over()) {
            set_next_player();
        }
    }
}

bool tic_tac_toe::game_over() {
    if(check_row_win() || check_column_win() || check_diagonal_win()) {
        set_winner();
        return true;
    } else if(check_board_full()) {
        winner = "C";
        return true;
    }
    return false;
}

std::string tic_tac_toe::get_player() const {
    return player;
}

void tic_tac_toe::display_board() const {
    std::cout << "\n";
    std::cout << " " << pegs[0] << " | " << pegs[1] << " | " << pegs[2] << "\n";
    std::cout << "-----------\n";
    std::cout << " " << pegs[3] << " | " << pegs[4] << " | " << pegs[5] << "\n";
    std::cout << "-----------\n";
    std::cout << " " << pegs[6] << " | " << pegs[7] << " | " << pegs[8] << "\n";
    std::cout << "\n";
}

std::string tic_tac_toe::get_winner() const {
    return winner;
}

bool tic_tac_toe::check_column_win() {
    for(int i = 0; i < 3; ++i) {
        if(pegs[i] != " " && pegs[i] == pegs[i+3] && pegs[i+3] == pegs[i+6]) {
            return true;
        }
    }
    return false;
}

bool tic_tac_toe::check_row_win() {
    for(int i = 0; i < 9; i += 3) {
        if(pegs[i] != " " && pegs[i] == pegs[i+1] && pegs[i+1] == pegs[i+2]) {
            return true;
        }
    }
    return false;
}

bool tic_tac_toe::check_diagonal_win() {
    return (pegs[0] != " " && pegs[0] == pegs[4] && pegs[4] == pegs[8]) || 
           (pegs[2] != " " && pegs[2] == pegs[4] && pegs[4] == pegs[6]);
}

void tic_tac_toe::set_winner() {
    winner = player == "X" ? "O" : "X";
}

void tic_tac_toe::set_next_player() {
    player = (player == "X") ? "O" : "X";
}

bool tic_tac_toe::check_board_full() const {
    for(auto& peg : pegs) {
        if(peg == " ") {
            return false;
        }
    }
    return true;
}

void tic_tac_toe::clear_board() {
    pegs = std::vector<std::string>(9, " ");
}

std::ostream& operator<<(std::ostream& out, const tic_tac_toe& game) {
    for (int i = 0; i < 9; i += 3) {
        out << game.pegs[i] << " | " << game.pegs[i+1] << " | " << game.pegs[i+2] << "\n";
    }
    return out;
}

std::istream& operator>>(std::istream& in, tic_tac_toe& game) {
    for (auto& peg : game.pegs) {
        in >> peg;
    }
    return in;
}
