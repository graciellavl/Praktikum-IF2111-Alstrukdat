#ifndef adt_h
#define adt_h

#define MaxEl 99
#define Mark -9999
#define InvalidIdx -2

typedef int IdxType;
typedef int ElType;

typedef struct {
	ElType A[MaxEl];
} List;

// Soal 1
bool IsSimetrik (List L);

// Soal 2
List PlusList (List L1, List L2);

// Soal 3
bool IsEQ (List L1, List L2);

// Soal 4
IdxType Search (List L, int X);

// Soal 5
int CountX (List L, int X);

// Soal 6
void InsertUniq (List L, int X);

#endif
