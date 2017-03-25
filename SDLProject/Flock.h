#ifndef FLOCK_H_
#define FLOCK_H_
#include <vector>
#include <random>
#include <SDL.h>
#include "Boid.h"

class Flock {
private:
	SDL_Renderer* renderer;
	std::vector<Boid> boids;
	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution;

public:
	Flock();
	Flock(SDL_Renderer* renderer);
	void Run();
	void AddBoid(double x, double y);
	void Render();
};
#endif