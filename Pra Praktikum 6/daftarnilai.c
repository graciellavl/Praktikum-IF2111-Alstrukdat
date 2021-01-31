// Nama	: Graciella Valeska Liander
// NIM	: 18219075

// daftarnilai.c

#include <stdio.h>
#include "listlinier.h"

int main() {
	List L;
	CreateEmpty(&L);
	int X;
	scanf("%d", &X);
	while ((X >= 0) && (X <=100)){
		InsVLast(&L, X);
		scanf("%d", &X);
	}
	if (NbElmt(L) > 0) {
		printf("%d\n", NbElmt(L));
		printf("%d\n", Max(L));
		printf("%d\n", Min(L));
		printf("%.2f\n", Average(L));
		PrintInfo(L);
		printf("\n");
		InversList(&L);
		PrintInfo(L);
		printf("\n");
	} else {
		printf("Daftar nilai kosong\n");
	}
	return 0;
}
