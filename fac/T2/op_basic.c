#include <stdio.h>

int main(){
    int a;
    int b;
    int c;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    //aritmética básica: soma e subtração
    int sum = a + b;
    int diff = a - b;

    //lógica: and, or e xor
    int and_logic = a & b;
    int or_logic = a | b;
    int xor_logic = a ^ b;

    int m = c & 31;
    
    int desloca_a = a << m;
    int desloca_b = b >> m;


    printf("ADD: %d \n", sum);
    printf("SUB: %d\n", diff);
    printf("AND: %d\n", and_logic);
    printf("OR: %d\n", or_logic);
    printf("XOR: %d\n", xor_logic);
    printf("MASK: %d\n", m);
    printf("SLL(%d): %d\n", m, desloca_a);
    printf("SRL(%d): %d\n", m, desloca_b);

    return 0;
}