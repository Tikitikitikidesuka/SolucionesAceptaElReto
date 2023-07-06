#include <algorithm>
#include <iostream>
#include <cstdint>
#include <array>

#define MAX_BOARD_SIDE_LENGTH 128
#define WATER_TYPE 0
#define BOAT_TYPE 1

inline void fastIntInput(uint_fast8_t& number) {
    register uint_fast8_t input;

    number = 0;
    input = getchar_unlocked();

    // Clear noise on buffer
    for (; (input < '0' || input > '9'); input = getchar_unlocked());

    // Get number
    for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
        number = number * 10 + input - 48;
}

class Board {
private:
    uint_fast8_t side_length;
    uint_fast8_t board[MAX_BOARD_SIDE_LENGTH][MAX_BOARD_SIDE_LENGTH];

public:
    Board(uint_fast8_t side_length) : side_length(side_length) {}

    uint_fast8_t get_side_length() const {
        return side_length;
    }

    // WARNING: No safety checks
    void set_tile(uint_fast8_t i, uint_fast8_t j, uint_fast8_t type) {
        board[i][j] = type;
    }

    uint_fast8_t get_tile(uint_fast8_t i, uint_fast8_t j) const {
        return (i >= 0 && i < side_length && j >= 0 && j < side_length ? board[i][j] : WATER_TYPE);
    }
};

class Boat {
private:
    bool horizontal;
    uint_fast8_t i, j, length;

public:
    Boat(uint_fast8_t i, uint_fast8_t j, uint_fast8_t length, bool horizontal)
    : i(i), j(j), length(length), horizontal(horizontal) {}

    uint_fast8_t get_i() const {
        return i;
    }

    uint_fast8_t get_j() const {
        return j;
    }

    uint_fast8_t get_length() const {
        return length;
    }

    uint_fast8_t is_horizontal() const {
        return horizontal;
    }

    uint_fast8_t is_vertical() const {
        return !horizontal;
    }
};

Boat find_boat_horizontal(const Board& board, uint_fast8_t i, uint_fast8_t j);
Boat find_boat_vertical(const Board& board, uint_fast8_t i, uint_fast8_t j);

Boat find_boat(const Board& board, uint_fast8_t i, uint_fast8_t j) {
    bool vertical_move = board.get_tile(i + 1, j) == BOAT_TYPE;
    bool horizontal_move = board.get_tile(i, j + 1) == BOAT_TYPE;

    if (horizontal_move) {
        return find_boat_horizontal(board, i, j);
    } else if (vertical_move) {
        return find_boat_vertical(board, i, j);
    } else {
        return Boat(i, j, 1, true);
    }
}

Boat find_boat_horizontal(const Board& board, uint_fast8_t i, uint_fast8_t j) {
    uint_fast8_t j_it = j;
    while (board.get_tile(i, j_it) != WATER_TYPE) ++j_it;
    return Boat(i, j, j_it - j, true);
}

Boat find_boat_vertical(const Board& board, uint_fast8_t i, uint_fast8_t j) {
    uint_fast8_t i_it = i;
    while (board.get_tile(i_it, j) != WATER_TYPE) ++i_it;
    return Boat(i, j, i_it - i, false);
}

bool valid_horizontal_boat_perimeter(const Board& board, const Boat& boat);
bool valid_vertical_boat_perimeter(const Board& board, const Boat& boat);

bool valid_boat_perimeter(const Board& board, const Boat& boat) {
    if (boat.is_horizontal()) {
        return valid_horizontal_boat_perimeter(board, boat);
    } else {
        return valid_vertical_boat_perimeter(board, boat);
    }
}

bool valid_horizontal_boat_perimeter(const Board& board, const Boat& boat) {
    uint_fast8_t i = boat.get_i();
    uint_fast8_t j = boat.get_j();
    uint_fast8_t length = boat.get_length();

    bool left_and_right_sides = board.get_tile(i + 1, j - 1) == WATER_TYPE
            && board.get_tile(i, j - 1) ==  WATER_TYPE
            && board.get_tile(i - 1, j - 1) == WATER_TYPE
            && board.get_tile(i + 1, j + length) == WATER_TYPE
            && board.get_tile(i, j + length) ==  WATER_TYPE
            && board.get_tile(i - 1, j + length) == WATER_TYPE;

    bool top_and_bottom_sides = true;
    for (uint_fast8_t offset = 0; top_and_bottom_sides && offset < length; ++offset) {
        top_and_bottom_sides = board.get_tile(i + 1, j + offset) == WATER_TYPE
                && board.get_tile(i - 1, j + offset) == WATER_TYPE;
    }

    return left_and_right_sides && top_and_bottom_sides;
}

