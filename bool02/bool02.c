/**
 * Boolesche Algebra, Schaltplan in Wertetabelle
 * umsetzen.
 *
 * TINF25CS1, 17.11.2025
 *
 * Logische UND: &&
 * Logische ODER: ||
 * Logische NICHT bzw. logische Negation: !
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
	int a, b, c;
	int alpha, beta, a_quer;
	int z;
	int i;

	printf("Schaltplan in Wertetabelle umsetzen:\n");

	printf("a b c | alpha beta a_quer | z\n");
	printf("------+-------------------+---\n");
	for(a = 0; a < 2; a++)
		for(b = 0; b < 2; b++)
			for(c = 0; c < 2; c++)
			{
				alpha = !(a && b);
				beta = alpha || c;
				a_quer = !a;
				z = !a_quer && beta || a_quer && !beta;
				printf("%d %d %d |   %d     %d     %d   | %d\n",
					a, b, c, alpha, beta, a_quer, z);
			}
	printf("\n");

	printf("a b c | alpha beta a_quer | z\n");
	printf("------+-------------------+---\n");
	for(a = 0; a < 2; a++)
	{
		a_quer = !a;
		for(b = 0; b < 2; b++)
		{
			alpha = !(a && b);
			for(c = 0; c < 2; c++)
			{
				beta = alpha || c;
				// z = !a_quer && beta || a_quer && !beta;
				z = a && beta || a_quer && !beta;
				printf("%d %d %d |   %d     %d     %d   | %d\n",
					a, b, c, alpha, beta, a_quer, z);
			}
		}
	}
	printf("\n");

	printf("a b c | alpha beta a_quer | z\n");
	printf("------+-------------------+---\n");
	for(a = 0; a < 2; a++)
	{
		for(b = 0; b < 2; b++)
		{
			for(c = 0; c < 2; c++)
			{
				z = a && !b || a && c;
				printf("%d %d %d |   -     -     -   | %d\n",
					a, b, c, z);
			}
		}
	}
	printf("\n");

	printf("a b c | alpha beta a_quer | z\n");
	printf("------+-------------------+---\n");
	for(i = 0; i < 8; i++)
	{
		a = i / 4;
		b = i / 2 % 2;
		c = i % 2;
		alpha = !(a && b);
		beta = alpha || c;
		a_quer = !a;
		z = !a_quer && beta || a_quer && !beta;
		printf("%d %d %d |   %d     %d     %d   | %d\n",
			a, b, c, alpha, beta, a_quer, z);
	}


	// PROGRAMMIERAUFGABE

	printf("\n\nPROGRAMMIERAUFGABE\n");
	printf("a b c | alpha beta a_quer | z\n");
	printf("------+-------------------+---\n");
	for(i = 0; i < 8; i++)
	{
		a = i >> 2;
		b = i >> 1 & 1;
		c = i & 1;
		alpha = !(a && b);
		beta = alpha || c;
		a_quer = !a;
		z = !a_quer && beta || a_quer && !beta;
		printf("%d %d %d |   %d     %d     %d   | %d\n",
			a, b, c, alpha, beta, a_quer, z);
	}

	return EXIT_SUCCESS;
} // main

