/* File : listsirkuler.c */
/* infotype adalah integer */
/* Nama	: Graciella Valeska Liander*/
/* NIM	: 18219075*/

#include "diantarakita.h"
#include "boolean.h"
#include <stdio.h>
# include <stdlib.h>

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* List dengan 1 elemen: First(L) = Next(First(L)) */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=First(List) */

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
	return First(L) == Nil;
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
	First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
	address P;
	P = (ElmtList *)malloc(sizeof(ElmtList));
	if (P != Nil) {
		Info(P) = X;
		Next(P) = Nil;
		return P;
	} else {
		return Nil;
	}
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=P */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P) {
	free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean FSearch (List L, infotype X) {
	address P = First(L);
	boolean found = false;
	do {
		if (Info(P) == X ) {
			found = true;
		} else {
			P = Next(P);
		}
	} while ((Next(P) != First(L)) && !found);
	return found;
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan true. */
/* Jika tidak ada, mengirimkan false */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertFirst (List *L, infotype X) {
	address P = Alokasi(X);
	if (P != Nil) {
		if (IsEmpty(*L)) {
			Next(P) = P;
		} else {
			address last = First(*L);
			while (Next(last) != First(*L)) {
				last = Next(last);
			}
			Next(P) = First(*L);
			Next(last) = P;
		}
		First(*L) = P;
	}
}
/* I.S. L mungkin kosong */
/* F.S. Mengecek apakah X ada di List. */
/* Jika ada, hapus X dari list. */
/* Selanjutnya melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsertLast (List *L, infotype X) {
	if (IsEmpty(*L)) {
		InsertFirst(L, X);
	} else {
		address P = Alokasi(X);
		if (P!= Nil) {
			address last = First(*L);
			while (Next(last) != First(*L)) {
				last = Next(last);
			}
			Next(last) = P;
			Next(P) = First(*L);
		}
	}
}
/* I.S. L mungkin kosong */
/* F.S. Mengecek apakah X ada di List. */
/* Jika ada, hapus X dari list. */
/* Selanjutnya melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void InsertAfter (List *L, infotype X, infotype Y) {
	if (!IsEmpty(*L)) {
		address P = First(*L);
		if (FSearch(*L, X)) {
			if (FSearch(*L, Y)) {
				DeleteElement(L, Y);
				while (Info(P) != X) {
					P = Next(P);
				}
				address y = Alokasi(Y);
				Next(y) = Next(P);
				Next(P) = y;
			}
		}
	}
}
/* I.S. List L mungkin kosong, Y mungkin ada di list, */
/*      Mungkin elemen X tidak ada pada list  */
/* F.S. Mencari X dan Y pada list. Jika X tidak ada I.S.=F.S. */
/*      Jika Y ada pada list, hapus Y dari list */
/*      Selanjutnya alokasi Y dan masukkan di list setelah X. */
void InsertBefore (List *L, infotype X, infotype Y) {
	if (!IsEmpty(*L)) {
		address P = First(*L);
		address prec = Nil;
		if (FSearch(*L, X)) {
			if (FSearch(*L, Y)) {
				DeleteElement(L, Y);
				while (Info(P) != X) {
					prec = P;
					P = Next(P);
				}
				address y = Alokasi(Y);
				Next(y) = Next(prec);
				Next(prec) = y;
			}
		}
	}
}
/* I.S. List L mungkin kosong, Y mungkin ada di list, */
/*      Mungkin elemen X tidak ada pada list  */
/* F.S. Mencari X dan Y pada list. Jika X tidak ada I.S.=F.S. */
/*      Jika Y ada pada list, hapus Y dari list */
/*      Selanjutnya alokasi Y dan masukkan di list sebelum X. */
/*      Jika X pada I.S. adalah First, maka Y menjadi First pada F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DeleteFirst (List *L, infotype *X) {
	address P = First(*L);
	*X = Info(P);
	if (Next(First(*L)) == First(*L)) {
		First(*L) = Nil;
	} else {
		address last = First(*L);
		while (Next(last) != First(*L)) {
			last = Next(last);
		}
		First(*L) = Next(First(*L));
		Next(last) = First(*L);
	}
	Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DeleteLast (List *L, infotype *X) {
	if (!IsEmpty(*L)) {
		address last = First(*L);
		address prec = Nil;
		while (Next(last) != First(*L)) {
			prec = last;
			last = Next(last);
		}
		if (prec == Nil) {
			First(*L) = Nil;
		} else {
			Next(prec) = First(*L);
		}
		*X = Info(last);
		Dealokasi(&last);
	}
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
void DeleteElement (List *L, infotype X) {
	if (FSearch(*L, X)) {
		address P = First(*L);
		address prec = Nil;
		boolean found = false;
		while ((Next(P) != First(*L)) && !found) {
			prec = P;
			P = Next(P);
		}
		if (prec == Nil) {
			First(*L) = Nil;
		} else if (prec = (First(*L))) {
			DeleteFirst(L, &X);
		} else {
			Next(prec) = Next(P);
		}
		Dealokasi(&P);
	}
}
/* I.S. list mungkin kosong */
/* F.S. Mencari X. Jika ada, hapus X */
/*      Jika pada I.S., X adalah First, maka elemen setelah X menjadi First, */
/*      KECUALI X adalah satu-satunya elemen */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L) {
	printf("[");
	if (!IsEmpty(L)) {
		address P = First(L);
		printf("%d", Info(P));
		P = Next(P);
		while (P != First(L)) {
			printf(",%d", Info(P));
			P = Next(P);
		}
	}
	printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
//int NbElmt (List L) {
//	if (IsEmpty(L)) {
//		return 0;
//	} else {
//		int count = 0;
//		address P = First(L);
//		while (Next(P) != First(L)) {
//			count++;
//		}
//		return count;
//	}
//}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

//boolean FSearch(List L, infotype X);
/* List L mungkin kosong */
/* Output true jika X ada di list L. */

int CountElement (List L) {
	if (IsEmpty(L)) {
		return 0;
	} else {
		int count = 0;
		address P = First(L);
		while (Next(P) != First(L)) {
			count++;
			P = Next(P);
		}
		return count;
	}
}
/* List L mungkin kosong */
/* Output banyaknya jumlah elemen pada list L */

/****************** PROSES TERHADAP LIST ******************/
void MoveLastToFirst(List *L) {
	address P = First(*L);
	if (Next(P) != First(*L)) {
		while (Next(P) != First(*L)) {
			P = Next(P);
		}
		First(*L) = P;
	}
}
/* I.S. List mungkin kosong */
/* F.S. Jika list memiliki lebih dari 1 elemen, pindahkan elemen terakhir menjadi elemen pertama */
/* Tips: Perkara mudah jangan dibuat sulit */

