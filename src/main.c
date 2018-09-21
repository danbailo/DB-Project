#include <stdio.h>
#include "dbSurface.h"

int main(int argc, char *argv[]){

	dbSurface* surface = setSurface("points.txt","vertices.txt");

    // int point_id = 0;
    // int vertex_id = 0;
    // int triangle_id = 0;

    printf("\nPoints\n");
	for(dbPoint* p = surface->Points; p != NULL; p=(dbPoint*)(p->hh.next)) {
        printf("id: %d | %lf %lf %lf\n",p->id,p->x,p->y,p->z);
    }

    printf("\nVertices\n");
	for(dbVertex* v = surface->Vertices; v != NULL; v=(dbVertex*)(v->hh.next)) {
        printf("id: %i | %i %i %i\n",v->id,v->v1,v->v2,v->v3);
        // vertex_id = v->id;
    }

    printf("%p\n",surface->Triangles);
    for(dbTriangle* t = surface->Triangles; t != NULL; t=(dbTriangle*)(t->hh.next)){
        printf("%i %i %i %i\n",t->id,t->e1->v1,t->e1->v2,t->e2->v2);
    }

    printf("\n");

	return 0;
}
