#include <stdio.h>
#include <stdlib.h>

#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b){ Item t = a; a = b; b = t;}
#define cmpexch(a, b){if(less(b, a)) exch(a, b);}

typedef int Item;

void merge(Item *v, int l, int m, int r){
	int tam = r+1-l;
	
	int *aux = malloc(sizeof(int) *tam);
	
	int i = l;
	int j = m+1;
	int k = 0;

	while(i<=m && j<=r){
		if(v[i] <= v[j])
			aux[k++] = v[i++];
		else
			aux[k++] = v[j++];
	}

	while(i <= m) aux[k++] = v[i++];
	while(j <= r) aux[k++] = v[j++];

	k=0;
	for(i=l; i <= r; i++)
		v[i] = aux[k++];

	free(aux);
}

void merge2(Item *v, int l, int m, int r){
	int tam = r+1-l;
	
	int *aux = malloc(sizeof(int) *tam);
	
	int i = l;
	int j = m+1;
	int k = 0;

	while(k<tam){
		if(i>m)
			aux[k++] = v[j++];
		else if (j>r)
			aux[k++] = v[i++];
		else if(v[i] < v [j])
			aux[k++] = v[i++];
		else
			aux[k++] = v[j++];
	}

	k=0;
	for(i=l; i <= r; i++)
		v[i] = aux[k++];

	free(aux);
}

void mergeBU_sort(int *v, int l, int r){
	int tam = (r-l+1);
	
	for(int sz=1; sz<tam; sz = 2*sz){
		for(int lo=1; lo<tam-sz; lo+=2*sz){
			int hi = lo+2*sz - 1;
			if(hi>tam-1) hi=tam-1;
			
			merge(v, lo, lo+sz-1, hi);
		}
	}
}

void merge_sort(Item *v, int l, int r){
	if( l >= r) return;
	int m = (r+l)/2;
	
	merge_sort(v, l, m);
	merge_sort(v, m+1, r);
	merge2(v, l, m, r);
}

int main(){
	Item vetor[10] = {5, 0, 1, 7, 10, 6, 90, 8, 9, 10};

	merge_sort(vetor, 0, 9);

	return 0;
}