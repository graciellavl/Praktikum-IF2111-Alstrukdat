#include <stdio.h>
#include "point.c"

int main() {
	POINT P, P1;
	float deltaX, deltaY;
	
	printf("Absis Ordinat\n");
	BacaPOINT(&P);
	printf("Titik yg dibaca\n");
	TulisPOINT(P);
	printf("\n");

	printf("Absis Ordinat\n");
	BacaPOINT(&P1);
	printf("Titik yg dibaca\n");
	TulisPOINT(P1);
	printf("\n");
	
	if (EQ(P, P1)) {
		printf("EQ true\n");
	} else {
		printf("EQ false\n");
	}
	
	if (NEQ(P,P1)){
		printf("NEQ true\n");
	} else {
		printf("NEQ false\n");
	}
}
