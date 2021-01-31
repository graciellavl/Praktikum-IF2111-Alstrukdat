#include <stdio.h>
#include "mesinkata.h"

char cc;
boolean EOP;

static FILE *pita;
static int retval;

int main() {
	pita = fopen("pitakar.txt", "r");
	ADV();
}

void ADV() {
	retval = fscanf(pita, "%c", &cc);
	EOP = (cc== MARK);
	if (EOP) {
		fclose(pita);
	}
}
