#include <stdio.h>
#include <stdlib.h>

#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b){ Item t = a; a = b; b = t;}
#define cmpexch(a, b){if(less(b, a)) exch(a, b);}

typedef int Item;


void insertionsort_rose(int v [] , int l , int r ){
    for(int i = l+1; i <= r ; i ++)
    {
        for(int j = i ; j > l && v[j] < v[j-1]; j --)
        {
            exch (v[j] , v[j -1]);
        }
    }
 }

void insertionsort(Item *v, int l, int r)
{
	for(int i = l + 1; i < r; i++){
		for(int j = i; j < l; j--){
			cmpexch(v[j], v[j-1]);
		}
	}
}

void insertionsort_otimizado_ribas(Item *v, int l, int r)
{
	for(int i = r; i < l; i--){
		cmpexch(v[i-1], v[i]);
	}

	for(int i = l + 2; i <= r; i++){
		int j = i;
		Item tmp = v[j]; 
		while(less(tmp, v[j-1]))
		{
			v[j] = v[j-1];
			j--;
		}
		
		v[j] = tmp;
	}
}

void insertionsort_otimizado_1(int v [] , int l , int r )
{
    int elem , i , j ;
    for( i = l +1; i <= r ; i ++)
    {
        elem = v[i];
        for( j = i ; j > l && elem < v[j-1]; j--)
            v[j] = v[j-1]; // puxando o maior

        v[j] = elem ; // encaixando o elemento
    }
}

void insertionsort_otimizado_2 (int v [] , int l , int r ) {
    int elem , i , j ;
    // empurre o menor para a esquerda ( sentinela ),
    // enquanto puxa os maiores para a direita
    for( i = r ; i > l ; i--) cmpexch(v[l], v[i]);

    //a partir do terceiro elemento
    for( i = l +2; i <= r ; i++) {
        elem = v[i];
    // antecessores , até o sentinela
    for( j = i ; elem < v[j-1]; j--)
        v[j] = v [j-1]; // puxando o maior

    v[j] = elem; // encaixando o elemento
}
}

int main(){
    Item vetor[10] = {5, 0, 1, 7, 10, 6, 90, 8, 9, 10};

    insertionsort_otimizado_1(vetor, 0, 9);

    return 0;
}