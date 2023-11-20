#include <stdio.h>
#include <stdlib.h>


// [12, 0, 45, 90, 1, 2, 3]

void selection_sort(int *v, int l, int r){ 
    for(int i = l; i < r; i++){ 
        int min = i;
        for(int j = i + 1; j < r; j++){ 
            if(v[j] < v[min]){ 
                min = j; 
            }
        }
        int temp = v[min];
        v[min] = v[i];
        v[i] = temp; 
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

    selection_sort(vetor, 0, tamanho);

    printf("\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);

    return 0;
}