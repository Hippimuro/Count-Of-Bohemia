/*
 * =====================================================================================
 *
 *       Filename:  game.cpp
 *
 *    Description:  I shouldn't be allowed to program games.
 *
 *        Version:  1.0
 *         Author:  Eero Leno
 *         Github:  Rimminen
 *        Created:  22.11.2014 15.52.18
 *       Revision:  none
 *       Compiler:  clang plus plus
 *
 * =====================================================================================
 */

#include "thirdincludes.h"
#include "texture.h"
#include "error.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;

const int SCREENWIDTH  = 640;
const int SCREENHEIGHT = 480;

/* Initializes everything in SDL
 * Upon failure returns false
 * and if everything went correctly returns true
 */
bool initSDL();
// void renderTexture(SDL_Texture*, SDL_Renderer*, int x, int y);
// SDL_Texture* loadTexture(const string, SDL_Renderer*);

/* declaring all SDL elements (window, surface, image) 
 * also pointing to NULL to check for errors and enhance performance
 */
SDL_Window* window = NULL;
SDL_Renderer* gameRenderer = NULL;
SDL_Event event;

int main(int argc, char* argv[]) {
        const string countPath = "res/count.bmp";
        vector<VTexture> textureBatch;

	if(!initSDL()) {
		return 1;
	} else {
		cout << "SDL and window initialized correctly!" << endl;
	}

        SDL_SetRenderDrawColor(gameRenderer, 255, 255, 255, 255);

        VTexture countTexture;
        countTexture.loadFromFile(countPath, gameRenderer);
        textureBatch.push_back(countTexture);
        const Uint8* keystate = SDL_GetKeyboardState(NULL);
	
	while(true) {
		if (SDL_PollEvent(&event)) {
                        if (event.type == SDL_QUIT) {
				break;
                        }
                        if(event.type == SDL_KEYDOWN) {
                                cout << "User pressed a key." << endl;
                                cout << "Keystate: " << SDL_GetKeyboardState(NULL) << endl;
                        }
                        if(event.type == SDL_MOUSEBUTTONDOWN) {
                                cout << "User clicked with the mouse." << endl;
                        }
		}
		SDL_RenderClear(gameRenderer);
                for(auto vtex : textureBatch) {
                        vtex.render(123, 400, gameRenderer);
                }
		SDL_RenderPresent(gameRenderer);
	}
        for(auto vtex : textureBatch) {
                vtex.free();
        }
	SDL_DestroyRenderer(gameRenderer);
	SDL_DestroyWindow(window);

	SDL_Delay(2200);
	SDL_Quit();

	return 0;
}

bool initSDL() {
	bool success = true; // everything is bound to be well unless proven otherwise!
                             // note: it is probable that one will be proven wrong if they assume that everything goes well.

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		logError("SDL couldn't init");
		success = false;
	} else {
		window = SDL_CreateWindow("Count of Bohemia", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREENWIDTH, SCREENHEIGHT, SDL_WINDOW_SHOWN);
		
		if(window == NULL) {
			logError("SDL couldn't init window");
			success = false;
		}
                gameRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

                if(gameRenderer == NULL) {
                        logError("THE GODDAMN RENDERER IS FAULTY FUCK THIS SHIT");
                        SDL_Quit();
			return 1;
			
		}
	}
	return success;
}

/*
SDL_Texture* loadTexture(const string filepath, SDL_Renderer *renderer) {
	SDL_Texture* texture = NULL; // if an error happens, we won't be rendering an old texture
	SDL_Surface* loadedImage = SDL_LoadBMP(filepath.c_str());
	if(loadedImage == NULL) {
		logError("Couldn't load image");
	} 
        texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
        SDL_FreeSurface(loadedImage);
        if(texture == NULL) {
                logError("Couldn't load texture");
	}
	return texture;
}
*/
/*
void renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y) {
	SDL_Rect position;
	position.x = x;
	position.y = y;

	SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h); // get the width and height of texture
	SDL_RenderCopy(renderer, texture, NULL, &position);
}
*/
