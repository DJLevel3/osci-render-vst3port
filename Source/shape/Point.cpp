#include "Point.h"

Point::Point() : x(0), y(0), z(0) {}

Point::Point(double val) : x(val), y(val), z(0) {}

Point::Point(double x, double y) : x(x), y(y), z(0) {}

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

Point Point::nextVector(double drawingProgress){
	return Point(x, y, z);
}

void Point::rotate(double theta) {
    double cosTheta = std::cos(theta);
    double sinTheta = std::sin(theta);
    
    double newX = x * cosTheta - y * sinTheta;
    double newY = x * sinTheta + y * cosTheta;

	x = newX;
	y = newY;
}

void Point::scale(double x, double y) {
	this->x *= x;
	this->y *= y;
}

void Point::translate(double x, double y) {
	this->x += x;
	this->y += y;
}

void Point::reflectRelativeToVector(double x, double y) {
	this->x += 2.0 * (x - this->x);
	this->y += 2.0 * (y - this->y);
}

double Point::length() {
	return 0.0;
}

double Point::magnitude() {
	return sqrt(x * x + y * y + z * z);
}

std::unique_ptr<Shape> Point::clone() {
	return std::make_unique<Point>(x, y, z);
}

std::string Point::type() {
	return std::string();
}

Point& Point::operator=(const Point& other) {
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}
