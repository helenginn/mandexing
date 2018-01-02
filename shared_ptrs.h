//
//  shared_ptrs.h
//  vagabond
//
//  Created by Helen Ginn on 11/07/2017.
//  Copyright (c) 2017 Strubi. All rights reserved.
//

#ifndef vagabond_shared_ptrs_h
#define vagabond_shared_ptrs_h

#define BOOST_DISABLE_ASSERTS
#include "boost/shared_ptr.hpp"
#include "boost/weak_ptr.hpp"
#include "boost/enable_shared_from_this.hpp"
#include <math.h>

#define deg2rad(a) ((a) * M_PI / 180)
#define rad2deg(a) ((a) / M_PI * 180)

class RefinementGridSearch;
class RefinementStepSearch;
class RefinementStrategy;
class NelderMead;
typedef boost::shared_ptr<RefinementStepSearch> RefinementStepSearchPtr;
typedef boost::shared_ptr<RefinementGridSearch> RefinementGridSearchPtr;
typedef boost::shared_ptr<RefinementStrategy> RefinementStrategyPtr;
typedef boost::shared_ptr<NelderMead> NelderMeadPtr;

class CSV;
class PNGFile;
class TextManager;
typedef boost::shared_ptr<PNGFile> PNGFilePtr;
typedef boost::shared_ptr<TextManager> TextManagerPtr;
typedef boost::shared_ptr<CSV> CSVPtr;


typedef enum
{
	BravaisLatticePrimitive,
	BravaisLatticeBody,
	BravaisLatticeFace,
	BravaisLatticeBase
} BravaisLatticeType;

#endif
