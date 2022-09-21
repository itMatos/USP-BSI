#include <stdio.h>
#include <stdlib.h>

typedef int apontador;
typedef int indice;
typedef int contador;
 
typedef struct {
 contador trocas;
 contador comparacoes;
} resultado;
 
resultado insertionResult = { 0, 0 };
resultado mergeResult = { 0, 0 };
 
void insercao (int vetor[], int tamanho_vetor);
void merge2 (int vetor[], int comeco, int fim, int aux[]);
void merge (int vetor[], int tamanho_vetor);
void lerValores(int n_vetores, int tamanhos[]);

int main(){

    //quantidade de vetores
    int n_vetores;
    scanf("%d", &n_vetores);
    
    //recebendo o tamanho de cada vetor
    int tamanhos[n_vetores];
    for (int i = 0; i < n_vetores; i++){
    scanf("%d", &tamanhos[i]);
    }
    
    //lendo os valores do vetor e chamando as funcoes
    lerValores(n_vetores, tamanhos);
    
    return 0;
}

void insercao(int vetor[], int tamanho_vetor){
   contador comp = 0, troca = 0;

   for(indice posicao = 1; posicao < tamanho_vetor; posicao++){
       int swap = vetor[posicao];
       troca++;
       indice i = posicao-1;
     
       while(i >= 0 && swap < vetor[i]){ //i nao chegou no fim e o que reservei ainda eh menor que a posicao que eu quero colocar ele
           comp++;
           vetor[i+1] = vetor[i];
           troca++;
           i--;
       }
       if(swap>=vetor[i] && i>=0){
           comp++;
       }

       vetor[i+1] = swap;
       troca++;
   }

   insertionResult.trocas = troca;
   insertionResult.comparacoes = comp;
   printf("I %d %d %d\n", tamanho_vetor, insertionResult.trocas, insertionResult.comparacoes);
}
 
void merge2(int vetor[], int comeco, int fim, int aux[]){
   contador comp = 0, troca = 0;

   //caso base (vetor tam 0 ou 1 ja ordenado)
   if(comeco >= fim) return;

   //posicao central do vetor
   int meio = (comeco+fim)/2;

   //chamando a funcao ate diminuir o vetor
   merge2(vetor, comeco, meio, aux); //do comeco ate a metade
   merge2(vetor, meio+1, fim, aux); // da metade ate o fim
   //deu return volta pra ca

   //---------- comecando a ordenar ------------ */

   apontador esquerda = comeco; //comeco do vetor da esquerda
   apontador direita = meio + 1; //comeco do vetor da direita
   indice i = 0; //indice do vetor auxiliar

   //ordenando e jogando pro vetor auxiliar
   while(esquerda <= meio && direita <= fim){
       comp++;
       if(vetor[esquerda] <= vetor[direita]){
           aux[i] = vetor[esquerda];
           troca++;
           esquerda++;
       } else{
           aux[i] = vetor[direita];
           troca++;
           direita++;
       } i++;
   }

   //atribuindo o restante do vetor da esquerda (se o da direita acabar antes dele)
   while(esquerda<=meio){
       aux[i] = vetor[esquerda];
       troca++;
       esquerda++;
       i++;
   }

   //atribuindo o restante do vetor da direita (se o da esquerda acabar antes dele)
   while(direita <= fim){
       aux[i] = vetor[direita];
       troca++;
       direita++;
       i++;
   }
   
   //devolvendo do vetor auxiliar pro vetor original
   i=0;
   for(indice j = comeco; j <= fim; j++){
       vetor[j] = aux[i];
       troca++;
       i++;
   }
 
   mergeResult.comparacoes += comp;
   mergeResult.trocas += troca;
}

void merge(int vetor[], int tamanho_vetor){
   int *aux = (int *) malloc(sizeof(int)  * tamanho_vetor);
 
   mergeResult.trocas = 0;
   mergeResult.comparacoes = 0;
 
   merge2(vetor, 0, tamanho_vetor-1, aux);
 
   free(aux);
   printf("M %d %d %d\n", tamanho_vetor, mergeResult.trocas, mergeResult.comparacoes);
}
 
void lerValores(int n_vetores, int tamanhos[]) {
 
 for (int i = 0; i < n_vetores; i++){
   int ordenarMerge[tamanhos[i]];
   int ordenarInsertion[tamanhos[i]];
   int valor;

   for(int j = 0; j < tamanhos[i]; j++){
     scanf("%d", &valor);
     ordenarInsertion[j] = valor;
     ordenarMerge[j] = valor;
   }
 
   insercao(ordenarInsertion, tamanhos[i]);
   merge(ordenarMerge, tamanhos[i]);
 }
}