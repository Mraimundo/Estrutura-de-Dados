#ifndef CARTA_H
#define CARTA_H

// Tipos definidos pelo usuário
typedef struct carta Carta;


struct carta{
	int id;
  int prioridade;
  char flag;
	char num;
	char naipe[10];
	struct carta *prox;
};

typedef struct jogador Jogador;

struct jogador{
  int id;
  char nome[50];
  char grupo;
  Carta *cartas[3];
  struct jogador *prox;
};


// declarações das funções
Carta *carta_cria(int id, char num, char *naipe);
Carta *distribui(Carta *R, Jogador *J);
int jogoManual(Lista *L);
int prioridade(Carta *C1, Carta *C2, char manilha);
Jogador *busca_pos(Jogador *Inicio, int n);
int turno(Lista *R, Jogador *J, char manilha);
int rodada(Lista *R, Jogador *J, char manilha);
int menu();
int menu1();
int menu2();
int menu3(Jogador *j);
void insereNomes(Jogador *J);
void exibeJogo(Jogador *j);

#endif