
// #include "tic_tac_toe.h"
// #include "tic_tac_toe_manager.h"
// #include <iostream>

// int main() {
//     tic_tac_toe game;
//     tic_tac_toe_manager manager;
//     std::string player;
//     char choice;

//     int games_played = 0;
//     const int total_games = 3;

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

//         games_played++;

//         if (games_played % total_games == 0 || games_played == 1) {
//             int x_wins, o_wins, ties;
//             manager.get_winner_total(o_wins, x_wins, ties);
//             std::cout << "Score: X wins: " << x_wins << ", O wins: " << o_wins << ", Ties: " << ties << std::endl;
//             std::cout << "Play next game? (Y/N): ";
//             std::cin >> choice;
//         }

//     } while (games_played % total_games != 0 || (choice == 'Y' || choice == 'y'));

//     std::cout << "All games finished!" << std::endl;

//     return 0;
// }
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <iostream>

int main() {
    tic_tac_toe game;
    tic_tac_toe_manager manager;
    std::string player;
    char choice = 'Y';  // Initialize to 'Y' to enter the loop at least once

    int games_played = 0;
    const int total_games = 3;  // Number of games after which to show scores and ask if the user wants to continue

    while (choice == 'Y' || choice == 'y') {
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

        // Show scores and ask if the user wants to continue every `total_games` games or at least once
        if (games_played % total_games == 0) {
            int x_wins, o_wins, ties;
            manager.get_winner_total(x_wins, o_wins, ties);
            std::cout << "Score: X wins: " << x_wins << ", O wins: " << o_wins << ", Ties: " << ties << std::endl;
            if (games_played % total_games == 0) {
                std::cout << "Play next game? (Y/N): ";
                std::cin >> choice;
            }
        }
    }

    std::cout << "All games finished!" << std::endl;

    return 0;
}

