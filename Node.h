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
#include "Crystal.h"

typedef struct Node
{
	int xMin;
	int xMax;
	int yMin;
	int yMax;
	Reflection *start;
	Node *nextNodes[4];
	int *reflPtrs;
	size_t nRefls;
} Node;

Node *make_node();
void prepare_node(Node *node, Reflection *refls, int nRefls);
void recursive_split_node(Node *node);
void split_node(Node *node);
void delete_node(Node *node);
