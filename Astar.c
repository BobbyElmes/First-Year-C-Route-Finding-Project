//A* path finding algorithm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nodeList.h"

//works out heuristic value
float hValue(Node currentNode,Node finishNode){
  return  (100000*sqrt((currentNode.xy[0] - finishNode.xy[0])*(currentNode.xy[0] - finishNode.xy[0]) + (currentNode.xy[1] - finishNode.xy[1])*(currentNode.xy[1] - finishNode.xy[1]))); //a^2 + b^2 = c^2
}

//A star algorithm
NSize AStar(Adj ** adjList, Node startNode, Node finishNode, Node*closedList, Node* nodes){
  Node * openList;
  Node currentNode;
  Node successorNode;
  NSize closedReturn;
  int openSpace = 1;
  int closedSpace = 0;
  int i,c,q,pos, skip;
  float successor_cost;
  closedList = malloc(sizeof(Node));

  //initialize list
  openList = malloc(openSpace*sizeof(Node));
  startNode.f = hValue(startNode, finishNode);
  startNode.h = hValue(startNode, finishNode);
  startNode.g = 0.0;
  openList[0] = startNode;

  while(openSpace > 0){


    currentNode = openList[openSpace-1];
    openSpace --;
    openList = realloc(openList, openSpace*sizeof(Node));

    //if current node is destination
    if(currentNode.id == finishNode.id){
      closedSpace++;
      closedList = realloc(closedList, closedSpace*sizeof(Node));
      closedList[closedSpace-1] = currentNode;
      break;
    }
    //generate successor nodes
    i = 0;
    for(; i < nodes[currentNode.id].links ; i++){
      successorNode = adjList[currentNode.id][i].node;
      successor_cost = currentNode.g + adjList[currentNode.id][i].length;

      //if successor is in the open list
      skip = 0;
      pos = -1;

      pos = isinarray(successorNode, openList, openSpace);
      if(pos != -1){
        if(openList[pos].g <= successor_cost)
          skip = 1;
      }
      //if successor is in the closed list
      else{
        pos = isinarray(successorNode, closedList, closedSpace);
        if(pos != -1){
          if(closedList[pos].g <= successor_cost){
            skip = 1;
          }
          //if current node is better option than closed list successor
          else{
            c = pos;
            for(;c < closedSpace-1; c++){
              closedList[c] = closedList[c+1];
            }
            closedSpace--;
            closedList = realloc(closedList,closedSpace*sizeof(Node) );
          }

        }

      }

      if(skip == 0){
        successorNode.h = hValue(successorNode, finishNode);
        successorNode.g = successor_cost;
        successorNode.f = successorNode.g + successorNode.h;
        c = 0;
        openSpace ++;
       if(openSpace == 1){
          openList = malloc(openSpace*sizeof(Node));
          openList[0] = successorNode;
        }
        else{
          openList = realloc(openList, openSpace*sizeof(Node));
          while(c < openSpace){
            if(c == openSpace-1){
              openList[c] = successorNode;
            }
            else{
              if(openList[c].f < successorNode.f){
                q = openSpace-1;
                for(;q > c; q--){
                  openList[q] = openList[q-1];
                }

                openList[c] = successorNode;
                break;
              }
            }
            c++;
          }
        }
      }
    }
    closedSpace++;
    closedList = realloc(closedList, closedSpace*sizeof(Node));
    closedList[closedSpace-1] = currentNode;
  }
  closedReturn.node = malloc(sizeof(Node)*closedSpace);
  closedReturn.node = closedList;
  closedReturn.nodeSpace = closedSpace;

  return closedReturn;
}

//function checks whether node is in the array of nodes already and returns the index of that node
int isinarray(Node val, Node *array, int size){
  int i = 0;
  int id = -1;
  for(; i< size; i++){
    if(array[i].id == val.id){
      id = i;
      break;
    }
  }
  return id;
}
