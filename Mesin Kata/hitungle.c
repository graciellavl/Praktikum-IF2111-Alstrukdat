#include <stdio.h>
#include "hitungle.h"

char cc;
boolean EOP;

static FILE *pita;
static retval;

int main(void) {
	int countL = 0;
	int countE = 0;
	START();
	while (cc != '.') {
		if (cc = 'L') {
			countL++;
		} else if (cc = 'E') {
			countE++;
		} 
		ADV();
	}
	printf("Jumlah L ada %d dan E ada %d", countL, countE);
	return 0;
}

void ADV() {
	retval = fscanf(pita, "%c", &cc);
	EOP = (cc== MARK);
	if (EOP) {
		fclose(pita);
	}
}
