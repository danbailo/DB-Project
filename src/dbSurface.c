#include <stdio.h>
// #include "dbPoint.h"
// #include "dbVertex.h"
#include "dbSurface.h"
// #include "dbEdge.h"
// #include "dbTriangle.h"
// #include "uthash.h"

void error(){
	printf("error!\n");
	// exit(-1);
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

	HASH_FIND_INT(surface->Points, &point_id, p);
	if( p != NULL ){

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


	HASH_FIND_INT(surface->Vertices, &vertex_id, v);
	
	if( v != NULL ){

		printf("id: %i | %i %i %i\n",vertex_id ,v->v1 , v->v2, v->v3);

	  	return v;
	}
	error();
	printf("the max vertex_id is %i\n",HASH_COUNT(surface->Vertices)-1); /* se o point id for menor ou maior que o numero de pontos */
	return NULL;
}

dbEdge* setEdge(dbSurface *surface, int edge_id, int vertex_origin, int vertex_extreme){

	printf("\nsaida da egde\n");

	dbEdge *temp = NULL;
	dbEdge *e = (dbEdge*)malloc(sizeof(dbEdge));
	e->id = edge_id;
	
	dbVertex *v1 = getVertexID(surface,vertex_origin);
	dbVertex *v2 = getVertexID(surface,vertex_extreme);

	if(v1 == NULL) error();
	if(v2 == NULL) error();
	
	e->v1 = v1;
	e->v2 = v2;

	HASH_FIND_INT(temp, &edge_id, surface->Edges);
	if(temp != NULL){
		printf("colisão\n");
		error();
	}

	HASH_ADD_INT(surface->Edges, id, e);

	return e;
}

dbTriangle* setTriangle(dbSurface *surface, int triangle_id, dbEdge *e1, dbEdge *e2, dbEdge *e3){

	dbTriangle *temp = NULL;
	dbTriangle *triangle = (dbTriangle*)malloc(sizeof(dbTriangle));

    triangle->e1 = e1;
    triangle->e2 = e2;
    triangle->e3 = e3;

    HASH_FIND_INT(temp, &triangle_id, surface->Triangles);

	if(temp != NULL){
		printf("colisão\n");
		error();
	}

	HASH_ADD_INT(surface->Triangles, id, triangle);

    return triangle;
}