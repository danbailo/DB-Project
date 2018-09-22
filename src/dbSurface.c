#include <stdio.h>
// #include "dbPoint.h"
// #include "dbVertex.h"
#include "dbSurface.h"
// #include "dbEdge.h"
// #include "dbTriangle.h"
// #include "uthash.h"

void error(){
	printf("error!\n");
	exit(-1);
}

dbSurface* setSurface(char* arc1,char* arc2){

	dbSurface *ans = (dbSurface*)calloc(1,sizeof(dbSurface));
	ans->Points = getPoint(arc1);
	ans->Vertices = getVertex(arc2);
	ans->Triangles = getTriangle(ans->Vertices,&ans->Edges);

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

dbVertex* getVertexID(dbVertex *vertices, int vertex_id){

	dbVertex *v;

	// printf("count:%d\n",HASH_COUNT(surface->Vertices));


	HASH_FIND_INT(vertices, &vertex_id, v);
	
	if( v != NULL ){

		// printf("id: %i | %i %i %i\n",vertex_id ,v->v1 , v->v2, v->v3);

	  	return v;
	}
	error();
	printf("the max vertex_id is %i\n",HASH_COUNT(vertices)-1); /* se o point id for menor ou maior que o numero de pontos */
	return NULL;
}

dbEdge* setEdge(dbVertex *vertices, dbEdge **v, int edge_id, int vertex_origin, int vertex_extreme){

	// printf("\nsaida da egde\n");

	dbEdge *temp = NULL;
	dbEdge *e = (dbEdge*)malloc(sizeof(dbEdge));
	e->id = edge_id;
	
	e->v1 = vertex_origin;
	e->v2 = vertex_extreme;

	HASH_FIND_INT(*v, &e->id, temp);
	if(temp != NULL){
		printf("colisãom\n");
		error();
	}

	HASH_ADD_INT(*v, id, e);

	return e;
}

dbTriangle* setTriangle(dbTriangle *triangles, int triangle_id, dbEdge *e1, dbEdge *e2, dbEdge *e3){

	dbTriangle *temp = NULL;
	dbTriangle *triangle = (dbTriangle*)malloc(sizeof(dbTriangle));

    triangle->e1 = e1;
    triangle->e2 = e2;
    triangle->e3 = e3;
    triangle->id = triangle_id;

    HASH_FIND_INT(triangles, &triangle->id, temp);

	if(temp != NULL){
		printf("colisão\n");
		error();
	}

	HASH_ADD_INT(triangles, id, triangle);

    return triangles;
}

dbTriangle* getTriangle(dbVertex *v, dbEdge **e){
	dbTriangle *triangles = NULL;
	dbEdge *e1;
	dbEdge *e2;
	dbEdge *e3;
	int i = 0;
	for(dbVertex *temp = v; temp != NULL; temp = (dbVertex*)temp->hh.next){
    	// printf("temp : %i %i %i\n",temp->v1,temp->v2,temp->v3);
    	e1 = setEdge(v,e,i++,temp->v1,temp->v2);
    	// printf("e1: %i %i\n",e1->v1,e1->v2);
  	   	e2 = setEdge(v,e,i++,temp->v2,temp->v3);
    	// printf("e2: %i %i\n",e2->v1,e2->v2);
    	e3 = setEdge(v,e,i,temp->v3,temp->v1);
    	// printf("e3:%i %i\n",e3->v1,e3->v2);
    	// printf("%i %p\n",i,triangles);
    	triangles=setTriangle(triangles,(i-1)/3,e1,e2,e3);
    	i++;
	}
	return triangles;
}