#include <stdio.h>
#include "dbSurface.h"

int main(int argc, char *argv[]){

	dbSurface* surface = setSurface("points.txt","vertices.txt");
    
    printf("\nPoints\n");
	for(dbPoint* p = surface->Points; p != NULL; p=(dbPoint*)(p->hh.next)) {
        printf("id: %d | %lf %lf %lf\n",p->id,p->x,p->y,p->z);
    }


    printf("\nVertices\n");
	for(dbVertex* v = surface->Vertices; v != NULL; v=(dbVertex*)(v->hh.next)) {
        printf("id: %i | %i %i %i\n",v->id,v->v1,v->v2,v->v3);
    }

    printf("\n");

    getPointID(surface,48);
    getVertexID(surface,95);

    getEdge(surface,5);

    printf("\n");

	return 0;
}
