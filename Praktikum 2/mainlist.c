#include <stdio.h>
#include "list.c"

int main () {
	List L;
	int i = 2;
	Set(&L, 0, 1);
	printf("L.A[0] = %d\n", Get(L,0)); 
	Set(&L, 1, 2);
	printf("L.A[1] = %d\n", Get(L,1));
//	Set(&L, 1, Mark);
//	printf("L.A[1] = %d\n", Get(L,1));
//	printf("LastIdx = %d\n", LastIdx(L));
	InsertLast(&L, 10);
	printf("L.A[0] = %d\n", Get(L,0));
	printf("L.A[1] = %d\n", Get(L,1));
	printf("L.A[2] = %d\n", Get(L,2));
	printf("L.A[3] = %d\n", Get(L,3));
	printf("L.A[4] = %d\n", Get(L,4));
}


