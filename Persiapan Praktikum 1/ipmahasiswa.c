#include <stdio.h>
#include <stdbool.h>

bool IsWithinRange(float a, float b, float c) {
	return ((b<=a) && (a<=c));
}


int main() {
	float a,b,c, avg;
	int ip;
	int jlh_mahasiswa = 0;
	int lulus = 0;
	int tidak_lulus = 0;
	float jumlah = 0;
	
	scanf("%f", &ip);
	
	while (ip != -999) {
		if (IsWithinRange(ip, 0.00, 4.00)){
			jlh_mahasiswa +=1;
			jumlah += ip;
			if (IsWithinRange(ip, 2.75, 4.00)){
				lulus +=1;
			} else {
				tidak_lulus +=1;
			}
		} 
		scanf ("%d", &ip);
	}
	if (jlh_mahasiswa == 0) {
		printf("Tidak ada data");
	} else {
		avg = jumlah/jlh_mahasiswa;
		printf("Banyak mahasiswa = %d\n", jlh_mahasiswa);
		printf("Banyak yg lulus = %d\n", lulus);
		printf("Banyak yg tdk lulus = %d\n", tidak_lulus);
		printf("Rata-rata IP = %.2f\n", avg);
	}

	return 0;
}
