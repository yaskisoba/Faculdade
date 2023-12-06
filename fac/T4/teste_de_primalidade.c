#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int a;
    scanf("%d", &a);

    if(a <= 0){
        return printf("Entrada invalida.\n");
    }
    else if(a == 1){
        return printf("nao\n");
    }
    else if(a == 2){
        return printf("sim\n"); 
    }
    else if(a % 2 == 0){
        return printf("nao\n");
    }

    int raiz = 1;
    while (raiz * raiz <= a) {
        raiz++;
    }
    raiz--;

    for(int i = 3; i <= raiz + 1; i+=2){
        if (a % i == 0 && a != i){
            return printf("nao\n");
        }
    }

    printf("sim\n");
    
    return 0;
}