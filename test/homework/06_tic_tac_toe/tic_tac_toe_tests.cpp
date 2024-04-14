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


void test_tie_condition() {
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
    assert(game.game_over() == true);
    assert(game.get_winner() == "C"); // C for Cat's game (tie)
    std::cout << "Test tie condition passed.\n";
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
    REQUIRE(game.game_over());
  // Validate winner as "X"
  REQUIRE(game.get_winner() == "X");
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
    REQUIRE(game.game_over());
    // Validate winner as "X"
  REQUIRE(game.get_winner() == "O");
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
    REQUIRE(game.game_over());
    // Validate winner as "X"
  REQUIRE(game.get_winner() == "O");
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
    REQUIRE(game.game_over());
    // Validate winner as "X"
  REQUIRE(game.get_winner() == "O");
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
    REQUIRE(game.game_over());
    // Validate winner as "X"
  REQUIRE(game.get_winner() == "O");
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
    REQUIRE(game.game_over());
    // Validate winner as "X"
  REQUIRE(game.get_winner() == "O");
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
    REQUIRE(game.game_over());
    // Validate winner as "X"
  REQUIRE(game.get_winner() == "O");
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
    REQUIRE(game.game_over());
    // Validate winner as "X"
  REQUIRE(game.get_winner() == "O");
}
// TEST_CASE("Test Tie Condition using tic_tac_toe_manager", "[tic_tac_toe]") {
//   tic_tac_toe_manager manager; // Ensure this is the correct class name

//   // Assuming we have a method to play a game and return the winner
//   std::string winner;

//   // Simulate game 1
//   tic_tac_toe game1;
//   game1.start_game("X");
//   game1.mark_board(1); game1.mark_board(2); // and so on
//   winner = game1.get_winner();
//   manager.save_game(game1);

//   // Simulate game 2
//   tic_tac_toe game2;
//   game2.start_game("O");
//   game2.mark_board(4); game2.mark_board(9); // and so on
//   winner = game2.get_winner();
//   manager.save_game(game2);

//   // Simulate game 3 (Tie)
//   tic_tac_toe game3;
//   game3.start_game("X");
//   game3.mark_board(1); game3.mark_board(2); // and so on, ending in a tie
//   winner = game3.get_winner();
//   manager.save_game(game3);

//   int x_wins, o_wins, ties;
//   manager.get_winner_total(o_wins, x_wins, ties); // Ensure this is the correct method name

//   REQUIRE(x_wins == 1);
//   REQUIRE(o_wins == 1);
//   REQUIRE(ties == 1);
// }
TEST_CASE("Test Tie Condition using tic_tac_toe_manager", "[tic_tac_toe]") {
    tic_tac_toe_manager manager;
    std::string winner;
    
    // Simulate game 1
    tic_tac_toe game1;
    game1.start_game("X");
    game1.mark_board(1);
    game1.mark_board(2);
    // and so on
    winner = game1.get_winner();
    manager.save_game(game1);
    
    // Simulate game 2
    tic_tac_toe game2;
    game2.start_game("O");
    game2.mark_board(4);
    game2.mark_board(9);
    // and so on
    winner = game2.get_winner();
    manager.save_game(game2);
    
    // Simulate game 3 (Tie)
    tic_tac_toe game3;
    game3.start_game("X");
    game3.mark_board(1);
    game3.mark_board(2);
    // and so on, ending in a tie
    winner = game3.get_winner();
    manager.save_game(game3);
    
    int x_wins, o_wins, ties;
    manager.get_winner_total(x_wins, o_wins, ties); // Corrected method name
    
    // Check for one win each for X and O, and one tie
    REQUIRE(x_wins == 1);
    REQUIRE(o_wins == 1);
    REQUIRE(ties == 1);
}