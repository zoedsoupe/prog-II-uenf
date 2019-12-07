#include<stdio.h>
#include<stdlib.h>

typedef struct alP2 {
    int info;
    struct alP2* next;
}P2;

typedef struct stLista {
    int n;
    P2 *first, *last;
}lista;

int main() {
    int w;  
    P2 *newno, *tmpno;
    lista mylist;
    mylist.n = 0;
    mylist.first = NULL;
    mylist.last = NULL;
    
    printf("Digite um valor inteiro:\n");
    scanf("%d", &w);
    
    //preencher lista
    while(w) {
        newno = (P2*)malloc(sizeof(P2));
        
        newno->info = w;
        newno->next = NULL;

        mylist.n += 1;

        if (mylist.first == NULL) {
            mylist.first = newno;
            mylist.last = newno;
        }
        else {
            tmpno = mylist.last;
            tmpno->next = newno;
            mylist.last = newno;
        }

        printf("\nDigite um valor inteiro ou ZERO:\n");
        scanf("%d", &w);
    }
    
    //imprimir lista
    newno = mylist.first;

    while(newno) {
        printf("\n %d ", newno->info);
        newno = newno->next;
    }
    
    //liberar mem
    newno = mylist.first;
    
    while(newno) {
        mylist.first = newno->next;
        free(newno);
        newno = mylist.first;
    }
    
    return 0;
}