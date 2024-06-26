#include <iostream>

int power(int num, int exp) {
	int res = 1;

	for (int i = 0; i < exp; ++i)
		res *= num;

	return res;
}

int numDigits(int num, int base) {
    if (num == 0)
        return 1;

	int sol = 0;

	while (num > 0) {
		num /= base;
		++sol;
	}

	return sol;
}

void upperBoundary(int num, int base, int& boundary, int& digits) {
	digits = numDigits(num, base);
	boundary = power(base, digits);
	if (num != 1 && boundary / 10 == num) boundary = num;
	if (boundary > num) ++digits;
}

void lowerBoundary(int num, int base, int& boundary, int& digits) {
	digits = numDigits(num, base);
	boundary = power(base, digits - 1);
    if (boundary < base) boundary = 0;
}

int digitsToUpperBoundary(int num, int base, int& upper_boundary, int& digits_upper_boundary) {
    upperBoundary(num, base, upper_boundary, digits_upper_boundary);
    int digits = upper_boundary > num ? digits_upper_boundary - 1 : digits_upper_boundary;
    int extra_begining = upper_boundary - num;
    return extra_begining * digits;
}

int digitsToLowerBoundary(int num, int base, int& lower_boundary, int& digits_lower_boundary) {
    lowerBoundary(num, base, lower_boundary, digits_lower_boundary);
    int digits_b = digits_lower_boundary;
    int extra_end = num - lower_boundary + 1;
    return extra_end * digits_b;
}

int digitsBetween(int a, int b, int base) {
    int digit_sum = 0;

    int upper_boundary, lower_boundary;
    int digits_upper_boundary, digits_lower_boundary;
    int digits_to_upper_boundary = digitsToUpperBoundary(a, base, upper_boundary, digits_upper_boundary);
    int digits_to_lower_boundary = digitsToLowerBoundary(b, base, lower_boundary, digits_lower_boundary);


    if (upper_boundary > lower_boundary) { // Rango sencillo
        digit_sum = numDigits(a, base) * (b - a + 1);
    } else if (upper_boundary == lower_boundary) { // Sin seccion intermedia
        digit_sum = digits_to_upper_boundary + digits_to_lower_boundary;
    } else { // Con seccion intermedia
        digit_sum = digits_to_upper_boundary + digits_to_lower_boundary;
        int base_acc = power(base, digits_upper_boundary);
        for (int i = digits_upper_boundary; i < digits_lower_boundary; ++i) {
            int local_lb, local_lb_digits;
            lowerBoundary(base_acc - 1, base, local_lb, local_lb_digits);
            digit_sum += i * (base_acc - local_lb);
            base_acc *= base;
        }
    }

	return digit_sum;
}

int classicDigitsBetween(int a, int b, int base) {
    int digits = 0;
    for (int i = a; i <= b; ++i) {
        digits += numDigits(i, base);
    }
    return digits;
}

int equalDigitsPage(int first, int last) {
    int i = first, j = last;
    int pivot = (i + j) / 2;
    int left_digits, right_digits;

    left_digits = digitsBetween(first, pivot, 10);
    right_digits = digitsBetween(pivot + 1, last, 10);

    while (left_digits != right_digits && i < j) {
        if (left_digits < right_digits) {
            i = pivot + 1;
        } else {
            j = pivot;
        }

        pivot = (i + j) / 2;
        left_digits = digitsBetween(first, pivot, 10);
        right_digits = digitsBetween(pivot + 1, last, 10);
    }

    if (left_digits > right_digits)
        --pivot;

    return pivot;
}

int main() {
    int first, last;
    std::cin >> first >> last;

    while (first != 0 || last != 0) {
        std::cout << equalDigitsPage(first, last) << "\n";
        std::cin >> first >> last;
    }

	return 0;
}
