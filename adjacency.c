//Adjacency list creation function
#include <stdio.h>
#include <stdlib.h>
#include "nodeList.h"


//takes original node id and returns the new ordered one to go on the linked list
Node linkedNode(int linknodeid, Node * nodes, int nodesSize){
  int i = 0;
  for(;i < nodesSize; i++){
    if (nodes[i].oldID == linknodeid){
      return nodes[i];
      break;
    }
  }
}


void AdjCreator(Adj** adjList, Node * nodes, Link * link, int nspace, int lspace){
  int nodesSize = nspace;
  int linksSize = lspace;
  int i = 0, c, q;
  float length, xy[2];
  Node linknode;
  int currentid, nodeid, linkid, linknodeid, linkCount;

  for(; i< (nodesSize); i++){ //loops through array of nodes
    currentid = nodes[i].id;
    nodeid = nodes[i].oldID;
    c=0;
    nodes[i].links =0;
    linkCount = 0;
    for(; c < (linksSize); c++){ //loops through array of links
      if(nodeid == link[c].nodeid[0]){ //if current node is in the link
        linknodeid = link[c].nodeid[1];
        length = link[c].length;
        linknode = linkedNode(linknodeid, nodes, nodesSize); //finds the node to be added to the adjacency list under the current node
        if(linkCount == 0){ //if there are no current links on the adjacency list for the current node it allocates memory for it
          adjList[i] = malloc(sizeof(Adj));
          adjList[i][0].node = linknode;
          adjList[i][0].length = length;
          nodes[i].links ++;
          linkCount++;
        }
        else{ //else it reallocates memory for the node to be linked
          linkCount++;
          adjList[i] = realloc(adjList[i], (linkCount * sizeof(Adj)));
          adjList[i][linkCount-1].node = linknode;
          adjList[i][linkCount-1].length = length;
          nodes[i].links ++;

        }
      }
      if(nodeid == link[c].nodeid[1]){ //checks if the link is the other way around
        linknodeid = link[c].nodeid[0];
        length = link[c].length;
        linknode = linkedNode(linknodeid, nodes, nodesSize);
        if(linkCount == 0){
          adjList[i] = malloc(sizeof(Adj));
          adjList[i][0].node = linknode;
          adjList[i][0].length = length;
          nodes[i].links ++;
          linkCount++;
        }
        else{
          linkCount++;
          adjList[i] = realloc(adjList[i], (linkCount * sizeof(Adj)));
          adjList[i][linkCount-1].node = linknode;
          adjList[i][linkCount-1].length = length;
          nodes[i].links ++;
        }
      }

    }


  }

}
