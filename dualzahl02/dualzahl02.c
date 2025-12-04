/**
 * Eine Ganzzahlvariable als Dualzahl
 * ausgeben.
 *
 * TINF25CS1, 17.11.2025
 */
// Standard-Header
#include <stdio.h>
#include <stdlib.h>

// Prototypen
int bin_zaehlen(int num);

/**
 * Hauptprogramm.
 */
int main(int argc, char*argv[])
{
	// 0111 0000  1111 1101  0001 1010  0011 1011
	// 1000 0000  0000 0000  0000 0000  0000 0000
	// 0x70FD1A3B
	int zahl = 0xA3B,zahl2 = zahl;
	short zahl_short = 0x187;
	int maske;
	unsigned int umaske;
	unsigned short umaske_short;
	int maske2;
	int i;
	int hex;
	int oct;
	int started = 0, started_short = 0;

	printf("Ganzzahlvariable 0x%08X als Dualzahl ausgeben\n", zahl);

	printf("Variante 1:\n");
	if(zahl<0) printf("1"); else printf("0");
	printf("\n");
	printf("%d\n", (zahl<0) ? 1 : 0);
	printf("%c\n", (zahl<0) ? '1' : '0');
	printf("%s\n", (zahl<0) ? "1": "0");
	printf("%d\n", (zahl<0));
	// maske = 1000 0000  0000 0000  0000 0000  0000 0000
	maske = 1 << (sizeof(maske)*8-1);
	printf("%d\n", (maske & zahl) != 0);
	printf("%d\n", !!(maske & zahl));

	printf("Variante 2: komplette Binärdarstellung\n");
	maske = 1 << (sizeof(maske)*8 - 1);
	for (;maske != 0; maske = ((unsigned int)maske) >> 1) {
		printf("%c", (zahl & maske) ? '1' : '0');
	}
	printf("\n");

	printf("Variante 3: komplette Binärdarstellung\n");
	maske = 1 << (sizeof(maske)*8 - 1);
	umaske = (unsigned)maske;
	for (;umaske != 0; umaske >>= 1 ) {
		printf("%c", (zahl & umaske) ? '1' : '0');
	}
	printf("\n");

	printf("Variante 4: komplette Binärdarstellung\n");
	maske = 1 << (sizeof(maske)*8 - 1);
	maske2 = ~maske;
	for (;maske != 0; maske >>= 1, maske &= maske2) {
		printf("%c", (zahl & maske) ? '1' : '0');
	}
	printf("\n");

	printf("Variante 5: Maske neu berechnen\n");
	for (i = 0; i <sizeof(zahl)*8; i++) {
		maske = 1 << (sizeof (zahl)*8 - 1 - i);
		printf("%c", (zahl & maske) ? '1' : '0');
	}
	printf("\n");

	printf("Variante 6: Zahl verschieben\n");
	for (i = 0; i <sizeof(zahl2)*8; i++) {
		printf("%c", (zahl2 < 0) ? '1' : '0');
		zahl2 <<= 1;
	}
	zahl2 = zahl;
	printf("\n");

	printf("Variante 7: Hex ausgeben\n");
	for (i = 0; i < sizeof(zahl2)*2; i++) {
		umaske = 0xF << (sizeof(zahl2)*8 - 4 - 4*i);
		hex = (zahl2 & umaske) >> (sizeof(zahl2)*8 - 4 - 4*i);
		if(0) printf("%X", hex);
		printf("%c", hex + ((hex <= 9) ? '0' : 'A'-10));
	}
	zahl2 = zahl;
	printf("\n");



	// Programmieraufgabe
	printf("\n\n\nProgrammieraufgabe 4.1\n");

	printf("Variante 8.1: int Oktal ausgeben\n");
	// für „angebrochene“ Oktalstelle an der höchstwertigen Position
	unsigned int first = (zahl2 & 0xC0000000) >> 30;
	if (first != 0) {
		printf("%d", first);
		started = 1;
	}
	// restliche Stellen
	for (i = 1; i <= (sizeof(zahl2)* 8 - 2) / 3 ; i++) {
		umaske = 0x7 << (sizeof(zahl2)*8 - 2 - 3*i);

		oct = (int) (zahl2 & umaske) >> (sizeof(zahl2)*8 - 2 - 3*i);
		if (oct != 0 || started) {
			printf("%d", oct);
			started = 1;
		}
	}
	printf("\n%%o: %o", zahl2);
	printf("\n");



	printf("\n\n\nProgrammieraufgabe 4.2\n");

	printf("Variante 8.2: short Oktal ausgeben\n");
	// für „angebrochene“ Oktalstelle an der höchstwertigen Position
	unsigned short first_short = (zahl_short & 0x8000) >> 15;
	if (first_short != 0) {
		printf("%d", first_short);
		started_short = 1;
	}
	// restliche Stellen
	for (i = 1; i <= (sizeof(zahl_short)* 8 - 1) / 3 ; i++) {
		umaske_short = 0x7 << (sizeof(zahl_short)*8 - 1 - 3*i);

		oct = (short) (zahl_short & umaske_short) >> (sizeof(zahl_short)*8 - 1 - 3*i);
		if (oct != 0 || started_short) {
			printf("%d", oct);
			started_short = 1;
		}
	}
	printf("\n%%o: %o", zahl_short);
	printf("\n");

	return EXIT_SUCCESS;
} // main


int bin_zaehlen(int num) {
	int stellen;
	for (stellen = 0; num > 0; num >>= 1)
		stellen++;
	return stellen;
}
