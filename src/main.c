#include <stdio.h>
#include "dbPoint.h"
// #include "dbVertice.h"
// #include "dbEdge.h"
// #include "dbTriangle.h"
// #include "dbSurface.h"

// #include "dbSegment.h"
// #include "dbFace.h"

int main(int argc, char *argv[]){

	dbPoint* POINTS_HASH = getPoint("points_sphere.txt");

	for(dbPoint* s=POINTS_HASH; s != NULL; s=(dbPoint*)(s->hh.next)) {
        printf("%lf %lf %lf\n",s->x,s->y,s->z);
    }
	return 0;
}
