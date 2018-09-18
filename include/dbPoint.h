#ifndef _DBPOINT_H_
#define _DBPOINT_H_

#include "uthash.h"
// #include "dbSurface.h"

/*! Declaração da estrutura ponto, onde esta
  * contém os elementos x, y e z referentes ao espaço tridimensional;
  */

typedef struct dbPoint{

	double x,y,z;

	/* For hashtable */
	int id;
	UT_hash_handle hh;

}dbPoint;

dbPoint * getPoint( const char* arc);

// int getPointID(dbPoint *p);

#endif /*_DBPOINT_H_*/
