// Mandexing: a manual indexing program for crystallographic data.
// Copyright (C) 2017-2018 Helen Ginn
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
// 
// Please email: vagabond @ hginn.co.uk for more details.

#ifndef __cppxfel__TextManager__
#define __cppxfel__TextManager__

#include <stdio.h>
#include <png.h>
#include "shared_ptrs.h"
#include <string>

class TextManager
{
private:
    static TextManagerPtr textManager;
    
    TextManager();
    
public:
    static void text_malloc(png_byte **pointer, std::string text, int *width, int *height);
    static void text_free(png_byte **pointer);
};

#endif /* defined(__cppxfel__TextManager__) */
