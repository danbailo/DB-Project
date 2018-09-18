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

dbSurface* setSurface(char* arc1,char* arc2){

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

		printf("id: %d | %lf %lf %lf\n",point_id ,p->x , p->y, p->z);
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

		printf("id: %i | %i %i %i\n",vertex_id ,v->v1 , v->v2, v->v3);

	  	return v;
	}
	error();
	printf("the max vertex_id is %i\n",HASH_COUNT(surface->Vertices)-1); /* se o point id for menor ou maior que o numero de pontos */
	return NULL;
}

dbEdge* getEdge(dbSurface *surface, int vertex_id){

	printf("\nsaida da egde\n");

	dbEdge *e = (dbEdge*)malloc(sizeof(dbEdge));
	dbVertex *v = getVertexID(surface,vertex_id);

	// getVertexID(surface,vertex_id);
	// printf("teste:%i\n",->v3);

	e->e1[0] = v->v1;
	e->e1[1] = v->v2;

	e->e2[0] = v->v2;
	e->e2[1] = v->v3;

	e->e3[0] = v->v3;
	e->e3[1] = v->v1;

	for(int i=0; i<2; i++){
		printf("%i ", e->e1[i]);
	}
	printf("\n");
	for(int i=0; i<2; i++){
		printf("%i ", e->e2[i]);
	}
	printf("\n");
	for(int i=0; i<2; i++){
		printf("%i ", e->e3[i]);
	}

	return NULL;
}

