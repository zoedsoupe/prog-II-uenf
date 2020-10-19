#include <stdio.h>
#include <stdlib.h>

typedef struct stElem {  
	char info; 
	int freq;
	struct stElem* next; 
} Elem; 

typedef struct stLst {  
	int  n;
	Elem *first,*last;
} Lst;

Elem *searchPos(Elem *no, char w, int *sw) {
	Elem *tmp = NULL;
	*sw = 0;
	while (no) {
		if(no->info > w) {
			break;
		}
		else if (no-> info == w) {
		    *sw = 1;
			tmp = no;
	        break;
		}
		else
		    tmp = no;
		no = no -> next;
	}
	return tmp;
}

void addNo(Lst *myList, char w) {
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
		        newNo->next = myList->first;
		        myList->first = newNo;
	        } else
		        myList->first = myList->last = newNo;
        }
		else {
		    newNo->next = noAnt->next;
		    noAnt->next = newNo;
    	}
    	myList->n += 1;
    }
}

void printList ( Lst *myList)  {
	Elem *newNo;
	newNo = myList->first;
	while(newNo) {
		printf("\nCaractere: %c - ", newNo->info);
		printf(" ASCII: %d - Freq: (%dx)", newNo->info, newNo->freq);
		newNo = newNo->next;
	}
	printf("\n\n");
}


int main() {
    FILE *fArq;
    
	char w;

	Elem *newNo;

	Lst myList;

	myList.n = 0;
	myList.first = NULL;
	myList.last = NULL;

    fArq = fopen("text.txt", "r");
    if (!fArq) {
        printf("NO arquivo");
        exit (1);
    }
   
	fscanf (fArq, "%c", &w);

	while(!feof(fArq)) { 
		addNo(&myList, w);
		fscanf (fArq, "%c", &w);
	}

	printf("\nExistem %d elementos\n", myList.n);

    printList(&myList);

	newNo = myList.first;
	while(newNo) {
		myList.first = newNo->next;
		free(newNo);
		newNo = myList.first;
	}

	return 0;
}