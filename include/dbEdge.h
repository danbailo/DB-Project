#ifndef _DB_EDGE_
#define _DB_EDGE_

#include "dbVertex.h"

/*! Declaração da estrutura vértice, onde esta
  * contém um ponteiro do tipo "dbPoint" que é o ponto do vértice.
  *
  */
typedef struct dbEdge{

	int v1;
	int v2;

 	/* For hashtable */
 	int id;
 	UT_hash_handle hh;

}dbEdge;

#endif /*_DB_EDGE_*/
