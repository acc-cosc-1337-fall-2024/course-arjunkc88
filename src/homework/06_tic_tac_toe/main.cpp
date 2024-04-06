#include "tic_tac_toe.h"
#include <iostream>


int main() {
    TicTacToe game;
    std::string player;
    char choice;
    do {
        std::cout << "Start game as X or O: ";
        std::cin >> player;
        while(player != "X" && player != "O") {
            std::cout << "Invalid input. Please enter X or O: ";
            std::cin >> player;
        }
        game.start_game(player);
        int position;
        while(!game.game_over()) {
            game.display_board();
            std::cout << "Player " << game.get_player() << " enter a position: ";
            std::cin >> position;
            game.mark_board(position);
        }
        game.display_board();
        std::cout << "Winner: " << game.get_winner() << "\n";
        std::cout << "Play again? (Y/N): ";
        std::cin >> choice;
    } while(choice == 'Y' || choice == 'y');
    return 0;
}
