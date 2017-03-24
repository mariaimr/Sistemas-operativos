/*  Neyder Leoncio Daza Cardona
    Maria Isabel Martinez Rendón
    micd --> chdir,fchdir
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "parser.h"


#define TAM 150

int main ()
{
  char ** items;
  int i, num, background, j;
  char expresion[TAM];
  char str1[TAM];
  char str2[TAM];
  char comandos[8][10] = {"mipwd","mils","mikill","micd","micp","miecho","miclr","mipause"};
  int ret,comparacion,status, h;
  char (*b)[10];

do{
    printf ("teclea_una_orden$ ");
    fgets (expresion, TAM, stdin);
    num = separaItems (expresion, &items, &background);
    strcpy(str1, "miexit");
    ret = strcmp(str1, items[0]);//si ingresa miexit
    if(ret==0)break;//sale del while

    b = (char(*)[10]) comandos[0];
    for(j=0 ;j<8; j++){
    	strcpy(str2,  (char *) (b + j));
    	comparacion=strcmp(str2, items[0]);
    	if(comparacion==0){
    		switch(j){
    			case 0: //mipwd
    				h= fork();//se crea un hijo
      				if (h==0){
        				execl("./pwd","./pwd",NULL);//se ejecuta el ejecutable pwd
        				exit(0);
     				}else{
       					wait(&status);// el padre espera a que el hijo finalice
     				}
     				j=7;
    			break;
    			case 1:
    				h= fork();//se crea un hijo
      				if (h==0){
        				execl("./ls","./ls ",items[1],NULL);//se ejecuta el ejecutable ls
        				exit(0);
     				}else{
       					wait(&status);// el padre espera a que el hijo finalice
     				}
     				j=7;
    			break;
    			case 2:
    				h= fork();//se crea un hijo
      				if (h==0){
        				execl("./kill","./kill ",items[1],items[2],NULL);//se ejecuta el ejecutable ls
        				exit(0);
     				}else{
       					wait(&status);// el padre espera a que el hijo finalice
     				}
     				j=7;
    			break;
    			case 3:
    				h= fork();//se crea un hijo
      				if (h==0){
        				execl("./cd","./cd ",items[1],NULL);//PREGUNTAR
        				exit(0);
     				}else{
       					wait(&status);// el padre espera a que el hijo finalice
     				}
     				j=7;
    			break;
    			case 4:
    				h= fork();//se crea un hijo
      				if (h==0){
      					printf("%s\n", items[1]);
      					printf("%s\n", items[2]);
        				execl("./cp","./cp",items[1],items[2],NULL);//se ejecuta el ejecutable ls
        				exit(0);
     				}else{
       					wait(&status);// el padre espera a que el hijo finalice
     				}
     				j=7;
    			break;
    			case 5:
    				h= fork();//se crea un hijo
      				if (h==0){
      					printf("%s\n", items[1]);
      					printf("%s\n", items[2]);
        				execl("./echo","./echo",items[1],items[2],NULL);//se ejecuta el ejecutable ls
        				exit(0);
     				}else{
       					wait(&status);// el padre espera a que el hijo finalice
     				}
     				j=7;
    			break;
    			case 6:
    			break;
    			case 7:
    			break;
    		}
    	}else{
    		if (j==7){
    			printf("Comando no encontrado\n");
    		}
    	}
    }
    printf ("Numero de parametros: %d\n", num);
  }while(ret !=0);// mientras la instruccion sea diferente de miexit 
  return 0;
}
