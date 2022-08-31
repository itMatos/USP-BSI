#include <stdio.h>
#include <stdlib.h>

void swap (int *indexA, int *indexB) {
  int aux = *indexA;
  *indexA = *indexB;
  *indexB = aux;
}

int leftGreater(int leftElement, int rightElement) {
  return leftElement > rightElement ? 1 : 0;
}

int bubbleSort(int *array, int size) {
  for (int i = 0; i < size - 1; i++) {

    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
      }
    }
  }
}

void printArray(int *array, int size) {
  
}

int main() {
  int vet[] = {5, 4, 3, 2, 1};

  bubbleSort(vet, 5);

  for (int i = 0; i < 5; i++){
    printf("%d ", vet[i]);
  }
  printf("\n");
}