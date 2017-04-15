#include <stdio.h>
#include <stdlib.h>

typedef struct reg celula;
struct reg {
   int  conteudo;
   celula *prox;
};

int tam = 0;

void push(int item,celula *p){
  celula *nova = (celula *) malloc(sizeof(celula));
  
  nova->conteudo = item;
  
  if(p->prox == NULL){
  	 p->prox = nova;
  	  tam++;
  	 return;
  }
  
  nova->prox = p->prox;
  p->prox = nova;

  tam++;
}
int pop(celula *lista){
	if(lista->prox == NULL){
  	  return 0;
  	}

  	celula *tmp = lista->prox;

  	int aux = tmp->conteudo;

  	lista->prox = tmp->prox;

  	tam--;

  	return aux;

}
void imprimeTotal(celula *p){
	celula *tmp; 
	tmp = p->prox;
  while(tmp != NULL){
  		printf("%d\n",tmp->conteudo);
  		tmp = tmp->prox;
  }
	
}


int main(){

	celula *pilha = (celula *) malloc(sizeof(celula));

	printf("Inserindo...\n");

	push(20,pilha);
	push(30,pilha);
	push(40,pilha);

	printf("Lista:\n");
	imprimeTotal(pilha);

	printf("Removendo %d...\n",pop(pilha));

	printf("Lista:\n");
	imprimeTotal(pilha);

	return 0;
}