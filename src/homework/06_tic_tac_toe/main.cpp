#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <iostream>

 int main() {
    tic_tac_toe game;
    tic_tac_toe_manager manager;
    std::string player;
    char choice;

    do {
        std::cout << "Start game as X or O: ";
        std::cin >> player;
        while (player != "X" && player != "O") {
            std::cout << "Invalid input. Please enter X or O: ";
            std::cin >> player;
        }
        game.start_game(player);

        int position;
        while (!game.game_over()) {
            game.display_board();
            std::cout << "Player " << game.get_player() << " enter a position: ";
            std::cin >> position;
            game.mark_board(position);
        }
        
        game.display_board();
        manager.save_game(game);

        int x_wins, o_wins, ties;
        manager.get_winner_total(o_wins, x_wins, ties);
        std::cout << "Score: X wins: " << x_wins << ", O wins: " << o_wins << ", Ties: " << ties << std::endl;

        std::cout << "Play again? (Y/N): ";
        std::cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
 }
