#include <stdio.h>
#include "dbSurface.h"

int main(int argc, char *argv[]){

	dbSurface* surface = setSurface("points.txt","vertices.txt");

    int n_pontos = HASH_COUNT(surface->Points);

    FILE *f = fopen("esfera_final.vtk","w");

    fprintf(f,"# vtk DataFile Version 2.0\n");
    fprintf(f,"Piramide example\n");
    fprintf(f,"ASCII\n");
    fprintf(f,"DATASET POLYDATA\n");
    fprintf(f,"POINTS %i float\n",n_pontos);
	for(dbPoint* p = surface->Points; p != NULL; p=(dbPoint*)(p->hh.next)) {
        fprintf(f,"%lf %lf %lf\n",p->x,p->y,p->z);
    }
    fprintf(f,"\nPOLYGONS %i %i\n",(n_pontos-2)*2, (((n_pontos-2)*3+(n_pontos-2)))*2);
    for(dbVertex* v = surface->Vertices; v != NULL; v=(dbVertex*)(v->hh.next)){ //for each
        fprintf(f,"3 %i %i %i\n",v->v1,v->v2,v->v3);
    }
    fclose(f);

    // for(dbPoint* p = surface->Points; p != NULL; p=(dbPoint*)(p->hh.next)) {
    //     printf("id: %d | %lf %lf %lf\n",p->id,p->x,p->y,p->z);
    //     // p_size = p->id;
    // }
    // printf("\nVertices\n");
	// for(dbVertex* v = surface->Vertices; v != NULL; v=(dbVertex*)(v->hh.next)) {
        // printf("id: %i | %i %i %i\n",v->id,v->v1,v->v2,v->v3);
        // vertex_id = v->id;
    // }

    // printf("%p\n",surface->Triangles);
    // for(dbTriangle* t = surface->Triangles; t != NULL; t=(dbTriangle*)(t->hh.next)){
        // printf("%i %i %i %i\n",t->id,t->e1->v1,t->e1->v2,t->e2->v2);
    // }

    printf("\n");

	return 0;
}
