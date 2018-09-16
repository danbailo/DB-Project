#ifndef _DB_SEGMENT_
#define _DB_SEGMENT_

/*! Declaração da estrutura vértice, onde esta
  * contém um ponteiro do tipo "dbPoint" que é o ponto do vértice.
  *
  */
typedef struct dbSegment{

	dbPoint p;

	/* For hashtable */
	int id;
	UT_hash_handle hh;


}dbSegment;

#endif /*_DB_SEGMENT_*/
