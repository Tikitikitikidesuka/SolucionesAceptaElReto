#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_SECTORS 50
#define MAX_OBJECTIVE_POINTS 500

#define MIN_DARTS_UNACHIEVABLE (-1)

void updateMatrixField(int matrix[MAX_SECTORS][MAX_OBJECTIVE_POINTS + 1], int p, int i, const std::vector<int>& sector_values) {
    // Base case
    if (p == 0) {
        matrix[i][p] = 0;
        return;
    }

    // Recursive case
    int used = p >= sector_values[i] ? matrix[sector_values.size() - 1][p - sector_values[i]] : MIN_DARTS_UNACHIEVABLE;
    int not_used = i > 0 ? matrix[i - 1][p] : MIN_DARTS_UNACHIEVABLE;

    if (used != MIN_DARTS_UNACHIEVABLE && not_used != MIN_DARTS_UNACHIEVABLE) {
        matrix[i][p] = std::min(used + 1, not_used);
    } else if (used != MIN_DARTS_UNACHIEVABLE) {
        matrix[i][p] = used + 1;
    } else {
        matrix[i][p] = not_used;
    }
}

int solveMinDarts(int objective, const std::vector<int>& sector_values, std::vector<int>& solution) {
    // matrix[i][p] = f(p, i)
    int matrix[MAX_SECTORS][MAX_OBJECTIVE_POINTS + 1];

    // Solve all states
    for (int p = 0; p <= objective; ++p) {
        for (int i = 0; i < sector_values.size(); ++i) {
            updateMatrixField(matrix, p, i, sector_values);
        }
    }

    if (matrix[sector_values.size() - 1][objective] == MIN_DARTS_UNACHIEVABLE)
        return false;

    // Optimal solution container
    solution.clear();
    solution.reserve(matrix[sector_values.size() - 1][objective]);

    // Get optimal solution
    int p = objective;
    int i = sector_values.size();
    while (p >= 0 && i >= 0) {
        int prev = p - sector_values[i];
        if (prev >= 0 && matrix[i][p] == matrix[i][p - sector_values[i]] + 1) { // Used
            solution.push_back(sector_values[i]);
            p = prev;
        } else { // Not used
            --i;
        }
    }

    return true;
}

int main() {
    int objective, num_values;
    while (std::cin >> objective >> num_values) {
        std::vector<int> sector_values;
        sector_values.reserve(num_values);
        for (int i = 0; i < num_values; ++i) {
            int input_sector_value;
            std::cin >> input_sector_value;
            sector_values.push_back(input_sector_value);
        }

        std::vector<int> solution;
        bool possible = solveMinDarts(objective, sector_values, solution);
        if (possible) {
            std::cout << solution.size() << ":";
            for (int val: solution)
                std::cout << " " << val;
            std::cout << "\n";
        } else {
            std::cout << "Imposible\n";
        }
    }

    return 0;
}