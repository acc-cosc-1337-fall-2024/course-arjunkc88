//h
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <vector>
#include <string>

class TicTacToe {
public:
    void start_game(std::string first_player);
    void mark_board(int position);
    bool game_over();
    void display_board() const;
    std::string get_player() const;

private:
    std::string player;
    std::vector<std::string> pegs{9, " "};
    void set_next_player();
    bool check_board_full();
    void clear_board();
};

#endif // TIC_TAC_TOE_H
