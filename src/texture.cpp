/*
 * =====================================================================================
 *
 *       Filename:  texture.cpp
 *
 *    Description:  I shouldn't be allowed to program games.
 *
 *        Version:  1.0
 *         Author:  Eero Leno
 *         Github:  Rimminen
 *        Created:  22.11.2014 15.52.18
 *       Revision:  none
 *       Compiler:  clang plus plus or gee plus plus
 *
 * =====================================================================================
 */

#include "thirdincludes.h"
#include "texture.h"
#include "error.h"

using std::cout;
using std::endl;
using std::string;

VTexture::VTexture() {
        cout << "creating VTexture" << endl;
}

VTexture::~VTexture() {
        cout << "destroying VTexture" << endl;
}

/* //disabled until I find a way to include deps
void VTexture::setBlendMode(SDL_BlendMode blend) {
        SDL_SetTextureBlendMode(hardwareTex, blend);
}


void VTexture::setAlpha(Uint8 alpha) {
        SDL_SetTextureAplhaMod(hardwareTex, alpha);
}
*/


bool VTexture::loadFromFile(const string path, SDL_Renderer *renderer) {
        bool success = true;
	SDL_Texture* texture = NULL; // if an error happens, we won't be rendering an old texture
	SDL_Surface* loadedImage = SDL_LoadBMP(path.c_str());
	if(loadedImage == NULL) {
                success = false;
		logError("Couldn't load image");
	} 
        texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
        SDL_FreeSurface(loadedImage);
        if(texture == NULL) {
                success = false;
                logError("Couldn't load texture");
	}
	hardwareTex = texture;
        return success;
}

void VTexture::free() {
        SDL_DestroyTexture(hardwareTex);
}

void VTexture::render(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip)  {
        clip->x = x;
        clip->y = y;

        SDL_QueryTexture(hardwareTex, NULL, NULL, &clip->w, &clip->h);
        SDL_RenderCopy(renderer, hardwareTex, NULL, clip);
}
