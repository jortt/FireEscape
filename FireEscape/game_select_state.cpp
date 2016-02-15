#include "game_select_state.h"
#include "engine.h"

void GameSelectState::update(vector<SDL_Event> input) {
	Engine& e = Engine::getInstance();

	for (auto in : input) {
		if (in.type == SDL_KEYDOWN) {
			if (in.key.keysym.sym == SDLK_ESCAPE) {
				e.quit();
			}
		}
	}
}

void GameSelectState::render(SDL_Renderer* renderer) {
	Uint32 format;
	int access, w, h;

	Engine& e = Engine::getInstance();

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); //black
	SDL_RenderClear(renderer);

	SDL_Texture* fe_logo = e.getTexture(Engine::AssetId::LOGO);
	SDL_QueryTexture(fe_logo, &format, &access, &w, &h);
	SDL_Rect dest = { e.SCREEN_WIDTH / 2 - w * 2 , 100, w * 4, h * 4 };
	SDL_RenderCopy(renderer, fe_logo, NULL, &dest);

	SDL_Texture* pac_logo = e.getTexture(Engine::AssetId::LOGO); //this will be changed to the pacman logo
	SDL_QueryTexture(pac_logo, &format, &access, &w, &h);
	dest = { e.SCREEN_WIDTH / 2 - w * 2 , 120 + h * 2, w * 4, h * 4 };
	SDL_RenderCopy(renderer, pac_logo, NULL, &dest);
}

void GameSelectState::enter() {

}

void GameSelectState::exit() {

}