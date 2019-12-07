#include <stdio.h>
#include <stdlib.h>

typedef struct stElem {  
		int  info;
		struct stElem* next;
} Elem;

typedef struct stLst {  
		int  n;
		Elem *first, 
			 *last;
} Lst;

void insereNode(Lst *myList, int w)
{
	Elem *newNo;
	Elem *tmpNo;

	newNo = (Elem*) malloc(sizeof(Elem));

	newNo->info = w;
	newNo->next = NULL;
	

	if(myList->first == NULL)
		myList->first = myList->last = newNo;
	else {
		tmpNo = myList->last;
		myList->last = newNo;
		tmpNo->next = newNo;
	}
	myList->n += 1;
}

void imprime ( Lst *myList) {
	Elem *newNo;
	newNo = myList->first;
	while(newNo) {
		printf("\n %d ", newNo->info);
		newNo = newNo->next;
	}
}

void main(void) {
	int w;

	Elem *newNo;

	Lst myList;

	myList.n = 0;
	myList.first = NULL;
	myList.last = NULL;



	printf("\n Digite um valor inteiro...");
	scanf("%d", &w);

	while(w) {
		insereNode(&myList, w);
			
		printf("\n Digite um valor inteiro.ou ZERO..");
		scanf("%d", &w);
	}

	// imprimir
    imprime(&myList);

	// libera memoria da lista
	newNo = myList.first;
	while(newNo) {
		myList.first = newNo->next;
		free(newNo);
		newNo = myList.first;
	}
}