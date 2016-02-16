#include "pacman_state.h"
#include "engine.h"

void PacmanState::update(vector<SDL_Event> input) {
	Engine& e = Engine::getInstance();

	for (auto in : input) {
		if (in.type == SDL_KEYDOWN) {
			switch (in.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				e.quit();
				break;
			}
		}
	}
}

void PacmanState::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
}

void PacmanState::enter() {

}

void PacmanState::exit() {

}