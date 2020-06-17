#ifndef STRUCT_HEADER
# define STRUCT_HEADER

struct node {
  int oldID, id, links;
  float xy[2], f,g ,h;
};
typedef struct node Node;

struct link{
  int nodeid[2];
  float length;
  };
  typedef struct link Link;

struct adj{
  Node node; 
  float length;
  };
  typedef struct adj Adj;

struct size{
  int nodeSpace;
  Node* node;
}; typedef struct size NSize;


struct linkSize{
  int linkSpace;
  Link* link;
}; typedef struct linkSize LSize;



#endif
