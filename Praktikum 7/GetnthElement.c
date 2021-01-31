/* Tuliskan header di sini berisi nama, dll */

#include "diantarakita.h"
int GetnthElement(List L, int r)
{
  /* Tuliskan implementasi di sini */
  	address P = First(L);
  	int x = CountElement(L);
  	int i = 1;
  	int y;
	while (i <= r%x) {
		y = Info(P);
		P = Next(P);
		i++;
	}
	return y;  
}
