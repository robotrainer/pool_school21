#include <stdio.h>

void coding(void);
void decoding_1(void);

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Ошибка! Не ввели аргумент или указали больше одного аргумента\n");
		return 0;
	}

	if (argv[1][0] == '0') {
		coding();
	}

	if (argv[1][0] == '1') {
		decoding_1();
	}

	return 0;
}

void coding(void) {
	int ch;
	while ((ch = getchar()) != '\n') {
		if (ch != ' ') {
			printf("%x", ch);
		} else {
			printf(" ");
		}
	}
	return;
}

void decoding_1(void) {
	int ch;
	while (scanf("%x", &ch) == 1) {
		printf("%c", ch);
		if (getchar() == '\n') break;
		printf(" ");
	}
	return;
}
