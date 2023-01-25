#include <iostream>
#include <vector>
#include <deque>

typedef uint_fast32_t c_int;

#define MAX_DATA 500000

c_int data[MAX_DATA];
c_int output[MAX_DATA];

inline void fastIntInput(c_int& number) {
	register std::int_fast8_t input;

	number = 0;
	input = getchar_unlocked();

	// Clear noise on buffer
	for (; (input < '0' || input > '9'); input = getchar_unlocked());

	// Get number
	for (; (input >= '0' && input <= '9'); input = getchar_unlocked())
		number = number * 10 + input - 48;
}

inline void fastIntOutput(c_int x){
	std::int_fast8_t buffer[35];
	register std::int_fast8_t i=0;
	do{
		buffer[i++] = (x % 10) + '0';
		x /= 10;
	} while(x);
	i--;
	while(i >= 0) putchar_unlocked(buffer[i--]);
}

void maxSlidingWindow(const c_int* data, c_int size, c_int windowSize, c_int* output) {
	std::deque<c_int> dq;
	c_int left = 0, right = 0, it = 0;

	while (right < size) {
		while (!dq.empty() && data[dq.back()] < data[right])
			dq.pop_back();

		dq.push_back(right);

		if (left > dq.front())
			dq.pop_front();

		if (right + 1 >= windowSize) {
			output[it++] = data[dq.front()];
			++left;
		}

		++right;
	}
}

int main() {
	c_int total, take;
	fastIntInput(total);
	fastIntInput(take);

	while(total > 0) {
		for(c_int i = 0; i < total; ++i)
			fastIntInput(data[i]);

		maxSlidingWindow(data, total, take, output);

		for(c_int i = 0; i < total - take; ++i) {
			fastIntOutput(output[i]);
			putchar_unlocked(' ');
		}
		fastIntOutput(output[total-take]);
		putchar_unlocked('\n');
		

		fastIntInput(total);
		fastIntInput(take);
	}

	return 0;
}
