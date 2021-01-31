#include <stdio.h>
#include <stdbool.h>

#include "adt.h"

// Soal 1
/* 
	{ Menghasilkan true jika list simetrik
	List disebut simetrik jika:
	elemen pertama = elemen terakhir,
	elemen kedua = elemen sebelum terakhir, dan seterusnya
	List kosong adalah list simetrik }
*/
bool IsSimetrik (L) {
	
}

// Soal 2
/*
	{ Prekondisi: L1 dan L2 berukuran sama dan tidak kosong
	Mengirimkan L1+L2, yaitu penjumlahan setiap elemen L1
	dan L2 pada indeks yang sama }
*/
List PlusList (L1, L2) {
	return L1+L2;
}

// Soal 3
/*
	{ Mengirimkan true jika L1=L2, yaitu jika ukuran L1=L2
	dan semua elemen L1 dan L2 pada indeks yang sama bernilai sama }
*/
bool IsEQ (L1, L2) {
	
}

// Soal 4
/*
	{ Search apakah ada elemen list L yang bernilai X.
	Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X.
	Jika tidak ada, mengirimkan InvalidIdx.
	Menghasilkan indeks tak terdefinisi (InvalidIdx) jika list kosong.
	Memakai skema searching tanpa Boolean. }
*/
IdxType Search (L, X) {
	
}


// Soal 5
/*
	{ Menghasilkan berapa banyak kemunculan elemen bernilai X di List L.
	Jika list kosong, menghasilkan 0 }
*/
int CountX (L, X) {
	
}

// Soal 6
/*
	{ Menambahkan X sebagai elemen terakhir list, pada list dengan elemen unik }
	{ I.S. List L boleh kosong, tetapi tidak penuh }
	{ dan semua elemennya bernilai unik, tidak terurut }
	{ F.S. Menambahkan X sebagai elemen terakhir L, }
	{ jika belum ada elemen yang bernilai X. }
	{ Jika sudah ada elemen list yang bernilai X }
	{ maka I.S. = F.S. }
*/
void InsertUniq (L, X) {
	
}
