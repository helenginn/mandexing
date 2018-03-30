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


Detector::Detector()
{
    _beamCentre = make_vec3(-1, -1, STARTING_DISTANCE);
    _wavelength = STARTING_WAVELENGTH;
	_lookupTree = NULL;
}

void Detector::calculatePositions()
{
	vec3 samplePos = make_vec3(0, 0, - 1 / _wavelength);

	for (int i = 0; i < _xtal->millerCount(); i++)
	{
		vec3 miller = _xtal->miller(i);

		vec3 diff = vec3_subtract_vec3(miller, samplePos);
		double mult = _beamCentre.z / diff.z;
        vec3_mult(&diff, mult);
        
		_xtal->setPositionForMiller(i, diff);
    }
}

bool Detector::nearMiller(int i, int x, int y)
{
	bool onImage = _xtal->shouldDisplayMiller(i);

	if (!onImage) return false;

	vec3 pos = _xtal->position(i);

	if (x >= pos.x - CLOSENESS && x <= pos.x + CLOSENESS &&
	    y >= pos.y - CLOSENESS && y <= pos.y + CLOSENESS)
	{
		return true;
	}
	
	return false;
}

int Detector::positionNearCoord(int x, int y)
{
	x -= _beamCentre.x;
	y -= _beamCentre.y;

	if (!_lookupTree)
	{
		for (int i = 0; i < _xtal->millerCount(); i++)
		{
			if (nearMiller(i, x, y))
			{
				return i;
			}
		}

		return -1;
	}
	
	Node *node = _lookupTree;
	int drills = 0;

	while (true)
	{
		for (int i = 0; i < 4; i++)
		{
			Node *trial = node->nextNodes[i];

			if (!trial)
			{
				goto finished_node_search;
			}	

			if (x > trial->xMin && x < trial->xMax && 
			    y > trial->yMin && y < trial->yMax)
			{
				node = trial;
				break;
			}
		}
		
		drills++;
	}
	
finished_node_search:
	
	std::cout << "Drilled down " << drills << " nodes." << std::endl;
	
	for (int i = 0; i < node->nRefls; i++)
	{
		int n = node->reflPtrs[i];

		if (nearMiller(n, x, y))
		{
			return n;
		}
	}
	
	return -1;
}

void Detector::prepareLookupTable()
{
	delete_node(_lookupTree);
	_lookupTree = NULL;
	
	size_t count = _xtal->millerCount();
	if (!count) return;

	Reflection *start = _xtal->refl(0);
	_lookupTree = make_node();
	prepare_node(_lookupTree, start, count);
	recursive_split_node(_lookupTree);
}

Detector::~Detector()
{
	if (_lookupTree)
	{
		delete_node(_lookupTree);
	}
}

