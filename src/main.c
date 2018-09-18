#include <stdio.h>
#include "dbSurface.h"

int main(int argc, char *argv[]){

	dbSurface* surface = getSurface("points.txt","vertices.txt");
    
    printf("\nPoints\n");
	for(dbPoint* p = surface->Points; p != NULL; p=(dbPoint*)(p->hh.next)) {
        printf("id:%d %lf %lf %lf\n",p->id,p->x,p->y,p->z);
    }


    printf("\nVertices\n");
	for(dbVertex* v = surface->Vertices; v != NULL; v=(dbVertex*)(v->hh.next)) {
        printf("id:%d %.lf %.lf %.lf\n",v->id,v->v1,v->v2,v->v3);
    }

    getPointID(surface,48);
    getVertexID(surface,95);

	return 0;
}
