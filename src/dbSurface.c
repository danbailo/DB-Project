#include "dbPoint.h"
#include "dbVertex.h"
#include "dbEdge.h"
// #include "dbTriangle.h"
#include "dbSurface.h"
#include "uthash.h"



dbSurface* getSurface(char* arc1,char* arc2){

	dbSurface *ans = (dbSurface*)malloc(sizeof(dbSurface));
	ans->Points = getPoint(arc1);
	ans->Vertices = getVertex(arc2);
	//ans->Triangle = getTriangle(arc3);

	return ans;
}
