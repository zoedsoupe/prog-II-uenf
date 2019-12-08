#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void define_tam_vet (int *tam_vet) {
    printf("Qual será o tamanho do vetor?\n");
    scanf("%d", tam_vet);
}

void informa_pivo (int *pivo) {
    printf("Informe o pivô: \n");
    scanf("%d", pivo);
}

void gera_vet (int vet[], int tam) {
    //srand(time(NULL));
    for (int i = 0; i <= tam; i++) {
        vet[i] = (rand() % 100);
    }
}

void print_vet (int vet[], int tam) {
    printf("\n");
    for (int i = 0; i <= tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n\n");
}

void order_pivot (int vet[], int pivo, int tam_vet) {
    int tmp;

    for (int i = 0; i <= tam_vet; i++) {
        if (vet[i] > pivo) {
            tmp = vet[i];
            vet[i] = vet[i+1];
            vet[i+1] = tmp;
        }
    }
}

int main() {
    int pivo;
    int vet[100];
    int tam_vet;

    define_tam_vet(&tam_vet);
    gera_vet(vet, tam_vet);
    print_vet(vet, tam_vet);
    informa_pivo(&pivo);
    order_pivot(vet, pivo, tam_vet);
    print_vet(vet, tam_vet);
    return 0;
}
