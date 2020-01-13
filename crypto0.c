#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long task1() {
	int a = 0x00000123;
	int b = 0xfeffffff;
	long c = b;
	c = (c << 32) | a;
	return c;
}

short task2() {
	short a = 0xcafe;
	short b = 0x1234;
	return a ^ b;
}

int task3() {
	int a = 0xcafe1234;
	int b = 0x12340000;
	return a ^ b;
}

void task4() {
	short a = 0xcafe;
	short b = 0x1234;
	a = b; //???
}

unsigned int task5() {
	unsigned int x = 0;
	for (unsigned short a = 0; a < 0xffff; a++) {
		x += a;
	}
	return x;
}

unsigned int task6() {
	unsigned int x = 3221225505;
	return x << 11 | x >> 21; // =69120
}

unsigned int task7() {
	int t;
	srand((unsigned) time(&t));

	unsigned int x = 3221225505;

	for (int i = 0; i < 32; i++) {
		int place = rand() % 32;

		int current = x >> i & 1;
		int old = x >> place & 1;

		if (current ^ old) {
			if (old) {
				x = x ^ (1 << place);
			}
			if (current) {
				x = x ^ (1 << i);
			}

			x = x | (current << place);
			x = x | (old << i);
		}
	}

	return x;
}

unsigned int task13() {
	char plainText[] = "qwerty123";
	int len = strlen(plainText);

	unsigned long int h = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < len - 1; j++) {
			plainText[j] = (plainText[j] + plainText[j + 1] % 256);
		}
	}

	for (int j = 0; j < len; j++) {
		h = h ^ (plainText[j] & 1) << j % 64;
	}

	return h;
}

void task14() {
	char text[] = "qwerty1234567890";
	char A[] = "adk4tne0o9sdi4nr"; //"random" sequence
	char B[] = "DkfIjgjq-M1jd8bn"; //"random" sequence

	int len = 16;

	for (int i = 0; i < len / 4; i++) {
		unsigned int x = 0;
		unsigned int a = 0;
		unsigned int b = 0;
		
		for (int j = 0; j < 4; j++) {
			x = x | text[i] << j * 8;
			a = a | A[i] << j * 8;
			b = b | B[i] << j * 8;
		}

		x += a;
		x += b;

		for (int j = 0; j < 4; j++) {
			text[i + j] = (char)(x << j * 8);
		}
	}
}

void task15() {
	char pass[] = "pass";
	int passLen = 4;

	char text[] = "qwerty1234567890";
	int textLen = 16;

	for (int i = 0; i < textLen; i++) {
		text[i] ^= pass[i % passLen];
	}
}

int main() {


	return 0;
}







