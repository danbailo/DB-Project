#include <stdio.h>
#include "listarchive.h"
// #include "dbPoint.h"
// #include "dbVertice.h"
// #include "dbSegment.h"
// #include "dbEdge.h"
// #include "dbTriangle.h"
// #include "dbFace.h"

int main(int argc, char *argv[]){

	if(argc != 2){
		printf("[USO] %s [ARQUIVO].\n",argv[0]);
		return -1;
	}

	list *l = create_list();

	list_archive(l,argv[1]);

	print_list(l);

	return 0;
}
