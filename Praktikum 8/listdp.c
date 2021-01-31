/* Nama	: Graciella Valeska Liander */
/* NIM	: 18219075 */

/* File : listdp.h */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */
#include "listdp.h"
#include "boolean.h"
#include <stdio.h>
# include <stdlib.h>

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
	return ((First(L) == Nil) && (Last(L) == Nil));
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
	First(*L) = Nil;
	Last(*L) = Nil;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
	address P;
	P = (ElmtList *)malloc(sizeof(ElmtList));
	if (P != Nil) {
		Info(P) = X;
		Next(P) = Nil;
		Prev(P) = Nil;
		return P;
	} else {
		return Nil;
	}
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P) {
	free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X) {
	address P = First(L);
	boolean found = false;
	while (P != Nil && !found) {
		if (Info(P) == X) {
			found = true;
		} else {
			P = Next(P);
		}
	}
	if (found) {
		return P;
	} else {
		return Nil;
	}
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X) {
	address P = Alokasi(X);
	if(P != Nil) {
		InsertFirst(L, P);
	}
}
//	Prev(First(*L)) = P;
//	Next(P) = First(*L);
//	First(*L) = P;
//	Prev(P) = Nil;
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X) {
	address P = Alokasi(X);
	if (P!= Nil) {
		InsertLast(L,P);
	}
}
//	Next(Last(*L)) = P;
//	Prev(P) = Last(*L);
//	Last(*L) = P;
//	Next(P) = Nil;
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X) {
	address P;
	DelFirst(L,&P);
	*X = Info(P);
	Dealokasi(P);
//	First(*L) = Next(First(*L));
//	Prev(First(*L)) = Nil;
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X) {
	address P;
	DelLast(L, &P);
	*X = Info(P);
	Dealokasi(P);
}
//	Last(*L) = Prev(Last(*L));
//	Next(Last(*L)) = Nil;
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) {
	Next(P) = First(*L);
	if (!IsEmpty(*L)) {
		Prev(First(*L)) = P;
	} else {
		Last(*L) = P;
		Prev(P) = Nil;
	}
	First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P) {
  Prev(P) = Last(*L);
  if (!IsEmpty(*L)) {
    Next(Last(*L)) = P;
    Next(P) = Nil;
  } else {
    First(*L) = P;
    Next(P) = Nil;
  }
  Last(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec) {
	if (Next(Prec) == Nil) {
		Last(*L) = P;
	} else {
		Prev(Next(Prec)) = P;
	}
	Next(P) = Next(Prec);
	Prev(P) = Prec;
	Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address P, address Succ) {
	if (Prev(Succ) == Nil) {
		First(*L) = P;
	} else {
		Next(Prev(Succ)) = P;
	}
	Prev(P) = Prev(Succ);
	Next(P) = Succ;
	Prev(Succ) = P;
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P) {
  *P = First(*L);

  if (First(*L) != Last(*L)) {
    Prev(Next(First(*L))) = Nil;
  } else {
    Last(*L) = Nil;
  }
  First(*L) = Next(*P);
  Next(*P) = Nil;
  Prev(*P) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P) {
  	*P = Last(*L);
  	if (Last(*L) != First(*L)) {
    	Next(Prev(Last(*L))) = Nil;
	} else {
    	First(*L) = Nil;
  	}
  	Last(*L) = Prev(*P);
  	Next(*P) = Nil;
  	Prev(*P) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (List *L, infotype X) {
	address P = Search(*L, X);
	if (P != Nil) {
		if (Info(First(*L)) == X) {
			DelVFirst(L,&X);
		} else {
			address Prec = First(*L);
			while (Info(Next(Prec))!= X) {
				Prec = Next(Prec);
			}
			DelAfter(L, &P, Prec);
			Dealokasi(P);
		}
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, address *Pdel, address Prec) {
	*Pdel = Next(Prec);
	if (Next(Next(Prec)) == Nil) {
		Last(*L) = Prec;
	} else {
		Prev(Next(Next(Prec))) = Prec;
	}
	Next(Prec) = Next(Next(Prec));
	Next(*Pdel) = Nil;
	Prev(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, address *Pdel, address Succ) {
	*Pdel = Prev(Succ);
	if (Prev(Prev(Succ)) == Nil) {
		First(*L) = Succ;
	} else {
		Next(Prev(Prev(Succ))) = Succ;
	}
	Prev(Succ) = Prev(Prev(Succ));
	Next(*Pdel) = Nil;
	Prev(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L) {
	printf("[");
	if (!IsEmpty(L)) {
		address P = First(L);
		printf("%d", Info(P));
		P = Next(P);
		while (P != Nil) {
			printf(",%d", Info(P));
			P = Next(P);
		}
	}
	printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (List L) {
	printf("[");
	if (!IsEmpty(L)) {
		address P = Last(L);
		printf("%d", Info(P));
		P = Prev(P);
		while (P != Nil) {
			printf(",%d", Info(P));
			P = Prev(P);
		}
	}
	printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

