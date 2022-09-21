#include <stdio.h>
#include "Lista.h"

static t_apontador pesquisa_pos(t_lista *lista, t_chave chave){
  t_apontador i;
  for (i = 0; i <= lista->ultimo; i++){
    
    if (lista->elementos[i].chave == chave) return 1;

  }
  return NAO_ENCONTROU;
}

int criar(t_lista *lista) {
  lista->ultimo = -1;
}

int inserir(t_lista *lista, t_elemento elemento) {
  
  if (cheia(lista)) return ERRO_CHEIA;
  
  if (pesquisa_pos(lista, elemento.chave) >= 0) return JA_EXISTE;

  lista->ultimo++;
  lista->elementos[lista->ultimo] = elemento;
  
  return SUCESSO;
}

int vazia(t_lista *lista){
	if(lista->ultimo == -1)
		return 1;
	else
		return 0;
}

int cheia(t_lista *lista) {
	if(lista->ultimo == MAX_TAM-1)
		return 1;
	else
		return 0;
}

void imprimir(t_lista *lista) {
	t_apontador i;
	printf("{ ");
	for (i=0; i <= lista->ultimo; i++) {
		printf("%d ", lista->elementos[i].chave);
	}
	printf("}\n");
	return;

}