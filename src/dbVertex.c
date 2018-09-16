#include <stdio.h>
#include "dbPoint.h"
#include "dbVertex.h"

dbVertex* getVertex(const char* arc){
	dbVertex* ans=NULL;
	FILE *f = fopen(arc,"r");
	dbVertex* vaux;

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
			vaux=(dbVertex*)malloc(sizeof(dbVertex));
		    buff+=n;

		    int res=sscanf(buff,"%lf %lf %lf%n",&vaux->v1,&vaux->v2,&vaux->v3,&n);
		    if(res!=3) break;  
			vaux->id=item;
			item++;
			dbVertex* s;
  			HASH_FIND_INT(ans, &vaux->id, s);
  			if(s!=NULL){
  				printf("colisão!\n");exit(-1);
  			}

		    HASH_ADD_INT(ans, id, vaux);
		    
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