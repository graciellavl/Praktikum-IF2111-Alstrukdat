#include "list.h"
#include <stdlib.h>

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk List kosong dengan ukuran InitialSize
 */
List MakeList() {
	List L;
	L.Capacity = InitialSize;
	L.A = (ElType *) malloc (InitialSize * sizeof(ElType));
	L.Neff = 0;
	return L;
}

/**
 * Destruktor
 * I.S. List terdefinisi
 * F.S. list->A terdealokasi
 */
void DeallocateList(List *list) {
	(*list).Neff = 0;
	(*list).Capacity = 0;
	free(list->A);
}

/**
 * Fungsi untuk mengetahui apakah suatu list kosong.
 * Prekondisi: list terdefinisi
 */
boolean IsEmpty(List list) {
	return (list.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif list, 0 jika tabel kosong.
 * Prekondisi: list terdefinisi
 */
int Length(List list) {
	return list.Neff;
}

/**
 * Mengembalikan elemen list L yang ke-I (indeks lojik).
 * Prekondisi: list tidak kosong, i di antara 0..Length(list).
 */
ElType Get(List list, IdxType i) {
	return list.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: list terdefinisi
 */
int GetCapacity(List list) {
	return list.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: list terdefinisi, i di antara 0..Length(list).
 */
void InsertAt(List *list, ElType el, IdxType i) {
	if(list->Neff == list->Capacity) {
		list->Capacity *= 2;
		List temp;
		temp = MakeList();
		IdxType idx;
		for (idx =0; idx < list->Neff; idx++) {
			if (idx < i) {
				temp.A[i] = Get(*list, i);			
			} else if (idx > i) {
				temp.A[i+1] = Get(*list, i);
			} else temp.A[i];
		}
		DeallocateList(list);
		list->A = temp.A;		
	}
	list->A[i] = el;
	list->Neff += 1;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir list.
 * Prekondisi: list terdefinisi
 */
void InsertLast(List *list, ElType el) {
	if(list->Neff == list->Capacity) {
		list->Capacity *= 2;
		List temp;
		temp = MakeList();
		IdxType i;
		for (i =0; i < list->Neff; i++) {
			temp.A[i] = Get(*list, i);
		}
		DeallocateList(list);
		list->A = temp.A;		
	}
	list->A[list->Neff] = el;
	list->Neff += 1;
}

/**
 * Fungsi untuk menambahkan elemen baru di awal list.
 * Prekondisi: list terdefinisi
 */
void InsertFirst(List *list, ElType el) {
	if(list->Neff == list->Capacity) {
		list->Capacity *= 2;
		List temp;
		temp = MakeList();
		IdxType i;
		for (i =0; i < list->Neff; i++) {
			temp.A[i+1] = Get(*list, i);
		}
		DeallocateList(list);
		list->A = temp.A;
	}
	list->A[0] = el;
	list->Neff += 1;
}


