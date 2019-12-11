#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void define_tam_vet (int *tam_vet) {
    printf("Qual será o tamanho do vetor?\n");
    scanf("%d", tam_vet);
}

void gera_vet (int *vet, int tam_vet) {
    //srand(time(NULL));
    for (int i = 0; i < tam_vet; i++) {
        vet[i] = (rand() % 100);
    }
}

void print_vet (int *vet, int tam) {
    printf("\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n\n");
}

void order_pivo (int *vet, int tam_vet, int pivo) {
    int pos_certa = vet[(0 + tam_vet) / 2];
    int tmp = 0, aux = 0;

    for (int i = 0; i < tam_vet; i++) {
        if (vet[i] == pivo) {
            tmp = vet[pos_certa];
            vet[pos_certa] = pivo;
            vet[i] = vet[i];
        }
        for (int j = 0; j < tam_vet; j++) {
           if (vet[i] < vet[j]) {
               aux = vet[i];
               vet[i] = vet[j];
               vet[j] = aux;
           }
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
    order_pivo(vet, tam_vet, vet[0]);
    print_vet(vet, tam_vet);
    return 0;
}
