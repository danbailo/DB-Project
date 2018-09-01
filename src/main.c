#include <stdio.h>
// #include "dbPoint.h"
#include "listarchive.h"
// #include "dbVertice.h"
// #include "dbSegment.h"
// #include "dbEdge.h"
// #include "dbTriangle.h"
// #include "dbFace.h"

int main(int argc, char const *argv[]){

	linked_list.l = create_list();
	read_archive("arquivo.txt");

	print_list(linked_list.l);

	printf("\nsize:%d\n",linked_list.l->size);
	
	printf("\nindex from the first node:%d\n",linked_list.l->begin->index);
	printf("\nindex from the last node:%d\n",linked_list.l->end->index);

	printf("\nx:%lf,y;%lf,z:%lf\n",linked_list.l->end->x,linked_list.l->end->y,linked_list.l->end->z);
	printf("\n");

	return 0;

	return 0;
}
