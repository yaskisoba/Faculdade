#include <stdio.h>
#include <stdint.h>

void float_to_binary(float num) {
    uint32_t binary_representation;
    memcpy(&binary_representation, &num, sizeof(float));

    // Obter o sinal
    int sign_bit = (binary_representation >> 31) & 1;
    char sign = (sign_bit == 0) ? '+' : '-';

    // Obter o expoente
    int exponent = (binary_representation >> 23) & 0xFF;
    exponent -= 127;  // Remover o bias

    // Obter a mantissa
    uint32_t mantissa = binary_representation & 0x7FFFFF;

    printf("%f\n", num);
    printf("%c\n", sign);
    printf("%d\n", exponent);
    printf("%08X\n", mantissa);
}

int main() {
    float num;
    scanf("%f", &num);

    float_to_binary(num);

    return 0;
}
