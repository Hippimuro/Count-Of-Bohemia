/*
 * =====================================================================================
 *
 *       Filename:  texture.h
 *
 *    Description:  I shouldn't be allowed to program games.
 *
 *        Version:  1.0
 *         Author:  Eero Leno
 *         Github:  Rimminen
 *        Created:  22.11.2014 15.52.18
 *       Revision:  none
 *       Compiler:  clang plus plus or gee plus plus, aiming to be compatibe with both
 *
 * =====================================================================================
 */
#pragma once

#include "thirdincludes.h"

using std::string;

class VTexture {
        public:
                VTexture();
                ~VTexture(); // this somehow is regarded as undefined symbols

                bool loadFromFile(const string path, SDL_Renderer* renderer);
                void free();
                void setColor(Uint8 r, Uint8 g, Uint8 b);
                //void setBlendMode(SDL_BlendMode blend); //disabled util find way to include deps
                //void setAlpha(Uint8 alpha); // BlendMode needs to be set to set alpha
                void render(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip = NULL);
                
                int getWidth();
                int getHeight();
        private:
                SDL_Texture* hardwareTex;
                int width;
                int height;
};
