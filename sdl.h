#pragma once

#include <string>

const int ROWS = 8;
const int COLS = 8;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;
const int TILE_SIZE = SCREEN_WIDTH / COLS;

int makeSDLPreparations();
SDL_Texture* getTexture(std::string imagePath);
SDL_Renderer* getRenderer();
SDL_Window* getWindow();
void close();
void showWinningMessage();
void renderChessBoard();
