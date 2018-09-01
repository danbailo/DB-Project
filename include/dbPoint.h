#ifndef DBPOINT_H
#define DBPOINT_H

/*! Declaração da estrutura ponto, onde esta
  * contém os elementos x, y e z referentes ao espaço tridimensional;
  */
typedef struct dbPoint{

  double x,y,z;

}dbPoint;

void print_point();

#endif /*DBPOINT_H*/
