#include <stdio.h>
#include "dbPoint.h"

Point::Point(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}
void read_point(const char* str){
    int res=sscanf(str,"%lf %lf %lf",&x,&y,&z);
    if(res!=3) throw "menos de 3 pontos numa linha";
}

void print_point(){
    printf("%lf %lf %lf\n",x,y,z);
}
