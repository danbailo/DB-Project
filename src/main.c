#include <stdio.h>
#include "dbPoint.h"
#include "dbVertex.h"
#include "dbEdge.h"
// #include "dbTriangle.h"
#include "dbSurface.h"
#include "uthash.h"

// #include "dbSegment.h"
// #include "dbFace.h"

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

    getPointID(surface,2);
    getVertexID(surface,5);
    // getPointID("points.txt",2);

	return 0;
}
