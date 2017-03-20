/*  Neyder Leoncio Daza Cardona
    Maria Isabel Martinez Rendón
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "parser.h"

#define TAM 100

int main ()
{
  char ** items;
  int i, num, background;
  char expresion[TAM];
  char str1[TAM];
  char str2[TAM];
  int ret,comparacion,status;

do{
    printf ("teclea una orden$ ");
    fgets (expresion, TAM, stdin);
    num = separaItems (expresion, &items, &background);
    strcpy(str1, "miexit");
    ret = strcmp(str1, items[0]);//si ingresa miexit
    if(ret==0)break;//sale del while
    strcpy(str2, "mipwd");
    comparacion=strcmp(str2, items[0]);
    if(comparacion==0){//si es mipwd
      int h= fork();//se crea un hijo
      if (h==0){
        execl("./pwd","./pwd",NULL);//se ejecuta el ejecutable pwd
        exit(0);
     }else{
       wait(&status);// el padre espera a que el hijo finalice
     }
      
    }
    printf ("Numero de parametros: %d\n", num);
  }while(ret !=0);// mientras la instruccion sea diferente de miexit 
  return 0;
}
