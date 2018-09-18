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

dbSurface* getSurface(char* arc1,char* arc2);

dbPoint* getPointID(dbSurface *s,int point_id);

#endif /*_DB_SURFACE_*/



