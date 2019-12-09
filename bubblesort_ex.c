void bubble_sort (int vet[], int n) {
    int k, j, aux;

    for (k = n - 1; k > 0; k--) {
        printf("\n[%d] ", k);

        for (j = 0; j < k; j++) {
            printf("%d, ", j);

            if (vet[j] > vet[j + 1]) {
                aux          = vet[j];
                vet[j]     = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}