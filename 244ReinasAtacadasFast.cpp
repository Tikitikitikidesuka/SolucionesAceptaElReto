#include <iostream>
#include <cinttypes>

#define MAX_SIDE_LENGTH 2000

inline int_fast16_t get_right_diagonal_by_coords(int_fast16_t side, int_fast16_t x, int_fast16_t y) {
    return side - x + y - 1;
}

inline int_fast16_t get_left_diagonal_by_coords(int_fast16_t x, int_fast16_t y) {
    return x + y - 2;
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    register int_fast16_t board_side_length, queens;
    std::cin >> board_side_length >> queens;

    while (board_side_length != 0 || queens != 0) {
        bool rows[MAX_SIDE_LENGTH] {false};
        bool columns[MAX_SIDE_LENGTH] {false};
        bool right_diagonals[MAX_SIDE_LENGTH * 2] {false};
        bool left_diagonals[MAX_SIDE_LENGTH * 2] {false};

        int_fast16_t x, y;
        int_fast16_t queen_idx = 0;
        register bool valid_board = true;

        while (valid_board && queen_idx < queens) {
            std::cin >> x >> y;

            int_fast16_t left_diagonal = get_left_diagonal_by_coords(x, y);
            int_fast16_t right_diagonal = get_right_diagonal_by_coords(board_side_length, x, y);

            valid_board = !columns[x - 1] && !rows[y - 1]
                    && !right_diagonals[right_diagonal]
                    && !left_diagonals[left_diagonal];

            rows[y - 1] = true;
            columns[x - 1] = true;
            left_diagonals[left_diagonal] = true;
            right_diagonals[right_diagonal] = true;

            ++queen_idx;
        }

        if (queen_idx < queens) std::cin.ignore(100000, '\n');

        if (valid_board) {
            putchar_unlocked('N');
            putchar_unlocked('O');
            putchar_unlocked('\n');
        } else {
            putchar_unlocked('S');
            putchar_unlocked('I');
            putchar_unlocked('\n');
        }

        std::cin >> board_side_length >> queens;
    }

    return 0;
}