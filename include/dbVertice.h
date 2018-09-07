#ifndef DB_VERTICE_H
#define DB_VERTICE_H

/*! Declaração da estrutura vértice, onde esta
  * contém um ponteiro do tipo "dbPoint" que é o ponto do vértice.
  *
  */
typedef struct dbVertice{

  dbPoint p;
  
  list *segmentos;


}dbVertice;

#endif /*DB_VERTICE_H*/
