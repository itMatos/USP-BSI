#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define delimiter '|'

typedef struct tLivro{
    int id;
    char nome[100];
    char autor[100];
    int ByteOffset;
}tLivro;

tLivro lerLivrosInfo() {
  tLivro livro;

  scanf("%d", &livro.id);
  scanf(" %[^(\r|\n)]", livro.nome);
  scanf(" %[^(\r|\n)]", livro.autor);

  return livro;
}

void escreverLivroArquivo(tLivro livro, FILE *arquivop) {
  fwrite(&livro.id, sizeof(int), 1, arquivop);
  fprintf(arquivop, "%s", livro.nome);
  fputc(delimiter, arquivop);
  int tam = strlen(livro.autor);
  fwrite(&tam, sizeof(int), 1, arquivop);
  fwrite(livro.autor, tam, 1, arquivop);
  char delimitLivro = '*';
  fputc(delimitLivro, arquivop);
}

int count = 0;
void imprimirLivroInfo(tLivro livro){
  if(count>0) printf("\n");
  
  printf("Id: %d\n", livro.id);
  printf("Titulo: %s\n", livro.nome);
  printf("Autor: %s\n", livro.autor);
  printf("Byte offset: %d\n", livro.ByteOffset);
  count++;
}

char lerEntrada(FILE *fp, char *atual) {
  char charAtual;
  int inputIndex;
  inputIndex = 0;
  charAtual = fgetc(fp);
  while((charAtual != EOF) && (charAtual != delimiter))
  {
      atual[inputIndex++] = charAtual;
      charAtual = fgetc(fp);
  }
  atual[inputIndex] = '\0';
  return charAtual;
}

tLivro lerLivrosArquivo(FILE *fp) {
  tLivro livro;
  livro.ByteOffset = ftell(fp);

  fread(&livro.id,sizeof(int), 1,  fp);
  char currentInput[50];
  lerEntrada(fp, currentInput);
  strcpy(livro.nome, currentInput);
  int aut;
  fread(&aut, sizeof(int), 1, fp);
  fread(livro.autor, sizeof(char), aut, fp);
  livro.autor[aut] = '\0';
  char currentChar;
  currentChar = fgetc(fp);
  
  return livro;
}

void imprimirLivros(int totalLivros, int saidas){
  FILE *fp;
  fp = fopen("arquivo.txt", "r");
  tLivro livro;
  
  int dif = (totalLivros - saidas);
  for(int i = 0; i < totalLivros; i++) {
    livro = lerLivrosArquivo(fp);

    if (i >= dif) {
      if (i == 0){
        livro.ByteOffset = 0;
        imprimirLivroInfo(livro);
      }
      else imprimirLivroInfo(livro);
    }
  }
}


int main(void) {
  int valores;
  tLivro livro;
  scanf("%d", &valores);

  FILE *fp;
  fp = fopen("arquivo.txt", "w");
  
  for(int i = 0; i < valores; i++) {
    livro = lerLivrosInfo();
    escreverLivroArquivo(livro, fp);
  }
  fclose(fp);

  int qtdSaidas;
  scanf("%d", &qtdSaidas);
  imprimirLivros(valores, qtdSaidas);
  
}