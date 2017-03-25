#include "Flock.h"
#include <iostream>
const double TWO_PI = 6.28318530718;

Flock::Flock(){
	renderer = NULL;
}

Flock::Flock(SDL_Renderer* renderer) : renderer(renderer) 
{
	distribution = std::uniform_real_distribution<double> (0.0, TWO_PI);
}

void Flock::Run() {
	for (std::vector<Boid>::iterator b = boids.begin(); b != boids.end(); b++) {
		(*b).Run(boids);
	}
}

void Flock::AddBoid(double x, double y) {
	boids.push_back(Boid(x, y, distribution(generator), renderer));
}

void Flock::Render() {
	for (std::vector<Boid>::iterator b = boids.begin(); b != boids.end(); b++) {
		(*b).Render();
	}
}