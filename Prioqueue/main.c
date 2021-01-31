#include "prioqueuelist.c"
#include <stdio.h>

int main() {
	PrioQueue Q;
	if (IsEmpty(Q)) {
		printf("IsEmpty acc\n");
	}
	printf("%d\n", NBElmt(Q));
	printf("tes1\n");
	Enqueue(&Q, 1, 2);
	printf("tes2\n");
	Enqueue(&Q, 2, 3);
	Enqueue(&Q, 3, 4);
	printf("%d\n", NBElmt(Q));
	address P = Head(Q);
	printf("%d\n", P);
	printf("%d\n", Info(P));
	printf("%d\n", Prio(P));
	printf("%d\n", NBElmt(Q));
	if (!IsEmpty(Q)) {
		printf("PrioQueue:\n");
		while (P!= Nil) {
			printf("%d", Prio(P));
			P = Next(P);
		}	
	}
	return 0;
}

//	if (A != Nil) {
//		if (!IsEmpty(*Q)) {
//			address P = Head(*Q);
//			address Prec = Nil;
//			boolean enq = false;
//			while ((Next(P) != Nil) && !enq){
//				if (Prio(Next(P)) < PQ) {
//					enq = true;
//				}
//				Prec = P;
//				P = Next(P);
//			}
//			if (Prec != Nil || enq) {
//				Next(A) = P;		
//				Next(Prec) = A;
//			} else if (Prec == nil) { // hanya satu elemen atau elemen paling akhir
//				Head(*Q) = A;
//			} else {
//				Next(P) = A;
//			}
//		} else {
//			Head(*Q) = A;
//		}
//	}
