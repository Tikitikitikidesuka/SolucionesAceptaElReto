#include <iostream>
#include <limits>

inline int32_t trip_end_instant(int32_t road_length, int32_t start_instant, int32_t speed) {
	if (start_instant < 0) return std::numeric_limits<int32_t>::max();
	if (speed <= 0) return std::numeric_limits<int32_t>::max();

	return road_length / speed + start_instant;
}

int main() {
	int32_t road_length, vehicle_num;

	while(std::cin >> road_length >> vehicle_num) {
		int32_t current_instant;
		int32_t start_instant, speed;
		int32_t min_instant = std::numeric_limits<int32_t>::max();

		for (int32_t i = 0; i < vehicle_num; ++i) {
			std::cin >> start_instant >> speed;
			min_instant = std::min(min_instant, trip_end_instant(road_length, start_instant, speed));
		}

		std::cout << min_instant << "\n";
	}

	return 0;
}
