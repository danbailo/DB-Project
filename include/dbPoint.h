#ifndef DBPOINT_H
#define DBPOINT_H

/*! Declaração da estrutura ponto, onde esta
  * contém os elementos x, y e z referentes ao espaço tridimensional;
  */
typedef struct dbPoint{

  double x,y,z;

}dbPoint;

void getPoint(double x1, double y1, double z1);
int readPoint(dbPoint *p,const char* str);
void printPoint();

#endif /*DBPOINT_H*/
