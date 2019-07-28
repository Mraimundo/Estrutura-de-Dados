#include "carta.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


 
Carta *carta_cria(int id, char num, char *naipe)
{
  Carta *c = (Carta*)malloc(sizeof(Carta));
  strcpy(c->naipe,naipe);
  c->id=id;
  c->flag=0;
  c->num=num;
  return c;
}
===============================================================================================================================================================

/**************************************
 * 0: Empate, 1: C1 Ganha, 2: C2 Ganha
 **************************************/
int prioridade(Carta *C1, Carta *C2, char manilha)
{
    if(C1->num != manilha && C2->num != manilha)
    {
        if(C1->prioridade>C2->prioridade)
            return 1;
        else if(C1->prioridade<C2->prioridade)
            return 2;
        else
            return 0;
    }

    else if(C1->num == manilha && C2->num != manilha)
        return 1;

    else if(C2->num == manilha && C1->num != manilha)
        return 2;

    else
    {
        if(strcmp(C1->naipe, "Paus") == 0)
            return 1;
        else if(strcmp(C2->naipe, "Paus") == 0)
            return 2;

        else if(strcmp(C1->naipe, "Copas") == 0)
            return 1;
        else if(strcmp(C2->naipe, "Copas") == 0)
            return 2;

        else if(strcmp(C1->naipe, "Espada") == 0)
            return 1;
        else if(strcmp(C2->naipe, "Espada") == 0)
            return 2;

        else
            return 0;
    }
}
==============================================================================================================================================================

int jogoManual(Lista *L)
{
  Lista *R; // ponteiro para carta embaralhadas no inicio de cada rodada
  Carta *Vira; // a carta vira do turno
  char manilha, opcao; // a manilha do turno
  int i, n; // contador para a posição do jogar que irá inicia a rodada
  Jogador *A1, *A2, *B1, *B2;// os jogadores dos dois grupos
  Jogador *J, *J1;// j - é o jogador atual, j1 - é o jogador que iniciou a rodada 
  int gA; // pontos do grupoA do turno
  int gB; // pontos do grupoA do Jogo

  A1= (Jogador*)malloc(sizeof(Jogador));
  A2= (Jogador*)malloc(sizeof(Jogador));
  B1= (Jogador*)malloc(sizeof(Jogador));
  B2= (Jogador*)malloc(sizeof(Jogador));
  A1->prox=B1;// lista circular
  B1->prox=A2;//     |----B2<------
              //     V             |
  A2->prox=B2;//    A1            A2
             //      |             ^
  B2->prox=A1;//     |---->B1------|


  i = rand()%4;
  J = busca_pos(A1,i);
  
   do
   {
      opcao = menu();
      printf("Jogador Inicial: %d : %s\n",i,J->nome);
      if(opcao == 0)
        break;
      else if (opcao == 1)
        insereNomes(A1);
     
      do
      {
        R = lst_embaralha(L);
        Vira = distribui(R->topo,J);
        // chama turno()
        n = turno(R,J, manilha);
        switch (n)
        {
        case 0:
          break;
        case 1:
          break;
        case 2:
          break;
        }
        free(R);
      }while(1);
    
      
  }while(1);
return 0;
}
===========================================================================================================================================================
int rodada(Lista *R, Jogador *J, char manilha)
{
  int x;
   Jogador *Jaux, *ini;
  x = menu1();
  // 0 - Empate
  // 1 - grupo A ganhou
  // 2 - grupo B ganhou
  return x;
}
==========================================================================================================================================================


int turno(Lista *R, Jogador *J, char manilha)
{
  int pA;// pontos do grupoB do turno
  int pB; // pontos do grupoB do Jogo
  do
  {
    

  }while(1);
}
==========================================================================================================================================================
Jogador *busca_pos(Jogador *Inicio, int n)
{
  int i;
  for(i=0; i<4; i++, Inicio= Inicio->prox)
  {
    if(i == n)
      return Inicio;
  }
  return NULL;
}
==========================================================================================================================================================
void exibeJogo(Jogador *j)
{
  int i;
  printf("Jogador: %s",j->nome);
  printf("Cartas");
  for(i=0; i<3; i++)
  {
    if(j->cartas[i]!=NULL)
      printf("%d: %c : %s \n", i, j->cartas[i]->num, j->cartas[i]->naipe);
  }
  printf("\n");
}
=======================================================================================================================================================
int menu1()
{
  int i;
  do{
     printf("Escolha uma das opção:\n");
     printf("0 - Jogar Carta Virada\n");
     printf("1 - Jogar\n");
     printf("2 - Trucar\n");
     scanf("%d",&i);
  }while(i<0 && i>2);
  return i;
}

======================================================================================================================================================
int menu2()
{
  int i;
  do{
     printf("Escolha uma opção:\n");
     printf("0 - Recusa e paga\n");
     printf("1 - Aceita\n");
     printf("2 - Aumenta a aposta\n");
     scanf("%d",&i);
  }while(i<0 && i>2);
  return i;
}
=======================================================================================================================================================
int menu3(Jogador *j)
{
  int i;
  printf("\n");
  do{
     printf("Escolha uma opção:\n");
     //printf("0 - Jogar Carta Virada\n");
     //printf("1 - Jogar\n");
     //printf("2 - Trucar\n");
     for(i=0; i<3; i++)
     {
        if(j->cartas[i]!=NULL)
        printf("%d - Jogar a carta %d\n", i, i);
     }
     scanf("%d",&i);
  }while(i<0 && i>2);
  return i;
}
=======================================================================================================================================================

int menu()
{
  int i;
  do{
     printf("Escolha uma opção:\n");
     printf("0 - sair\n");
     printf("1 - jogar\n");
     printf("2 - Inserir nomes\n");
     scanf("%d",&i);
  }while(i<0 && i>2);
  return i;
}
=======================================================================================================================================================
Carta *distribui(Carta *R, Jogador *J)
{
  Carta *C = R;
   Jogador *j1;
  int i,j;
  for(i=0; i<3; i++)
  {
    j1 = J;
    for(j=0; j<4; j++, C = C->prox)
    {
      j1->cartas[i]= C;
      j1=j1->prox;
    }
   
  }
  return C->prox;
}
======================================================================================================================================================
void insereNomes(Jogador *J)
{
  printf("Digite o nome do jogador 1 do grupo A: ");
  gets(J->nome);
  J = J->prox;
  printf("Digite o nome do jogador 2 do grupo A: ");
  gets(J->nome);
  J = J->prox;
  printf("Digite o nome do jogador 1 do grupo B: ");
  gets(J->nome);
  J = J->prox;
  printf("Digite o nome do jogador 2 do grupo B: ");
  gets(J->nome);

}
======================================================================================================================================================