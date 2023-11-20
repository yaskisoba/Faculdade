#include <stdio.h>
#include <stdlib.h>

// [12, 0, 45, 90, 1, 2, 3]


typedef int Item;

#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b) { Item t = a; a = b; b = t; }
#define cmpexch(a, b) { if (less(b, a)) exch(a, b); }

void insertion_sort(int *v, int l, int r) {
    for (int i = l + 1; i < r; i++) {
        for (int j = i; j > l && less(v[j], v[j-1]); j--) {
            cmpexch(v[j-1], v[j]);
        }
    }
}



int main(){
    int *vetor = NULL; // Ponteiro para o array
    int valor;
    int tamanho = 0; // Tamanho inicial do array

    while (scanf("%d", &valor) != EOF) {
        // Realloc para aumentar o tamanho do array dinamicamente
        vetor = (int *)realloc(vetor, (tamanho + 1) * sizeof(int));

        // if (vetor == NULL) {
        //     printf("Erro ao alocar memória\n");
        //     return 1;
        // }

        // Armazena o valor no final do array
        vetor[tamanho] = valor;
        tamanho++;
    } //ctrl+D pra terminar a leitura no terminal

   insertion_sort(vetor, 0, tamanho);

    printf("\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);

    return 0;
}