#include <stdio.h>

int main(){
    int num;
    int tam;
    int aux = 0;
    int maior_num;

    scanf("%d", &tam);
    scanf("%d", &maior_num);

    while(aux < tam - 1){
        scanf("%d", &num);
        if(num > maior_num){
            maior_num = num;
        }
        aux++;

    }

    // for(int i = 0; i < tam-1; i++){
    //     int min = i;
    //     int aux_order;
    //     for(int j = (i+1); j< tam; j++){
    //         if(num[j] < num[min])
    //         min = j;
    //     }
    //     if(i != min){
    //         aux_order = num[i];
    //         num[i] = num[min];
    //         num[min] = aux_order;
    //     }
    // }

    printf("%d\n", maior_num);

    return 0;
}