#include <stdio.h>
#include <stdlib.h>


int i = 0;
int j = 0;

void combina_vet1_vet2(int *vet1, int *vet2, int *vet3);
void order_vet3(int *vet3);

int main() {

    int vet1[5] = {4,9,10,15,14};
    int vet2[5] = {2,1,90,22,21};
    int vet3[10];

    
    int tmp = 0;

    combina_vet1_vet2(vet1, vet2, vet3);
    order_vet3(vet3);
    return 0;
}

void combina_vet1_vet2(int *vet1, int *vet2, int *vet3) {
    for (i = 0; i < 5; i++ )
        vet3[i] = vet1[i];

    for (i = 5; i < 10; i++ )
        vet3[i] = vet2[i-5];

    printf("Vetores combinados: \n");
    for (i = 0; i < 10; i++ )
        printf( "%d ", vet3[i] );
    printf("\n");
}

void order_vet3(int *vet3) {
    int tmp = vet3[0]; 
    for (i = 0; i < 10; i++ )
        for (j = i; j < 10; j++ )
            if ( vet3[j] < vet3[i]  ) {
                tmp = vet3[j];
                vet3[j] = vet3[i];
                vet3[i] = tmp;
            }

    printf("\nVetor ordenado: \n");
    for ( i = 0; i < 10; i++ )
        printf( "%d ", vet3[i] );
    printf("\n");
}