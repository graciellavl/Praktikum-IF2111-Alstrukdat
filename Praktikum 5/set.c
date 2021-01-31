// Nama	: Graciella Valeska Liander
// NIM	: 18219075

#include "set.h"
#include <stdio.h>

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

//#define false 0
//#define true 1
//#define Nil 0
//#define MaxEl 10
//
//typedef int bool;
//typedef int infotype;
//typedef int address;
//
//typedef struct
//{
//    infotype Elements[MaxEl];
//    address Count;
//} Set;

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S) {
	(*S).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsEmpty(Set S) {
	return S.Count == Nil;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

bool IsFull(Set S) {
	return S.Count == MaxEl;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt) {
	int i;
	bool found = 0;
	for (i = 0; i < S->Count && found==0 ; i++) {
		if (S->Elements[i] == Elmt) {
			found = 1;
		}
	}
	if (found == 0) {
		S->Elements[S->Count] = Elmt;
		S->Count ++;
	}
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, infotype Elmt) {
	int i = 0;
	bool found = false;
	while (i < (*S).Count && !found){
		if (S->Elements[i] == Elmt) {
			found = true;
			while (i < S->Count-1) {
				S->Elements[i] = S->Elements[i+1];
				i++;
			}
			S->Count--;
		}
		i++;
	}
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

bool IsMember(Set S, infotype Elmt) {
	int i;
	for (i = 0; i < S.Count; i++) {
		if (S.Elements[i] == Elmt) {
			return true;
		}
	}
	return false;
}
/* Mengembalikan true jika Elmt adalah member dari S */

