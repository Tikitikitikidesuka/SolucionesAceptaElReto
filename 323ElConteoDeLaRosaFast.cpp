#include <iostream>

typedef int_fast32_t c_int;

c_int TEN_POWERS[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
c_int CENTER_SECTION_ACC[] = {0, 9, 189, 2889, 38889, 488889, 5888889};

c_int numDigits(c_int num) {
    if (num <= 0)
        return 1;

    c_int i = 0;
    while (num >= TEN_POWERS[i]) ++i;
    return i;
}

void upperBoundary(c_int num, c_int& boundary, c_int& digits) {
	digits = numDigits(num);
	boundary = TEN_POWERS[digits];
	if (num != 1 && boundary / 10 == num) boundary = num;
	if (boundary > num) ++digits;
}

void lowerBoundary(c_int num, c_int& boundary, c_int& digits) {
	digits = numDigits(num);
	boundary = TEN_POWERS[digits - 1];
    if (boundary < 10) boundary = 0;
}

c_int digitsToUpperBoundary(c_int num, c_int& upper_boundary, c_int& digits_upper_boundary) {
    upperBoundary(num, upper_boundary, digits_upper_boundary);
    c_int digits = upper_boundary > num ? digits_upper_boundary - 1 : digits_upper_boundary;
    c_int extra_begining = upper_boundary - num;
    return extra_begining * digits;
}

c_int digitsToLowerBoundary(c_int num, c_int& lower_boundary, c_int& digits_lower_boundary) {
    lowerBoundary(num, lower_boundary, digits_lower_boundary);
    c_int digits_b = digits_lower_boundary;
    c_int extra_end = num - lower_boundary + 1;
    return extra_end * digits_b;
}

c_int digitsBetween(c_int a, c_int b) {
    c_int digit_sum = 0;

    c_int upper_boundary, lower_boundary;
    c_int digits_upper_boundary, digits_lower_boundary;
    c_int digits_to_upper_boundary = digitsToUpperBoundary(a, upper_boundary, digits_upper_boundary);
    c_int digits_to_lower_boundary = digitsToLowerBoundary(b, lower_boundary, digits_lower_boundary);


    if (upper_boundary > lower_boundary) { // Rango sencillo
        digit_sum = numDigits(a) * (b - a + 1);
    } else if (upper_boundary == lower_boundary) { // Sin seccion c_int
        digit_sum = digits_to_upper_boundary + digits_to_lower_boundary;
    } else { // Con seccion c_int
        digit_sum = digits_to_upper_boundary + digits_to_lower_boundary
                + CENTER_SECTION_ACC[digits_lower_boundary-1] - CENTER_SECTION_ACC[digits_upper_boundary-1];
    }

	return digit_sum;
}

c_int equalDigitsPage(c_int first, c_int last) {
    c_int i = first, j = last;
    c_int pivot = (i + j) / 2;
    c_int left_digits, right_digits;

    left_digits = digitsBetween(first, pivot);
    right_digits = digitsBetween(pivot + 1, last);

    while (left_digits != right_digits && i < j) {
        if (left_digits < right_digits) {
            i = pivot + 1;
        } else {
            j = pivot;
        }

        pivot = (i + j) / 2;
        left_digits = digitsBetween(first, pivot);
        right_digits = digitsBetween(pivot + 1, last);
    }

    if (left_digits > right_digits)
        --pivot;

    return pivot;
}

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
    putchar_unlocked('\n');
}

int main() {
    c_int first, last;
    fastIntInput(first);
    fastIntInput(last);

    while (first != 0 || last != 0) {
        fastIntOutput(equalDigitsPage(first, last));

        fastIntInput(first);
        fastIntInput(last);
    }

	return 0;
}
