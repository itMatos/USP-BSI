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

int main(){
  int vetor[] = { 3, 6, 5, 2 };
  printfArray(vetor, 4);
  insertionSort(vetor, 4);
  printfArray(vetor, 4);
}