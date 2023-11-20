#include <stdio.h>

int f91(int n) {
    if (n >= 101) {
        return n - 10;
    } else {
        return f91(f91(n + 11));
    }
}

int main() {
    int input[250000];
    int condition = 0;

    int i = 0;
    while (i < 250000) {
        scanf("%d", &condition);
        if (condition == 0) {
            break;
        } else {
            input[i] = condition;
            i++;
        }
    }

    for (int j = 0; j < i; j++) {
        if (input[j] != 0) {
            int maldicao = f91(input[j]);
            printf("f91(%d) = %d\n", input[j], maldicao);
        }
    }

    return 0;
}
