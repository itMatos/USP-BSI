#include <stdio.h>
#include <stdlib.h>

void printfArray(int *array, int size) {
  for (int i = 0; i < size; i ++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void insertionSort (int *array, int size) {
  for (int p = 1; p < size; p++) {
    int aux = array[p];
    int i = p - 1;

    printf("i: %d -- p: %d \n", i, p);
    printf("aux: %d\n", aux);
    
    while (aux < array[i] && i >= 0) {
      array[i + 1] = array[i];
      i--;
    }

    array[i + 1] = aux;
    printfArray(array, size);
  }
}

// { 8, 6, 3, 2, 7, 5 }
// 8

// 8  6   6 maior do que 8, ordena
// 6  8

// 6  8  3  ordena, indice 0
// 3  6  8

int main(){
  int vetor[] = { 8, 6, 3, 2, 7, 5 };
  printfArray(vetor, 6);
  // printf("\n");
  insertionSort(vetor, 6);
  printfArray(vetor, 6);
}