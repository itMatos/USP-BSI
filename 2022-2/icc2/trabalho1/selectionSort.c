#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (int *indexA, int *indexB) {
  int aux = *indexA;
  *indexA = *indexB;
  *indexB = aux;
}

void insertionSort(int *array, int size) {
  int i, j, min;
  for (int i = 0; i < size-1; i++){
    min = i;
    
    for(int j = i + 1; j < size; j++){
      printf("C %d %d\n", min, j);
      if (array[j] < array[min]) {
        min = j;
      }

    }
    
    if (min != i) {
      printf("T %d %d\n", i, min);
      swap(&array[min], &array[i]);
    }
  }
}
 
void printArray(int *array, int size) {
  for (int i = 0; i < size; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int tamanho = 4;
  int vetor[] = { 3, 6, 5, 2 };
  printArray(vetor, tamanho);
  insertionSort(vetor, tamanho);
  printArray(vetor, tamanho);
}