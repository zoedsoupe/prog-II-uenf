#include <stdio.h>
#include <stdlib.h>

typedef struct stElem {  
	int  info; 
	int freq;
	struct stElem* next; 
} Elem; 

typedef struct stLst {  
	int  n;
	Elem *first,*last;
} Lst; 

Elem *searchPos(Elem *no, int w, int *sw) {
	Elem *tmp = NULL;
	*sw = 0;
	while (no) {
		if(no->info > w) {
			break;
		}
		else if (no->info == w) {
		    *sw = 1;
			tmp = no;
	        break;
		}
		else {
			tmp = no;
		    no = no->next;
		}
	}
	return tmp;
}

void addNo(Lst *myList, int w) {
	Elem *newNo;
	Elem *tmpNo;
	Elem *noAnt;
	
	int sw; 
	
	noAnt = searchPos(myList->first, w, &sw);

	if(sw)
       noAnt->freq += 1;
    else {
       newNo = (Elem*) malloc(sizeof(Elem));
       newNo->info = w;
       newNo->next = NULL;
       newNo->freq = 1;
        if(!noAnt) {
	      	if(myList->first) {
	      	    newNo->freq +=1;
		       	newNo->next = myList->first;
		       	myList->first = newNo;
	       	} else
		      	myList->first = myList->last = newNo;
        } else {
	       newNo->next = noAnt->next;
           noAnt->next = newNo;
        }
    	myList->n += 1;
	}
}

void printList(Lst *myList) {
	Elem *newNo;
	newNo = myList->first;
	while(newNo) {
		printf("\n %d: (%dx)", newNo->info, newNo->freq);
		newNo = newNo->next;
	}
	printf("\n");
}


int main() {
	int w;

	Elem *newNo;

	Lst myList;

	myList.n = 0;
	myList.first = NULL;
	myList.last = NULL;

	printf("\nDigite um valor inteiro: ");
	scanf("%d", &w); 

	while(w) { 
		addNo(&myList, w);
			
		printf("\nDigite um valor inteiro ou ZERO: ");
		scanf("%d", &w);
	}

    printList(&myList);

	newNo = myList.first;
	while(newNo) {
		myList.first = newNo->next;
		free(newNo);
		newNo = myList.first;
	}
}