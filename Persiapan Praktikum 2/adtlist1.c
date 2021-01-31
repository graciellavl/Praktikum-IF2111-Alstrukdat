#include <stdio.h>
#include "adtlist1.h"

// Konstruktor

List MakeList() {
	List L;
	IdxType i;
	for (i=0; i < MaxEl; i++) {
		L.A[i] = Mark;
	}
	return L;
}

boolean IsEmpty(List L) {
	return (L.A[0] == Mark);
}

int Length(List L) {
	int i = 0;
	while (L.A[i] != Mark) {
		i += 1;
	}
	return i;
}

ElType Get(List L, IdxType i) {
	return L.A[i];
}

void Set(List *L, IdxType i, ElType v) {
	(*L).A[i] = v;
}

IdxType FirstIdx(List L) {
	int i = 0;
	while ((i < MaxEl) && (L.A[i] == Mark)) {
		i += 1;
	}
	return i;
}

IdxType LastIdx(List L) {
	int i = FirstIdx(L);
	while ((i < MaxEl) && (L.A[i] != Mark)) {
		i += 1;
	}
	return i;
}

boolean IsIdxValid (List L, IdxType i) {
	return (0 <= i) && (MaxEl >= i);
}

boolean IsIdxEff (List L, IdxType i) {
	return (FirstIdx(L) <= i) && (LastIdx(L) >= i);
}

void Search(List L, ElType X) {
	int i = FirstIdx(L);
	int j = LastIdx(L);
	boolean notFound = true;
	while ((i < j) && notFound ) {
		i += 1;
		if (L.A[i] == X) {
			notFound = false;
		}
	}
}

void InsertFirst(List *L, ElType X) {
	IdxType i = LastIdx(*L);
	IdxType j = FirstIdx(*L);
	while (i >= j) {
		Set(L, i+1, Get(*L,i));
		i -= 1;
	}
	Set(L, j, X);
}

//	IdxType i = FirstIdx(L);
//	IdxType j = LastIdx(L);
//	while (j >= i) {
//		Set(&L, j+1, Get(L,j));
//		j -= 1;
//	}
//	Set(&L, i, X);

//void InsertAt(List L, ElType X, IdxType i) {
//	int j = i;
//	while (j < LastIdx(L)) {
//		Set(&L, j+1, Get(L,j));
//	}
//	Set(L,i,X);
//}

void InsertLast(List L, ElType X) {
	if ((LastIdx(L) != Mark) && (FirstIdx(L) != 0)) {
		L.A[LastIdx(L) + 1] = X;
	}
}

void DeleteFirst(List L, ElType F) {
	int i = FirstIdx(L);
	while (i < LastIdx(L)) {
		L.A[i] = L.A[i+1];
	}
}

void DeleteAt(List L, ElType X, IdxType i) {
	int j = i;
	while (j < LastIdx(L)) {
		L.A[j] = L.A[j+1];
	}
}

void DeleteLast(List L, ElType F) {
	L.A[LastIdx(L)] = Mark;
}

void Concat(List L1, List L2) {
	List L3 = MakeList();
	int i = FirstIdx(L1);
	int j = FirstIdx(L2);
	int idx = 0;
	while (i < LastIdx(L1)) {
		L3.A[idx] = L1.A[i];
		idx += 1;
		i += 1;
	}
	while (j < LastIdx(L2)) {
		L3.A[idx] = L2.A[j];
		idx += 1;
		j += 1;
	}
}
