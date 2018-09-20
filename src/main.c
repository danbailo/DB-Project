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

    getPointID(surface,5);
    getVertexID(surface,95);

    dbEdge *e1 = setEdge(surface,0,0,1);
    dbEdge *e2 = setEdge(surface,1,1,2);
    dbEdge *e3 = setEdge(surface,2,2,0);

    dbTriangle *triangle = setTriangle(surface,0,e1,e2,e3);

    printf("%i\n", triangle->id);

    printf("vertice\n");
    printf("%i ", triangle->e1->v1->v1);
    printf("%i ", triangle->e1->v1->v2);
    printf("%i\n", triangle->e1->v1->v3);

    printf("%i ", triangle->e2->v1->v1);
    printf("%i ", triangle->e2->v1->v2);
    printf("%i\n", triangle->e2->v1->v3);

    printf("%i ", triangle->e3->v1->v1);
    printf("%i ", triangle->e3->v1->v2);
    printf("%i\n", triangle->e3->v1->v3);

    printf("\n");

	return 0;
}
