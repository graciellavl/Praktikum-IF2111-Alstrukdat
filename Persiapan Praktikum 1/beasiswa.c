#include <stdio.h>
#include <stdbool.h>

bool IsWithinRange(float a, float b, float c) {
	return ((b<=a) && (a<=c));
}

bool kategori (float ip, float pot) {
	if ((pot < 1) && (ip <3.5)) {
		printf("Berhak atas beasiswa kategori 1");
	} else if (ip < 2.0) {
		printf("Berhak atas beasiswa kategori 2");
	} else if ((ip>= 2.0) && (ip < 3.5)) {
		printf("Berhak atas beasiswa kategori 3");
	} else if ((ip >= 3.5) && (ip <=4)) {
		printf("Berhak atas beasiswa kategori 4");
	} else {
		printf("Tidak berhak atas kategori beasiswa manapun");
	}
	return 0;
}

int main () {
	float ip, pot;
	scanf("%f %f", &ip, &pot);
	kategori(ip, pot);
	return 0;
}
