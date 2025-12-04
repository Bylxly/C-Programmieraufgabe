/**
 * enum-Beispiel
 *
 * TINF25CS1, 03.11.2025
 */
// Standard-Header
#include <stdio.h>
#include <stdlib.h>

// Eigene Header-Dateien
#include "datentypen.h"

// Eigene (lokale) Datentypdefinitionen

// Prototypen
char* liefere_wochentags_text(enum sprache_typ, enum wochentage_typ);
void myassert(int sprache, int wochentag);

// Globale Variablen
char *tag_namen[2][7] = {
	{ "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag", "Sonntag", },
	{ "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", },
	};
int tag_namen_sprachen = sizeof(tag_namen)/sizeof(tag_namen[0]);
int tag_namen_tage = sizeof(tag_namen[0])/sizeof(tag_namen[0][0]);

/**
 * Hauptprogramm.
 */
int main(int argc, char*argv[])
{

	enum wochentage_typ heute = Montag;

	if(heute == Monday)
		printf("Heute ist Montag.\n");
	heute++;
	if(heute == Dienstag)
		printf("Today is Tuesday.\n");
	printf("heute = %d\n", heute);
	heute = 2*heute;
	printf("heute = %d\n", heute);


	// Programmieraufgabe
	printf("\n\n\n\n");

	// 5.2
	printf("Sprachen: %d, Tage: %d\n", tag_namen_sprachen, tag_namen_tage);

	// 5.3 c)
	myassert(0,0);

	printf("%s\n\n\n", liefere_wochentags_text(englisch, Montag));

	// 5.4
	for (int i = 0; i < tag_namen_sprachen; ++i) {
		for (int j = 0; j < tag_namen_tage; ++j) {
			myassert(i, j);
			printf("%s\n", liefere_wochentags_text(i, j));
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
} // main


char* liefere_wochentags_text(enum sprache_typ sprache_typ, enum wochentage_typ wochentage_typ) {
	char *wochentag = tag_namen[sprache_typ][wochentage_typ];
	return wochentag;
}

void myassert(int sprache, int wochentag) {
	if (!(0 <= wochentag && wochentag <= tag_namen_tage)) {
		if (!(0 <= sprache && sprache <= tag_namen_sprachen)) {
			exit(-1);
		}
	}
}

