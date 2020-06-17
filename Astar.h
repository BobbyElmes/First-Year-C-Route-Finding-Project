#include "nodeList.h"
#ifndef ASTAR_HEADER
# define ASTAR_HEADER

NSize AStar(Adj ** adjList, Node startNode, Node finishNode, Node* closedList, Node *nodes);
int isinarray(Node val, Node *array, int size);
float hValue(Node currentNode,Node finishNode);

#endif
