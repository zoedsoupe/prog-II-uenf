#include <stdio.h>
#include <stdlib.h>


void combina (int n1, int* vet1, int n2, int *vet2);

int mergesort (int tam_vet, int *vet) {
    int tmp_pos;

    if (tam_vet > 1) {
        tmp_pos = tam_vet / 2;
        mergesort(tmp_pos, vet);
        mergesort(tam_vet-tmp_pos, &vet[tmp_pos]);
        combina (tmp_pos, vet, tam_vet-tmp_pos , &vet[tmp_pos]);
    }
}
void combina (int n1, int* vet1, int n2, int *vet2) {
    int n = n1 + n2;
    int vetor[n], k, i = 0, j = 0;

    for (k = 0; k < n; k++) {
        if ((i < n1) && (j < n2)) {
            if (vet1[i] < vet2[j]) {
                vetor[k] = vet1[i];
                i++;
            }
            else {
                vetor[k] = vet2[j];
                j++;
            }
        }
        else {
            if (i < n1) {
                vetor[k] = vet1[i];
                i++;
            }
            else {
                vetor[k] = vet2[j];
                j++;
            }
        }
    }
    for (k = 0; k < n; k++) {
        vet1[k] = vetor[k];
    }
}
void print_vet(int tam_vet, int *vet) { 
    
    for (int i = 0; i < tam_vet; i++) {
    printf ("%d ", vet[i]);
    }
}

int main(void) {
    int vet[] = {9,5,3,6,1,34,12,67,33,22,21,0}, tam_vet = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor desordenado: \n");
    print_vet(tam_vet, vet);
    mergesort(tam_vet, vet);
    printf("\n\nVetor ordenado pelo Merge Sort: \n");
    print_vet(tam_vet, vet);
    printf("\n");

  return 0;
}