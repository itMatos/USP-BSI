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

*/

#define tam_read 30
int indicep1 = -1;
int indicep2 = -1;

void concatena(char *dna, char *aux, int tamanho, char *resposta) {
  
  char resultado[50];
  int j = 0;

  for (int i = tamanho; i < strlen(aux); i++) {
    resultado[j] = aux[i];
    j++;
  }

  j = 0;
  strcpy(resposta, dna);

  for (int k = strlen(dna); k < strlen(dna) + strlen(aux) - tamanho; k++) {
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

      aux = (char*) malloc((strlen(dna[j]))*(sizeof(char)));
      strcpy(aux, dna[j]);
      printf("auxx: %s \n", aux);


      // nao ta diminuindo a string aux [agora ta! :)]
      for (int k = strlen(dna[j]); k > 0; k--) {
        printf("entrei no for\n");
        char *ulisses = (char*) calloc(k , (sizeof(char)));
        

        for (int z = 0; z < k; z++) {
          ulisses[z] = aux[z];
        }
        printf("ulisses: %s \n", ulisses);
         

        char *ponteiro = strstr(dna[i], ulisses);

        if (ponteiro != NULL) {
          int overlap = strlen(ulisses);
            
          // printf("%d\n", overlap);

          if (overlap > maior_overlap) {

            maior_overlap = overlap;
            indicep1 = i;
            indicep2 = j;
            resposta = malloc((strlen(dna[i]) + strlen(dna[j]) - overlap - 1) *
                              sizeof(char));
            concatena(dna[i], dna[j], overlap, resposta);
            // printf("%s\n", resposta);
            break;
          }
        }
        free(ulisses);

      }
    }
  }
  free(aux);
  return resposta; // ta retornandoo NAO MEXE EM MAIS NADA DESSA PARTE
                   // kkkkkkkkkkk
}

int main(void) {
  int N;
  scanf("%d", &N);
  char **DNA;

  DNA = calloc((N) , sizeof(char *));
  for (int i = 0; i < N; i++) {
    DNA[i] = calloc(tam_read , sizeof(char));
  }
  char temp;
  for (int i = 0; i < N; i++) {
    scanf("%c", &temp);
    scanf("%[^\n]s", DNA[i]);
    printf("\n%s\n", DNA[i]);
  }

  // char *resposta = malloc(tam_read * sizeof(char));
  char **DNA_AUX;
  char *resultado;

  int primeiravez = 1;

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
          strcpy(DNA_AUX[i], DNA[j]);
          /* printf("DNA[J]: %s\n", DNA[j]);
          printf("aux: %s\n", DNA_AUX[i]); */
          jafoi = j;
          break;
        }

        
         
      }
    }    
    resultado = joao(DNA_AUX, N);
    // printf("resultado: %s\n", resultado);

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

  
   printf("%s", resultado);
  // free(resposta);
}

// ENTRADA
/*
3
atccat
ctgatc
ccatg

*/