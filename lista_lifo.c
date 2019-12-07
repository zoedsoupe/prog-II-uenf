#include<stdio.h>
#include<stdlib.h>

typedef struct alP2 {
    int info;
    struct alP2* next;
}P2;

typedef struct stLista {
    int n;
    P2* no;
}lista;


int main() {
    int w;  
    P2 *newno;
    lista mylist;
    mylist.n = 0;
    mylist.no = NULL;
    
    printf("Digite um valor inteiro:\n");
    scanf("%d", &w);
    
    //preencher lista
    while(w) {
        newno = (P2*)malloc(sizeof(P2));
        
        newno->info = w;
        newno->next = mylist.no;
        
        mylist.no = newno;
        mylist.n += 1;
        
        printf("\nDigite um valor inteiro ou ZERO:\n");
        scanf("%d", &w);
    }
    
    newno = mylist.no;
    
    //imprimir lista
    while(newno) {
        printf("\n %d ", newno->info);
        newno = newno->next;
    }
    
    //liberar mem
    newno = mylist.no;
    
    while(newno) {
        mylist.no = newno->next;
        free(newno);
        newno = mylist.no;
    }
    
    return 0;
}