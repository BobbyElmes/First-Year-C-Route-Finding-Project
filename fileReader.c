//File reader function
#include <stdio.h>
#include <stdlib.h>
#include "nodeList.h"

//reads the nodes into an array
NSize NodeReader(char * map){
  FILE * file;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  size_t nodeSpace = 1;
  char characters[800];
  char nodeID[20], x[20], y[20];
  int count, counter;
  int nodeTrue = 0;
  int i,size, ID = 0, nodeCount = 0;
  Node* nodes = (Node*)(malloc(sizeof(Node)));
  NSize nodeListSize;


  file = fopen(map, "r");

  while((read = getline(&line,&len,file)) != -1){ //loops through once to get node data
    memset (characters, 0, 300);
    memset(nodeID, 0, 20);
    memset(y, 0, 20);
    memset(x, 0, 20);
    i=0;
    count = 0;
    counter = 0;
    size = (int)strlen(line);
    for(; i < size; i++ ){
      characters[counter] = line[i];

    if(nodeTrue == 1 && (characters[counter] != ' ')){
        if(count > 0){
          nodeID[count-1] = characters[counter];
        }
        count ++;
      }
      else{
        if(nodeTrue == 1){
        nodeTrue = 0;
        count = 0;
        memset (characters, 0, 300);
        counter = -1;
        nodes[nodeCount].oldID = atoi(nodeID);
        }
      }

      if(nodeTrue == 2 && (characters[counter] != ' ')){
          if(count > 0){
            y[count-1] = characters[counter];
          }
          count ++;
        }
        else{
          if(nodeTrue == 2){
          nodeTrue = 0;
          count = 0;
          counter = -1;
          memset (characters, 0, 300);
          nodes[nodeCount].xy[1] = atof(y);
          nodes[nodeCount].id = ID;
          ID++;
          }
        }

        if(nodeTrue == 3 && (characters[counter] != ' ')){
            if(count > 0){
              x[count-1] = characters[counter];
            }
            count ++;
          }
          else{
            if(nodeTrue == 3){
            nodeTrue = 0;
            count = 0;
            nodes[nodeCount].xy[0] = atof(x);
            nodeCount++;
            nodeSpace++;
            nodes = realloc(nodes, nodeSpace*sizeof(Node));
            }
          }
          if(strcmp(characters, "<node id") == 0){
            nodeTrue = 1;
          }

          if(strcmp(characters, "lat") == 0){
            nodeTrue = 2;
          }

          if(strcmp(characters, "lon") == 0){
            nodeTrue = 3;
          }

    counter ++;
  }


  }
  fclose(file);
  if(line)
    free(line);
  nodeListSize.node = malloc(sizeof(Node)*nodeSpace);
  nodeListSize.node = nodes;
  nodeListSize.nodeSpace = nodeSpace;
  return nodeListSize;
}

//reads the links between nodes into an array
LSize LinkReader(char * map){
  FILE * file;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  size_t linkSpace = 1;
  char characters[800];
  char node1[20], node2[20], length[20];
  int count, counter;
  int linkTrue = 0, linkLine;
  int i,size, ID = 0, linkCount = 0;
  Link* links = (Link*)(malloc(sizeof(Link)));
  LSize linkListSize;


  file = fopen(map, "r");

  while((read = getline(&line,&len,file)) != -1){ //loops through once to get node data
    memset (characters, 0, 300);
    memset(node1, 0, 20);
    memset(node2, 0, 20);
    memset(length, 0, 20);
    i=0;
    count = 0;
    counter = 0;
    linkLine = 0;
    size = (int)strlen(line);
    for(; i < size; i++ ){
      characters[counter] = line[i];

    if(linkTrue == 1 && (characters[counter] != ' ')){
        if(count > 0){
          node1[count-1] = characters[counter];
        }
        count ++;
      }
      else{
        if(linkTrue == 1){
        linkTrue = 4;
        count = 0;
        memset (characters, 0, 300);
        counter = -1;
        links[linkCount].nodeid[0] = atoi(node1);
        }
      }

      if(linkTrue == 2 && (characters[counter] != ' ')){
          if(count > 0){
            node2[count-1] = characters[counter];
          }
          count ++;
        }
        else{
          if(linkTrue == 2){
          linkTrue = 0;
          count = 0;
          counter = -1;
          memset (characters, 0, 300);
          links[linkCount].nodeid[1] = atof(node2);
          }
        }

        if(linkTrue == 3 && (characters[counter] != ' ')){
            if(count > 0){
              length[count-1] = characters[counter];
            }
            count ++;
          }
          else{
            if(linkTrue == 3){
            linkTrue = 0;
            count = 0;
            links[linkCount].length = atof(length);
            linkCount++;
            linkSpace++;
            links = realloc(links, linkSpace*sizeof(Link));
            }
          }

          if(strcmp(characters, "<link id") == 0){
            linkLine = 1;
          }
          if(linkLine == 1){
            if(characters[counter] == 'e' && characters[counter-1] == 'd' && characters[counter-2] == 'o' && linkTrue == 0){ //different search for key words due to filtering out some irrelevent data
              linkTrue = 1;
            }

            if(characters[counter] == 'e' && characters[counter-1] == 'd' && characters[counter-2] == 'o' && linkTrue == 4){
              linkTrue = 2;
            }

            if(characters[counter] == 'h' && characters[counter-1] == 't' && characters[counter-2] == 'g'){
              linkTrue = 3;
            }
          }

    counter ++;
  }


  }
  fclose(file);
  if(line)
    free(line);
  linkListSize.link = malloc(sizeof(Link)*linkSpace);
  linkListSize.link = links;
  linkListSize.linkSpace = linkSpace;
  return linkListSize;
}
