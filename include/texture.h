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
 *       Compiler:  clang plus plus
 *
 * =====================================================================================
 */
#pragma once

#include <SDL2/SDL.h>
#include <string>

using std::cout;
using std::endl;
using std::string;

class VTexture {
        public:
                Vtexture();
                ~VTexture();

                bool LoadFromFile(string path);
                void free();
                void setColor(Uint8 r, Uint8 g, Uint8 b);
                void setBlendMode(SDL_BlendMode blend);
                void setAlpha(Uint8 alpha); // BlendMode needs to be set
                void render(int x, int y, SDL_Rect* clip = NULL);
                
                int getWidth();
                int getHeight();
        private:
                SDL_Texture* hardwareTex;
                int width;
                int height;
};