
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
    REQUIRE(true == true);
}

TEST_CASE("Test first player set to X", "[tic_tac_toe]") {
    tic_tac_toe game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O", "[tic_tac_toe]") {
    tic_tac_toe game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test tie condition", "[tic_tac_toe]") {
    tic_tac_toe game;
    game.start_game("X");
    game.mark_board(1); // X
    game.mark_board(2); // O
    game.mark_board(3); // X
    game.mark_board(5); // O
    game.mark_board(4); // X
    game.mark_board(6); // O
    game.mark_board(8); // X
    game.mark_board(7); // O
    game.mark_board(9); // X
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "C"); // C for Cat's game (tie)
    tic_tac_toe_manager games;
    games.save_game(game);
    int x, o, t;
    games.get_winner_total(x, o, t);
    REQUIRE(x == 0);
    REQUIRE(o == 0);
    REQUIRE(t == 1);
}

TEST_CASE("Test win by first column", "[tic_tac_toe]") {
    tic_tac_toe game;
    game.start_game("X");
    game.mark_board(1);
    REQUIRE(!game.game_over());
    game.mark_board(2);
    REQUIRE(!game.game_over());
    game.mark_board(4);
    REQUIRE(!game.game_over());
    game.mark_board(5);
    REQUIRE(!game.game_over());
    game.mark_board(7);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
    // tic_tac_toe_manager games;
//     games.save_game(game);
//     int x, o, t;
//     games.get_winner_total(x, o, t);
// //    REQUIRE(x == 1);
//     REQUIRE(o == 0);
//     REQUIRE(t == 0);
}

TEST_CASE("Test win by second column", "[tic_tac_toe]") {
    tic_tac_toe game;
    game.start_game("X");
    game.mark_board(2);
    REQUIRE(!game.game_over());
    game.mark_board(1);
    REQUIRE(!game.game_over());
    game.mark_board(5);
    REQUIRE(!game.game_over());
    game.mark_board(4);
    REQUIRE(!game.game_over());
    game.mark_board(8);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
    // tic_tac_toe_manager games;
    // games.save_game(game);
    // int x, o, t;
    // games.get_winner_total(x, o, t);
    // REQUIRE(x == 1);
    // REQUIRE(o == 0);
    // REQUIRE(t == 0);
}

TEST_CASE("Test win by third column", "[tic_tac_toe]") {
    tic_tac_toe game;
    game.start_game("X");
    game.mark_board(3);
    REQUIRE(!game.game_over());
    game.mark_board(1);
    REQUIRE(!game.game_over());
    game.mark_board(6);
    REQUIRE(!game.game_over());
    game.mark_board(4);
    REQUIRE(!game.game_over());
    game.mark_board(9);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
    // tic_tac_toe_manager games;
    // games.save_game(game);
    // int x, o, t;
    // games.get_winner_total(x, o, t);
    // REQUIRE(x == 1);
    // REQUIRE(o == 0);
    // REQUIRE(t == 0);
}

TEST_CASE("Test win by first row", "[tic_tac_toe]") {
    tic_tac_toe game;
    game.start_game("X");
    game.mark_board(1);
    REQUIRE(!game.game_over());
    game.mark_board(4);
    REQUIRE(!game.game_over());
    game.mark_board(2);
    REQUIRE(!game.game_over());
    game.mark_board(5);
    REQUIRE(!game.game_over());
    game.mark_board(3);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
    // tic_tac_toe_manager games;
    // games.save_game(game);
    // int x, o, t;
    // games.get_winner_total(x, o, t);
    // REQUIRE(x == 1);
    // REQUIRE(o == 0);
    // REQUIRE(t == 0);
}

TEST_CASE("Test win by second row", "[tic_tac_toe]") {
    tic_tac_toe game;
    game.start_game("X");
    game.mark_board(4);
    REQUIRE(!game.game_over());
    game.mark_board(1);
    REQUIRE(!game.game_over());
    game.mark_board(5);
    REQUIRE(!game.game_over());
    game.mark_board(2);
    REQUIRE(!game.game_over());
    game.mark_board(6);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
    // tic_tac_toe_manager games;
    // games.save_game(game);
    // int x, o, t;
    // games.get_winner_total(x, o, t);
    // REQUIRE(x == 1);
    // REQUIRE(o == 0);
    // REQUIRE(t == 0);
}

