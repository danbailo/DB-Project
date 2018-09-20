#ifndef _DB_TRIANGLE_
#define _DB_TRIANGLE_

#include "dbEdge.h"

/* Defines the structure of a triangle. A triangle consists of 3 edges. Moreover, a triangle has 3 vertices */
typedef struct dbTriangle{

    dbEdge *e1;
    dbEdge *e2;
    dbEdge *e3;
    
    /* For hashtable */
    int id;
    UT_hash_handle hh;

}dbTriangle;

#endif /*_DB_TRIANGLE_*/

