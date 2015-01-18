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
 *       Compiler:  clang plus plus
 *
 * =====================================================================================
 */

#include <SDL2/SDL.h>
#include "texture.h"

Vtexture::VTexture() {
}

void VTexture::setBlendMode(SDL_BlendMode blend) {
        SDL_SetTextureBlendMode(hardwareTex, blend);
}

void VTexture::setAlpha(Uint8 alpha) {
        SDL_SetTextureAplhaMod(hardwareTex, alpha);
}
