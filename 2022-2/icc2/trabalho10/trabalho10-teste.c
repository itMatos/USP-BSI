#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Ta dando certooooo :D

// ENTRADA
/*
3
atccat
ctgatc
ccatg

tttcattg
ttgaaaac
aagtacaca
*/

#define tam_read 200
int indicep1 = -1;
int indicep2 = -1;

void concatena(char *dna, char *aux, char *resposta , int tamanho) {
  char *resultado = malloc((tam_read*100) * sizeof(char));
  int j = 0;

  /* for (int i = tamanho; i < strlen(aux); i++) {
    resultado[j] = aux[i];
    j++;
  } */
  strcpy(resultado, aux);

  j = 0;
  strcpy(resposta, dna);

  for (int k = strlen(dna) - tamanho; k < strlen(dna) + strlen(aux) - tamanho; k++) {
    resposta[k] = resultado[j];
    j++;
  } 

}

char *joao(char **dna, int N) {

  int maior_overlap = -1;
  char *resposta;
  char *aux;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
       if (i == j)
        continue; 

      aux = calloc((strlen(dna[j])*100),(sizeof(char)));
      strcpy(aux, dna[j]);


      // nao ta diminuindo a string aux [agora ta! :)]
      for (int k = strlen(dna[j]); k >= 0; k--) {
        int sai = 0;
        char *ulisses; 
        ulisses = calloc(k*100, (sizeof(char)));
        
        for (int z = 0; z < k; z++) {
          ulisses[z] = aux[z];
        }

         
        char *ponteiro = strstr(dna[i], ulisses);
        //if(strlen(ulisses)==0) *ponteiro = 0;

        if (ponteiro != NULL) {
          int overlap = strlen(ulisses);
          int contador = 0;

          
          for(int p = strlen(dna[i])-overlap; p<strlen(dna[i]); p++){
            if(ulisses[contador] != dna[i][p]){
              sai = 1;
            }
            contador++;
          }
          if(sai == 1 && overlap>1){
            free(ulisses);
            continue;
          }
            

          if (overlap > maior_overlap && sai != 1) {

            maior_overlap = overlap;
            indicep1 = i;
            indicep2 = j;
            if(resposta!=NULL) free(resposta);
            resposta = calloc((strlen(dna[i]) + strlen(dna[j])*10000) , sizeof(char));
            concatena(dna[i], dna[j], resposta, overlap);
            // printf("%s\n", resposta);
            sai = 1;
          }
        }
        if(sai == 1){
            free(ulisses);
            break;
          }
      }
    }
  free(aux);
  }
  return resposta; // ta retornandoo NAO MEXE EM MAIS NADA DESSA PARTE
                   // kkkkkkkkkkk
}

int main(void) {
  int N;
  scanf("%d", &N);
  char DNA[N][tam_read];
  char temp;
  for (int i = 0; i < N; i++) {
    scanf("%c", &temp);
    scanf("%[^\n]s", DNA[i]);
  }

  // char *resposta = malloc(tam_read * sizeof(char));
  char **DNA_AUX;
  char **DNA_AUX_AUX;
  char *resultado;

  int primeiravez = 1;

  DNA_AUX_AUX = malloc((N + 1) * sizeof(char *));
    for (int i = 0; i < N; i++) {
      DNA_AUX_AUX[i] = malloc((tam_read + 1) * sizeof(char));
    }

  for(int i=0; i<N; i++){
      strcpy(DNA_AUX_AUX[i], DNA[i]);
    }

  while (N > 1) {
    // free(resposta);

    DNA_AUX = malloc((N + 1) * sizeof(char *));
    for (int i = 0; i < N; i++) {
      DNA_AUX[i] = malloc((tam_read + 1) * sizeof(char));
    }
    
    int jafoi = -1;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N + 1; j++) {
        if(i==0 && primeiravez == 0){
          strcpy(DNA_AUX[i], resultado);
          break;
        }
        else if (j != indicep1 && j != indicep2 && j>jafoi) {
          strcpy(DNA_AUX[i], DNA_AUX_AUX[j]);
          jafoi = j;
          break;
        }
         
      }
    }

    for (int i = 0; i < N; i++) {
      free(DNA_AUX_AUX[i]);
    }
    free(DNA_AUX_AUX);

    
    resultado = joao(DNA_AUX, N);



    DNA_AUX_AUX = malloc((N + 1) * sizeof(char *));
    for (int i = 0; i < N; i++) {
      DNA_AUX_AUX[i] = malloc((tam_read + 1) * sizeof(char));
    }

    for(int i=0; i<N; i++){
      strcpy(DNA_AUX_AUX[i], DNA_AUX[i]);
    }
    for (int i = 0; i < N; i++) {
      free(DNA_AUX[i]);
    }
    free(DNA_AUX);

    N--;
    primeiravez = 0;
  }
  for (int i = 0; i < N; i++) {
      free(DNA[i]);
    }
    free(DNA);

    for (int i = 0; i < N; i++) {
      free(DNA_AUX_AUX[i]);
    }
    free(DNA_AUX_AUX);

  
   printf("%s", resultado);
  // free(resposta);
}

// ENTRADA
/*
3
atccat
ctgatc
ccatg

5
catg
ctaagt
gcta
ttca
atgcatc

3 
cttaaaaaggttt
ttccagg
aaaaggttcaa

3
tttcattg
ttgaaaac
aagtacaca

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