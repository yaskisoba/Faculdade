#include <stdio.h>
#include <stdlib.h>

#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b){ Item t = a; a = b; b = t;}
#define cmpexch(a, b){if(less(b, a)) exch(a, b);}

typedef int Item;

void bubble_sort(Item *v, int l, int r){
    int swap = 1;
    for(int i = l; i < r && swap; i++){
        swap = 0;
        for(int j = l; j < r; j++){
            if(less(v[j+1], v[j])){
                exch(v[j+1], v[j]);
                swap = 1;
            }
        }
    }
}


int main(){
    Item vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    bubble_sort(vetor, 0, 10);

    return 0;
}