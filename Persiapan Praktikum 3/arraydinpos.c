/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi III : dengan banyaknya elemen didefinisikan secara implisit,
   memori tabel dinamik */

# include <stdio.h>
# include <stdlib.h>
# include "arraydinpos.h"

/* ********** SELEKTOR ********** */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel) {
	T->MaxEl = maxel;
	T->TI = (int *) malloc (maxel * sizeof(int));
	IdxType i;
	for (i =IdxMin; i< maxel; i++) {
		T->TI[i] = ValUndef;
	}
}
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */

void Dealokasi(TabInt *T) {
	T->MaxEl = 0;
	free(T->TI);
}
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T) {
	IdxType i = IdxMin;
	boolean eff = true;
	while ((i < T.MaxEl) && eff) {
		if (T.TI[i] == ValUndef) eff = false;
		else i++;
	}
	return i;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxElement(TabInt T) {
	return T.MaxEl;
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T) {
	return IdxMin;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx(TabInt T) {
	return NbElmt(T) -1;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i) {
	return 0 <= i && i < T.MaxEl;
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff(TabInt T, IdxType i) {
	return 0 <= GetFirstIdx(T) && i <= GetLastIdx(T);
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T) {
	return NbElmt(T) == 0;
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T) {
	return (NbElmt(T) == T.MaxEl);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T) {
	int i, N;
	boolean element = true;
	scanf("%d", &N);
	for (i = 0; element; i++) {
		if (0 <= N && N <= T->MaxEl) element = false;
	}
	for (i =0; i < N; i++) {
		scanf("%d", &(T->TI[i]));
	}
}
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void TulisIsiTab(TabInt T) {
	printf("[");
	int i;
	if (!IsEmpty(T)) {
		printf("%d", T.TI[IdxMin]);
		for (i = GetFirstIdx(T) + 1; i < GetLastIdx(T); i++) {
			printf(",%d", T.TI[i]);
		}
	}
	printf("]");
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus) {
	TabInt temp;
	MakeEmpty(&temp, T1.MaxEl);
	int i;
	for (i=0; i < GetLastIdx(T1); i++) {
		if (plus) {
			temp.TI[i] = T1.TI[i] + T2.TI[i];
		} else {
			temp.TI[i] = T1.TI[i] - T2.TI[i];
		}
	}
	return temp;
}
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen T1-T2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2) {
	if (GetLastIdx(T1) != GetLastIdx(T2)) return false;
	else {
		boolean sama = true;
		int i;
		for (i=0; i<GetLastIdx(T1) && sama; i++) {
			if (T1.TI[i] != T1.TI[i]) sama = false;
		}
		return sama;
	}
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X) {
	boolean tidakAda = true;
	int i=IdxMin;
	while (i <= GetLastIdx(T) && tidakAda) {
		if (T.TI[i] == X) tidakAda = false;
		else i++;
	}
	if (tidakAda) return IdxUndef;
	else return i;
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan ValUndef */
/* Menghasilkan indeks tak terdefinisi (ValUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
boolean SearchB(TabInt T, ElType X) {
	return (Search1(T, X) != IdxUndef);
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min) {
	int i;
	*Max = T.TI[GetFirstIdx(T)];
	*Min = T.TI[GetFirstIdx(T)];
	for (i=IdxMin; i <= GetLastIdx(T); i++) {
		if (T.TI[i] > *Max) {
			*Max = T.TI[i];
		}
		if (T.TI[i] < *Min) {
			*Min = T.TI[i];
		}
	}
}
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout) {
	MakeEmpty(Tout, Tin.MaxEl);
	int i;
	for (i=IdxMin; i < GetLastIdx(Tin); i++) {
		Tout->TI[i] = Tin.TI[i];
	}
}
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
ElType SumTab(TabInt T) {
	int i;
	int sum = 0;
	for (i=GetFirstIdx(T); i<= GetLastIdx(T); i++) {
		sum += T.TI[i];
	}
	return sum;
}
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
int CountX(TabInt T, ElType X) {
	int i;
	int count = 0;
	for (i=GetFirstIdx(T); i <= GetLastIdx(T); i++) {
		if (T.TI[i] == X) count+=1;
	}
	return count;
}
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
boolean IsAllGenap(TabInt T) {
	boolean allGenap = true;
	int i;
	for (i = 0; i< GetLastIdx(T) && allGenap; i++) {
		if (T.TI[i]%2 != 0) allGenap = false;
	}
	return allGenap;
}
/* Menghailkan true jika semua elemen T genap. T boleh kosong */

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc) {
	int i,j;
	for (i=0; i < GetLastIdx(*T)-1; i++) {
		for (j=0; j < GetLastIdx(*T)-i-1; j++) {
			if(asc) {
				if (T->TI[j] > T->TI[j+1]) {
					int temp = T->TI[i];
					T->TI[i] = T->TI[i+1];
					T->TI[i+1] = temp;
				}	
			} else {
				if (T->TI[j] < T->TI[j+1]) {
					int temp = T->TI[i];
					T->TI[i] = T->TI[i+1];
					T->TI[i+1] = temp;
				}
			}
		}
	}
}
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X) {
	if (!IsFull) {
		T->TI[GetLastIdx(*T) + 1] = X;
	}
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X) {
	if (!IsEmpty) {
		*X = T->TI[GetLastIdx(*T)];
		T->TI[GetLastIdx(*T)] = ValUndef;
	}
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num) {
	T->MaxEl += num;
}
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */

void ShrinkTab(TabInt *T, int num) {
	T->MaxEl -= num;
}
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */

void CompactTab(TabInt *T) {
	T-> MaxEl = GetLastIdx(*T) + 1;
}
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */

