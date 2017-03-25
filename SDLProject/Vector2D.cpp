#include "Vector2D.h"

Vector2D::Vector2D() : x(0), y(0) {

}

Vector2D::Vector2D(double x_, double y_) : x(x_), y(y_) {
	
}

void Vector2D::Set(double x_, double y_) {
	x = x_;
	y = y_;
}

void Vector2D::Set(Vector2D& v) {
	this->x = v.x;
	this->y = v.y;
}

Vector2D Vector2D::Get() const {
	return Vector2D(this->x, this->y);
}

double Vector2D::GetMagnitude() {
	return sqrt(x*x + y*y);
}

void Vector2D::Add(Vector2D& v) {
	x += v.x;
	y += v.y;
}

void Vector2D::Add(double x_, double y_) {
	x += x_;
	y += y_;
}

Vector2D Vector2D::Add(Vector2D& v1, Vector2D& v2) {
	return Vector2D(v1.x + v2.x, v1.y + v2.y);
}

void Vector2D::Sub(Vector2D& v) {
	x -= v.x;
	y -= v.y;
}

void Vector2D::Sub(double x_, double y_) {
	x -= x_;
	y -= y_;
}

Vector2D Vector2D::Sub(Vector2D& v1, Vector2D& v2) {
	return Vector2D(v1.x - v2.x, v1.y - v2.y);
}

void Vector2D::Mult(double scalar) {
	x *= scalar;
	y *= scalar;
}

Vector2D Vector2D::Mult(Vector2D& v, double scalar) {
	return Vector2D(scalar * v.x, scalar * v.y);
}

void Vector2D::Mult(Vector2D& v) {
	x *= v.x;
	y *= v.y;
}

Vector2D Vector2D::Mult(Vector2D& v1, Vector2D& v2) {
	return Vector2D(v1.x * v2.x, v1.y * v2.y);
}

void Vector2D::Div(double scalar) {
	x /= scalar;
	y /= scalar;
}

Vector2D Vector2D::Div(Vector2D& v, double scalar) {
	return Vector2D(v.x / scalar, v.y / scalar);
}

void Vector2D::Div(Vector2D& v) {
	x /= v.x;
	y /= v.y;
}

Vector2D Vector2D::Div(Vector2D& v1, Vector2D& v2) {
	return Vector2D(v1.x / v2.x, v1.y / v2.y);
}

double Vector2D::Distance(Vector2D& v) {
	double dx = x - v.x;
	double dy = y - v.y;
	return sqrt((dx * dx) + (dy * dy));
}

double Vector2D::Distance(Vector2D& v1, Vector2D& v2) {
	double dx = v1.x - v2.x;
	double dy = v1.y - v2.y;
	return sqrt((dx * dx) + (dy * dy));
}

double Vector2D::Dot(Vector2D& v) {
	return (x * v.x) + (y * v.y);
}

double Vector2D::Dot(double x_, double y_) {
	return (x * x_) + (y * y_);
}

double Vector2D::Dot(Vector2D& v1, Vector2D& v2) {
	return (v1.x * v2.x) + (v1.y * v2.y);
}

void Vector2D::Normalize() {
	double mag = GetMagnitude();
	if (mag != 0 && mag != 1) {
		Div(mag);
	}
}

void Vector2D::Limit(double max) {
	if (GetMagnitude() > max) {
		Normalize();
		Mult(max);
	}
}

double Vector2D::Heading() {
	return atan2(-y, x);
}