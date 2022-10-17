#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>

static int num_pos;

int criar(t_fila *fila) {
  fila->primeiro = NULL;
  fila->ultimo = NULL;
  num_pos = 0;
}

int enfileirar(t_fila *fila, t_elemento elemento) {
  
  t_apontador novo = (t_apontador) malloc(sizeof(t_no));

  if (novo == NULL) return ERRO_CHEIA;

  novo->elemento = elemento;
  novo->proximo = NULL;

  if (vazia(fila)) {
    fila->primeiro = novo;
  } else {
    fila->ultimo->proximo = novo;
  }

  fila->ultimo = novo;
  num_pos++;

  return SUCESSO;
}

int desenfileirar(t_fila *fila) {
  
  if (vazia(fila)) return NAO_ENCONTROU;

  if (fila->primeiro == fila->ultimo)
  fila->ultimo = NULL;

  t_apontador aux = fila->primeiro;
  fila->primeiro = fila->primeiro->proximo;
  free(aux);
  num_pos--;

  return SUCESSO;
}

t_no frente(t_fila *fila) {
  return *(fila->primeiro);
}

void imprimir(t_fila *fila) {

  if (fila->primeiro == NULL) return;

  t_apontador inicio = fila->primeiro;

  while(inicio != NULL) {
    printf("%d ", inicio->elemento.chave);
    inicio = inicio->proximo;
  }
  printf("\n");
  free(inicio);
}

int vazia(t_fila *fila) {
  if (fila->primeiro == NULL && fila->ultimo == NULL) return 1; 
  return 0;
}

int contar(t_fila *fila) {
  return num_pos;
}