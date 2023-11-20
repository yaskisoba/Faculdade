#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    fgets(str, 100, stdin);

    size_t len = strlen(str);
    int end = len - 2;

    for (int i = 0; i < end; i++) {
        if (str[i] == 'x') {
            for (int j = i; j < end; j++) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
            i--;
            end--;
        }
    }

    printf("%s", str);

    return 0;
}
