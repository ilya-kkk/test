#include "output.h"
#pragma warning(disable : 4996)
void getRandFile(char* fileName)
{
	const char* town[10] = { "Москва", "Питер", "Егоревск", "Самара", "Мурманск", "Североморск", "Ейск", "Сочи", "Иркутск", "Анапа"};
	FILE* file = fopen(fileName, "w");
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 30; j++)
			fprintf(file, "%s %i %f %f\n", town[i], j, 
				(double)rand() / (double)RAND_MAX * (25.0 - -25.0) -25.0 ,
				(double)rand() / (double)RAND_MAX * (100.0 - 0.0) + 0.0);
	fclose(file);
}