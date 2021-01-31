#include <stdio.h>
#include "mesinkata1.c"

int main() {
	STARTKATA();
	while (!EndKata) {
		for (int i=0; i<CKata.Length; i++) {
			printf(" %c", CKata.TabKata[i])
		}
		printf("\n");
		ADVKATA();
	}
	return 0;
}
