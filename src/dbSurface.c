#include "dbPoint.h"
#include "dbVertex.h"
#include "dbEdge.h"
// #include "dbTriangle.h"
#include "dbSurface.h"
#include "uthash.h"
#include <stdio.h>


dbSurface* getSurface(char* arc1,char* arc2){

	dbSurface *ans = (dbSurface*)malloc(sizeof(dbSurface));
	ans->Points = getPoint(arc1);
	ans->Vertices = getVertex(arc2);
	//ans->Triangle = getTriangle(arc3);

	return ans;
}

dbPoint* getPointID(dbSurface *s, int point_id){

	dbPoint *p;

  	HASH_FIND_INT(s->Points, &point_id, p);

	printf("%lf %lf %lf\n",p->x , p->y, p->z);

  	return p;
}


// dbPoint* getPointID(char* arc, int point_id){

// 	dbSurface *s = (dbSurface*)malloc(sizeof(dbSurface));
// 	s->Points = getPoint(arc);
// 	dbPoint *p;

//   	HASH_FIND_INT(s->Points, &point_id, p);

// 	printf("%lf\n", p->z);

//   	return p;
// }