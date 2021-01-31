#include "prioqueue.c"
#include <stdio.h>

int main() {
	Queue Q;
	if (IsEmpty(Q)) {
		printf("IsEmpty acc\n");
	}
	printf("%d\n", NbElmt(Q));
	printf("tes1\n");
	Enqueue(&Q, 1, 2);
	printf("tes2\n");
	Enqueue(&Q, 2, 3);
	Enqueue(&Q, 3, 4);
	printf("%d\n", NbElmt(Q));
	address P = Head(Q);
	printf("%d\n", P);
	printf("%d\n", Info(P));
	printf("%d\n", Prio(P));
	printf("%d\n", NbElmt(Q));
	if (!IsEmpty(Q)) {
		printf("PrioQueue:\n");
		while (P!= Nil) {
			printf("%d", Prio(P));
			P = Next(P);
		}	
	}
	return 0;
}

/*
void Enqueue (Queue * Q, infotype X, int prio) {
	address A;
	Alokasi(&A, X, prio);
	if (A != Nil) {
		if (!IsEmpty(*Q)) {
			address P = Head(*Q);
			boolean enq = false;
			while (Next(P) != Nil && !enq) {
				if (Prio(P) <= prio) {
					enq = true;
				} else {
					P = Next(P);
				}
			}
			if (P == Head(*Q)) {
				Next(A) = Head(*Q);
				Head(*Q) = A;
			} else if (enq) {
				Next(A) = Next(P);
				Next(P) = A;
			} else {
				Next(Tail(*Q)) = A;
				Tail(*Q) = A;
			}
		} else {
			Head(*Q) = A;
			Tail(*Q) = A;
		}
	}
}
*/
