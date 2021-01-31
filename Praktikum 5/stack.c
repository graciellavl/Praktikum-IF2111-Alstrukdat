// Nama	: Graciella Valeska Liander
// NIM	: 18219075

#include "stack.h"
#include <stdio.h>

/* MODUL STACK
Deklarasi stack yang diimplementasi dengan tabel kontigu alokasi statik
dan ukuran sama
TOP adalah alamat elemen puncak*/

#define false 0
#define true 1
#define Nil 0
#define MaxEl 10

//typedef int bool;
//typedef char infotype;
//typedef int address;
//
//typedef struct
//{
//    infotype T[MaxEl];
//    address TOP;
//} Stack;

/* Definisi stack S kosong : S.TOP = Nil */
/* S.TOP = jumlah element stack */
/* S.T[S.TOP-1] = element paling atas */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S) {
	(*S).TOP = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsEmpty(Stack S) {
	return S.TOP == Nil;
}
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
bool IsFull(Stack S) {
	return S.TOP == MaxEl;
}
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, infotype X) {
	if (IsEmpty(*S)) {
		(*S).TOP = 1;
	} else {
		(*S).TOP += 1;
	}
	(*S).T[(*S).TOP-1] = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
void Pop(Stack *S, infotype *X) {
	(*X) = (*S).T[(*S).TOP-1];
	if ((*S).TOP == 1) {
		(*S).TOP = Nil;
	} else {
		(*S).TOP--;
	}
}
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

/* ********** Operator Tambahan ********* */
void ForcePush(Stack *S, infotype X) {
	if (IsFull(*S)) {
		int i;
		for (i = 0; i < (*S).TOP - 1; i++)
		      (*S).T[i] = (*S).T[i + 1];
		      (*S).T[(*S).TOP - 1] = X;
	} else { 
		Push(S, X);
	}
}	
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S mungkin penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1
        Apabila S penuh, buang element paling bawah dari S dan masukkan X sebagai TOP
        Contoh: S berisi a b c d e f g h i j, setelah melakukan ForcePush(S, "k")
        S berisi b c d e f g h i j k */

