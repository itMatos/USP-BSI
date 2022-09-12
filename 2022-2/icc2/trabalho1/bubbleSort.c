#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (int *indexA, int *indexB) {
  int aux = *indexA;
  *indexA = *indexB;
  *indexB = aux;
}

int bubbleSort(int *array, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      printf("C %d %d\n", j, j+1);
      
      if (array[j] > array[j + 1]) {
        printf("T %d %d\n", j, j+1);
        swap(&array[j], &array[j + 1]);
      }
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
  bubbleSort(vetor, tamanho);
  printArray(vetor, tamanho);
}