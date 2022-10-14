#ifndef LISTA_H
#define LISTA_H

#define JA_EXISTE -2
#define NAO_ENCONTROU -1
#define ERRO_CHEIA 0
#define SUCESSO 1

typedef int t_chave;

typedef struct t_elemento {
  t_chave chave;
  char nome[50];
} t_elemento;

typedef struct t_no *t_apontador;

typedef struct t_no {
  t_elemento elemento;
  t_apontador proximo;
} t_no;

typedef struct {
  t_apontador primeiro;
  //t_apontador ultimo;
} t_lista;

#endif // !LISTA_H