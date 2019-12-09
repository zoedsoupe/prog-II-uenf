#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void define_tam_vet (int *tam_vet);
void gera_vet (int *vet, int tam_vet);
int right_pos (int *v, int first, int last );
void print_vet(int *vet,int tam_vet);
void print_vet(int *vet,int tam_vet);
void quicksort (int *vet, int first, int last);

int main() {
    int first = 0, last, tam_vet, vet[100];

    define_tam_vet(&tam_vet);
    last = tam_vet - 1;
    gera_vet(vet, tam_vet);
    print_vet(vet, tam_vet);
    quicksort(vet, first, last);
    print_vet(vet, tam_vet);

    return 0;
}

void define_tam_vet (int *tam_vet) {
    printf("Qual será o tamanho do vetor?\n");
    scanf("%d", tam_vet);
}

void gera_vet (int *vet, int tam_vet) {
    srand(time(NULL));
    for (int i = 0; i <= tam_vet; i++) {
        vet[i] = (rand() % 100);
    }
}

int right_pos (int *vet, int first, int last) {
    int tmp;

    while (last > first) {
        if (vet[first] < vet[first+1]) {
            while(vet[first] < vet[last]) {
                last--;
            }
            if (first < last) {
                tmp = vet[first+1];
                vet[first+1] = vet[last];
                vet[last] = tmp;
                last--;
            }
        }
        else {
           tmp = vet[first];
           vet[first] = vet[first+1];
           vet[first+1]= tmp;
           first++;
        }
    }
    return first;
}

void print_vet(int *vet,int tam_vet) {
   for(int i = 0; i < tam_vet; i++){
    printf("%d ", vet[i]);
   }
  printf("\n");
}

void quicksort (int *vet, int first, int last) {
    int j;

    if(last > first) {
        j = right_pos(vet, first, last);
        quicksort(vet, first, j-1);
        quicksort(vet, j+1, last);
    }
} 