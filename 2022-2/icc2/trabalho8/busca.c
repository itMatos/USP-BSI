// Bruna Pereira Serrano da Mata | 13733579
// Italo de Matos Saldanha | 13717560
// Rafael Meris Manson | 13692438

#include <stdio.h>
#include <stdlib.h>

int result = 0;

void merge2(int vetor[], int comeco, int fim, int aux[]) {

  if (comeco >= fim) return;

  int meio = (comeco + fim) / 2;

  merge2(vetor, comeco, meio, aux);
  merge2(vetor, meio + 1, fim, aux);

  int esquerda = comeco;
  int direita = meio + 1;
  int i = 0;

  while (esquerda <= meio && direita <= fim) {
    if (vetor[esquerda] <= vetor[direita]) {
      aux[i] = vetor[esquerda];
      esquerda++;
    } else {
      aux[i] = vetor[direita];
      direita++;
    }
    i++;
  }

  while (esquerda <= meio) {
    aux[i] = vetor[esquerda];
    esquerda++;
    i++;
  }
  
  while (direita <= fim) {
    aux[i] = vetor[direita];
    direita++;
    i++;
  }

  i = 0;
  for (int j = comeco; j <= fim; j++) {
    vetor[j] = aux[i];
    i++;
  }
}

void merge(int vetor[], int tamanho_vetor) {
  int *aux = (int *)malloc(sizeof(int) * tamanho_vetor);

  merge2(vetor, 0, tamanho_vetor - 1, aux);

  free(aux);
}

void buscaBinaria(int valor, int vetor[], int comeco, int fim) {
  while(comeco<=fim){
    int meio = (comeco+fim)/2;
    if (valor == vetor[meio]) {
      result = 1;
      return;
    } else if (valor < vetor[meio])
      fim = meio - 1;
    else
      comeco = meio + 1;
  }
  return;
}

int main() {
  int N, K, valor;

  scanf("%d", &N);
  int vetorValores[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &valor);
    vetorValores[i] = valor;
  }

  merge(vetorValores, N);

  scanf("%d", &K);

  for (int j = 0; j < K; j++) {
    scanf("%d", &valor);
    buscaBinaria(valor, vetorValores, 0, N - 1);
    printf("%d\n", result);
    result = 0;
  }
}