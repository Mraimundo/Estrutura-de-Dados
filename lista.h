#include "carta.h"

#ifndef LISTA_H
#define LISTA_H

// Tipos definidos pelo usuário
typedef struct lista Lista;

// definição da struct lista de matrizes
struct lista{
 int info;	
 Carta *topo;
};


// declarações das funções

// funções de lista
 Lista *lst_cria2(void);

 Lista *lst_cria(void);
void lst_pilha_to_pilha(Lista *L, Lista*R);
void lst_insere_fim(Lista *L, Carta *nova);
Lista *lst_embaralha(Lista *L);
void lst_exibe(Lista *L);
Carta *lst_busca(Lista *L, int n);
void lst_zera_flag(Lista *L);
List *lst_busca(List *L, int pos);
List *lst_busca(List *L, char *nome);
List *lst_remove_fim(List *L, int pos);
List *lst_remove_fim(List *L, char *nome);
List *lst_remove_inicio(List *L, int pos);
List *lst_remove_inicio(List *L, char *nome);
List *lst_remove_pos(List *L, int pos);
List *lst_remove_pos(List *L, char *nome);

#endif