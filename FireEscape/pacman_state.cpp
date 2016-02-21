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
	Engine& e = Engine::getInstance();
	vector<TwoDArray<Tile>*>& mapData = e.getMap();

	for (auto data : mapData) {
		// Draw the background tiles
		for (int j = 0; j < data->y; j++) {
			for (int i = 0; i < data->x; i++) {
				Tile currentTile = (*data)[i][j];
				int temp = currentTile.gid;
				SDL_Texture* texture = e.getTexture(currentTile.gid - 1);

				if (texture != nullptr) {
					SDL_Rect texture_rect;
					texture_rect.x = i * e.TILE_WIDTH - e.scrollOffset.x;  //the x coordinate
					texture_rect.y = j * e.TILE_HEIGHT - e.scrollOffset.y; // the y coordinate
					texture_rect.w = e.TILE_WIDTH; //the width of the texture
					texture_rect.h = e.TILE_HEIGHT; //the height of the texture			

													//Render texture to screen
					SDL_RenderCopy(renderer, texture, NULL, &texture_rect);
				}

			}
		}
	}
}

void PacmanState::enter() {
	Engine& e = Engine::getInstance();

	e.currentLevel = 5;
	e.loadLevel(e.levels[e.currentLevel]);
}

void PacmanState::exit() {

}