

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

#include <memory>

TEST_CASE("Test first player set to X TicTacToe3", "[TicTacToe3]") {
    auto board = std::make_unique<TicTacToe3>();
    board->start_game("X");
    REQUIRE(board->get_player() == "X");
}

TEST_CASE("Test first player set to O TicTacToe3", "[TicTacToe3]") {
    auto board = std::make_unique<TicTacToe3>();
    board->start_game("O");
    REQUIRE(board->get_player() == "O");
}
TEST_CASE("Test tie condition TicTacToe3", "[TicTacToe3]") {
    auto board = std::make_unique<TicTacToe3>();
    board->start_game("X");
    board->mark_board(1); // X
    board->mark_board(2); // O
    board->mark_board(3); // X
    board->mark_board(5); // O
    board->mark_board(4); // X
    board->mark_board(6); // O
    board->mark_board(8); // X
    board->mark_board(7); // O
    board->mark_board(9); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "C"); // C for Cat's game (tie)
    TicTacToeManager games;
    games.save_game(std::move(board));
    int x, o, t;
    games.get_winner_total(x, o, t);
    REQUIRE(x == 0);
    REQUIRE(o == 0);
    REQUIRE(t == 1);
}

TEST_CASE("Test win by first column TicTacToe3", "[TicTacToe3]") {
    auto board = std::make_unique<TicTacToe3>();
    board->start_game("X");
    board->mark_board(1); // X
    board->mark_board(2); // O
    board->mark_board(4); // X
    board->mark_board(5); // O
    board->mark_board(7); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by second column TicTacToe3", "[TicTacToe3]") {
    auto board = std::make_unique<TicTacToe3>();
    board->start_game("X");
    board->mark_board(2); // X
    board->mark_board(1); // O
    board->mark_board(5); // X
    board->mark_board(4); // O
    board->mark_board(8); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by third column TicTacToe3", "[TicTacToe3]") {
    auto board = std::make_unique<TicTacToe3>();
    board->start_game("X");
    board->mark_board(3); // X
    board->mark_board(1); // O
    board->mark_board(6); // X
    board->mark_board(4); // O
    board->mark_board(9); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}
TEST_CASE("Test win by first row TicTacToe3", "[TicTacToe3]") {
    auto board = std::make_unique<TicTacToe3>();
    board->start_game("X");
    board->mark_board(1); // X
    board->mark_board(4); // O
    board->mark_board(2); // X
    board->mark_board(5); // O
    board->mark_board(3); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by second row TicTacToe3", "[TicTacToe3]") {
    auto board = std::make_unique<TicTacToe3>();
    board->start_game("X");
    board->mark_board(4); // X
    board->mark_board(1); // O
    board->mark_board(5); // X
    board->mark_board(2); // O
    board->mark_board(6); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by third row TicTacToe3", "[TicTacToe3]") {
    auto board = std::make_unique<TicTacToe3>();
    board->start_game("X");
    board->mark_board(7); // X
    board->mark_board(1); // O
    board->mark_board(8); // X
    board->mark_board(2); // O
    board->mark_board(9); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}


TEST_CASE("Test win diagonally from top left TicTacToe3", "[TicTacToe3]") {
    auto board = std::make_unique<TicTacToe3>();
    board->start_game("X");
    board->mark_board(1); // X
    board->mark_board(2); // O
    board->mark_board(5); // X
    board->mark_board(3); // O
    board->mark_board(9); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left TicTacToe3", "[TicTacToe3]") {
    auto board = std::make_unique<TicTacToe3>();
    board->start_game("X");
    board->mark_board(7); // X
    board->mark_board(1); // O
    board->mark_board(5); // X
    board->mark_board(2); // O
    board->mark_board(3); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}
