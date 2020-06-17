#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "nodeList.h"
void writePath( Node *path, int closedSpace ) {

  FILE *fp = fopen("path.out","w");

  writePathCoords(fp,path, closedSpace);

  fclose(fp);

  return;
}

void writePathCoords( FILE *fp, Node *path, int closedSpace ) {

  int i=0;
  float x1, y1, x2, y2;
  for(;i< closedSpace-1;i++){
      x1 = path[i].xy[0];
      y1 = path[i].xy[1];
      x2 = path[i+1].xy[0];
      y2 = path[i+1].xy[1];
      fprintf(fp, " %f %f\n",x1,y1);
      fprintf(fp, " %f %f\n\n",x2,y2);
  }


  return;
}
void writeMap( Node * nodes, Link *path, int linkSpace, int nodeSpace ) {

  FILE *fp = fopen("map.out","w");
  writeCoords(fp, nodes, path, linkSpace, nodeSpace);

  fclose(fp);

  return;
}

void writeCoords( FILE *fp,Node * nodes, Link *path, int linkSpace, int nodeSpace ) {

  int i=0,c, nodeid1, nodeid2;
  float x1, y1, x2, y2;
  Node node1, node2;
  for(;i< linkSpace;i++){
    nodeid1 = path[i].nodeid[0];
    nodeid2 = path[i].nodeid[1];
    c = 0;
    for(; c < nodeSpace ; c++){
      if(nodes[c].oldID == nodeid1){
        node1 = nodes[c];
      }
      if(nodes[c].oldID == nodeid2)
        node2 = nodes[c];
    }
      x1 = node1.xy[0];
      x2 = node2.xy[0];
      y1 = node1.xy[1];
      y2 = node2.xy[1];

      fprintf(fp, " %f %f\n",x1,y1);
      fprintf(fp, " %f %f\n\n",x2,y2);
  }


  return;
}
// write out the (x,y) corners of the node
