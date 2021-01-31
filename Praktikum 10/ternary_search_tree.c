// Nama	: Graciella Valeska Liander
// NIM	: 18219075

/* ADT Ternary Search Tree */
/* Implementasi dengan menggunakan pointer */

/* Modul lain yang digunakan : */
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "ternary_search_tree.h"

#define Nil 0

/* *** Definisi Type Pohon Ternary *** */

/* Definisi Pohon Ternary : */
/* Pohon Ternary kosong : P = Nil */

/* *** Konstruktor *** */
TernaryTree Tree (infotype Akar) {
    TernaryTree P;
    P = AlokNode(Akar);
    if (P != Nil){
        Info(P) = Akar;
        Left(P) = Nil;
        Middle(P) = Nil;
        Right(P) = Nil;
        return P;
    }
    else {
        return Nil;
    }
}
/* Menghasilkan sebuah pohon ternary dengan nilai info root = Akar */
/* left, middle, dan right bernilai Nil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */

/* Manajemen Memory */
addrNode AlokNode (infotype X) {
    addrNode P;
    P  = (addrNode) malloc(sizeof(Node));
    if (P != Nil){
        Left(P) = Nil;
        Middle(P) = Nil;
        Right(P) = Nil;
        return P;
    }
    else {
        return Nil;
    }
}
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DealokNode (addrNode P) {
	free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (TernaryTree P) {
	return (P == Nil);
}
/* Mengirimkan true jika P adalah pohon ternary kosong */
boolean IsTreeOneElmt (TernaryTree P) {
	return (!IsTreeEmpty(P) && Left(P) == Nil && Right(P) == Nil && Middle(P) == Nil);
}
/* Mengirimkan true jika P adalah pohon ternary tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft (TernaryTree P) {
	return (!IsTreeEmpty(P) && Left(P) != Nil && Right(P) == Nil && Middle(P) == Nil);
}
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerMiddle (TernaryTree P) {
	return (!IsTreeEmpty(P) && Left(P) == Nil && Right(P) == Nil && Middle(P) != Nil);
}
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon unermiddle: hanya mempunyai subpohon tengah */
boolean IsUnerRight (TernaryTree P) {
	return (!IsTreeEmpty(P) && Left(P) == Nil && Right(P) != Nil && Middle(P) == Nil);
}
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBinary (TernaryTree P) {
	return !IsTreeEmpty(P) && ((Left(P) != Nil && Right(P) != Nil && Middle(P) == Nil) || (Left(P) != Nil && Right(P) == Nil && Middle(P) != Nil) || (Left(P) == Nil && Right(P) != Nil && Middle(P) != Nil));
}
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon biner: mempunyai 2 dari 3 subpohon (kiri, tengah, kanan)*/
boolean IsTernary (TernaryTree P){
	return (!IsTreeEmpty(P) && Left(P) != Nil && Right(P) != Nil && Middle(P) != Nil);
}
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon ternary lengkap: mempunyai seluruh subpohon kiri, tengah, kanan*/

/* *** Traversal *** */
void PrintTree (TernaryTree P) {
	if (IsTreeEmpty(P)) {
		printf("()");
	} else {
		printf("(");
		printf("%d", Info(P));
		PrintTree(Left(P));
		PrintTree(Middle(P));
		PrintTree(Right(P));
		printf(")");
	}
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, pohon tengah, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   () adalah pohon kosong
   (A()()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()()())(C()()())(D()()())) adalah pohon dengan akar A dan subpohon kiri (B()()()) dan subpohon tengah (C()()()) dan subpohon kanan (D()()()) */

/* *** Searching *** */
int CountElmt (TernaryTree P, infotype X) {
	if (!IsTreeEmpty(P)) {
		if (IsTreeOneElmt(P)) {
			if (Info(P) == X) return 0;
			else return 1;
		} else {
			if (Info(P) == X) {
				return 1 + CountElmt(Left(P), X) + CountElmt(Middle(P), X) + CountElmt(Right(P), X);
			} else {
				return 0;
			}
		}	
	}
}
/* Mengirimkan jumlah kemunculan nilai X pada node P (P bisa kosong) */
infotype GetSmallest (TernaryTree P) {
	if (IsTreeOneElmt(P)) {
		return Info(P);
	} else {
		return GetSmallest(Left(P));
	}
}
/* Mengirimkan nilai node infotype (int) terkecil pada P (P tidak kosong) */
infotype GetLargest (TernaryTree P) {
	if (IsTreeOneElmt(P)) {
		return Info(P);
	} else {
		return GetLargest(Right(P));
	}
}

/* Mengirimkan nilai node infotype (int) terbesar pada P (P tidak kosong) */
infotype GetMode (TernaryTree P) {
	if (IsTreeEmpty(P)) {
		return 0;
	} else {
		return Info(Middle(P));
	}
}
/* Mengirimkan nilai node infotype (int) dengan kemunculan paling banyak (modus) pada P (P tidak kosong)*/

/* *** Fungsi-Fungsi Lain *** */
int NbElmt (TernaryTree P) {
	if (IsTreeEmpty(P)) {
		return 0;
	} else {
		return 1 + NbElmt(Left(P)) + NbElmt(Middle(P)) + NbElmt(Right(P));
	}
}
/* Mengirimkan banyaknya elemen (node) pohon ternary P */
int NbUniqueElmt (TernaryTree P) {
	if (IsTreeEmpty(P)) return 0;
	else {
		if (CountElmt(P, Info(P)) == 1) {
			return 1 + NbUniqueElmt(Left(P)) + NbUniqueElmt(Middle(P)) + NbUniqueElmt(Right(P));
		} else {
			NbUniqueElmt(Left(P)) + NbUniqueElmt(Middle(P)) + NbUniqueElmt(Right(P));
		}
	}
}
/* Mengirimkan banyaknya elemen (node) dengan infotype unik pada pohon ternary P */
int NbDaun (TernaryTree P) {
	if (IsTreeEmpty(P)) {
		return 0;
	}
	if (IsTreeOneElmt(P)) {
		return 1;
	} else {
		return NbDaun(Left(P)) + NbDaun(Middle(P)) + NbDaun(Right(P));
	}
}
/* Mengirimkan banyaknya daun (node) pohon ternary P */
/* Prekondisi: P tidak kosong */
int max (int a, int b, int c) {
	if (a >= b && a >= c) return a;
	else if (b >= a && b >= c) return b;
	else if (c >= a && c >= b) return c;
}
int Tinggi (TernaryTree P) {
	if (IsTreeEmpty(P)) {
		return 0;
	} else {
		return 1 + max(Tinggi(Left(P)), Tinggi(Middle(P)), Tinggi(Right(P)));
	}
}
/* Pohon ternary mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim tinggi dari pohon, contoh:
   () --> 0
   (A()()()) --> 1
   (A(B()()())()()) --> 2 */

/* *** Operasi lain *** */
void AddElmt (TernaryTree *P, infotype X) {
	if (IsTreeEmpty(*P)) {
		*P = Tree(X);
	} else {
		if (Info(*P) > X){
			AddElmt(&Left(*P), X);
		} else if (Info(*P) == X) {
			AddElmt(&Middle(*P), X);
		} else if (Info(*P) < X) {
			AddElmt(&Right(*P), X);
		}
	}
}
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun sesuai definisi ternary search tree */
void DelDaun (TernaryTree *P, infotype X) {
	if (!IsTreeEmpty(*P)) {
		if (IsTreeOneElmt(*P) && Info(*P) == X) {
			addrNode X = *P;
			P = Nil;
			DealokNode(*P);
		} else {
			DelDaun(&Left(*P), X);
			DelDaun(&Middle(*P), X);
			DelDaun(&Right(*P), X);
		}	
	}
}
/* I.S. P tidak kosong, ada 1 daun bernilai X. */
/* F.S. Menghapus 1 daun bernilai X dari P. */