TEST_CASE("Test Tie Condition using TicTacToeManager", "[TicTacToeManager]") {
    TicTacToeManager manager;
    std::string winner;

    // Simulate game 1, expected to be a tie
    auto game1 = std::make_unique<TicTacToe3>();
    game1->start_game("X");
    game1->mark_board(1); // X
    game1->mark_board(2); // O
    game1->mark_board(3); // X
    game1->mark_board(5); // O
    game1->mark_board(4); // X
    game1->mark_board(6); // O
    game1->mark_board(8); // X
    game1->mark_board(7); // O
    game1->mark_board(9); // X
    manager.save_game(std::move(game1)); // No winner here, should be a tie if filled

    // Simulate game 2, O wins
    auto game2 = std::make_unique<TicTacToe3>();
    game2->start_game("O");
    game2->mark_board(1);
    game2->mark_board(2);
    game2->mark_board(5);
    game2->mark_board(4);
    game2->mark_board(3);
    game2->mark_board(8);
    game2->mark_board(9);   // O wins
    manager.save_game(std::move(game2));

    // Simulate game 3, X wins
    auto game3 = std::make_unique<TicTacToe3>();
    game3->start_game("X");
    game3->mark_board(1);
    game3->mark_board(4);
    game3->mark_board(2);
    game3->mark_board(5);
    game3->mark_board(7);
    game3->mark_board(8);
    game3->mark_board(3); // X wins
    manager.save_game(std::move(game3));

    int x_wins, o_wins, ties;
    manager.get_winner_total(x_wins, o_wins, ties);

    REQUIRE(x_wins == 1);
    REQUIRE(o_wins == 1);
    REQUIRE(ties == 1);
}

//For TicTacToe4

TEST_CASE("Test tie condition TicTacToe4", "[TicTacToe4]") {
    auto board = std::make_unique<TicTacToe4>();
    board->start_game("X");
    // Setup moves to fill the 4x4 board without a winner
    board->mark_board(1); // X
    board->mark_board(2); // O
    board->mark_board(5); // X
    board->mark_board(3); // O
    board->mark_board(6); // X
    board->mark_board(7); // O
    board->mark_board(10); // X
    board->mark_board(11); // O
    board->mark_board(12); // X
    board->mark_board(14); // O
    board->mark_board(4);  // X
    board->mark_board(8);  // O
    board->mark_board(9);  // X
    board->mark_board(13); // O
    board->mark_board(15); // X
    board->mark_board(16); // O
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "C"); // C for Cat's game (tie)
    TicTacToeManager games;
    games.save_game(std::move(board));
    int x, o, t;
    games.get_winner_total(x, o, t);
    REQUIRE(x == 0);
    REQUIRE(o == 0);
    REQUIRE(t == 1);
}

TEST_CASE("Test win by first column TicTacToe4", "[TicTacToe4]") {
    auto board = std::make_unique<TicTacToe4>();
    board->start_game("X");
    board->mark_board(1); // X
    board->mark_board(5); // O
    board->mark_board(2); // X
    board->mark_board(6); // O
    board->mark_board(3); // X
    board->mark_board(7); // O
    board->mark_board(4); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}
TEST_CASE("Test win by second column TicTacToe4", "[TicTacToe4]") {
    auto board = std::make_unique<TicTacToe4>();
    board->start_game("X");
    board->mark_board(2); // X
    board->mark_board(1); // O
    board->mark_board(6); // X
    board->mark_board(5); // O
    board->mark_board(10); // X
    board->mark_board(9); // O
    board->mark_board(14); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by third column TicTacToe4", "[TicTacToe4]") {
    auto board = std::make_unique<TicTacToe4>();
    board->start_game("X");
    board->mark_board(3); // X
    board->mark_board(1); // O
    board->mark_board(7); // X
    board->mark_board(5); // O
    board->mark_board(11); // X
    board->mark_board(9); // O
    board->mark_board(15); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by fourth column TicTacToe4", "[TicTacToe4]") {
    auto board = std::make_unique<TicTacToe4>();
    board->start_game("X");
    board->mark_board(4); // X
    board->mark_board(1); // O
    board->mark_board(8); // X
    board->mark_board(5); // O
    board->mark_board(12); // X
    board->mark_board(9); // O
    board->mark_board(16); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}
