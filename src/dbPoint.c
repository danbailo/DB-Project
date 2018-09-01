#include <stdio.h>
#include "dbPoint.h"

void getPoint(double x, double y, double z){
	dbPoint p;

    p.x = x;
   	p.y = y;
    p.z = z;
}

int readPoint(const char* str){
	dbPoint p;

    int res=sscanf(str,"%lf %lf %lf",&p.x,&p.y,&p.z);

    if(res!=3)
    	printf("menos de 3 pontos numa linha\n");

    return res;
}

void printPoint(){

	dbPoint p;

    printf("%lf %lf %lf\n",p.x,p.y,p.z);
}