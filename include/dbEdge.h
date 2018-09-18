#ifndef _DB_EDGE_
#define _DB_EDGE_

#include "dbPoint.h"
#include "dbVertex.h"
#include "uthash.h"

/*! Declaração da estrutura vértice, onde esta
  * contém um ponteiro do tipo "dbPoint" que é o ponto do vértice.
  *
  */
typedef struct dbEdge{

    dbVertex *v1;
    dbVertex *v2;
 	// int VertexID[2];

 	// dbTriangle *t1;
 	// dbTriangle *t2;
 	// int TriangleID[2];

 	/* For hashtable */
 	int id;
 	UT_hash_handle hh;

}dbEdge;

dbEdge *getEdge();

#endif /*_DB_EDGE_*/
