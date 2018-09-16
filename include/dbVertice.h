#ifndef _DB_VERTICE_H_
#define _DB_VERTICE_H_

// #include "dbPoint.h"
#include "uthash.h"

/*! Declaração da estrutura vértice, onde esta
  * contém um ponteiro do tipo "dbPoint" que é o ponto do vértice.
  *
  */
typedef struct dbVertice{

	dbPoint p;

	/* For hashtable */
	int id;
	UT_hash_handle hh;


}dbVertice;

#endif /*_DB_VERTICE_H_*/
