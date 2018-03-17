//
//  Detector.cpp
//  Windexing
//
//  Created by Helen Ginn on 11/12/2016.
//  Copyright (c) 2017 Helen Ginn. All rights reserved.
//

#include "Crystal.h"
#include "Detector.h"
#include "defaults.h"
#include <iostream>

#define CLOSENESS 30

Detector::Detector()
{
    _beamCentre = make_vec3(-1, -1, STARTING_DISTANCE);
    _wavelength = STARTING_WAVELENGTH;
}

void Detector::calculatePositions()
{
    vec3 samplePos = make_vec3(0, 0, - 1 / _wavelength);
    
    for (int i = 0; i < _xtal->millerCount(); i++)
    {
        vec3 miller = _xtal->miller(i);
        
        vec3 diff = vec3_subtract_vec3(miller, samplePos);
        double mult = - _beamCentre.z / samplePos.z;
        vec3_mult(&diff, mult);
        
		_xtal->setPositionForMiller(i, diff);
    }
}

int Detector::positionNearCoord(int x, int y)
{
    x -= _beamCentre.x;
    y -= _beamCentre.y;

    for (int i = 0; i < _xtal->millerCount(); i++)
    {
		bool onImage = _xtal->shouldDisplayMiller(i);

		if (!onImage) continue;

        vec3 pos = _xtal->position(i);
        
        if (x >= pos.x - CLOSENESS && x <= pos.x + CLOSENESS &&
            y >= pos.y - CLOSENESS && y <= pos.y + CLOSENESS)
        {
            return i;
        }
    }
    
    return -1;
}
