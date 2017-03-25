#ifndef VECTOR2D_H_
#define VECTOR2D_H_
#include <math.h>

class Vector2D {
public:
	double x;
	double y;

	//constructors
	Vector2D();
	Vector2D(double x_, double y_);

	//Vector2D Random2D();

	void Set(double x_, double y_);
	void Set(Vector2D& v);

	Vector2D Get() const;

	double GetMagnitude();

	void Add(Vector2D& v);
	void Add(double x_, double y_);
	static Vector2D Add(Vector2D& v1, Vector2D& v2);

	void Sub(Vector2D& v);
	void Sub(double x_, double y_);
	static Vector2D Sub(Vector2D& v1, Vector2D& v2);

	void Mult(double scalar);
	static Vector2D Mult(Vector2D& v, double scalar);
	
	void Mult(Vector2D& v);
	static Vector2D Mult(Vector2D& v1, Vector2D& v2);

	void Div(double scalar);
	static Vector2D Div(Vector2D& v, double scalar);

	void Div(Vector2D& v);
	static Vector2D Div(Vector2D& v1, Vector2D& v2);

	double Distance(Vector2D& v);
	static double Distance(Vector2D& v1, Vector2D& v2);

	double Dot(Vector2D& v);
	double Dot(double x_, double y_);
	static double Dot(Vector2D& v1, Vector2D& v2);

	void Normalize();

	void Limit(double max);

	double Heading();
};
#endif