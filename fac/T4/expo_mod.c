#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool testePrimo(int a){
    if(a <= 0){
       return false;
    }
    else if(a == 1){
        return false;
    }
    else if(a == 2){
        return true;
    }
    else if(a % 2 == 0){
        return false;
    }

    int raiz = 1;
    while (raiz * raiz <= a) {
        raiz++;
    }
    raiz--;

    for(int i = 3; i <= raiz + 1; i+=2){
        if (a % i == 0 && a != i){
            return false;
        }
    }

    return true;
}

int expMod(int base, int exp, int mod) {
    int result = 1;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * (long long)base) % mod;  // Usando long long para evitar estouro
        }
        base = (base * (long long)base) % mod;
        exp /= 2;
    }

    return result;
}


int main(){
    int n1, n2, n3;

    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);

    if((n1 >= 1 && n1 < 65535) && (n2 >= 1 && n2 < 65535) && (n3 >= 1 && n3 < 65535)){
        bool n3_eh_primo = testePrimo(n3);
        int expo = 1;
        int j = 0;

        if(n3_eh_primo){
            int mod = expMod(n1, n2, n3);
            return printf("A exponencial modular %d elevado a %d (mod %d) eh %d.\n", n1, n2, n3, mod);
        }else{
            return printf("O modulo nao eh primo.\n");
        }
        
    }

    return printf("Entradas invalidas.\n");

    


    return 0;
}