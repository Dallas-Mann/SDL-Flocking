#include "CApp.h"

void CApp::OnCleanup() {
	//free renderer
	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	//free screen
	SDL_DestroyWindow(window);
	window = NULL;

	//quit SDL subsystems
	SDL_Quit();
}