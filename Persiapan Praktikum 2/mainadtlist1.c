#include <stdio.h>
#include "adtlist1.c"

int main() {
	List L = MakeList();
	Set(&L, 0, 1);
	printf("L.A[0] = %d\n", Get(L,0)); 
	printf("FirstIdx = %d\n", FirstIdx(L));
	Set(&L, 1, 2);
	printf("L.A[1] = %d\n", Get(L,1));
	printf("FirstIdx = %d\n", FirstIdx(L));
//	Set(&L, 1, Mark);
//	printf("L.A[1] = %d\n", Get(L,1));
//	printf("LastIdx = %d\n", LastIdx(L));
	InsertFirst(&L, 10);
	printf("L.A[0] = %d\n", Get(L,0));
	printf("L.A[1] = %d\n", Get(L,1));
	printf("L.A[2] = %d\n", Get(L,2));
	return 0;
}
