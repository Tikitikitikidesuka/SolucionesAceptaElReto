#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX_STROKES 1000

int64_t painted_area(int64_t stroke_width, const std::vector<std::pair<int64_t, int64_t>>& rect_coords) {
    std::vector<std::pair<int64_t, int64_t>> height_changes;
    height_changes.reserve(rect_coords.size() * 2);

    for (const auto& rectangle : rect_coords) {
        height_changes.emplace_back(rectangle.first, -rectangle.second);
        height_changes.emplace_back(rectangle.first + stroke_width, rectangle.second);
    }

    std::sort(height_changes.begin(), height_changes.end());

    std::vector<std::pair<int64_t, int64_t>> skyline;
    std::multiset<int64_t> acc_height_changes = { 0 };

    for (const auto& height_change : height_changes) {
        const int64_t prev_height = *acc_height_changes.rbegin();

        if (height_change.second < 0) acc_height_changes.insert(-height_change.second);
        else acc_height_changes.erase(acc_height_changes.find(height_change.second));

        if (*acc_height_changes.rbegin() != prev_height)
            skyline.emplace_back(height_change.first, *acc_height_changes.rbegin());
    }

    int64_t area = 0;
    for (auto it = skyline.begin() + 1; it != skyline.end(); ++it)
        area += (it->first - (it - 1)->first) * (it - 1)->second;

    return area;
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int64_t stroke_width, stroke_num;

    std::vector<std::pair<int64_t, int64_t>> coords;
    coords.reserve(MAX_STROKES);

    std::cin >> stroke_width;
    while (stroke_width != 0) {
        std::cin >> stroke_num;

        for (int64_t i = 0; i < stroke_num; ++i) {
            int64_t x, y;
            std::cin >> x >> y;
            coords.emplace_back(x, y);
        }

        std::cout << painted_area(stroke_width, coords) << "\n";

        coords.clear();

        std::cin >> stroke_width;
    }

    return 0;
}
