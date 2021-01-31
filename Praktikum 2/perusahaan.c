/* 
NIM				: 18219075
Nama			: Graciella Valeska Liander
Tanggal			: 24 September 2020
Topik praktikum	: Pratikum 2
Deskripsi		: perusahaan
*/

#include <stdio.h>
#include "list.h"

int main() {
	int x; 
	scanf("%d", &x);
	List L1, L2;
	int i = 1;
	int j;
	while (i <= x ) {
		scanf("%d", &j);
		InsertLast(&L1, j);
		i += 1;
	}
	int k=0;
	int m;
	while ( k <= x ) {
		scanf("%d", &m);
		InsertLast(&L2, m);
		k+=1;
	}
	int a = 1;
	while ( a < x ){
		printf("%d %d\n", a, (Get(L1,a-1) + Get(L2, a-1)));
	}
	return 0;
}

