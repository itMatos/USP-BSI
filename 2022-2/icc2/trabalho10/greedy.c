// Bruna Pereira Serrano da Mata | 13733579
// Italo de Matos Saldanha | 13717560
// Rafael Meris Manson | 13692438

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam_read 200

// Processa todas as N cadeias de DNA, unificando-as.
char *processa(char **DNA, int N);

// Junta 2 pedaços de cadeias com o maior overlap possível.
char *junta(char *pedaco1, char *pedaco2);

int main(void) {

  int N;
  scanf("%d", &N);

  char **DNA = malloc(N * sizeof(char *));
  for (int i = 0; i < N; i++) {
    DNA[i] = malloc(tam_read*sizeof(char));
    scanf("%s", DNA[i]);
  }

  char *resposta = processa(DNA, N);
  printf("%s\n", resposta);
  free(resposta);

  return 0;
}

char *processa(char **DNA, int N) {

  if(N == 1){
    return DNA[0];
  }

  char *resposta = malloc(tam_read);
  int indice_p1, indice_p2, maior_overlap = -1;

  // for(int i = 0; i < N; i++) {
  //   printf("\n%s", DNA[i]);
  // }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j)
        continue;
      
      char *juncao = junta(DNA[i], DNA[j]);
      //if (!juncao) juncao = 0;
      int overlap = strlen(DNA[i]) + strlen(DNA[j]) - strlen(juncao);
      // printf("\noverlap %d", overlap);

      if(overlap > maior_overlap){
        maior_overlap = overlap;
        indice_p1 = i;
        indice_p2 = j;
        strcpy(resposta, juncao);
        //printf("%s\n", resposta);
      }
      
    }  
  }
  
  char **DNA_AUX;
  DNA_AUX = malloc((N-1) * sizeof(char*));

  for(int i = 0; i < N-1; i++){
    DNA_AUX[i] = malloc(tam_read * sizeof(char));
  }
  strcpy(DNA_AUX[0], resposta);
  
  for(int i = 0, j = 1; i < N; i++){
    if(i != indice_p1 && i != indice_p2){
      strcpy(DNA_AUX[j], DNA[i]);
      j++;
    }
  }

  for(int i = 0; i < N; i++) {
    free(DNA[i]);
  }
  free(DNA);
  return processa(DNA_AUX, N-1);
}

char  *junta(char *string1, char *string2) {
  int tamString1 = strlen(string1);
  int tamString2 = strlen(string2);
  char *resultado = calloc((tamString1 + tamString2+1), sizeof(char));

  int j = 0; //indice da string 2
  int p; //indice pra fazer a copia
  for(int i = 0; i < tamString1; i++) {
    int deuBreak = 0;
    int k = i;
    //entra se os caracteres forem iguais ou se i estiver na ultima posicao
    if (string1[i] == string2[j] || i == tamString1 - 1) {
      while(string1[k] != '\0' && string2[j] != '\0') {

        //a medida q os caracteres sao iguais, avanca ambos e continua comparando
        if (string1[k] == string2[j]){
          k++;
          j++;
        }
        //se n for igual, j reinicia pra posicao 0 e i atualiza pra posicao k, deuBreak faz voltar para o loop do for
        else{
          j = 0;
          //i = k;
          deuBreak = 1;
          break;
        }
      }

      if (deuBreak && i != tamString1-1) continue;

      //se houve overlap (j andou pelo menos uma posicao)
      if (j > 0) {
        p = i;
      }

      //se nao houve overlap
      else{
        p = tamString1;
      }

      //p eh o indice em que vai comecar a copiar no resultado

      int m = 0;
      strcpy(resultado, string1);
      while(string2[m] != '\0') {
        resultado[p] = string2[m];
        m++;
        p++;
      }
      return resultado;
    }
  }
  return string1;
}

/*
5
catg
ctaagt
gcta
ttca
atgcatc

5
cattcga
gtcagcatgcattcgagcatattagcgatc
tacgacgtctcagcatcatca
tacgg
tacggcagcatcatca


12
aaaaa
tttttttttt
cccccccccccccccccccc
gggggggggggggg
at
tc
cg
ga
ta
ct
gc
ag
*/