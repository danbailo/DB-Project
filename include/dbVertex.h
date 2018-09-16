#ifndef _DB_VERTEX_H_
#define _DB_VERTEX_H_

#include "dbPoint.h"
#include "uthash.h"

/*! Declaração da estrutura vértice, onde esta
  * contém um ponteiro do tipo "dbPoint" que é o ponto do vértice.
  *
  */
typedef struct dbVertex{

	double v1,v2,v3;

	/* For hashtable */
	int id;
	UT_hash_handle hh;


}dbVertex;

dbVertex* getVertex(const char* arc);

#endif /*_DB_VERTEX_H_*/
