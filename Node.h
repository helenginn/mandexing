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
