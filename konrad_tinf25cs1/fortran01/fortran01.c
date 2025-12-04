/**
 * Flussdiagramm --> Struktogramm --> C-Programm
 *
 * TINF25CS1, 18.11.2025
 */
// Standard-Header
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Hauptprogramm
 */
int main(int argc, char*argv[])
{
	double a, b;
	double z1, z2;

	printf("Fortan-Beispiel:\n");
	
	do
	{
		// Schritt 1
		printf("a = ");
		scanf("%lf", &a);
		printf("b = ");
		scanf("%lf", &b);
		// Abfrage
		if(b < a)
		{
			// Schritt 5
			printf("a = %.2lf; b = %.2lf\n", a, b);
			printf("Wurzel imaginaer!\n");
		}
		else
		{
			if(b > a)
			{
				// Schritt 2
				z1 = a/(5.0 + sqrt(b-a));
				// Abfrage, ob Wurzelausdruck genau 5 ergibt
				if(5.0 == sqrt(b-a))
				{
					// Schritt 6
					printf("a = %.2lf; b = %.2lf\n", a, b);
					printf("Funktion singulaer!\n");
				}
				else
				{
					// Schritt 4
					z2 = a/(5.0 - sqrt(b-a));
					// Schritt 8 (links!)
					printf("a = %.2lf; b = %.2lf\n", a, b);
					printf("z1 = %.2lf; z2 = %.2lf\n", z1, z2);
				}
			}
			else
			{
				// Schritt 3
				z1 = z2 = a/5.0;
				// Schritt 8 (rechts!)
				printf("a = %.2lf; b = %.2lf\n", a, b);
				printf("z1 = %.2lf; z2 = %.2lf\n", z1, z2);
			}
		}
	} while(a != 999999.0);

	return EXIT_SUCCESS;
} // main
