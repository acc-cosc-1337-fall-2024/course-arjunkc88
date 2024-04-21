
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <vector>
#include <string>
#include <iostream>

class TicTacToe {
public:
    TicTacToe(int size); // Constructor with size parameter

    // Public member functions
    void start_game(std::string first_player);
    void mark_board(int position);
    bool game_over();
    std::string get_player() const;
    void display_board() const;
    std::string get_winner() const;
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);

protected:
    // Now protected member variables and functions for derived classes
    std::vector<std::string> pegs;
    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();

private:
    void set_winner();
    void set_next_player();
    bool check_board_full() const;
    void clear_board();

    std::string player;
    std::string winner;
};

#endif // TIC_TAC_TOE_H
