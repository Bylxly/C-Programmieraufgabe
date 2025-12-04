/**
 * Fakultaet iterativ und rekursiv berechnen.
 *
 * TINF25CS1, 24.11.2025
 */
// Standard-Header
#include <stdio.h>
#include <stdlib.h>

// Prototypen
int fakultaet_iterativ(int n);
int fakultaet_rekursiv(int n);

/**
 * Hauptprogramm.
 */
int main(int argc, char*argv[])
{
	int n = 13;
	int f;

	printf("Fakultaet von %d iterativ berechnen...\n", n);
	f = fakultaet_iterativ(n);
	printf("Fakultaet von %d ist %d\n", n, f);

	printf("Fakultaet von %d rekursiv berechnen...\n", n);
	f = fakultaet_rekursiv(n);
	printf("Fakultaet von %d ist %d\n", n, f);

	return EXIT_SUCCESS;
} // main


/**
 * Fakultaet iterativ berechnen.
 */
int fakultaet_iterativ(int n)
{
	int f;
	int i;
	for(i = 1, f = 1; i <= n; i++)
	{
		f *= i;
	}
	return f;
} // fakultaet_iterativ


/**
 * Fakultaet rekursiv berechnen.
 */
int fakultaet_rekursiv(int n)
{
	if(n == 0)
		return 1;
	return n*fakultaet_rekursiv(n-1);
} // fakultaet_rekursiv

