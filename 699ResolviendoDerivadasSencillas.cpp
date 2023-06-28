#include <iostream>
#include <sstream>
#include <vector>

int to_digit(char c) {
	return c - '0';
}

std::string derive(const std::string& expr) {
	enum State {Start, ExplicitCoefficient, X, ExplicitExponent, Done};
	State state = State::Start;

	bool hasX = false;
	int coeff = 1, exp = 1;

	for (char c : expr) {
		switch (state) {
			case State::Start:
				if (isdigit(c)) {
					coeff = to_digit(c);
					state = ExplicitCoefficient;
				} else if (c == 'x') {
					coeff = 1;
					hasX = true;
					state = State::X;
				}

				break;
			case State::ExplicitCoefficient:
				if (isdigit(c)) {
					coeff = coeff * 10 + to_digit(c);
				} else if (c == 'x') {
					hasX = true;
					state = State::X;
				} else {
					exp = 0;
					state = State::Done;
				}

				break;
			case State::X:
				if (c == '^') {
					exp = 0;
					state = State::ExplicitExponent;
				} else {
					exp = 1;
					state = State::Done;
				}

				break;
			case State::ExplicitExponent:
				if (isdigit(c)) {
					exp = exp * 10 + to_digit(c);
				} else {
					state = State::Done;
				}

				break;
		}
	}

	if (!hasX) exp = 0;

	// Derive
	if (exp > 0) {
		coeff *= exp;
		exp -= 1;
	} else {
		coeff = 0;
	}

	// Output
	std::stringstream ss;

	if (coeff > 0) {
		ss << coeff;
	}

	if (exp > 0) {
		ss << "x";
		if (exp > 1) {
			ss << "^" << exp;
		}
	}

	return ss.str();
}

int main() {
	std::string input;

	while(std::cin >> input) {
		// --- Begin Tokenizer ---
		std::stringstream ss(input);
		std::string token;
		std::vector<std::string> tokens;

		while (std::getline(ss, token, '+'))
			tokens.push_back(token);
		// --- End Tokenizer ---
		
		// --- Begin Deriving ---
		std::vector<std::string> derivedTokens;

		for (std::string token : tokens)
			derivedTokens.push_back(derive(token));
		// --- End Deriving ---
		
		// --- Begin Printing ---
		bool printed = false;

		if (derivedTokens[0].length() > 0) {
			std::cout << derivedTokens[0];
			printed = true;
		}

		for (int i = 1; i < derivedTokens.size(); ++i) {
			if (derivedTokens[i].length() > 0) {
				std::cout << "+" << derivedTokens[i];
				printed = true;
			}
		}

		if (!printed) std::cout << "0";

		std::cout << "\n";
		// --- End Printing ---
	}

	return 0;
}