TEST_CASE("Test win by third row", "[tic_tac_toe]") {
    tic_tac_toe game;
    game.start_game("X");
    game.mark_board(7);
    REQUIRE(!game.game_over());
    game.mark_board(1);
    REQUIRE(!game.game_over());
    game.mark_board(8);
    REQUIRE(!game.game_over());
    game.mark_board(2);
    REQUIRE(!game.game_over());
    game.mark_board(9);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
    // tic_tac_toe_manager games;
    // games.save_game(game);
    // int x, o, t;
    // games.get_winner_total(x, o, t);
    // REQUIRE(x == 1);
    // REQUIRE(o == 0);
    // REQUIRE(t == 0);
}

TEST_CASE("Test win diagonally from top left", "[tic_tac_toe]") {
    tic_tac_toe game;
    game.start_game("X");
    game.mark_board(1);
    REQUIRE(!game.game_over());
    game.mark_board(2);
    REQUIRE(!game.game_over());
    game.mark_board(5);
    REQUIRE(!game.game_over());
    game.mark_board(3);
    REQUIRE(!game.game_over());
    game.mark_board(9);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
    // tic_tac_toe_manager games;
    // games.save_game(game);
    // int x, o, t;
    // games.get_winner_total(x, o, t);
    // REQUIRE(x == 1);
    // REQUIRE(o == 0);
    // REQUIRE(t == 0);
}

TEST_CASE("Test win diagonally from bottom left", "[tic_tac_toe]") {
   tic_tac_toe game;
    game.start_game("X");
    game.mark_board(7);
    REQUIRE(!game.game_over());
    game.mark_board(2);
    REQUIRE(!game.game_over());
    game.mark_board(5);
    REQUIRE(!game.game_over());
    game.mark_board(4);
    REQUIRE(!game.game_over());
    game.mark_board(3);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
    // tic_tac_toe_manager games;
    // games.save_game(game);
    // int x, o, t;
    // games.get_winner_total(x, o, t);
    // REQUIRE(x == 1);
    // REQUIRE(o == 0);
    // REQUIRE(t == 0);
}

TEST_CASE("Test Tie Condition using tic_tac_toe_manager", "[tic_tac_toe_manager]") {
    tic_tac_toe_manager manager;
    std::string winner;

    // Simulate game 1
    tic_tac_toe game1;
    game1.start_game("X");
    // game1.mark_board(1); game1.mark_board(2);
    // game1.mark_board(5); game1.mark_board(4);
    // game1.mark_board(7); game1.mark_board(6);
    // game1.mark_board(3); game1.mark_board(8);
    // game1.mark_board(9);
    game1.mark_board(1); // X
    game1.mark_board(2); // O
    game1.mark_board(3); // X
    game1.mark_board(5); // O
    game1.mark_board(4); // X
    game1.mark_board(6); // O
    game1.mark_board(8); // X
    game1.mark_board(7); // O
    game1.mark_board(9); // X
    manager.save_game(game1); // No winner here, should be a tie if filled

    // Simulate game 2
    tic_tac_toe game2;
    game2.start_game("O");
    game2.mark_board(1); game2.mark_board(2);
    game2.mark_board(5); game2.mark_board(4);
    game2.mark_board(3); game2.mark_board(8);
    game2.mark_board(9);   // O wins
    manager.save_game(game2);

    // Simulate game 3
    tic_tac_toe game3;
    game3.start_game("X");
    game3.mark_board(1); game3.mark_board(4);
    game3.mark_board(2); game3.mark_board(5);
    game3.mark_board(7); game3.mark_board(8); 
    game3.mark_board(3); // X wins
    manager.save_game(game3);

    int x_wins, o_wins, ties;
    manager.get_winner_total(x_wins, o_wins, ties);

    REQUIRE(x_wins == 1);
    REQUIRE(o_wins == 1);
    REQUIRE(ties == 1);
}
