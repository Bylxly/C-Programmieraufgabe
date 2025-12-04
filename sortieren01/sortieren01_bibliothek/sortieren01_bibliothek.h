/**
 * Header-Datei mit den Prototypen der
 * Bibliotheksfunktionen.
 *
 * TINF25CS1, 13.11.2025
 */
#pragma once

#ifndef SORTIEREN01_BIBLIOTHEK_H
#define SORTIEREN01_BIBLIOTHEK_H

#include <stdio.h>

void ausgeben_feld_allgemein(
	const void *feld_anf_vptr, int feld_n,
	int element_groesse,
	int (*ausgabe_fkt_ptr)
		(const void *element_vptr,
		FILE *ausgabe_fptr),
	FILE *ausgabe_fptr);

#endif // SORTIEREN01_BIBLIOTHEK_H