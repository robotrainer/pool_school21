#include <stdio.h>

int Ffib(int n);

int main() {
	int n;

	if (scanf("%d", &n) == 1 && n > 0) {
		printf("%d", Ffib(n));
	} else {
		printf("n/a");
	}
	return 0;
}

int Ffib(int n) {
	if(n == 1 || n == 2)
		return 1;
	return Ffib(n - 1) + Ffib(n - 2);
}
