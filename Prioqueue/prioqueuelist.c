/* Nama : Graciella Valeska Liander */
/* NIM	: 18219075*/

/* File: prioqueuelist.h */
#include "prioqueuelist.h"
#include <stdio.h>
#include <stdlib.h>

/* Prototype manajemen memori */
void Alokasi(address *P, int PQ, ElType X) {
	*P = (address)malloc(sizeof(ElType));
	if (*P != Nil) {
		Info(*P) = X;
		Next(*P) = Nil;
		Prio(*P) = PQ;
	} 
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/* P=Nil jika alokasi gagal */
void Dealokasi(address P) {
	free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

boolean IsEmpty(PrioQueue Q) {
	return Head(Q) == Nil;
}
/* Mengirim true jika Q kosong: HEAD(Q)=Nil */
int NBElmt(PrioQueue Q) {
	if (!IsEmpty(Q)) {
		int count = 0;
		address P = Head(Q);
		while (P != Nil) {
			count += 1;
			P = Next(P);
		}
		return count;
	} else {
		return 0;
	}
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmpty(PrioQueue *Q) {
	Head(*Q) = Nil;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Enqueue/Dequeue ***/
void Enqueue(PrioQueue *Q, int PQ, ElType X) {
	address A;
	Alokasi(&A, PQ, X);
	if (A != Nil) {
		if (!IsEmpty(*Q)) {
			address P = Head(*Q);
			boolean enq = false;
			while (Next(P) != Nil && !enq) {
				if (Prio(P) < PQ) {
					enq = true;
				} else {
					P = Next(P);
				}
			}
			if (P == Head(*Q)) {
				Next(A) = Head(*Q);
				Head(*Q) = A;
			} else {
				Next(A) = Next(P);
				Next(P) = A;
			}
		} else {
			Head(*Q) = A;
		}
	}
}
/* Proses: Mengalokasi node X dan menambahkan X pada Q sesuai dengan prioritas
jika alokasi berhasil; jika alokasi gagal Q tetap */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi elemen Q sesuai dengan urutan prioritas */
void Dequeue(PrioQueue *Q, ElType *X) {
	address P = Head(*Q);
	*X = Info(P);
	if (Next(Head(*Q)) == Nil) { // cuma satu elemen
		CreateEmpty(Q);
	} else {
		Head(*Q) = Next(Head(*Q));
	}
	Dealokasi(P);
}
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
