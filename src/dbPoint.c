#include <stdio.h>
#include "uthash.h"
#include "dbPoint.h"
#include "dbSurface.h"

// MFTL_Vertex *MFTL_AddVertex(MFTL_Object *Object, MFTL_Vertex *Vertex)
// {
//   MFTL_Vertex *tmpVertex;

//   HASH_FIND_INT(Object->Vertexes, &Vertex->id, tmpVertex);
//   if (tmpVertex != MF_NULL)
//     return (tmpVertex);
//   tmpVertex = (MFTL_Vertex*) malloc(sizeof(MFTL_Vertex));
//   memcpy(tmpVertex, Vertex, sizeof(MFTL_Vertex));
//   HASH_ADD_INT(Object->Vertexes, id, tmpVertex);
//   return (tmpVertex);
// }

dbPoint* getPoint( const char* arc){
	dbPoint* ans=NULL;
	FILE *f = fopen(arc,"r");
	dbPoint *paux;

	if(!f){
		printf("nao abri o arquivo");
		exit(-1);
	}
	char str[256];
	int i=1;	

	//para cada linha do arquivo até o final
	int item=0;
	while((fgets(str,256,f))){
		if(strlen(str)==255){
			printf("Error, the line of a file can not exceed 256 characters\n");
			exit(-1);
		}
		int n = 0;
		char *buff = str;
		int j = 0;
		while(1){
			paux=(dbPoint*)malloc(sizeof(dbPoint));
		    buff+=n;

		    int res=sscanf(buff,"%lf %lf %lf%n",&paux->x,&paux->y,&paux->z,&n);
		    if(res!=3) break;  
			paux->id=item;
			item++;
			dbPoint*s;
  			HASH_FIND_INT(ans, &paux->id, s);
  			if(s!=NULL){
  				printf("colisão!\n");exit(-1);
  			}

		    HASH_ADD_INT(ans, id, paux);
			// insert_list(l,x,y,z);
			j++;
		}
		if(j == 0){
			printf("erro na linha %i: \n",i);
		}
		i++;
	}
	fclose(f);
	return ans;
}

// void list_archive(list *l, const char *arc){
// 	FILE *f = fopen(arc,"r");
	
// 	if(!f){
// 		printf("nao abri o arquivo");
// 		return;
// 	}
// 	char str[256];
// 	int i=1;

// 	//para cada linha do arquivo até o final
// 	while((fgets(str,256,f))){
// 		if(strlen(str)==255){
// 			printf("Error, the line of a file can not exceed 256 characters\n");
// 			return;
// 		}
// 		int n = 0;
// 		char *buff = str;
// 		int j = 0;
// 		while(1){
//             double x,y,z;
// 		    buff+=n;

// 		    int res=sscanf(buff,"%lf %lf %lf%n",&x,&y,&z,&n);
			    
// 		    if(res!=3) break;    	

// 			insert_list(l,x,y,z);
// 			j++;
// 		}
// 		if(j == 0){
// 			printf("erro na linha %i: \n",i);
// 		}
// 		i++;
// 	}
// 	fclose(f);
// }