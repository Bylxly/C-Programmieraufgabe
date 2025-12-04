/**
 * Felder.
 *
 * TINF25CS1, 13.11.2025
 */
// Standard-Header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * Hauptprogramm.
 */
int main(int argc, char*argv[])
{
	int i_feld[] = {
		10, 5, 17, 23, 8, 1, 0, 15, 6, 4
	};
	int i_feld_n = sizeof(i_feld) / sizeof(i_feld[0]);
	int i;
	int *i_feld_anf_ptr_1 = i_feld - 1;

	printf("Felder und Indices\n");
	for(i = 0; i < i_feld_n; i++)
		printf("%3d  ", i_feld[i]);
	printf("\n");

	for(i = 1; i <= i_feld_n; i++)
		printf("%3d  ", i_feld_anf_ptr_1[i]);
	printf("\n");

	i_feld_anf_ptr_1 = i_feld + 5;
	for(i = -5; i <= 4; i++)
		printf("%3d  ", i_feld_anf_ptr_1[i]);
	printf("\n");

	return EXIT_SUCCESS;
} // main

