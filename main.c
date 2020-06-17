#include <stdio.h>
#include <stdlib.h>
#include "fileReader.h"
#include "Astar.h"
#include "nodeList.h"
#include "adjacency.h"
#include "output.h"

int main( int argc, char **argv ) {
  Node * nodes;
  Node * closedList;
  Node * closedListReturn;
  Link * links = malloc(sizeof(Link));
  Adj** adjList;
  int nSpace, lSpace, closedSpace;
  Node startNode, finishNode;



  //creates node list
  nSpace = (NodeReader("Final_Map.map")).nodeSpace;
  nodes = malloc(nSpace*sizeof(Node));
  nodes = (NodeReader("Final_Map.map")).node;
  startNode = nodes[3];
  finishNode = nodes[150];

  //creates list of links
  lSpace = (LinkReader("Final_Map.map")).linkSpace;
  links = malloc(lSpace*sizeof(Link));
  links = (LinkReader("Final_Map.map")).link;

  //creates adjacency list
  adjList = (Adj**)(malloc(nSpace * sizeof(Adj)));
  AdjCreator(adjList, nodes, links, nSpace, lSpace);


  //finds best path between coords
  closedSpace = (AStar(adjList, startNode, finishNode, closedList, nodes)).nodeSpace;
  closedListReturn = malloc(closedSpace*sizeof(Node));
  closedListReturn = (AStar(adjList, startNode, finishNode, closedList, nodes)).node;

  //writes the coords to file
  writeMap(nodes, links, nSpace, lSpace);
  writePath(closedListReturn,closedSpace);

  return 0;
}
