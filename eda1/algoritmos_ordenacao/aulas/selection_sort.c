#include <stdio.h>
#include <stdlib.h>

#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b){ Item t = a; a = b; b = t;}
#define cmpexch(a, b){if(less(b, a)) exch(a, b);}

typedef int Item;

void selectionsort(Item *v, int l, int r){
    for(int i = l; i < r; i++){
        int min = i;
        for (int j = i + 1; j <= r; j++){
            if(less(v[j], v[min])){
                min = j;
            }
        }
        exch(v[min], v[i])
    }
}

void selectionsortRec(Item *v, int l, int r){
    if(l == r) return;

    int min = l;

    for(int j = l + 1; j <= r; j++){
        if(less(v[j], v[min]))
        {
            min = j;
        }
    }
    exch(v[min], v[l]);
    selectionsortRec(v, l + 1, r);
}

int main(){
    // Item vetor[10] = {12, 3, 2, 4, 6, 90, 1239, 89, 0, 10};
    Item vetor[10000];

    for(int i = 0; i < 10; i++){
        vetor[i] = rand();
    }

    // selectionsort(vetor, 0, 9);
    selectionsortRec(vetor, 0, 9999);

    return 0;
}

