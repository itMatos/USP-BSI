// Bruna Pereira Serrano da Mata | 13733579
// Italo de Matos Saldanha | 13717560
// Rafael Meris Manson | 13692438

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return a > b ? a : b; }

// Armazena o caminho total (maior soma para o caminho i x j)
int robson(int *chace, int **matriz, int totalEsquinas, int i, int j,
           int folunaFinal) {

  int somaAmigos = 0;
  if (j <= totalEsquinas && chace[j] == -1) {

    // caso base (ultapassou a matriz)
    if (i >= totalEsquinas || j >= totalEsquinas) {
      return somaAmigos;

      // nao existe o caminho ou eu estou na posicao final (B)
    } else if (matriz[i][j] == -1 || (i == totalEsquinas -1 && j == totalEsquinas-1)) {
      return somaAmigos;
    }

    else {
      i = j;
      // duas possibilidades: direita ou baixo
      // so anda se estiver dentro da matriz e existir um caminho para o proximo
      int pra_direita = 0;
      int proximo = j + 1;
      if (proximo < totalEsquinas && matriz[i][proximo] != -1) {
        pra_direita = matriz[i][proximo] + robson(chace, matriz, totalEsquinas,
                                                  i, proximo, folunaFinal);
      }

      int pra_baixo = 0;
      int proximo_baixo = j + folunaFinal;
      if (proximo_baixo < totalEsquinas && matriz[i][proximo_baixo] != -1) {
        pra_baixo =
            matriz[i][proximo_baixo] +
            robson(chace, matriz, totalEsquinas, i, proximo_baixo, folunaFinal);
      }

      somaAmigos = max(pra_direita, pra_baixo);
      chace[j] = somaAmigos;
    }

  } else {// se chace ja ta preenchido so pega o maior valor
    somaAmigos = chace[j];
    }

  return somaAmigos;
}

// Conta os amigos
int rogerio(int **matriz, int totalEsquinas, int linhas, int colunas) {

  //chace vai armazenar o melhor caminho pra cada esquina
  int *chace = malloc(totalEsquinas * sizeof(int));
  for (int i = 0; i < totalEsquinas; i++) {
    chace[i] = -1;
  }

  int somaAmigos = robson(chace, matriz, totalEsquinas, 0, 0, colunas);

  free(chace);
  return somaAmigos;
}

int main(void) {
  int qntLinhas, qntColunas;
  int linha, coluna, amigos;
  scanf("%d %d", &qntLinhas, &qntColunas); // Lê quantidade de linhas e colunas

  int totalEsquinas = qntLinhas * qntColunas;
  int totalRuas = qntColunas * (qntLinhas - 1) + qntLinhas * (qntColunas - 1);

  // alocando a matriz que guarda os amigos fixos
  int **matriz = malloc(totalEsquinas * sizeof(int *));
  for (int i = 0; i < totalEsquinas; i++) {
    matriz[i] = malloc(totalEsquinas * sizeof(int));
    for (int j = 0; j < totalEsquinas; j++) {
      matriz[i][j] = -1;
    }
  }

  // preenchendo a matriz com os amigos
  for (int i = 0; i < totalRuas; i++) {
    scanf("%d %d %d", &linha, &coluna, &amigos);
    matriz[linha][coluna] = amigos;
  }

  matriz[0][0] = 0;
  printf("%d\n", rogerio(matriz, totalEsquinas, qntLinhas, qntColunas));

  for(int i=0; i<totalEsquinas; i++){
    free(matriz[i]);
  }
  free(matriz);
  return 0;
}