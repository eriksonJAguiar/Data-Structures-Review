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
int remover(){
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
int getList(int pos){
	if(pos > sizeof(conteudo)-1)
		return -1;
	
	return conteudo[pos];
}

int main(){
	add(2);
	add(4);
	add(8);
	add(16);

	printf("%d\n", getList(0));
	printf("%d\n", getList(1));
	printf("%d\n", getList(2));
	printf("%d\n", getList(3));

	printf("Removendo... %d \n",remover());

	printf("%d\n", getList(0));
	printf("%d\n", getList(1));
	printf("%d\n", getList(2));
	printf("%d\n", getList(3));


}