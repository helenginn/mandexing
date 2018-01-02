//
//  main.cpp
//  Windexing
//
//  Created by Helen Ginn on 11/12/2016.
//  Copyright (c) 2017 Helen Ginn. All rights reserved.
//

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
