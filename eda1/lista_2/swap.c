#include <stdio.h>

void swap(int *a, int *b){
    int troca = *a;
    *a = *b;
    *b = troca;
}