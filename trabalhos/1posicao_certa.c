#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void informa_n (int *n) {
    printf("Informe o pivô: \n");
    scanf("%d", n);
}

void gera_vet (int vet[]) {
    srand(time(NULL));
    for (int i = 0; i <= 14; i++) {
        vet[i] = (rand() % 100);
    }
}

void print_vet (int vet[]) {
    printf("\n");
    for (int i = 0; i <= 14; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void order_pivot (int vet[], int n) {
    int tmp;
    
    for (int i = 0; i <= 14; i++) {
        if (vet[i]) {
            
        }
        
    }
    
}

int main() {
    int n;
    int vet[100];

    gera_vet(vet);
    print_vet(vet);
    informa_n(&n);
    order_pivot(vet, n);
    return 0;
}
