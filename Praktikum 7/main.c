#include <stdio.h>
#include "diantarakita.c"

int main() {
	List L;
	CreateEmpty(&L);
	if (IsEmpty(L)) {
		printf("isempty acc\n");
	}
	InsertLast(&L, 1);
	if (!IsEmpty(L)) {
		printf("isempty acc\n");
	}
	InsertFirst(&L, 2);
	InsertFirst(&L, 3);
	InsertLast(&L, 4);
	InsertFirst(&L, 5);
	if (FSearch(L, 3)) {
		printf("FSearch acc\n");
	}
	PrintInfo(L);
	MoveLastToFirst(&L);
	PrintInfo(L);
	return 0;
}