TEST_CASE("Test win by first row TicTacToe4", "[TicTacToe4]") {
    auto board = std::make_unique<TicTacToe4>();
    board->start_game("X");
    board->mark_board(1); // X
    board->mark_board(5); // O
    board->mark_board(2); // X
    board->mark_board(6); // O
    board->mark_board(3); // X
    board->mark_board(7); // O
    board->mark_board(4); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by second row TicTacToe4", "[TicTacToe4]") {
    auto board = std::make_unique<TicTacToe4>();
    board->start_game("X");
    board->mark_board(5); // X
    board->mark_board(1); // O
    board->mark_board(6); // X
    board->mark_board(2); // O
    board->mark_board(7); // X
    board->mark_board(3); // O
    board->mark_board(8); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by third row TicTacToe4", "[TicTacToe4]") {
    auto board = std::make_unique<TicTacToe4>();
    board->start_game("X");
    board->mark_board(9); // X
    board->mark_board(1); // O
    board->mark_board(10); // X
    board->mark_board(2); // O
    board->mark_board(11); // X
    board->mark_board(3); // O
    board->mark_board(12); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by fourth row TicTacToe4", "[TicTacToe4]") {
    auto board = std::make_unique<TicTacToe4>();
    board->start_game("X");
    board->mark_board(13); // X
    board->mark_board(1); // O
    board->mark_board(14); // X
    board->mark_board(2); // O
    board->mark_board(15); // X
    board->mark_board(3); // O
    board->mark_board(16); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left TicTacToe4", "[TicTacToe4]") {
    auto board = std::make_unique<TicTacToe4>();
    board->start_game("X");
    board->mark_board(1); // X
    board->mark_board(2); // O
    board->mark_board(6); // X
    board->mark_board(3); // O
    board->mark_board(11); // X
    board->mark_board(4); // O
    board->mark_board(16); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}
TEST_CASE("Test win diagonally from bottom left TicTacToe4", "[TicTacToe4]") {
    auto board = std::make_unique<TicTacToe4>();
    board->start_game("X");
    board->mark_board(13); // X
    board->mark_board(2); // O
    board->mark_board(10); // X
    board->mark_board(3); // O
    board->mark_board(7); // X
    board->mark_board(5); // O
    board->mark_board(4); // X
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}
TEST_CASE("Test Tie Condition using TicTacToeManager for TicTacToe4", "[TicTacToeManager]") {
    TicTacToeManager manager;

    // Simulate game 1, expected to be a tie
    auto game1 = std::make_unique<TicTacToe4>();
    game1->start_game("X");
    // Mark the board in a way that ensures a tie
    game1->mark_board(1);  // X
    game1->mark_board(2);  // O
    game1->mark_board(5);  // X
    game1->mark_board(3);  // O
    game1->mark_board(6);  // X
    game1->mark_board(7);  // O
    game1->mark_board(10); // X
    game1->mark_board(11); // O
    game1->mark_board(13); // X
    game1->mark_board(14); // O
    game1->mark_board(4);  // X
    game1->mark_board(8);  // O
    game1->mark_board(12);  // X
    game1->mark_board(9); // O
    game1->mark_board(15); // X
    game1->mark_board(16); // O
    manager.save_game(std::move(game1)); // Should be a tie

    // Simulate game 2, O wins
    auto game2 = std::make_unique<TicTacToe4>();
    game2->start_game("O");
    game2->mark_board(1); 
    game2->mark_board(2);
    game2->mark_board(5);
    game2->mark_board(6);
    game2->mark_board(9);  
    game2->mark_board(10);
    game2->mark_board(13); // O wins
    manager.save_game(std::move(game2));

    // Simulate game 3, X wins
    auto game3 = std::make_unique<TicTacToe4>();
    game3->start_game("X");
    game3->mark_board(1); 
    game3->mark_board(5); 
    game3->mark_board(2);
    game3->mark_board(6); 
    game3->mark_board(3); 
    game3->mark_board(7);
    game3->mark_board(4); // X wins
    manager.save_game(std::move(game3));

    int x_wins, o_wins, ties;
    manager.get_winner_total(x_wins, o_wins, ties);

    REQUIRE(x_wins == 1);
    REQUIRE(o_wins == 1);
    REQUIRE(ties == 1);
}
