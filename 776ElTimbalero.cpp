#include <cstdio>
#include <iostream>
#include <vector>

int main() {
    int num_intervals;
    std::cin >> num_intervals;
    
    while (num_intervals != 0) {
        std::vector<int> intervals;
        intervals.reserve(num_intervals);
        std::vector<int> plate_hits;

        for (int i = 0; i < num_intervals; ++i) {
            int start, end;
            std::cin >> start >> end;
            intervals.push_back(start);
            intervals.push_back(end);
        }
        
        int in;
        std::cin >> in;
        while (in != 0) {
            plate_hits.push_back(in);
            std::cin >> in;
        }
        
        int acc = 0;
        int interval = 0, hit = 0;
        while (hit < plate_hits.size() && interval < num_intervals) {
            int start = intervals[interval * 2];
            int end = intervals[interval * 2 + 1];            
            
            if (plate_hits[hit] >= start && plate_hits[hit] <= end) {
                acc += 1;
                hit += 1;
            } else if (plate_hits[hit] > end) {
                interval += 1;
            } else if (plate_hits[hit] < start) {
                hit += 1;
            }
        }
        
        std::cout << plate_hits.size() - acc << "\n";

        std::cin >> num_intervals;
    }
    
    return 0;
}