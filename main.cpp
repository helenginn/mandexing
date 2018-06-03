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

#include <iostream>
#include <QtCore/qglobal.h>
#include <QtWidgets/qapplication.h>
#include "Tinker.h"

int main(int argc, char * argv[])
{
    // insert code here...

    std::cout << "Qt version: " << qVersion() << std::endl;
    
    QApplication app(argc, argv);
    
    Tinker window;
    window.show();
    
    return app.exec();
}
