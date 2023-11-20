#include <stdio.h>
#include <stdlib.h>

#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b){ Item t = a; a = b; b = t;}
#define cmpexch(a, b){if(less(b, a)) exch(a, b);}

typedef int Item;

int partitionLSEDGEWICK ( int *v , int l , int r ) { //primeiro elemento do array é o pivô/o mais a esquerda
    int i = l ;
    int j = r +1;
    int pivot = v [l];

    while (1) {
        while (v [++i] < pivot) if ( i == r ) break;
        while (pivot < v [--j]) if ( j == l ) break;
        if ( i >= j ) break;

        exch ( v[i], v[j]);
    }
    exch ( v[l], v[j]); 

    return j;

}

int partitionRSEDGEWICK ( int *v , int l , int r ) //o elemento mais a direita é o pivô/o último elemento
{
    int i = l -1;
    int j = r ;
    int pivot = v [r];

    while (i < j )
    {
        while (v [++i] < pivot ) ;
        while (v [--j] >= pivot && j > l ) ; // pivot <v[ - -j]
        if(i < j ) exch ( v[i], v[j]) ;
    }
    exch (v[i] ,v[r]) ;

    return i;
}

int partitionCORMEM(int *v, int l, int r) {
    int pivot = v[r];
    int j = l;
    int i = l;

    while (i < r) {
        if (less(v[i], pivot)) {
            exch(v[i], v[j]);
            i++;
        }
        i++;
    }

    exch(v[r], v[j]);

    return j;
}

int partition(int *v, int l, int r) {
    int i = l - 1, j = r, pivot = v[r];

    while (i < j) {
        while (v[++i] < pivot); // Avança i enquanto v[i] < pivot
        while (pivot < v[--j] && j > l); // Retrocede j enquanto v[j] > pivot e j está dentro dos limites
        if (i < j) {
            exch(v[i], v[j]); // Troca v[i] e v[j] se i < j
        }
    }

    exch(v[i], v[r]); // Coloca o pivô no lugar correto

    return i; // Retorna a posição final do pivô
}

void quick_sort_partition(int *v, int l, int r) {
    if (r <= l) {
        return;
    }

    int p = partition(v, l, r); // Particiona o array

    quick_sort_partition(v, l, p - 1); // Ordena a metade à esquerda do pivô
    quick_sort_partition(v, p + 1, r); // Ordena a metade à direita do pivô
}




void quick_sort (int *v , int l , int r )
{
    if(r <= l ) return;

    int p = partitionRSEDGEWICK (v, l, r);

    quick_sort (v, l ,p-1);
    quick_sort (v, p+1 ,r );
}

int main(){
    return 0;
}