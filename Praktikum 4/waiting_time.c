#include "circular_queue.h"

/**
 * Menghitung waktu tunggu x pada Q, yaitu berapa banyak elemen yang ada
 * di depan elemen x pada Queue Q tanpa mengubah isi dari Q.Tab
 */
int WaitingTime(Queue Q, int x) {
	int count = 0;
	boolean stop = true;
	while(!IsEmpty(Q) && stop) {
		if (Q.Tab[Q.HEAD] != x) {
			count += 1;
		} else {
			stop = false;
		}
		Pop(&Q);
	}
	if (stop) {
		return -1;
	} else {
		return count;
	}
    // TODO: Implementasi fungsi
    //   I.S. Q sudah dialokasi, bisa kosong
    //   F.S. integer yang berisi "waktu tunggu" seperti definisi di atas
    //        jika x tidak ada pada antrean Q, kembalikan -1
}
