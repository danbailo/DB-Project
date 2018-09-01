#include <stdio.h>
#include <stdlib.h>
#include <gts.h>

/*! Declaração da estrutura ponto, onde esta
  * contém os elementos x, y e z referentes ao espaço tridimensional;
  */
typedef struct dbPoint{
  GtsObject object;
  double x,y,z;
}dbPoint;


/*! Declaração da estrutura vértice, onde esta
  * contém um ponteiro do tipo "dbPoint" que é o ponto do vértice.
  *
  */
typedef struct dbVertice{
  dbPoint p;

  GSList* segments;
}dbVertice;


/*! Declaração da estrutura segmento, onde esta
  * contém dois ponteiros do tipo "dbVertice" que são os vértices de um
  * segmento de reta;
  */
typedef struct dbSegment{
  GtsObject object;

  dbVertice* v1;
  dbVertice* v2;
}dbSegment;


/*! Declaração da estrutura aresta, onde esta
  * contém três ponteiros do tipo "dbPoint" arestas que compõem um triângulo
  * que apontam para edge1, edge2 e edge3;
  */
typedef struct dbEdge{
  dbPoint* edge1;
  dbPoint* edge2;
  dbPoint* edge3;
}dbEdge;


/*! Declaração da estrutura triângulo, onde "e" é uma aresta, e esta estrutura
  * contém três arestas do tipo "dbEdge" arestas que compõem um triângulo.
  * Esses ponteiros apontam para e1, e2 e e3;
  */
typedef struct dbTriangle{
  GtsObject object;

  dbEdge* e1;
  dbEdge* e2;
  dbEdge* e3;
}dbTriangle;


/*! Declaração da estrutura face, onde "triangle" é uma triângulo do tipo
  * "dbTriangle" que no caso, é um triângulo que compõe uma face.
  */
typedef struct dbFace{
  dbTriangle triangle;

  GSList * surfaces;
}dbFace;


typedef struct dbSurface{
  GtsObject object;

#ifdef USE_SURFACE_BTREE
  GTree* faces;
#else /* not USE_SURFACE_BTREE */
  GHashTable* faces;
#endif /* not USE_SURFACE_BTREE */
  GtsFaceClass* face_class;
  GtsEdgeClass* edge_class;
  GtsVertexClass* vertex_class;
  gboolean keep_faces;
}dbSurface;
