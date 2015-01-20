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

using std::string;
using std::cout;
using std::endl;

void logError(string message) {
	cout << "Error: " << message << endl << SDL_GetError() << endl;
}

