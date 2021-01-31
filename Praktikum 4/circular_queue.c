// Nama	: Graciella Valeska Liander
// NIM	: 18219075

/* MODUL CIRCULAR QUEUE */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Implementasi Queue menggunakan circular buffer (Alternatif III) */

/* Nilai untuk indeks yang tidak terdefinisi */
//#define NIL -999

# include "circular_queue.h"
# include "boolean.h"
# include <stdlib.h>
# include <stdio.h>


//typedef struct { ElType * Tab;  /* tabel penyimpan elemen */
//                 IdxType HEAD;  /* indeks elemen paling awal (terdepan) */
//                 IdxType TAIL;  /* indeks tempat menambah elemen baru */
//                 int MaxEl;     /* kapasitas jumlah elemen */
//               } Queue;
/* Definisi Queue kosong: HEAD=NIL; TAIL=NIL. */

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q) {
	return Q.HEAD == NIL && Q.TAIL == NIL;
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q) {
	return (Q.TAIL + 1)%Q.MaxEl == Q.HEAD;
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int Length (Queue Q) {
	if (!IsEmpty(Q)) {
		if (Q.HEAD > Q.TAIL) {
			return Q.HEAD - Q.TAIL + 1;
		} else {
			return Q.TAIL - Q.HEAD + 1;
		}
	} else {
		return 0;
	}
}
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
int MaxLength (Queue Q) {
	return Q.MaxEl;
}
/* Mengirimkan kapasitas jumlah elemen Q */

/* *** Kreator *** */
Queue CreateQueue (int Max) {
	Queue Q;
	Q.Tab = (ElType *) malloc (Max * sizeof(int));
	if (Q.Tab != NULL) {
		Q.MaxEl = Max;
	} else {
		Q.MaxEl = 0;
	}
	Q.HEAD = NIL;
	Q.TAIL = NIL;
	return Q;
}
/* Proses : Melakukan alokasi memori, membuat sebuah Q kosong */
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/*   Jika alokasi berhasil, Tab dialokasi berukuran Max */
/*   Jika alokasi gagal, Q kosong dengan MaxEl=0 */

/* *** Destruktor *** */
void DeleteQueue (Queue * Q) {
	(*Q).MaxEl = 0;
	(*Q).HEAD = NIL;
	(*Q).TAIL = NIL;
	free((*Q).Tab);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. membebaskan memori Tab, Q.MaxEl di-set 0 */

/* *** Primitif Add/Delete *** */
void Push (Queue * Q, ElType X) {
	if (!IsEmpty(*Q)) {
		(*Q).TAIL = ((*Q).TAIL +1)%((*Q).MaxEl);
		(*Q).Tab[(*Q).TAIL] = X; 
	} else {
		(*Q).HEAD = 0;
		(*Q).Tab[0] = X;
		(*Q).TAIL = 0;
	}
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru,
        TAIL "maju" dengan mekanisme circular buffer
        Jika Q kosong, HEAD dimulai dari 0 */
ElType Pop (Queue * Q) {
	ElType X;
	X = (*Q).Tab[(*Q).HEAD];
	Q->Tab[(*Q).HEAD] = NIL;
	if ((*Q).HEAD == (*Q).TAIL) {
		(*Q).HEAD = NIL;
		(*Q).TAIL = NIL;
	} else {
		(*Q).HEAD = ((*Q).HEAD + 1)%((*Q).MaxEl);
	}
	return X;
}
/* Proses: Menghapus indeks HEAD pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
ElType Front (Queue Q) {
	return Q.Tab[Q.HEAD];
}
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */

/* *** Utilitas *** */
Queue CopyQueue (Queue Q) {
	int max = Q.MaxEl;
	Queue *Q1;
	*Q1 = CreateQueue(max);
	while(!IsEmpty(Q)) {
		ElType X;
		X = Pop(&Q);
		Push(Q1, X);
	}
	return *Q1;
}
/* Proses: Mengembalikan Queue baru dengan isi antrean sama seperti Q */
/* I.S. Q pernah dialokasi */
/* F.S. Queue baru dengan nilai isi antrean sama seperti Q;
        HEAD pada Queue baru dimulai dari 0 */
