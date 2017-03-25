#include "CApp.h"

void CApp::OnRender() {
	SDL_RenderClear(renderer);
	flock.Render();
	SDL_RenderPresent(renderer);
}