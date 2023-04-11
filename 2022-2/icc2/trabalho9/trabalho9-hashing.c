#include <stdio.h>

int hashing(int valor, int m, int *vetor) {
  int posicao = valor % m;
  printf("%d\n", posicao);
  return posicao;
}

void inserir(int valor, int m, int *vetor){
  int posicao = hashing(valor, m, vetor);
  while(vetor[posicao] != -1){
    posicao = (posicao + 1) % m;
  }
  vetor[posicao] = valor;
}

int buscar(int valor, int m, int *vetor){
  int posicao = hashing(valor, m, vetor);
  int i = posicao;

  if(vetor[posicao] == valor)
      return posicao;
  posicao = (posicao + 1) % m;
  
  while (posicao != i) {
    if(vetor[posicao] == valor)
      return posicao;
    posicao = (posicao + 1) % m;
  }
  printf("Nao achei o %d\n", valor);
  return -1;
}

void remover(int valor, int m, int *vetor){
  int posicao = buscar(valor, m, vetor);
  if (posicao != -1) {
    vetor[posicao] = -1;
  }
}

int main(void) {
  int m;
  scanf("%d", &m);
  int hash[m];

  for(int i = 0; i < m; i++){
    hash[i] = -1;
  }

  int N;
  int valor;
  scanf("%d", &N);
  for(int i = 0; i<N; i++){
    scanf("%d", &valor);
    inserir(valor, m, hash);
  }
  // for(int i=0; i < m; i++){
  //   printf("v[%d]: %d\n",i, hash[i]);
  // }

  int D;
  scanf("%d", &D);
  for(int i=0; i<D; i++){
    scanf("%d", &valor);
    remover(valor, m, hash);
  }

  // for(int i=0; i < m; i++){
  //   printf("v[%d]: %d\n",i, hash[i]);
  //  }

  // int B;
  // scanf("%d", &B);
  // for(int i=0; i<B; i++){
  //   scanf("%d", &valor);
  //   printf("%d ", buscar(valor, m, hash));
  // }

  return 0;
  }