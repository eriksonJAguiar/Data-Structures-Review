#include <stdio.h>
#include <stdlib.h>

typedef struct reg celula;
struct reg {
   int  conteudo;
   celula *prox;
};

int tam = 0;

void add(int item,celula *p){
  celula *nova = (celula *) malloc(sizeof(celula));

  nova->conteudo = item;

  if(p->prox == NULL){
  	p->prox = nova;
  	tam++;
  	return;
  }

  celula *tmp = p->prox;

  while(tmp->prox != NULL){

  		tmp = tmp->prox;
  }
	
	tmp->prox = nova;
	tam++;

}
int remover(celula *lista){
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

	celula *fila = (celula *) malloc(sizeof(celula));

	printf("Inserindo...\n");

	add(20,fila);
	add(30,fila);
	add(40,fila);

	printf("Lista:\n");
	imprimeTotal(fila);

	printf("Removendo %d...\n",remover(fila));

	printf("Lista:\n");
	imprimeTotal(fila);



}