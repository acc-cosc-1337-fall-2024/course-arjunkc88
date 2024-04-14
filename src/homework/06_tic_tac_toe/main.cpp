// #include "tic_tac_toe.h"
// #include "tic_tac_toe_manager.h"
// #include <iostream>

//  int main() {
//     tic_tac_toe game;
//     tic_tac_toe_manager manager;
//     std::string player;
//     char choice;

//     do {
//         std::cout << "Start game as X or O: ";
//         std::cin >> player;
//         while (player != "X" && player != "O") {
//             std::cout << "Invalid input. Please enter X or O: ";
//             std::cin >> player;
//         }
//         game.start_game(player);

//         int position;
//         while (!game.game_over()) {
//             game.display_board();
//             std::cout << "Player " << game.get_player() << " enter a position: ";
//             std::cin >> position;
//             game.mark_board(position);
//         }
        
//         game.display_board();
//         manager.save_game(game);

//         int x_wins, o_wins, ties;
//         manager.get_winner_total(o_wins, x_wins, ties);
//         std::cout << "Score: X wins: " << x_wins << ", O wins: " << o_wins << ", Ties: " << ties << std::endl;

//         std::cout << "Play again? (Y/N): ";
//         std::cin >> choice;
//     } while (choice == 'Y' || choice == 'y');

//     return 0;
//  }
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <iostream>

int main() {
    tic_tac_toe game;
    tic_tac_toe_manager manager;
    std::string player;
    char choice;

    int games_played = 0;
    const int total_games = 3;

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

        games_played++;

        if (games_played < total_games) {
            int x_wins, o_wins, ties;
            manager.get_winner_total(o_wins, x_wins, ties);
            std::cout << "Score: X wins: " << x_wins << ", O wins: " << o_wins << ", Ties: " << ties << std::endl;
            std::cout << "Play next game? (Y/N): ";
            std::cin >> choice;
        } else {
            std::cout << "All games finished!" << std::endl;
            choice = 'N'; // End the loop
        }

    } while (choice == 'Y' || choice == 'y');

    return 0;
}
