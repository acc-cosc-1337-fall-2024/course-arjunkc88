

#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <iostream>
#include <memory>

int main() {
    TicTacToeManager manager;
    char choice = 'Y';

    do {
        std::unique_ptr<TicTacToe> game;
        int game_type = 0;
        std::cout << "Type 3 for TicTacToe3 or 4 for TicTacToe4: ";
        std::cin >> game_type;

        if (game_type == 3) {
            game = std::make_unique<TicTacToe3>();
        } else if (game_type == 4) {
            game = std::make_unique<TicTacToe4>();
        } else {
            std::cerr << "Invalid game type." << std::endl;
            continue;
        }

        std::string player;
        std::cout << "Start game as X or O: ";
        std::cin >> player;

        while (player != "X" && player != "O") {
            std::cout << "Invalid input. Please enter X or O: ";
            std::cin >> player;
        }

        game->start_game(player);

        while (!game->game_over()) {
            game->display_board();
            int position;
            std::cout << "Player " << game->get_player() << ", enter a position: ";
            std::cin >> position;
            game->mark_board(position);
        }

        game->display_board();
        std::cout << "Winner: " << game->get_winner() << std::endl;

        manager.save_game(std::move(game));

        // Displaying win totals after each game
        int x_wins, o_wins, ties;
        manager.get_winner_total(x_wins, o_wins, ties);
        std::cout << "Score: X wins: " << x_wins << ", O wins: " << o_wins << ", Ties: " << ties << std::endl;

        std::cout << "Play again? (Y/N): ";
        std::cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    manager.display_games();

    return 0;
}
