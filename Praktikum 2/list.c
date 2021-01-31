/* 
NIM				: 18219075
Nama			: Graciella Valeska Liander
Tanggal			: 24 September 2020
Topik praktikum	: Pratikum 2
Deskripsi		: Implementasi list.h
*/

#include <stdio.h>
#include "list.h"
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika L adalah List, cara deklarasi dan akses: */
/* Deklarasi : L : List */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen list
 * L.Neff untuk mengetahui banyaknya elemen
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong */
void MakeEmpty (List *T) {
	(*T).Neff = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length (List L) {
	return L.Neff;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
/* *** Daya tampung container *** */
int MaxLength (List L) {
	return IdxMax - IdxMin + 1;
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh list */
/* *** Selektor INDEKS *** */
IdxType FirstIdx (List L) {
	return IdxMin;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType LastIdx (List L) {
	return L.Neff - 1;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
ElType Get (List L, IdxType i) {
	return L.A[i];
}
/* Prekondisi : list tidak kosong, i antara FirsLIdx(T)..LasLIdx(T) */
/* Mengirimkan elemen list yang ke-i */

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set (List *T, IdxType i, ElType v) {
	(*T).A[i] = v;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
void SetNeff (List *L, IdxType N) {
	(*L).Neff = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (List L, IdxType i) {
	return (i <= IdxMax) && (i >= IdxMin);
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/
boolean IsIdxEff (List L, IdxType i) {
	return (i >= IdxMin) && (i < L.Neff);
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
IdxType Search (List L, ElType v) {
	IdxType i = IdxMin;
	IdxType j = L.Neff;
	boolean notFound = true;
	for (i=FirstIdx(L); ((i<L.Neff) && notFound); i++) {
		if(Get(L,i) == v) notFound = false;
	}
	if (notFound) {
		return IdxUndef;
	} else {
		return i;
	}
}
/* I.S. L, i, v terdefinisi.
/* F.S. Mengembalikan indeks lojik elemen pertama L yang bernilai v (jika ada), */
/* atau mengembalikan IdxUndef jika tidak ada. */
void InsertFirst (List *L, ElType v) {
	IdxType j = IdxMin;
	IdxType i = (*L).Neff;
	while (i >= j) {
		Set(L, i+1, Get(*L,i));
		i -= 1;
	}
	(*L).Neff += 1;
	Set(L, IdxMin, v);
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */
void InsertAt (List *L, IdxType i, ElType v) {
	IdxType j = (*L).Neff;
	(*L).Neff += 1;
	while ( j >= i ) {
		Set(L, i+1, Get(*L,i));
		i -= 1;
	}
	Set(L, i, v);
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
void InsertLast (List *L, ElType v) {
	if ((*L).Neff == 0) {
		Set(L, (*L).A[IdxMin], v);
	} else {
		Set(L, (*L).Neff-1, v);	
		(*L).Neff += 1;
	}
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
void DeleteFirst (List *L, ElType *F) {
	IdxType i = IdxMin;
	IdxType j = (*L).Neff;
	*F = Get(*L, IdxMin);
	while (i <= j) {
		Set(L, i, Get(*L,i+1));
		i += 1;
	}
	(*L).Neff -= 1;
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
void DeleteAt (List *L, IdxType i) {
	IdxType j = (*L).Neff;
	while ( i >= j ) {
		Set(L, i, Get(*L,i+1));
		i -= 1;
	}
	(*L).Neff -= 1;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */
void DeleteLast (List *L, ElType *F) {
	List *L1;
	MakeEmpty(L1);
	IdxType i = 0;
	while (i < (*L).Neff-1) {
		Set(L1, i, Get(*L, i));
		i += 1;
	}
	*F = Get(*L, (*L).Neff);
	(*L).Neff -= 1;
	MakeEmpty(L);
	i = 0;
	while (i <= (*L).Neff) {
		Set(L, i, Get(*L1, i));
	}
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
void Concat (List L1, List L2, List *L3) {
	MakeEmpty(L3);
	IdxType i = 1;
	IdxType idxL1 = IdxMin;
	IdxType idxL2 = IdxMin;
	IdxType idxL3 = IdxMin;
	while (i <= L1.Neff) {
		Set(L3, idxL3, Get(L1, idxL1));
		i += 1;
		idxL1 += 1;
	}
	i = 0;
	while (i < L2.Neff) {
		Set(L3, idxL3, Get(L2, idxL2));
		i += 1;
		idxL2 += 1;
	}
}
/* I.S. L1 ? L2, L1 ? L3, dan L3 ? L2; L1, L2 mungkin kosong */
/* F.S. L3 adalah hasil Konkatenasi ("Menyambung") dua buah list, L2 */
/* ditaruh di belakang L1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty (List L) {
	return L.Neff == 0;
}
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

