/**
 * Die Definitionen der Bibliotheksfunktionen
 * sind hier enthalten.
 *
 * TINF25CS1, 13.11.2025
 */
// Standard-Header
#include <stdio.h>

// Eigene Header-Datei(en)
#include "sortieren01_bibliothek.h"

/** 
 * Diese Bibliotheksfunktion gibt ein Feld
 * mit Elemente eines beliebigen Datentyps 
 * aus.
 * Formaler Parameter:
 *   feld_anf_vptr - void-Zeiger auf das 1. 
 *			Feldelement und damit den Feldanfang.
 *   feld_n - Anzahl der Feldelemente (bei den
 *			C-Bibiotheksfunktionen wird hier size_t
 *			und damit unsigned int verwendet.)
 *   element_groesse - Größe eines jeden Feldelementes
 *			in Bytes; notwendig, damit man "zu Fuß"
 *			die Adressen der Feldelemente berechnen
 *			kann. (Bei Funktionen mit konkreten Datentypen
 *			ergibt sich die Größe der Datenelemente aus
 *			dem Zieltyp des Feldanfangszeigers, so dass
 *			dieser Parameter überflüssig ist!)
 *   ausgabe_fkt_ptr - Einsprungadresse einer Callback-
 *			Funktion, die bei jedem Feldelement gerufen
 *			wird und es ausgibt. Für jeden gewünschten 
 *			Datentyp bei den Feldelementen und für jede 
 *			gewünschte Variante einer Ausgabe muss eine
 *			eigene solche Callback-Funktion programmiert
 *			werden! - Die Callback-Funktion bekommt als
 *			Parameter die Adresse des auszugebenden
 *			Elementes und den zu verwendenden Datenstrom 
 *			übergeben.
 *   ausgabe_fptr - Adresse einer Struktur vom Typ FILE,
 *			die den Ausgabedatenstrom verwaltet.
 */
void ausgeben_feld_allgemein(
	const void *feld_anf_vptr, int feld_n,
	int element_groesse,
	int (*ausgabe_fkt_ptr)
		(const void *element_vptr,
		FILE *ausgabe_fptr),
	FILE *ausgabe_fptr)
{
	int i;
	for(i = 0; i < feld_n; i++)
		// printf("%5.1lf  ", dfeld_anf_ptr[i]);
		ausgabe_fkt_ptr((char*)feld_anf_vptr + i*element_groesse,
				ausgabe_fptr);
	printf("\n");
} // ausgeben_feld_allgemein


