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
