#include <stdio.h>
#include <stdlib.h>

#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b){ Item t = a; a = b; b = t;}
#define cmpexch(a, b){if(less(b, a)) exch(a, b);}

typedef int Item;

void shellsort(Item *v, int l, int r){
    int h = 1;
    while(h < (r-l+1)/3) h=3*h+1;

    while(h>=1){
        for(int i = l+h; i<=r; i++){
            for(int j = i; j>= l+h && v[j]<v[j-h]; j-=h){
                exch(v[j], v[j-h]);
            }
        }

        h = h/3;
    }
}

int main(){
    Item vetor[10] = {5, 0, 1, 7, 10, 6, 90, 8, 9, 10};

    shellsort(vetor, 0, 9);

    return 0;
}