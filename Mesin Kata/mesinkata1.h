#ifndef __MESINKATA1__
#define __MESINKATA1__

#include "mesinkata.h"

#define NMax 50
#define BLANK ' '

typedef struct {
	char TabKata[NMax];
	int Length;
} Kata;

extern boolean EndKata;
extern Kata CKata;

void ignoreBlank();

void STARTKATA();

void ADVKATA();

void SalinKata();

#endif
