#ifndef _DB_SURFACE_
#define _DB_SURFACE_

#include "dbPoint.h"
#include "dbVertice.h"
#include "dbEdge.h"
#include "dbTriangle.h"
#include "uthash.h"

/*! Declaração da estrutura ponto, onde esta
  * contém os elementos x, y e z referentes ao espaço tridimensional;
  */

//An object contains a number of triangles and also has pointers to the edges and vertices 
typedef struct dbSurface{

	dbPoint *Points;
    dbVertice *Vertexes;
    dbEdge *Edges;
    dbTriangle *Triangles;

  	/* For hashtable */
  	int id;
  	UT_hash_handle hh;
  	
}dbSurface;

#endif /*_DB_SURFACE_*/



