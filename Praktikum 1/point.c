/* 
NIM				: 18219075
Nama			: Graciella Valeska Liander
Tanggal			: 17 September 2020
Topik praktikum	: Pratikum 1
Deskripsi		: Implementasi point.h
*/

#include <stdio.h>
#include <math.h>
#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */

/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y) {
	POINT P;
	Absis(P) = X;
	Ordinat(P) = Y;
	return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P) {
	float X, Y;
	scanf("%f", &X);
	scanf("%f", &Y);
	*P = MakePOINT(X,Y);
}

void TulisPOINT (POINT P) {
	printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}
           

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2) {
	return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2){
	return !EQ(P1, P2);
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P) {
	return((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX (POINT P) {
	return(Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P) {
	return(Absis(P) == 0);
}

int Kuadran (POINT P) {
	if ((Absis(P) > 0) && (Ordinat(P) > 0)) {
		return 1;
	} else if ((Absis(P) < 0) && (Ordinat(P) > 0)) {
		return 2;
	} else if ((Absis(P) < 0) && (Ordinat(P) < 0)) {
		return 3;
	} else if ((Absis(P) > 0) && (Ordinat(P) < 0)) {
		return 4;
	}
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT PlusDelta (POINT P, float deltaX, float deltaY) {
	return (MakePOINT(Absis(P) + deltaX, Ordinat(P) + deltaY));
}

void Geser (POINT *P, float deltaX, float deltaY) {
	float X, Y;
	X = (*P).X + deltaX;
	Y = (*P).Y + deltaY;
	*P =  MakePOINT(X,Y);
}

float Jarak0 (POINT P) {
	return sqrt(Absis(P)*Absis(P) + Ordinat(P)*Ordinat(P));	
}

float Panjang (POINT P1, POINT P2) {
	return sqrt((Absis(P1) - Absis(P2))*(Absis(P1) - Absis(P2)) + (Ordinat(P1) - Ordinat(P2))*(Ordinat(P1) - Ordinat(P2)));	
}


