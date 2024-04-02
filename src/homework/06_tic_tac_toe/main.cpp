
#include "tic_tac_toe.h"
#include <iostream>

int main() {
    TicTacToe game;
    std::string player;
    std::cout << "Enter first player (X or O): ";
    std::cin >> player;
    game.start_game(player);

    bool continue_playing = true;
    while (continue_playing) {
        game.display_board();
        std::cout << "Player " << game.get_player() << ", enter position (1-9): ";
        int position;
        std::cin >> position;
        game.mark_board(position);

        // Check for game-over conditions and handle user choice
        if (game.game_over()) {
            game.display_board();
            // Ask if the user wants to play again
            char choice;
            std::cout << "Play again? (y/n): ";
            std::cin >> choice;
            if (choice != 'y') {
                continue_playing = false;
            } else {
                // Restart the game
                game.start_game(game.get_player()); // Maintain the same starting player

            }
        }
    }
  std::cout << "Thanks for playing!" << std::endl;
    return 0;
}
