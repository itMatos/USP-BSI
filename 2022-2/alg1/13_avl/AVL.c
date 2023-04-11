#include "AVL.h"
#include <stdio.h>
#include <stdlib.h>

static int max(int a, int b) {
  return a > b ? a : b;
}

static void rotacao_esq(t_avl *avl) {
  t_apontador j, B;

  // filho a esquerda da raiz
  j = (*avl)->esq;
  // filho a direita da raiz;
  B = j->dir;

  //
}