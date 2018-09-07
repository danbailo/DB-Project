#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listarchive.h"
#include "dbPoint.h"


list *create_list(){
  list *l = (list*)malloc(sizeof(list));
  l->begin = l->end = NULL;
  l->size = 0;
  return l;
}

node *new_node(double x,double y,double z){
  node *temp = (node*)malloc(sizeof(node));
  temp->next = NULL;
  temp->point.x = x;
  temp->point.y = y;
  temp->point.z = z;
  return temp;
}

void insert_list(list *l,double x,double y,double z){
  node *new = new_node(x,y,z);
  l->size++;
  if(l->begin == NULL){//Primeira inserção;
	l->begin = new;
  }
  else{
	l->end->next = new;
  }
  l->end = new;
}

void print_list(list *l){
  node *temp = l->begin;

  if(temp == NULL){
	printf("list empty\n");
	return;
  }
  int i = 0;
  while(temp != NULL){
		printf("x: %lf y: %lf z: %lf", temp->point.x,temp->point.y,temp->point.z);
		printf("\n");
		temp = temp->next;
		i++;
  }
  printf("numero de pontos: %d\n",i);
}

//funcao que le um arquivo e adiciona os dados numa lista
// void read_archive(char *name_archive){

//   FILE *ent;
//   int i=1;
//   node temp;
//   //garantir que a string de tamanho 2 SNo.tipo é terminada nula
//   // temp.tipo[1]='\0';
//   ent = fopen(name_archive,"r");
//   if(ent == NULL){
// 	printf("Check the file name and path!\n");
// 	exit(-1);
//   }
//   else{
// 	printf("\nFile successfully read!\n\n");
//   }
//   char buff[256];
//   //para cada linha do arquivo até o final
//   while((fgets(buff,256,ent))){
// 	if(strlen(buff)==255){
// 	  printf("Error, the line of a file can not exceed 256 characters\n");
// 	  exit(-1);
// 	}
// 	//captura uma string no max 30 caracteres, um inteiro, um caracter, outra string max 8 chars, e um float
// 		int res=sscanf(buff,"%lf,%lf,%lf",&temp.point.x,&temp.point.y,&temp.point.z);
// 		//se o scanf capturar 5 variávei, ou seja, a linha tem um formato válido
// 		if(res==3){
// 	  insert_list(linked_list.l,temp.point.x,temp.point.y,temp.point.z);
// 		}
// 	else{
// 	  printf("line% i of the file has an incorrect format and was ignored\n",i);
// 	}
// 	i++;
// 	}
// 	fclose(ent);
// }

void list_archive(list *l, const char *arc){
	FILE *arq = fopen(arc,"r");
	
	if(!arq){
		printf("nao abri o arquivo");
		return;
	}
	char str[256];
	int i=1;

	//para cada linha do arquivo até o final
	while((fgets(str,256,arq))){
		if(strlen(str)==255){
			printf("Error, the line of a file can not exceed 256 characters\n");
			return;
		}
		int n = 0;
		char *buff = str;
		int j = 0;
		while(1){
            double x,y,z;
		    buff+=n;

		    int res=sscanf(buff,"%lf %lf %lf%n",&x,&y,&z,&n);
			    
		    if(res!=3) break;    	

			insert_list(l,x,y,z);
			j++;
		}
		if(j == 0){
			printf("erro na linha %i: \n",i);
		}
		i++;
	}
	fclose(arq);
}