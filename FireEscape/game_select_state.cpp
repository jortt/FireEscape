#include "game_select_state.h"
#include "engine.h"

void GameSelectState::update(vector<SDL_Event> input) {
	auto toggleGame = [&]() {
		if (selected_game_ == SelectedGame::FireEscape)
			selected_game_ = SelectedGame::PacMan;
		else
			selected_game_ = SelectedGame::FireEscape;
	};

	Engine& e = Engine::getInstance();

	for (auto in : input) {
		if (in.type == SDL_KEYDOWN) {
			switch (in.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				e.quit();
				break;
			case SDLK_UP:
			case SDLK_DOWN:
				toggleGame();
				break;
			case SDLK_RETURN:
				if (selected_game_ == SelectedGame::FireEscape)
					e.setState(Engine::StateId::MAIN_MENU);
				else
					e.setState(Engine::StateId::PACMAN);
				break;
			}
			/*
			if (in.key.keysym.sym == SDLK_ESCAPE) {
				e.quit();
			}
			else if (in.key.keysym.sym == SDLK_UP) {
				toggleGame();
			}
			else if (in.key.keysym.sym == SDLK_DOWN) {
				toggleGame();
			}
			*/
		}
	}
}

void GameSelectState::render(SDL_Renderer* renderer) {
	Uint32 format;
	int access, w, h;

	Engine& e = Engine::getInstance();

	//set window background
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); //black
	SDL_RenderClear(renderer);

	//get logo info
	SDL_Texture* fe_logo = e.getTexture(Engine::AssetId::LOGO);
	SDL_QueryTexture(fe_logo, &format, &access, &w, &h);

	//to ease my muddled brain
	int logo_width = w * kLogoScaleFactor;
	int logo_height = h * kLogoScaleFactor;

	//set logo background
	SDL_SetRenderDrawColor(renderer, 0x60, 0x60, 0x60, 0x60);
	SDL_Rect rect = {	(e.SCREEN_WIDTH / 2) - (logo_width / 2 + kBoarderSize * 2),
						(e.SCREEN_HEIGHT / 2) - (logo_height + kBoarderSize * 3),
						logo_width + kBoarderSize * 4,
						logo_height * 2 + kBoarderSize * 6 };
	SDL_RenderFillRect(renderer, &rect);

	//set highlighted logo background
	int logo_offset = 0;
	if (selected_game_ == SelectedGame::FireEscape)
		logo_offset = logo_height + kBoarderSize * 2;
	SDL_SetRenderDrawColor(renderer, 0x90, 0x90, 0x90, 0x90);
	rect = {			(e.SCREEN_WIDTH / 2) - (logo_width / 2 + kBoarderSize),
						(e.SCREEN_HEIGHT /2) - logo_offset,
						logo_width + kBoarderSize * 2,
						logo_height + kBoarderSize * 2 };
	SDL_RenderFillRect(renderer, &rect);

	//add fire escape logo
	rect = {			(e.SCREEN_WIDTH / 2) - logo_width / 2,
						(e.SCREEN_HEIGHT / 2) - (logo_height + kBoarderSize),
						logo_width,
						logo_height };
	SDL_RenderCopy(renderer, fe_logo, NULL, &rect);

	//add pacman logo
	SDL_Texture* pac_logo = e.getTexture(Engine::AssetId::LOGO); //this will be changed to the pacman logo
	
	rect = {			(e.SCREEN_WIDTH / 2) - logo_width / 2,
						(e.SCREEN_HEIGHT / 2) + kBoarderSize,
						logo_width,
						logo_height };
	SDL_RenderCopy(renderer, pac_logo, NULL, &rect);
	
}

void GameSelectState::enter() {

}

void GameSelectState::exit() {

}