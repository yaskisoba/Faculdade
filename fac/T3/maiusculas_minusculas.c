#include <stdio.h>

int main(){
    char op;
    int tam;

    scanf("%c", &op);
    scanf("%d", &tam);
    getchar();

    char string[tam + 1];

    fgets(string, sizeof(string), stdin);
    
    if(op == 'M'){
        for(int i = 0; i < tam; i++){
            if(string[i] >= 'a' && string[i] <= 'z'){
                string[i] = string[i] - 'a' + 'A';
            }
        }
    }else if (op == 'm'){
        for(int i = 0; i < tam; i++){
            if(string[i] >= 'A' && string[i] <= 'Z'){
                string[i] = string[i] - 'A' + 'a';
            }
        }
    }else if (op == 'c'){
        int i = 0;
        while (string[i] != '\0') {
        // Verifica se o caractere atual é uma letra e se é o primeiro caractere
            if ((i == 0 || string[i - 1] == ' ') && (string[i] >= 'a' && string[i] <= 'z')) {
                string[i] = string[i] - 'a' + 'A';  // Converte para maiúscula usando a tabela ASCII
            }
            i++;
        }
    }

    printf("%s\n", string);

    return 0;
}