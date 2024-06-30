#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <map>
#include <vector>
#include "Board.h"
#include "Pawn.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;
const int ROWS = 8;
const int COLS = 8;
const int TILE_SIZE = SCREEN_WIDTH / COLS;

std::map<std::string, SDL_Texture*> pieceTextures;

bool loadMedia(SDL_Renderer* renderer) {
    // Load images for all piece types
    std::vector<std::string> pieceFiles = {
        "images/white-pawn.png",
        "images/black-pawn.png",
        "images/white-bishop.png",
        "images/black-bishop.png",
        "images/white-rook.png",
        "images/black-rook.png",
        "images/white-king.png",
        "images/black-king.png",
        "images/white-knight.png",
        "images/black-knight.png",
        "images/white-queen.png",
        "images/black-queen.png"
    };
    for (const auto& file : pieceFiles) {
        SDL_Surface* loadedSurface = IMG_Load(file.c_str());
        if (!loadedSurface) {
            std::cerr << "Unable to load image " << file << "! SDL_image Error: " << IMG_GetError() << std::endl;
            return false;
        }
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (!texture) {
            std::cerr << "Unable to create texture from " << file << "! SDL Error: " << SDL_GetError() << std::endl;
            SDL_FreeSurface(loadedSurface);
            return false;
        }
        pieceTextures[file] = texture;
        SDL_FreeSurface(loadedSurface);
    }
    return true;
}

void close() {
    for (auto& pair : pieceTextures) {
        SDL_DestroyTexture(pair.second);
    }
    pieceTextures.clear();
    IMG_Quit();
    SDL_Quit();
}

void renderChessBoard(SDL_Renderer* renderer, std::shared_ptr<Board> board) {
    bool white = true;
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (white) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White
            }
            else {
                SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255); // Gray
            }
            SDL_Rect tile = { col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE, TILE_SIZE };
            SDL_RenderFillRect(renderer, &tile);
            white = !white;

            // Render the piece on the board
            std::shared_ptr<Piece> piece = board->getPiece(row, col);
            if (piece) {
                std::string imagePath;
                if (piece->isEmpty()) continue;
                
                imagePath = piece->getImagePath();
                SDL_Texture* texture = pieceTextures[imagePath];
                if (texture) {
                    SDL_Rect pieceRect = { col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE, TILE_SIZE };
                    SDL_RenderCopy(renderer, texture, nullptr, &pieceRect);
                }
            }
        }
        white = !white;
    }
}

int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (!IMG_Init(IMG_INIT_PNG)) {
        std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("ChessGame",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Load media
    if (!loadMedia(renderer)) {
        std::cerr << "Failed to load media!" << std::endl;
        close();
        return 1;
    }

    // Initialize your game logic
    std::shared_ptr<Board> board = getBoard();
    int turn_counter = 1;

    bool quit = false;
    SDL_Event e;
    int print = 0;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {

            if (!print) {
                std::cout << (turn_counter % 2 != 0 ? "Player1 (White) " : "Player2 (Black) ") << "turn" << std::endl;
                print = 1;
            }

            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                int row = y / TILE_SIZE;
                int col = x / TILE_SIZE;

                // Handle mouse click event to select/move pieces
                std::string input;
                int src_row, src_col, dest_row, dest_col;

                // Simulate reading input from mouse clicks
                static int click_counter = 0;
                static int first_row, first_col;

                if (click_counter == 0) {
                    first_row = row;
                    first_col = col;
                    click_counter++;
                }
                else {
                    src_row = first_row;
                    src_col = first_col;
                    dest_row = row;
                    dest_col = col;
                    click_counter = 0;
                    print = 0;

                    // Make the move
                    bool res = board->move(src_row, src_col, dest_row, dest_col);

                    // Check if the move was valid and proceed to the next round
                    if (res == true) {
                        std::cout << "Move from (" << src_row << ", " << src_col << ") to (" << dest_row << ", " << dest_col << ")" << std::endl;
                    } else {
                        std::cout << "Invalid Move. Try again" << std::endl;
                        continue;
                    }

                    if (board->isCheckmate(turn_counter)) {
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                        SDL_RenderClear(renderer);
                        renderChessBoard(renderer, board);
                        SDL_RenderPresent(renderer);

                        std::string winner = (turn_counter % 2 != 0) ? "Player1 (White)" : "Player2 (Black)";
                        std::string message = "Checkmate! " + winner + " has won the game!";
                        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Game Over", message.c_str(), window);
                        quit = true;
                        break;
                    }

                    turn_counter++;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        renderChessBoard(renderer, board);
        SDL_RenderPresent(renderer);
    }

    close();
    return 0;
}
