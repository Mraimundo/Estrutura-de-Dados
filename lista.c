#include "lista.h"
#include "carta.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util.h"
#include <time.h>


void lst_pilha_to_pilha(Lista *L, Lista *R)
{
   Carta *ptr;
   for( ptr=L->topo; ptr != NULL  ; ptr = ptr->prox)
      lst_insere_fim(R,carta_cria(ptr->id,ptr->num,ptr->naipe));
}
=============================================================================================================================================================

 Lista *lst_cria(void)
 {
   Lista *l;
   l = (Lista*)malloc(sizeof(Lista));
   l->info=0;
   l->topo=NULL;

   return l;
 }  
============================================================================================================================================================

void lst_ler_arq(Lista *L, char *nome)
{
  Carta *C;
  int cont=0,n=0;
  FILE *p = util_abre_arq(nome);
  char naipe[10], linha[50], valor;

  while(!feof(p))
  {
    cont++;
    fgets(linha, 50, p);
    sscanf(linha,"%c %s",&valor, naipe );
    C = carta_cria( cont, valor, naipe);
    C->prioridade = n;
    lst_insere_fim(L, C);

    if(cont%4==0)
        n++;

  }
 fclose(p);
}
============================================================================================================================================================

 void lst_exibe(Lista *L)
 {
   Carta *ptr;
   for( ptr=L->topo; ptr != NULL  ; ptr = ptr->prox)
    printf("Id: %d Num: %c Naipe: %s Prioridade: %d\n",ptr->id,ptr->num, ptr->naipe, ptr->prioridade);
 }
=========================================================================================================================================================

// funções de lista
Lista *lst_cria2(void){
  Lista *l;
  l = (Lista*)malloc(sizeof(Lista));
  l->topo=NULL;
  l->info=0;
  return l;
}
===========================================================================================================================================================


// void lst_insere_inicio(List *L, Mat *novo);
 void lst_insere_fim(Lista *L, Carta *nova)
 {
   nova->prox = L->topo;
   L->topo=nova;
 }
=======================================================================================================================================================

 void lst_insere_inicio(Lista *L, Carta *novo)
  {
    Carta *ptr;
    for(ptr=L->topo; ptr->prox!=NULL; ptr=ptr->prox);

    novo->prox = NULL;
    ptr->prox = novo;
 }
=======================================================================================================================================================

// void lst_insere_pos(List *L, Mat *novo);
void lst_exibe_elementos(Lista *L)
{
  Carta *ptr;
  for(ptr=L->topo; ptr!=NULL;ptr=ptr->prox)
  {
    printf("Nº %2d: Carta: %c  Naipe: %s Prioridade: %d\n",ptr->id,ptr->num, ptr->naipe, ptr->prioridade);
  }
}
======================================================================================================================================================

void lst_ler_arq(Lista *L, char *nome)
{
  FILE *p;
  Carta *C;
  p= util_abre_arq(nome);
  int id=0;
  char num;
  char naipe[10];
  do{
    id++;
    fgets(nome,MAX_IN,p);
    if(!feof(p))
    nome[strlen(nome)-1]='\0';
    else
    nome[strlen(nome)]='\0';
    sscanf(nome,"%c%s",&num,naipe);
    C = carta_cria( id,  num, naipe);
    lst_insere_fim(L, C);

  }while(id<40 && !feof(p));

}
====================================================================================================================================================
void lst_libera(Lista *L)
{
  Carta *p;
  for( ; L->topo!=NULL; )
  {
    p = L->topo;
    L->topo = p->prox;
    free(p);
  }
  L->topo=NULL;
  free(L);
}
======================================================================================================================================================
Lista *lst_embaralha(Lista *L)
{
  srand(time(NULL));
  Lista *R;
  int i=0,n;
  Carta *C,*C2;
  R = lst_cria();
  while(i<40)
  {
    n = rand()%40+1;
    C = lst_busca(L,n);
    if(C ==NULL) 
      continue;
      i++;

    C2 = carta_cria(C->id, C-> num, C->naipe);
    C2->prioridade = C->prioridade;
    lst_insere_fim(R, C2);
   
  }
  return R;
}
===================================================================================================================================================

Carta *lst_busca(Lista *L, int n)
{
  Carta *c;
  for(c=L->topo; c != NULL;c = c->prox)
  {
    if(c->id == n)
    {
      if(c->flag == 1)
        return NULL;
      else {
        c->flag=1;
        return c;
      }
    }
  }
  return NULL;
}
================================================================================================================================================

void lst_zera_flag(Lista *L)
{
  Carta *c;
  for(c=L->topo; c != NULL;c = c->prox)
  {
    c->flag=0;
  }
}
================================================================================================================================================