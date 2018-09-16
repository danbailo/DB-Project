#include <stdio.h>
#include "dbPoint.h"
#include "dbVertex.h"
#include "dbEdge.h"
// #include "dbTriangle.h"
// #include "dbSurface.h"

// #include "dbSegment.h"
// #include "dbFace.h"

int main(int argc, char *argv[]){

    printf("\nPoints\n");

	dbPoint* POINTS_HASH = getPoint("points.txt");

	for(dbPoint* p=POINTS_HASH; p != NULL; p=(dbPoint*)(p->hh.next)) {
        printf("%lf %lf %lf\n",p->x,p->y,p->z);
    }

    printf("\nVertices\n");

    dbVertex* VERTICES_HASH = getVertex("vertices.txt");

	for(dbVertex* v=VERTICES_HASH; v != NULL; v=(dbVertex*)(v->hh.next)) {
        printf("%.lf %.lf %.lf\n",v->v1,v->v2,v->v3);
    }

    printf("\n%lf\n",VERTICES_HASH->v1);
    VERTICES_HASH = VERTICES_HASH->hh.next;
    printf("\n%lf\n",VERTICES_HASH->v1);

	return 0;
}
