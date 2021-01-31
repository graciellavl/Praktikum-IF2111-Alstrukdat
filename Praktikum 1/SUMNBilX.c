/* 
NIM				: 18219075
Nama			: Graciella Valeska Liander
Tanggal			: 17 September 2020
Topik praktikum	: Pratikum 1
Deskripsi		: Program mengkonversi notasi algoritmik dalam bahasa c
*/

#include <stdio.h>

int main() {
	int i = 1;
	int sum = 0;
	int x;
	scanf("%d", &x);
	while (x != 9999) {
		printf("%d\n", x);
		sum += x;
		i += 1;
		scanf("%d", &x);
	}
	printf("Jumlah : %d\n", sum);
	printf("Banyaknya bilangan : %d\n", i-1);
	
	return 0;
}
