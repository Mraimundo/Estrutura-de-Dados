#include "util.h"
#include<stdio.h>
#include<stdlib.h>


FILE *util_abre_arq(char *nome)
{
  FILE *f = fopen(nome,"r");
  if(f==NULL)
  {
    printf("Não foi possível abrir o arquivo: %s\n",nome);
    exit(1);
  }
  return f;
}