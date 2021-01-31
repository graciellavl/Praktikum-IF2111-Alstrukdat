// Nama	: Graciella Valeska Liander
// NIM	: 18219075

#include "map.h"
#include <stdio.h>

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M) {
	(*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsEmpty(Map M) {
	return M.Count == Nil;	
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

bool IsFull(Map M) {
	return M.Count == MaxEl;
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k) {
	int i = 0;
	while (i < M.Count) {
		if (M.Elements[i].Key == k) {
			return M.Elements[i].Value;
		} 
		i++;
	}
	return Nil;	
}
/* Mengembalikan nilai value dengan key k dari M */

void Insert(Map *M, keytype k, valuetype v){
	if (!IsMember(*M, k)) {
		(*M).Elements[(*M).Count].Value = v;
		(*M).Count++;
	}
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete(Map *M, keytype k) {
	if (IsMember(*M, k)) {
		int i = 0;
		bool found = false;
		while (i < (*M).Count && !found) {
			if ((*M).Elements[i].Key == k) {
				(*M).Count--;
				while (i < (*M).Count) {
					(*M).Elements[i] = (*M).Elements[i+1];
					i++;				
				}
				found = true;
			}
			i++;
		}
	}
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

bool IsMember(Map M, keytype k) {
	int i = 0;
	bool found = false;
	while (i < M.Count && !found) {
		if (M.Elements[i].Key == k) {
			found = true;
		}
		i++;
	}
	return found;
}
/* Mengembalikan true jika k adalah member dari M */

