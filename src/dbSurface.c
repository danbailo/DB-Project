#include <stdio.h>
#include "dbPoint.h"
#include "dbVertex.h"
#include "dbSurface.h"
#include "dbEdge.h"
// #include "dbTriangle.h"
#include "uthash.h"

void error(){
	printf("error!\n");
}

dbSurface* getSurface(char* arc1,char* arc2){

	dbSurface *ans = (dbSurface*)malloc(sizeof(dbSurface));
	ans->Points = getPoint(arc1);
	ans->Vertices = getVertex(arc2);
	//ans->Triangle = getTriangle(arc3);

	return ans;
}

dbPoint* getPointID(dbSurface *surface, int point_id){

	dbPoint *p;

	// printf("count:%d\n",HASH_COUNT(surface->Points));

	if( point_id < HASH_COUNT(surface->Points) ){
	  	HASH_FIND_INT(surface->Points, &point_id, p);

		printf("%lf %lf %lf\n",p->x , p->y, p->z);
  		return p;
	}
	error(); /* se o point id for menor ou maior que o numero de pontos */
	printf("the max point_id is %d\n",HASH_COUNT(surface->Points)-1);
	return NULL;
}

dbVertex* getVertexID(dbSurface *surface, int vertex_id){

	dbVertex *v;

	// printf("count:%d\n",HASH_COUNT(surface->Vertices));

	if( vertex_id < HASH_COUNT(surface->Vertices) ){
	  	HASH_FIND_INT(surface->Vertices, &vertex_id, v);

		printf("%.lf %.lf %.lf\n",v->v1 , v->v2, v->v3);

	  	return v;
	}
	error();
	printf("the max vertex_id is %d\n",HASH_COUNT(surface->Vertices)-1); /* se o point id for menor ou maior que o numero de pontos */
	return NULL;
}