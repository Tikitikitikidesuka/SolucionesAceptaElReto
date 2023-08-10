#include <iostream>
#include <vector>

const int MAX_SAMPLES = 200000;

const int MIN_BAG_SIZE = 0;
const int MAX_BAG_SIZE = 10000000;

struct Sample {
    enum Type { R, E, None };

    int size;
    Type type;
};

std::istream& operator>> (std::istream& istream, Sample::Type& sample_type) {
    std::string input;
    std::cin >> input;

    if (input == "E") {
        sample_type = Sample::Type::E;
    } else if (input == "R") {
        sample_type = Sample::Type::R;
    } else {
        sample_type = Sample::Type::None;
    }

    return istream;
}

bool valid_bag_size(int bag_size, int max_trips, const std::vector<Sample>& samples) {
    int trips_left = max_trips;

    int r_bag_space = bag_size;
    int e_bag_space = bag_size * 2;

    const int r_bag_size = bag_size;
    const int e_bag_size = bag_size * 2;

    for (const Sample& sample : samples) {
        switch (sample.type) {
            case Sample::R:
                if (sample.size > r_bag_size) return false;
                else if (sample.size > r_bag_space) {
                    if (trips_left <= 0) {
                        return false;
                    } else {
                        trips_left--;
                        r_bag_space = r_bag_size - sample.size;
                        e_bag_space = e_bag_size;
                    }
                } else {
                    r_bag_space -= sample.size;
                }

                break;
            case Sample::E:
                if (sample.size > e_bag_size) return false;
                else if (sample.size > e_bag_space) {
                    if (trips_left <= 0) {
                        return false;
                    } else {
                        trips_left--;
                        e_bag_space = e_bag_size - sample.size;
                        r_bag_space = r_bag_size;
                    }
                } else {
                    e_bag_space -= sample.size;
                }

                break;
            case Sample::None:
                // Only for debug
                std::cout << "Sample Type IO Error";
                break;
        }
    }

    if (r_bag_space < r_bag_size || e_bag_space < e_bag_size) return trips_left > 0;

    return true;
}

int min_bag_size(int max_trips, const std::vector<Sample>& samples) {
    int min = MIN_BAG_SIZE;
    int max = MAX_BAG_SIZE;

    while (min < max) {
        int pivot = (min + max) / 2;

        if (valid_bag_size(pivot, max_trips, samples)) {
            max = pivot;
        } else {
            min = pivot + 1;
        }
    }

    return min;
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    std::vector<Sample> samples;
    samples.reserve(MAX_SAMPLES);

    int trips = 0, sample_num = 0;

    std::cin >> trips >> sample_num;
    while (trips != 0 || sample_num != 0) {
        for (int i = 0; i < sample_num; ++i) {
            Sample sample;
            std::cin >> sample.size >> sample.type;
            samples.push_back(sample);
        }

        std::cout << min_bag_size(trips, samples) << "\n";

        samples.clear();

        std::cin >> trips >> sample_num;
    }

    return 0;
}