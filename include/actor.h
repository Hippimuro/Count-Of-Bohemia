/*
 * =====================================================================================
 *
 *       Filename:  actor.h
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

#include "thirdincludes.h"
#include "texture.h"

using std::cout;
using std::endl;
using std::string;

class VActor {
        public:
                VActor();
                ~VActor();
                
                void free();
                void draw();
                
                int getX();
                int getY();

                void setPos(int x, int y);

                void draw();

                void addVelocity(int x, int y);
                
        private:
                VTexture vTex;

                int posX;
                int posY;
                int velX;
                int velY;

};
