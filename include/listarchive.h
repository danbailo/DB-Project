#ifndef LISTARCHIVE_H
#define LISTARCHIVE_H

#include <stdlib.h>
#include "dbPoint.h"

typedef struct node{

  double x,y,z;
  int index;
  struct node *next;

}node;

typedef struct list{

  node *begin;
  node *end;
  int size;

}list;

struct linked_list{

  list *l;

}linked_list;

list *create_list();
node *new_node(double x,double y,double z);
void insert_list(list *l,double x,double y,double z);
int GetNth(list *l, int index);
void print_list(list *l);
void read_archive(char *name_archive);
void list_archive(const char *arc);

#endif /*LISTARCHIVE_H*/
