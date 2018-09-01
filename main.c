#include<stdio.h>
#include"lib.h"

/*! Test function*/
int function(int var){
   var = var * 2; /**<A variavel "var" recebe ela mesmo vezes 2*/
   return var;
}
/** \brief Descrição em breve.
*
* Função main
*/
int main(){

   int var; /*!< Detailed description after the member */

   printf("Hello");

   return 0;
}
