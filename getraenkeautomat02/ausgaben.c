/**
 * Dieses C-Modul enthält die Funktionsdefinitionen
 * von Funktionen zur Ausgabe an den Benutzer.
 *
 * TINF25CS1, 23.10.2025
 */
// Standard-Header
#include <stdio.h>

// Eigene Header-Datei(en)
#include "ausgaben.h"
// ggf. weitere Header-Dateien des Projektes
// #include ".....h"

/**
 * Simulation der Getränkeausgabe.
 *
 * Formale Parameter:
 *   sorte - Index der Getränkesorte.
 *   menge - Anzahl der Dosen/Flaschen.
 * 
 * Rückgabewert:
 *   Keiner!
 */
void ausgabeGetraenke(int sorte, int menge) 
{
	int i, j;
	printf("\n--- Getraenkeausgabe ---\n");
	for(i=0, j = menge; i < menge; i++, j--)  
	{
		printf("\nFlasche %d von %d der Sorte %d wurde ausgegeben.",
			i+1, menge, sorte);
	} // for
	return; // Optional
} // ausgabeGetraenke
