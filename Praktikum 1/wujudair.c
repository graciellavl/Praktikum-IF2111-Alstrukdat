/* 
NIM				: 18219075
Nama			: Graciella Valeska Liander
Tanggal			: 17 September 2020
Topik praktikum	: Pratikum 1
Deskripsi		: Program yang merepresentasikan wujud air berdasarkan suhu
*/

#include <stdio.h>

int main() {
	int suhu;
	
	scanf("%d", &suhu);
	if (suhu < 0 ) {
		printf("PADAT\n");
	} else if ( suhu == 0 ) {
		printf("PADAT-CAIR\n");
	} else if (( suhu > 0 ) && ( suhu < 100 )) {
		printf("CAIR\n");
	} else if (suhu == 100 ) {
		printf("CAIR-GAS\n");
	} else {
		printf("GAS\n");
	}
	return 0;
}
