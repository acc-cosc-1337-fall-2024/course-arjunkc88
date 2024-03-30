
#include "tic_tac_toe.h"
#include <iostream>

int main() {
    TicTacToe game;
    std::string player;
    std::cout << "Enter first player (X or O): ";
    std::cin >> player;
    game.start_game(player);

    while(!game.game_over()) {
        game.display_board();
        std::cout << "Player " << game.get_player() << ", enter position (1-9): ";
        int position;
        std::cin >> position;
        game.mark_board(position);
    }

    game.display_board();
    std::cout << "Game over! The board is full." << std::endl;
    return 0;
}
