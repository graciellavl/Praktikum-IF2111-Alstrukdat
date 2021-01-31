#include "mesinkata1.h"

boolean EndKata;
Kata CKata;
char cc;

void IgnoreBlank() {
	while (cc == BLANK){
		ADV();
	}
}

void STARTKATA() {
	START();
	IgnoreBlank(); 
	if (cc == MARK){
		EndKata = true;
	} else {
		EndKata = false;
		SalinKata();
	}
}

void ADVKATA() {
	IgnoreBlank();
	if (cc == MARK) {
		EndKata = true;
	} else {
		SalinKata();
	}
}

void SalinKata() {
	int i = 0;
	while ((cc != MARK) && (cc != BLANK)) {
		CKata.TabKata[i] = cc;
		ADV();
		i++;
	}
	CKata.Length = i;
}
