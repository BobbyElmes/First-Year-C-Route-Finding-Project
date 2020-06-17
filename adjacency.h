#include "nodeList.h"
#ifndef ADJ_HEADER
# define ADJ_HEADER

Node linkedNode(int linknode, Node * nodes, int nodesSize);
void AdjCreator(Adj** adjList, Node * nodes, Link * links, int nspace, int lspace);
float coords(int linknode, Node * nodes, int nodesSize, int num);

#endif
