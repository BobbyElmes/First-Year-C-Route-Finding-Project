#include "nodeList.h"
#ifndef OUTPUT_HEADER
# define OUTPUT_HEADER

void writePath( Node *path, int closedSpace) ;
void writePathCoords( FILE *fp, Node *path, int closedSpace ) ;
void writeMap( Node * nodes, Link *path, int linkSpace, int nodeSpace );
void writeCoords( FILE *fp,Node * nodes, Link *path, int linkSpace, int nodeSpace );

#endif
