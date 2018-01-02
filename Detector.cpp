//
//  Detector.cpp
//  Windexing
//
//  Created by Helen Ginn on 11/12/2016.
//  Copyright (c) 2017 Helen Ginn. All rights reserved.
//

#include "Crystal.h"
#include "Detector.h"
#include <iostream>

#define CLOSENESS 30

Detector::Detector()
{
    _beamCentre = make_vec3(-1, -1, 174286);
    _wavelength = STARTING_WAVELENGTH;
}

void Detector::calculatePositions(Crystal &xtal)
{
    _positions.clear();
    _positions.reserve(xtal.millerCount());
    vec3 samplePos = make_vec3(0, 0, - 1 / _wavelength);
    
    for (int i = 0; i < xtal.millerCount(); i++)
    {
        vec3 miller = xtal.miller(i);
        
        vec3 diff = vec3_subtract_vec3(miller, samplePos);
        double mult = - _beamCentre.z / samplePos.z;
        vec3_mult(&diff, mult);
        
        _positions.push_back(diff);
    }
}

int Detector::positionNearCoord(int x, int y)
{
    x -= _beamCentre.x;
    y -= _beamCentre.y;

    for (int i = 0; i < positionCount(); i++)
    {
        vec3 pos = position(i);
        
        if (x >= pos.x - CLOSENESS && x <= pos.x + CLOSENESS &&
            y >= pos.y - CLOSENESS && y <= pos.y + CLOSENESS)
        {
            return i;
        }
    }
    
    return -1;
}
