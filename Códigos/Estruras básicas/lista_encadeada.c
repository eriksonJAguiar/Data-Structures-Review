#include <stdio.h>
#include <stdlib.h>

typedef struct reg celula;
struct reg {
   int  conteudo;
   celula *prox;
};

int tam = 0;

void addLast(int item,celula *p){
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
void addFirst(int item,celula *p){
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
void add(int item, celula *p, int pos){
  celula *nova = (celula *) malloc(sizeof(celula));
  nova->conteudo = item;
  
  if(p->prox == NULL){
  	 p->prox = nova;
  	 tam++;
  	 return;
  }

  else if(pos == 0){
  	addFirst(item,p);
  }
  else if(pos == tam){
  	addLast(item,p);
  }
  else if(pos > tam){
  	printf("Estouro...\n");
  	return;
  }
  celula *tmp = p->prox;
  int i = 0;
  while(i < pos-1){
  	 tmp = tmp->prox;
  	 i++;
  }

   nova->prox = tmp->prox;
   tmp->prox = nova;
   tam++;

}

int removeLast(celula *lista){
	if(lista->prox == NULL){
  	  return 0;
  	}

  	celula *penultimo = lista;
  	celula *ultimo = lista->prox;

  while(ultimo->prox != NULL){  	
  		penultimo = ultimo;
  		ultimo = ultimo->prox;
  }

  int aux = ultimo->conteudo;
  penultimo->prox = NULL;

  tam--;

  return aux;

}
int removeFirst(celula *lista){
	if(lista->prox == NULL){
  	  return 0;
  	}

  	celula *tmp = lista->prox;

  	int aux = tmp->conteudo;

  	lista->prox = tmp->prox;

  	tam--;

  	return aux;

}
int remover(celula *lista, int pos){
	if(lista->prox == NULL){
  	  return 0;
  	}
  	else if(pos == 0){
  		return removeFirst(lista);
  	}
  	else if(pos == tam){
  		return removeLast(lista);
  	}
  	else if(pos > tam){
  		printf("Estouro...\n");
  		return 0;
  	}
  	
  	celula *tmp = lista->prox;	
  	
  	int i = 0;
  	while(i < pos-1){
  		tmp = tmp->prox;
  		i++;
  	}
  	int aux = tmp->prox->conteudo;
  	tmp->prox = tmp->prox->prox;


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

	celula *lista = (celula *) malloc(sizeof(celula));

	printf("Inserindo no Final...\n");
	
	addLast(10,lista);
	addLast(20,lista);
	addLast(30,lista);

	printf("Lista:\n");
	imprimeTotal(lista);

	printf("Inserindo no Comeco...\n");
	
	addFirst(15,lista);
	addFirst(29,lista);
	addFirst(61,lista);

	printf("Lista:\n");
	imprimeTotal(lista);

	printf("Qualquer Lugar...\n");

	add(35,lista,2);

	printf("Lista:\n");
	imprimeTotal(lista);

	printf("Removendo %d do final...\n", removeLast(lista));

	printf("Lista:\n");
	imprimeTotal(lista);

	printf("Removendo %d do Comeco...\n", removeFirst(lista));

	printf("Lista:\n");
	imprimeTotal(lista);

	printf("Removendo %d de Qualquer Lugar...\n", remover(lista,3));

	printf("Lista:\n");
	imprimeTotal(lista);

	return 0;
}