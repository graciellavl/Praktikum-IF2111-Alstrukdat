#ifndef ADTList1
#define ADTList1

#include "boolean.h"

#define MaxEl 100
#define Mark -9999
#define InvalidIdx -1

#define IdxType int
#define ElType int

typedef struct {
	ElType A[MaxEl];
} List;

#define List(i) L.A(i)

// Konstruktor

List MakeList();

boolean IsEmpty(List L);

int Length(List L);

ElType Get(List L, IdxType i);

void Set(List *L, IdxType i, ElType v);

IdxType FirstIdx(List L);

IdxType LastIdx(List L);

boolean IsIdxValid (List L, IdxType i);

boolean IsIdxEff (List L, IdxType i);

void Search(List L, ElType X);

void InsertFirst(List *L, ElType X);

void InsertAt(List L, ElType X, IdxType i);

void InsertLast(List L, ElType X);

void DeleteFirst(List L, ElType F);

void DeleteAt(List L, ElType X, IdxType i);

void DeleteLast(List L, ElType F);

void Concat(List L1, List L2);

#endif
