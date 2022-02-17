#include <iostream>


// Vars optimized for cpu speed
// At least n bits (might be bigger)
typedef std::uint_fast8_t  int8;
typedef std::uint_fast16_t int16;


class Maze {
    private:
        int16** tiles; // Tile matrix [y][x]
        int8 sizeX, sizeY;

        int8 capX, capY;
        int8 lobX, lobY;

    public:
        constexpr static const int16 PATH = 0;
        constexpr static const int16 OBSTACLE = ~0;

    public:
        Maze(int8 sizeX, int8 sizeY) : sizeX(sizeX), sizeY(sizeY) {
            // Allocate tiles matrix
            tiles = new int16*[sizeY];
            for(int8 it = 0; it < sizeY; ++it)
                tiles[it] = new int16[sizeX]();
                // Se supone que new int16[sizeX]() inicializa a cero, pero cuidado.

        }
        
        Maze(int8 sizeX, int8 sizeY, const std::string& representation) : Maze(sizeX, sizeY) {
            // Set matrix values
            int8 character = 0;
            for(int8 y = 0; y < sizeY; ++y) {
                for(int8 x = 0; x < sizeX; ++x) {
                    //std::cout << (int) x << ", " << (int) y << "\n";
                    switch (representation[character++]) {
                    case '.':
                        tiles[y][x] = PATH;
                        break;
                    case '#':
                        tiles[y][x] = OBSTACLE;
                        break;
                    case 'C':
                        capX = x;
                        capY = y;
                        break;
                    case 'L':
                        lobX = x;
                        lobY = y;
                        break;
                    }
                }
            }
        }

        ~Maze() {
            // Deallocate tiles matrix
            for(int8 it = 0; it < sizeY; ++it)
                delete[] tiles[it];
            delete[] tiles;
        }


        const int16& operator () (int8 x, int8 y) const {
            return tiles[y][x];
        }


        void moveCaperucita(int8 x, int8 y) {
            capX = x;
            capY = y;
        }

        void moveLobo(int8 x, int8 y) {
            lobX = x;
            lobY = y;
        }

        void setObstacle(int8 x, int8 y) {
            tiles[y][x] = OBSTACLE;
        }
};


int main() {
    std::string representation = 
        "...C."
        "...#."
        "##..."
        "..L.."
    ;

    Maze maze(5, 4, representation);

    maze.setObstacle(1, 3);
    std::cout << maze(1, 3) << "\n";
    return 0;
}