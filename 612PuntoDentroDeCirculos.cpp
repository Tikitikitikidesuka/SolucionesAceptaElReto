#include <iostream>

class NVec2 {
	public:
		int64_t x;
		int64_t y;

		NVec2(int64_t x, int64_t y) 
		: x(x), y(y) {}

		void makeCoordsAbs() {
			if(this->x < 0) this->x *= -1;
			if(this->y < 0) this->y *= -1;
		}

		int64_t squaredMod() {
			return this->x * this->x + this->y * this->y;
		}

		friend NVec2 operator-(const NVec2 &v1, const NVec2 &v2) {
			return NVec2(v1.x - v2.x, v1.y - v2.y);
		}
};

int main() {
	int64_t radius, pointX, pointY;
	while(std::cin >> radius >> pointX >> pointY) {
		NVec2 point(pointX, pointY);

		int circles = 0;
		while(radius >= 1) {
			// Place point on first quadrant
			point.makeCoordsAbs();

			// Check if point is inside circle
			if(point.squaredMod() <= radius * radius)
				++circles;

			// Update relative point position to nearest smaller circle
			if(abs(point.x - radius) <= abs(point.y - radius)) { // Horz circle
				point.x -= radius;
			} else { // Vert circle
				point.y -= radius;
			}
			
			// Update radius
			radius /= 2;
		}

		std::cout << circles << "\n";
	}

	return 0;
}
