#include <stdio.h>
#include "uthash.h"
#include "dbPoint.h"
// #include "dbSurface.h"

dbPoint* getPoint(const char* arc){
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

// int getPointID(dbPoint *p){
// 	HASH_FIND_INT(p,)
// }