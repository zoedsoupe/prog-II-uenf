#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	char letra; 
	int freq; 
	
	struct no *prox; // ponteiro ao proximo no da lista	
} No;

typedef struct lista
{
	int n; // numero de elementos na lista
	
	No *first; // ponteiro ao primeiro no da lista
} Lista;

void criaLista(Lista *l)
{
	l->n = 0; 
	l->first = NULL;
}


void addNo(Lista *l, char c, int f)
{
	No *noIns; // no a ser inserido na lista
	No *noAux; // no auxiliar (usado para percorrer a lista) 
	
	
	noIns = (No *) malloc(sizeof(No));
	
	noIns->letra = c;
	noIns->freq = f;
	
	if(l->n == 0) // Caso 1: Lista vazia
	{
		l->first = noIns;
		l->first->prox = NULL;
	}
	else // a lista nao esta vazia => percorrer a posicao correta
	{
		noAux = l->first; 
		
		if(noIns->letra < noAux->letra) // Caso 2: O no a ser inserido é o novo primeiro elemento
		{
		    l->first = noIns;
			noIns->prox = noAux;		
		}
		else
		{
			while(noAux != NULL && noAux->prox != NULL) // Loop p/ percorrer a lista
			{
				if(noIns->letra > noAux->letra && noIns->letra < noAux->prox->letra) // Caso 3: Insercao entre dois nos
				{
					noIns->prox = noAux->prox;	
					noAux->prox = noIns;
					break;
				}
				else
					noAux = noAux->prox; // Não encontrou a posicao certa => avança para o proximo no
			}
			 
			if(noAux->prox == NULL) // Caso 4: Insercao no final da lista
			{
				noAux->prox = noIns;
				noIns->prox = NULL;
			}
		}
			
	}
		
	l->n++; // Foi adicionado um elemento => incrementa o contador da lista
	
}


void percorreLista(Lista l)
{
	int i = 1;
	No *noAux;

	noAux = l.first;
	
	while(noAux != NULL)
	{
		printf("%d. %c e %d\n",i, noAux->letra, noAux->freq);
		noAux = noAux->prox;
		i++;
	}
}

int main(int argc, char *argv[]) 
{
    
	FILE *ARQ;
	Lista lista; 


	criaLista(&lista);
	addNo(&lista,'F',12);
	addNo(&lista,'B',14);
	addNo(&lista,'A',13);
	addNo(&lista,'D',11);
	addNo(&lista,'G',11);
    addNo(&lista,'C',5);
    addNo(&lista,'Z',11);
    addNo(&lista,'P',11);
	addNo(&lista,'\'',11);
	
	percorreLista(lista);
	
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	char letra; 
	int freq; 
	
	struct no *prox; // ponteiro ao proximo no da lista	
} No;

typedef struct lista
{
	int n; // numero de elementos na lista
	
	No *first; // ponteiro ao primeiro no da lista
} Lista;

void criaLista(Lista *l)
{
	l->n = 0; 
	l->first = NULL;
}


void addNo(Lista *l, char c, int f)
{
	No *noIns; // no a ser inserido na lista
	No *noAux; // no auxiliar (usado para percorrer a lista) 
	
	
	noIns = (No *) malloc(sizeof(No));
	
	noIns->letra = c;
	noIns->freq = f;
	
	if(l->n == 0) // Caso 1: Lista vazia
	{
		l->first = noIns;
		l->first->prox = NULL;
	}
	else // a lista nao esta vazia => percorrer a posicao correta
	{
		noAux = l->first; 
		
		if(noIns->letra < noAux->letra) // Caso 2: O no a ser inserido é o novo primeiro elemento
		{
		    l->first = noIns;
			noIns->prox = noAux;		
		}
		else
		{
			while(noAux != NULL && noAux->prox != NULL) // Loop p/ percorrer a lista
			{
				if(noIns->letra > noAux->letra && noIns->letra < noAux->prox->letra) // Caso 3: Insercao entre dois nos
				{
					noIns->prox = noAux->prox;	
					noAux->prox = noIns;
					break;
				}
				else
					noAux = noAux->prox; // Não encontrou a posicao certa => avança para o proximo no
			}
			 
			if(noAux->prox == NULL) // Caso 4: Insercao no final da lista
			{
				noAux->prox = noIns;
				noIns->prox = NULL;
			}
		}
			
	}
		
	l->n++; // Foi adicionado um elemento => incrementa o contador da lista
	
}


void percorreLista(Lista l)
{
	int i = 1;
	No *noAux;

	noAux = l.first;
	
	while(noAux != NULL)
	{
		printf("%d. %c e %d\n",i, noAux->letra, noAux->freq);
		noAux = noAux->prox;
		i++;
	}
}

int main(int argc, char *argv[]) 
{
    
	FILE *ARQ;
	Lista lista; 


	criaLista(&lista);
	addNo(&lista,'F',12);
	addNo(&lista,'B',14);
	addNo(&lista,'A',13);
	addNo(&lista,'D',11);
	addNo(&lista,'G',11);
    addNo(&lista,'C',5);
    addNo(&lista,'Z',11);
    addNo(&lista,'P',11);
	addNo(&lista,'\'',11);
	
	percorreLista(lista);
	
	return 0;
}
