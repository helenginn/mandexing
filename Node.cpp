#include "Node.h"
#include <climits>

Node *make_node()
{
	Node *node = (Node *)malloc(sizeof(Node) * 1);
	memset(node, '\0', sizeof(Node));
	return node;	
}

void add_refl(Node *node, int refl)
{
	(node->nRefls)++;
	int *tmp = (int *)realloc(node->reflPtrs, node->nRefls *
	                          sizeof(int));
	if (tmp != NULL)
	{
		node->reflPtrs = tmp;	
	}
	else
	{
		printf("Could not allocate memory.\n");
		exit(1);
	}
	
	node->reflPtrs[node->nRefls - 1] = refl;
}

void prepare_node(Node *node, Reflection *refls, int nRefls)
{
	int xMin = INT_MAX;
	int xMax = INT_MAX;
	int yMin = INT_MIN;
	int yMax = INT_MAX;
	
	for (int i = 0; i < nRefls; i++)
	{
		add_refl(node, i);
		if (!refls[i].onImage) continue;
		vec3 pos = refls[i].position;
	
		if (pos.x < xMin) xMin = pos.x;
		if (pos.y < yMin) yMin = pos.y;
		if (pos.x > xMax) xMax = pos.x;
		if (pos.y > yMax) yMax = pos.y;
	}	
	
	node->start = refls;
	node->xMin = xMin;
	node->xMax = xMax;
	node->yMin = yMin;
	node->yMax = yMax;
}

void make_child_refls(Node *node)
{
	int xMid = (node->xMin - node->xMax) / 2;
	int yMid = (node->yMin - node->yMax) / 2;

	for (size_t i = 0; i < node->nRefls; i++)
	{
		Reflection *refl = &node->start[node->reflPtrs[i]];
		vec3 pos = refl->position;
		
		int quarter = 0;
		if (pos.x > xMid && pos.y < yMid)
		{
			quarter = 1;
		}
		else if (pos.x < xMid && pos.y > yMid)
		{
			quarter = 2;
		}
		else if (pos.x > xMid && pos.y > yMid)
		{
			quarter = 3;
		}

		add_refl(node->nextNodes[quarter], node->reflPtrs[i]);
	}	
}

void split_node(Node *node)
{
	if (!node->reflPtrs)
	{
		printf("Warning: splitting node with no data.\n");	
	}

	int xMid = (node->xMin - node->xMax) / 2;
	int yMid = (node->yMin - node->yMax) / 2;
	
	Node *topLeft = make_node();
	topLeft->xMin = node->xMin;
	topLeft->xMax = xMid;
	topLeft->yMin = node->yMin;
	topLeft->yMax = yMid;
	topLeft->start = node->start;
	node->nextNodes[0] = topLeft;
	
	Node *topRight = make_node();
	topRight->xMin = xMid;
	topRight->xMax = node->xMax;
	topRight->yMin = node->yMin;
	topRight->yMax = yMid;
	topRight->start = node->start;
	node->nextNodes[1] = topRight;
	
	Node *bottomLeft = make_node();
	bottomLeft->xMin = node->xMin;
	bottomLeft->xMax = xMid;
	bottomLeft->yMin = yMid;
	bottomLeft->yMax = node->yMax;
	bottomLeft->start = node->start;
	node->nextNodes[2] = bottomLeft;
	
	Node *bottomRight = make_node();
	bottomRight->xMin = xMid;
	bottomRight->xMax = node->xMax;
	bottomRight->yMin = yMid;
	bottomRight->yMax = node->yMax;
	bottomRight->start = node->start;
	node->nextNodes[3] = bottomRight;
	
	make_child_refls(node);
}

void recursive_split_node(Node *node)
{
	split_node(node);
	
	for (int i = 0; i < 4; i++)
	{
		Node *newNode = node->nextNodes[i];

		if (newNode->nRefls > 10 && newNode->nRefls < node->nRefls)
		{
			split_node(newNode);
		}
	}
}

void delete_node(Node *node)
{
	if (!node)
	{
		return;
	}
	
	for (int i = 0; i < 4; i++)
	{
		if (node->nextNodes[i])
		{
			delete_node(node->nextNodes[i]);
		}
	}
	
	if (node->reflPtrs)
	{
		free(node->reflPtrs);	
	}
	
	free(node);
	node = NULL;
}
