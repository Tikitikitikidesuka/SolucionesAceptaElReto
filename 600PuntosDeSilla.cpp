#include <iostream>
#include <functional>

#define MAX_SIZE 300

int matrix[MAX_SIZE][MAX_SIZE];

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int *width, int *height) {
	std::cin >> *height >> *width;

	for(int y = 0; y < *height; ++y) {
		for(int x = 0; x < *width; ++x) {
			std::cin >> matrix[y][x];
		}
	}
}

int matrixRowCompare(int matrix[MAX_SIZE][MAX_SIZE], int width, int height, int row, std::function<bool (int, int)> comparator) {
	int selection = matrix[row][0];

	for(int column = 1; column < width; ++column) {
		if(comparator(matrix[row][column], selection)) {
			selection = matrix[row][column];
		}
	}

	return selection;
}

int matrixColumnCompare(int matrix[MAX_SIZE][MAX_SIZE], int width, int height, int column, std::function<bool (int, int)> comparator) {
	int selection = matrix[0][column];

	for(int row = 1; row < height; ++row) {
		if(comparator(matrix[row][column], selection)) {
			selection = matrix[row][column];
		}
	}

	return selection;
}

bool matrixContainsSaddlePoint(int matrix[MAX_SIZE][MAX_SIZE], int width, int height) {
	int row_mins[MAX_SIZE];
	int row_maxs[MAX_SIZE];
	int column_mins[MAX_SIZE];
	int column_maxs[MAX_SIZE];

	for(int y = 0; y < height; ++y) {
		row_mins[y] = matrixRowCompare(matrix, width, height, y, [](int a, int b) { return a < b; });
		row_maxs[y] = matrixRowCompare(matrix, width, height, y, [](int a, int b) { return a > b; });
	}

	for(int x = 0; x < width; ++x) {
		column_mins[x] = matrixColumnCompare(matrix, width, height, x, [](int a, int b) { return a < b; });
		column_maxs[x] = matrixColumnCompare(matrix, width, height, x, [](int a, int b) { return a > b; });
	}

	bool saddlePoint = false;
	for(int y = 0; y < height && !saddlePoint; ++y) {
		for(int x = 0; x < width && !saddlePoint; ++x) {
			saddlePoint = (matrix[y][x] == row_mins[y] && matrix[y][x] == column_maxs[x])
				|| (matrix[y][x] == row_maxs[y] && matrix[y][x] == column_mins[x]);
		}
	}

	return saddlePoint;
}

int main() {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int width, height;
	inputMatrix(matrix, &width, &height);

	while(width != 0 || height != 0) {
		if(matrixContainsSaddlePoint(matrix, width, height)) {
			std::cout << "SI\n";
		} else {
			std::cout << "NO\n";
		}

		inputMatrix(matrix, &width, &height);
	}

	return 0;
}
