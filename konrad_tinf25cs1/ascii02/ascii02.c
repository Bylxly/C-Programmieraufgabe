/**
 * ASCII-Zeichentabelle ausgeben
 *
 * TINF25CS1, 23.10.2025
 */
// Standard-HEader
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Prototypen
int my_isdigit(int z);

/**
 * Hauptprogramm
 */
int main(int argc, char*argv[])
{
	int i;
	system("chcp");
	system("chcp 1252");
	system("chcp");
	printf("ASCII-Zeichentabelle:\n");
	for(i = 0; i < 128; i++)
	{
		// Ternärer Operator:
		// (Bedingung) ? Wert_positiv : negativ
		printf("%3d  0x%02X  0x%02x  0%03o %c ",
			i, i, i, i, 
			(i < 32) ? ' ' : i);
		printf("isdigit(i)=%d "
			"my_isdigit(i)=%d\n",
			!!isdigit(i), !!my_isdigit(i));
	}
	printf("Umlaute: äöüÄÖÜß\n");
	return EXIT_SUCCESS;
} // main


/**
 * Selbst implementierte Variante von isdigit.
 * Siehe ctype.h bzw. Anhang A von Goll!
 */
int my_isdigit(int z)
{
	return '0' <= z && z <= '9';
} // my_isdigit
