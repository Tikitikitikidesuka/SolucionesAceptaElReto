#include <iostream>
#include <vector>
#include <deque>

typedef uint_fast32_t c_int;

std::vector<c_int> maxSlidingWindow(const std::vector<c_int>& buffer, c_int windowSize) {
	std::deque<c_int> dq;
	c_int left = 0, right = 0;

	std::vector<c_int> output;
	output.reserve(buffer.size());

	while (right < buffer.size()) {
		while (!dq.empty() && buffer[dq.back()] < buffer[right])
			dq.pop_back();

		dq.push_back(right);

		if (left > dq.front())
			dq.pop_front();

		if (right + 1 >= windowSize) {
			output.push_back(buffer[dq.front()]);
			++left;
		}

		++right;
	}

	return output;
}

int main() {
	c_int total, take;
	std::cin >> total >> take;

	while(total > 0) {
		std::vector<c_int> buffer;
		buffer.reserve(total);

		for(c_int i = 0; i < total; ++i) {
			c_int input;
			std::cin >> input;
			buffer.push_back(input);
		}

		std::vector<c_int> output = maxSlidingWindow(buffer, take);

		for(c_int i = 0; i < total - take; ++i)
			std::cout << output[i] << " ";
		std::cout << output[total - take] << "\n";

		std::cin >> total >> take;
	}

	return 0;
}
