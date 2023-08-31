#include <iostream>

#define MAX_SIDE_LENGTH 2000

inline int get_right_diagonal_by_coords(int side, int x, int y) {
    return side - x + y - 1;
}

inline int get_left_diagonal_by_coords(int x, int y) {
    return x + y - 2;
}

int main() {
    int board_side_length, queens;
    std::cin >> board_side_length >> queens;

    while (board_side_length != 0 || queens != 0) {
        bool rows[MAX_SIDE_LENGTH] {false};
        bool columns[MAX_SIDE_LENGTH] {false};
        bool right_diagonals[MAX_SIDE_LENGTH * 2] {false};
        bool left_diagonals[MAX_SIDE_LENGTH * 2] {false};

        int x, y;
        int queen_idx = 0;
        bool valid_board = true;

        while (valid_board && queen_idx < queens) {
            std::cin >> x >> y;

            int left_diagonal = get_left_diagonal_by_coords(x, y);
            int right_diagonal = get_right_diagonal_by_coords(board_side_length, x, y);

            valid_board = !columns[x - 1] && !rows[y - 1]
                    && !right_diagonals[right_diagonal]
                    && !left_diagonals[left_diagonal];

            rows[y - 1] = true;
            columns[x - 1] = true;
            left_diagonals[left_diagonal] = true;
            right_diagonals[right_diagonal] = true;

            ++queen_idx;
        }

        while (queen_idx++ < queens) std::cin >> x >> y;

        std::cout << (valid_board ? "NO\n" : "SI\n");

        std::cin >> board_side_length >> queens;
    }

    return 0;
}