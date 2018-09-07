#include <stdio.h>
#include "dbPoint.h"


int readPoint(dbPoint *p, const char* str){

    int res=sscanf(str,"%lf %lf %lf",&p->x,&p->y,&p->z);

    return res==3;
}

void printPoint(){

	dbPoint p={0.,0.,0.};

    printf("%lf %lf %lf\n",p.x,p.y,p.z);
}