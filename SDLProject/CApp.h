#ifndef CAPP_H_
	#define CAPP_H_
#include <SDL.h>
#include "Flock.h"

class CApp {
private:
	bool running;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Flock flock;

public:
	CApp();
	int OnExecute();
	bool OnInit();
	void OnEvent(SDL_Event* Event);
	void OnLoop();
	void OnRender();
	void OnCleanup();
};
#endif