bool valid_vertical_boat_perimeter(const Board& board, const Boat& boat) {
    uint_fast8_t i = boat.get_i();
    uint_fast8_t j = boat.get_j();
    uint_fast8_t length = boat.get_length();

    bool top_and_bottom_sides = board.get_tile(i - 1, j + 1) == WATER_TYPE
                     && board.get_tile(i - 1, j) ==  WATER_TYPE
                     && board.get_tile(i - 1, j - 1) == WATER_TYPE
                     && board.get_tile(i + length, j + 1) == WATER_TYPE
                     && board.get_tile(i + length, j) ==  WATER_TYPE
                     && board.get_tile(i + length, j - 1) == WATER_TYPE;

    bool left_and_right_sides = true;
    for (uint_fast8_t offset = 0; left_and_right_sides && offset < length; ++offset) {
        left_and_right_sides = board.get_tile(i + offset, j + 1) == WATER_TYPE
                               && board.get_tile(i + offset, j - 1) == WATER_TYPE;
    }

    return top_and_bottom_sides && left_and_right_sides;
}

void remove_boat_horizontal(Board& board, const Boat& boat);
void remove_boat_vertical(Board& board, const Boat& boat);

void remove_boat(Board& board, const Boat& boat) {
    if (boat.is_horizontal()) {
        remove_boat_horizontal(board, boat);
    } else {
        remove_boat_vertical(board, boat);
    }
}

void remove_boat_horizontal(Board& board, const Boat& boat) {
    uint_fast8_t i = boat.get_i();
    uint_fast8_t j = boat.get_j();

    for (uint_fast8_t offset = 0; offset < boat.get_length(); ++offset)
        board.set_tile(i, j + offset, WATER_TYPE);
}

void remove_boat_vertical(Board& board, const Boat& boat) {
    uint_fast8_t i = boat.get_i();
    uint_fast8_t j = boat.get_j();

    for (uint_fast8_t offset = 0; offset < boat.get_length(); ++offset)
        board.set_tile(i + offset, j, WATER_TYPE);
}

bool valid_board(Board& board, std::array<uint_fast8_t, MAX_BOARD_SIDE_LENGTH>& boats_by_length) {
    for (uint_fast8_t i = 0; i < board.get_side_length(); ++i) {
        for (uint_fast8_t j = 0; j < board.get_side_length(); ++j) {
            if (board.get_tile(i, j) == BOAT_TYPE) {
                Boat boat = find_boat(board, i, j);
                bool safe = valid_boat_perimeter(board, boat);

                if (!safe) {
                    return false;
                } else {
                    if (boats_by_length[boat.get_length() - 1] == 0) return false;
                    else {
                        --boats_by_length[boat.get_length() - 1];
                        remove_boat(board, boat);
                    }
                }
            }
        }
    }

    return std::all_of(
            boats_by_length.begin(),
            boats_by_length.end(),
            [](uint_fast8_t elem){return elem == 0;});
}

int main() {
    uint_fast8_t boat_num;

    fastIntInput(boat_num);
    while (boat_num > 0) {
        std::array<uint_fast8_t, MAX_BOARD_SIDE_LENGTH> boats_by_length{};
        boats_by_length.fill(0);
        for (uint_fast8_t i = 0; i < boat_num; ++i) {
            uint_fast8_t boat_length = 0;
            fastIntInput(boat_length);
            ++boats_by_length[boat_length - 1];
        }

        uint_fast8_t board_side_length;
        fastIntInput(board_side_length);

        Board board(board_side_length);
        for (uint_fast8_t i = 0; i < board_side_length; ++i) {
            for (uint_fast8_t j = 0; j < board_side_length; ++j) {
                uint_fast8_t tile_type;
                fastIntInput(tile_type);
                board.set_tile(i, j, tile_type);
            }
        }

        if (valid_board(board, boats_by_length)) {
            putchar_unlocked('S');
            putchar_unlocked('I');
            putchar_unlocked('\n');
        } else {
            putchar_unlocked('N');
            putchar_unlocked('O');
            putchar_unlocked('\n');
        }

        fastIntInput(boat_num);
    }

    return 0;
}
