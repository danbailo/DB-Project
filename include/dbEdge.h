#ifndef _DB_EDGE_
#define _DB_EDGE_

#include "dbPoint.h"
#include "dbVertice.h"
#include "dbTriangle.h"
#include "dbSurface.h"
#include "uthash.h"

/*! Declaração da estrutura vértice, onde esta
  * contém um ponteiro do tipo "dbPoint" que é o ponto do vértice.
  *
  */
typedef struct dbEdge{

    dbVertice *v1;
    dbVertice *v2;
 	int VertexID[2];

 	// dbTriangle *t1;
 	// dbTriangle *t2;
 	// int TriangleID[2];

 	/* For hashtable */
 	int id;
 	UT_hash_handle hh;

}dbEdge;

#endif /*_DB_EDGE_*/
