#include <stdio.h>
#include <stdlib.h>

typedef struct stElem {  
		int info;
		int cont; 
		int freq;
		struct stElem* next;
} Elem;

typedef struct stLst {  
		int  n;
		Elem *first,*last;
} Lst;

Elem *buscaPosicao(Elem *noAnt, Elem *no, int *sw) {
	Elem *tmp = NULL;
	*sw = 0;
	while (noAnt) {
		if(noAnt->info > no->info) {
			break;
		}
		else if(noAnt->info == w) {
			*sw++;
			tmp = noAnt;
			break;
		}
		else {
			noAnt = noAnt->next;
		}
	}
	return tmp;
}

void insereNode(Lst *myList, int w) {
	Elem *newNo;
	Elem *tmpNo;
	Elem *noAnt;

	int sw; //0 não existe, 1 existe

	noAnt = buscaPosicao(myList->first, newNo, &sw);
	
	if (sw) {
		noAnt->freq++;
	}
	else { //w == 0
		newNo = (Elem*) malloc(sizeof(Elem));

		newNo->info = w;
		newNo->next = NULL;

		newNo->freq = 1;
		if(!noAnt) {
			if(myList->first) {
				newNo->next = myList->first;
				myList->first = newNo;
			} else myList->first = myList->last = newNo;
		} else {
		    newNo->next = noAnt->next;
		    noAnt->next = newNo;
    	}
		myList->n += 1;
	}
}

void imprime ( Lst *myList) {
	Elem *newNo;
	newNo = myList->first;
	while(newNo)
	{
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



	printf("\n Digite um valor inteiro: ");
	scanf("%d", &w);

	while(w) {
		insereNode(&myList, w);
			
		printf("\n Digite um valor inteiro.ou ZERO: ");
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
