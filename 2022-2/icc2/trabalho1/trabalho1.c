#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (int *indexA, int *indexB) {
  int aux = *indexA;
  *indexA = *indexB;
  *indexB = aux;
}

void bubbleSort(int *array, int size) {
  int flag;
  for (int i = 0; i < size - 1; i++) {
    flag = 0;

    for (int j = 0; j < size - i - 1; j++) {
      printf("C %d %d\n", j, j+1);
      
      if (array[j] > array[j + 1]) {
        printf("T %d %d\n", j, j+1);
        swap(&array[j], &array[j + 1]);
        flag = 1;
      }
    }
    if (flag == 0) break;
  }
}

void insertionSort(int *array, int size) {
  int min;
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
  int size;
  char method[15];
  scanf("%s", method);

  if ((strcmp(method, "bolha") == 0)){
    scanf("%d", &size);
    int array[size], value;

    for(int i = 0; i < size; i++){
      scanf("%d", &value);
      array[i] = value;
    }

    bubbleSort(array, size);
    printArray(array, size);  
  }
  else {
    scanf("%d", &size);
    int array[size], value;

    for(int i = 0; i < size; i++){
      scanf("%d", &value);
      array[i] = value;
    }

    insertionSort(array, size);
    printArray(array, size);
  }
}