#ifndef DBPOINT_H
#define DBPOINT_H

#include "uthash.h"

/*! Declaração da estrutura ponto, onde esta
  * contém os elementos x, y e z referentes ao espaço tridimensional;
  */
typedef struct dbPoint{

  	double x,y,z;
  	 
  	/* For hashtable */
  	int id;
  	UT_hash_handle hh;
  	
}dbPoint;

#endif /*DBPOINT_H*/
