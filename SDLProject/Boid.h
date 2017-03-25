#ifndef BOID_H_
#define BOID_H_

#include <SDL.h>
#include "Vector2D.h"
#include "TextureLoader.h"
#include <vector>

class Boid {
private:
	SDL_Renderer* renderer;
	TextureLoader loader;
	Vector2D position;
	Vector2D velocity;
	Vector2D acceleration;
	double angle;
	double radius;
	double maxForce;
	double maxSpeed;
	
public:
	Boid(double x, double y, double angle, SDL_Renderer* renderer);
	void Run(std::vector<Boid>& boids);
	void ApplyForce(Vector2D force);
	void FlockTogether(std::vector<Boid>& boids);
	void Update();
	Vector2D Seek(Vector2D& target);
	void Render();
	void Borders();
};

#endif