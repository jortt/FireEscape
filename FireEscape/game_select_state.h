#pragma once

#include "game_state.h"

static const int kLogoScaleFactor = 4;
static const int kBoarderSize = 20;

class GameSelectState : public GameState {
	enum class SelectedGame {
		FireEscape,
		PacMan
	};

private:
	SelectedGame selected_game_ = SelectedGame::FireEscape;
public:
	virtual void update(vector<SDL_Event> input);
	virtual void render(SDL_Renderer* renderer);
	virtual void enter();
	virtual void exit();
};