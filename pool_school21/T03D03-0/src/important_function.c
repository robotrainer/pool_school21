#include <stdio.h>
#include <math.h>

int main(void) {
	float x = 0;
	float y = 0;
	printf("Введите число:\n");
	scanf("%f", &x);
	if (x != 0) {
		y = 7e-3 * pow(x, 4) + ((22.8 * pow(x, (1/3)) - 1e3) * x + 3) /
			(x * x / 2) - x * pow((10 + x), (2/x)) - 1.01;
		printf("%.1f\n", y);
	} else {
		printf("n/a\n");
	}
	return (0);
}
