#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>


int compare(const void *a, const void *b) {
	// Rzutowanie wskaŸników na typ int i porównanie wartoœci
	return (*(int*)b - *(int*)a);
}


int main() {
	char line[256]; // tablica na wczytan¹ liniê tekstu
	int count = 0;
	int num = 0;
	int elves[300];
	int j = 0;
	// otwieramy plik do odczytu
	FILE* fp;
	fopen_s(&fp,"input.txt", "r");

	if (fp == NULL) {
		perror("Nie udalo siê otworzyc pliku\n");
		return 1;
	}

	// wczytujemy liniê z pliku
	while (fgets(line, sizeof(line), fp) != NULL) {
		num = atoi(line);
		count += num;
		if (num == 0) {
			elves[j] = count;
			j++;
			count = 0;
			continue;
		}
	}
	int i;
	for (i = 0; i < 242; i++)
	{
		printf("tablica[%d] = %d\n", i, elves[i]);
	}
	int max = elves[0];

	for (int i = 0; i < 241; i++) {
		if (elves[i] > max) {
			max = elves[i];
		}
	}
	printf("Najwiêksza liczba w tablicy to: %d\n", max);


	qsort(elves, 241, sizeof(int), compare);
	int calories_top_three = 0;
	for (int i = 0; i < 3; i++)
	{
		calories_top_three += elves[i];
		printf("Calories elve : %d\n", elves[i]);
	}
	printf("Calories best 3 elves: %d\n", calories_top_three);

	system("pause");
	return 0;
}
