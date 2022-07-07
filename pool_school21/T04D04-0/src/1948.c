#include <stdio.h>
#include <math.h>

int prime_number(int a);

int main() {
	float x;
	int max = 0;

	if (scanf("%f", &x) == 1 && (float)((int) x) == x) {
		if (x < 0) x = - x;
		int z = x;

		for (int i = 2; i <= x; ++i, z = x) {
			if (prime_number(i)) {
				while (z > 0) {
					z -= i;
				}
				if (z == 0)
					max = i;
			}
		}
		if (max != 0 && max != 1) {
			printf("%d\n", max);
		} else {
			printf("n/a\n");
		}
	} else {
		printf("n/a\n");
	}
	return 0;
}

int prime_number(int a) {
	int root_number = sqrt(a);
	int y = a;
	for (int i = 2; i <= root_number; ++i, y = a) {
		while (y > 0) {
			y -= i;
		}
		if (y == 0)
			return 0;
	}
		return 1;
}
