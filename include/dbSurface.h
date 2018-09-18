#ifndef _DB_SURFACE_
#define _DB_SURFACE_

#include "dbPoint.h"
#include "dbVertex.h"
#include "dbEdge.h"
// #include "dbTriangle.h"
#include "uthash.h"

/*! Declaração da estrutura ponto, onde esta
  * contém os elementos x, y e z referentes ao espaço tridimensional;
  */

//An object contains a number of triangles and also has pointers to the edges and vertices 
typedef struct dbSurface{

	dbPoint *Points;
    dbVertex *Vertices;
    dbEdge *Edges;
    // dbTriangle *Triangles;
    
}dbSurface;

dbSurface* setSurface(char* arc1,char* arc2);

dbPoint* getPointID(dbSurface *surface,int point_id);

dbVertex* getVertexID(dbSurface *surface, int vertex_id);

dbEdge* getEdge(dbSurface *surface, int vertex_id);

#endif /*_DB_SURFACE_*/



