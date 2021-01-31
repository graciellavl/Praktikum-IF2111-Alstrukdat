#include "listlinier.c"
#include <stdio.h>
//#include <stlib.h>

int main() {
	printf("start\n");
	List L; 			// deklarasi list
	CreateEmpty(&L);	// inisiasi list
	if (IsEmpty(L)) {
		printf("List kosong\n");
	} else {
		printf("List ga kosong\n");
	}
	
	/* Cek Fungsi InsV*/
	InsVFirst(&L, 1);	
	InsVLast(&L, 5);
	PrintInfo(L);
	printf("\n");
	if (IsEmpty(L)) {
		printf("List kosong\n");
	} else {
		printf("List ga kosong\n");
	}
	
	/* Cek Fungsi Search */
	if (Search(L, 3) != Nil){
		printf("Angka ketemu\n");
	} else {
		printf("Angka ga ketemu\n");
	}
	
	/* Cek Fungsi DelV*/
	infotype X;
	DelVFirst(&L, &X);
	printf("elemen pertama yg dihapus = %d\n", X);
	
	infotype Y;
	DelVLast(&L, &Y);
	printf("elemen terakhir yg dihapus = %d\n", Y);
	
	PrintInfo(L);
	printf("\n");
	
	/* Cek Fungsi tambahan*/
	printf("Ini nilai maksnya %d", Max(L));
	printf("\n");
	printf("end");
	return 0;
}
