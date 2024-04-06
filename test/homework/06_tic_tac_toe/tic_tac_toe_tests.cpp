#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
 }





TEST_CASE("Test first player set to X", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O", "[TicTacToe]") {
    TicTacToe game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}


void test_tie_condition() {
    TicTacToe game;
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
    assert(game.game_over() == true);
    assert(game.get_winner() == "C"); // C for Cat's game (tie)
    std::cout << "Test tie condition passed.\n";
}
TEST_CASE("Test win by first column", "[TicTacToe]") {
    TicTacToe game;
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
    REQUIRE(game.game_over());
}

TEST_CASE("Test win by second column", "[TicTacToe]") {
    TicTacToe game;
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
    REQUIRE(game.game_over());
}

TEST_CASE("Test win by third column", "[TicTacToe]") {
    TicTacToe game;
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
    REQUIRE(game.game_over());
}

TEST_CASE("Test win by first row", "[TicTacToe]") {
    TicTacToe game;
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
    REQUIRE(game.game_over());
}

TEST_CASE("Test win by second row", "[TicTacToe]") {
    TicTacToe game;
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
    REQUIRE(game.game_over());
}

TEST_CASE("Test win by third row", "[TicTacToe]") {
    TicTacToe game;
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
    REQUIRE(game.game_over());
}

TEST_CASE("Test win diagonally from top left", "[TicTacToe]") {
    TicTacToe game;
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
    REQUIRE(game.game_over());
}

TEST_CASE("Test win diagonally from bottom left", "[TicTacToe]") {
    TicTacToe game;
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
    REQUIRE(game.game_over());
}