#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include "tic_tac_toe.h"
#include <vector>

class tic_tac_toe_manager {
public:
    void save_game(const tic_tac_toe& b);
    void get_winner_total(int& o, int& x, int& t) const;

private:
    std::vector<tic_tac_toe> games;
    int x_win{0};
    int o_win{0};
    int ties{0};
    void update_winner_count(const std::string& winner);
};

#endif // TIC_TAC_TOE_MANAGER_H