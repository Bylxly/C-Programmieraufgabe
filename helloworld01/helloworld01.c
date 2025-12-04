/**
 * Unser erster C-Programm.
 *
 * TINF25CS1, 09.10.2025
 */
// Standard-Header-Dateien einfuegen lassen
#include <stdio.h>

/**
 * Hauptprogramm.
 */
int main(int argc, char*argv[])
{
	int jahr = 25;
	if(argc > 1)
		sscanf(argv[1], "%d", &jahr);
	printf("Hallo, TINF%dCS1!\n", jahr);

	return 0;
} // main

