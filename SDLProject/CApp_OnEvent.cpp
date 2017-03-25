#include "CApp.h"

void CApp::OnEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		Running = false;
	}

	if (Event->type == SDL_MOUSEBUTTONDOWN) {
		if (Event->button.button == SDL_BUTTON_LEFT) {
			int x, y;
			SDL_GetMouseState(&x, &y);
			//spawn a boid
			try {
				flock.AddBoid(x, y);
			}
			catch (std::exception& e) {
				Running = false;
			}
		}
		else if (Event->button.button == SDL_BUTTON_RIGHT) {
			//remove a boid
		}
	}
}