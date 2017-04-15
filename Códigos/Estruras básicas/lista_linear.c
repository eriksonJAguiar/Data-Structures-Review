#include <stdio.h>
#define TAM 10

int primeiro;
int ultimo;
int conteudo[TAM];


void initList(){
	primeiro = 0;
	ultimo = 0;
}

void add(int valor){
	if(ultimo > TAM-1)
		return;

	conteudo[ultimo] = valor;
	ultimo++;

}
void addFirst(int valor){
	if(ultimo > TAM-1)
		return;

	for(int i=ultimo;i > primeiro;i--){
		int aux = conteudo[i-1];
		conteudo[i] = aux;
	}

	conteudo[primeiro] = valor;

	ultimo++;
}
int remover(){
	if(primeiro == ultimo)
		return 0;

	int aux = conteudo[ultimo-1];
	conteudo[ultimo-1] = 0;
	ultimo--;

	return aux;
}

int removerFirst(){
	if(primeiro == ultimo)
		return 0;

	int aux = conteudo[primeiro];
	conteudo[primeiro] = 0;

	for(int i=primeiro;i < ultimo;i++){
		conteudo[i] = conteudo[i+1];
	}

	conteudo[ultimo] = 0;

	ultimo--;

	return aux;

}
int removerAny(int pos){
	if(primeiro == ultimo)
		return 0;

	if(pos == 0)
		return removerFirst();

	else if(pos == TAM-1)
		return remover();

	int aux = conteudo[pos];
	conteudo[pos] = 0;

	for(int i=pos;i < ultimo;i++){
		conteudo[i] = conteudo[i+1];
	}

	conteudo[ultimo] = 0;

	ultimo--;

	return aux;

}
int getList(int pos){
	if(pos > sizeof(conteudo)-1)
		return -1;
	
	return conteudo[pos];
}

int main(){

	initList();

	printf("Inserindo... \n");

	add(10);
	addFirst(12);

	printf("%d\n", getList(0));
	printf("%d\n", getList(1));

	printf("Removendo... %d \n",removerFirst());

	printf("%d\n", getList(0));
	printf("%d\n", getList(1));

	printf("Inserindo... \n");

	add(15);
	add(20);
	add(30);

	printf("%d\n", getList(0));
	printf("%d\n", getList(1));
	printf("%d\n", getList(2));
	printf("%d\n", getList(3));

	printf("Removendo... %d \n",removerAny(2));

	printf("%d\n", getList(0));
	printf("%d\n", getList(1));
	printf("%d\n", getList(2));
	printf("%d\n", getList(3));

	return 0;
}