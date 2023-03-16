#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>


int main() {
	char line[256]; // tablica na wczytan¹ liniê tekstu
	int sum = 0;
	int sign = 0;
	int result;
	int elves[300];
	int j = 0;
	// otwieramy plik do odczytu
	FILE* fp;
	fopen_s(&fp, "input.txt", "r");

	if (fp == NULL) {
		perror("Nie udalo siê otworzyc pliku\n");
		return 1;
	}

	// wczytujemy liniê z pliku
	while (fgets(line, sizeof(line), fp) != NULL) {
		if (line[2] == 'X') {
			sum += 1;
			if (line[0] == 'A') sum += 3;
			if (line[0] == 'B') sum += 0;
			if (line[0] == 'C') sum += 6;
		}
		else if (line[2] == 'Y') {
			sum += 2;
			if (line[0] == 'A') sum += 6;
			if (line[0] == 'B') sum += 3;
			if (line[0] == 'C') sum += 0;
		}
		else if (line[2] == 'Z') {
			sum += 3;
			if (line[0] == 'A') sum += 0;
			if (line[0] == 'B') sum += 6;
			if (line[0] == 'C') sum += 3;
		}
		
	}
	printf("Sum : %d\n", sum);

	system("pause");
	return 0;
}
