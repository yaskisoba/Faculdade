#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *v, int l, int r){
    for(int i = l; i < r; i++){
        for(int j = l; j < r; j++){
            if(v[j+1] < v[j]){
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
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

    bubble_sort(vetor, 0, tamanho-1);

    printf("\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);

    return 0;
}