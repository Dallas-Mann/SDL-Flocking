#include "Boid.h"
#include "ScreenDimensions.h"
#include <iostream>

Boid::Boid(double x, double y, double angle, SDL_Renderer* renderer) : angle(angle), radius(2.0), maxSpeed(2), maxForce(0.03), renderer(renderer), loader()
{
	if (loader.LoadFromFile("boid3.png", renderer)) {
		acceleration = Vector2D(0, 0);
		velocity = Vector2D(cos(angle), -sin(angle));
		position = Vector2D(x, y);
	}
	else {
		throw std::runtime_error(std::string("Error loading texture! SDL_Error: %s", SDL_GetError()));
	}
}

void Boid::Run(std::vector<Boid>& boids) {
	FlockTogether(boids);
	Update();
	Borders();
}

void Boid::ApplyForce(Vector2D force) {
	acceleration.Add(force);
}

void Boid::FlockTogether(std::vector<Boid>& boids) {
	Vector2D sep = Vector2D::Vector2D();
	Vector2D ali = Vector2D::Vector2D();
	Vector2D coh = Vector2D::Vector2D();

	//separation
	double desiredSeparation = 25;
	int count1 = 0;

	//align
	double neighborDist = 50;
	Vector2D sum = Vector2D::Vector2D();
	Vector2D sum2 = Vector2D::Vector2D();
	int count2 = 0;

	//cohesion
	int count3 = 0;

	for (std::vector<Boid>::iterator b = boids.begin(); b != boids.end(); b++) {
		double d = Vector2D::Distance(position, b->position);
		if (d > 0 && d < desiredSeparation) {
			Vector2D diff = Vector2D::Sub(position, b->position);
			diff.Normalize();
			diff.Div(d);
			sep.Add(diff);
			count1++;
		}

		if (d > 0 && d < neighborDist) {
			sum.Add(b->velocity);
			count2++;

			sum2.Add(b->position);
			count3++;
		}
	}

	//separation
	if (count1 > 0) {
		sep.Div(count1);
	}

	if (sep.GetMagnitude() > 0) {
		sep.Normalize();
		sep.Mult(maxSpeed);
		sep.Sub(velocity);
		sep.Limit(maxForce);
	}

	//alignment
	if (count2 > 0) {
		sum.Div(count2);
		sum.Normalize();
		sum.Mult(maxSpeed);
		ali = Vector2D::Sub(sum, velocity);
		ali.Limit(maxForce);
	}
	else {
		ali = Vector2D::Vector2D();
	}

	//cohesion
	if (count3 > 0) {
		sum2.Div(count3);
		coh = Seek(sum2);
	}
	else {
		coh = Vector2D::Vector2D();
	}

	sep.Mult(1.5);
	ali.Mult(1.0);
	coh.Mult(1.0);

	ApplyForce(sep);
	ApplyForce(ali);
	ApplyForce(coh);
}

void Boid::Update() {
	velocity.Add(acceleration);
	velocity.Limit(maxSpeed);
	position.Add(velocity);
	acceleration.Mult(0);
	//update angle based on new velocity vector
	angle = velocity.Heading();
}

Vector2D Boid::Seek(Vector2D& target) {
	Vector2D desired = Vector2D::Sub(target, position);
	desired.Normalize();
	desired.Mult(maxSpeed);
	Vector2D steer = Vector2D::Sub(desired, velocity);
	steer.Limit(maxForce);
	return steer;
}

void Boid::Render() {
	
	//this was the old way of rendering a primitive triangle, now i'm rendering a texture
	//Render a triangle primitive
	//rotation translation
	//x' = -y*sin(a) + x*cos(a)
	//y' = y*cos(a) + x*sin(a)
	/*
	Sint16 x1 = -(-2 * radius)*sin(angle) + (0)*cos(angle) + position.x;
	Sint16 y1 = (-2 * radius)*cos(angle) + (0)*sin(angle) + position.y;

	Sint16 x2 = -(2 * radius)*sin(angle) + (-radius)*cos(angle) + position.x;
	Sint16 y2 = (2 * radius)*cos(angle) + (-radius)*sin(angle) + position.y;

	Sint16 x3 = -(2 * radius)*sin(angle) + (radius)*cos(angle) + position.x;
	Sint16 y3 = (2 * radius)*cos(angle) + (radius)*sin(angle) + position.y;

	aatrigonRGBA(renderer, x1, y1, x2, y2, x3, y3, 0x00, 0x00, 0xFF, 0xFF);
	*/

	//render texture
	loader.Render((int)position.x, (int)position.y, angle, renderer);
}

void Boid::Borders() {
	if (position.x < -radius) {
		position.x = SCREEN_WIDTH + radius;
	}

	if (position.y < -radius) {
		position.y = SCREEN_HEIGHT + radius;
	}

	if (position.x > SCREEN_WIDTH + radius) {
		position.x = -radius;
	}

	if (position.y > SCREEN_HEIGHT + radius) {
		position.y = -radius;
	}
}

