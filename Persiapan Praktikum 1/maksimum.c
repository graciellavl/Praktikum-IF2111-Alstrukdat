#include <stdio.h>
#include <stdbool.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d %d %d\n", a, b, c);
	if ((a>b) && (a>c)) {
		printf("&d", a);
	} else if ((b>c) && (b>a)) {
		printf("%d", b);
	} else {
		printf("%d", c);
	}
}
