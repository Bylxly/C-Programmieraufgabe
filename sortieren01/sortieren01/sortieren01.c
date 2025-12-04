/**
 * Sortieren von Feldern und darin suchen.
 *
 * TINF25CS1, 12.11.2025
 */
// Standard-Header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Header-Datei des Bibliotheksprojektes
#include "sortieren01_bibliothek.h"

// Prototypen
void ausgeben_i_feld(int *ifeld_anf_ptr, int i_feld_n);
void ausgeben_d_feld(double *dfeld_anf_ptr, int d_feld_n);
// Bibliotheksfunktionen
// --> Siehe Bibliotheksprojekt!!!
// Prototypen von Callback-Funktionen zum Vergleichen
int vgl_fkt_int_aufsteigend(const void*v1_ptr, const void*v2_ptr);
int vgl_fkt_int_absteigend(const void*v1_ptr, const void*v2_ptr);
int vgl_fkt_double_aufsteigend(const void*v1_ptr, const void*v2_ptr);
int vgl_fkt_double_absteigend(const void*v1_ptr, const void*v2_ptr);
int vgl_fkt_text_aufsteigend(const void*v1_ptr, const void*v2_ptr);

int vgl_fkt_name_gehalt_id_aufsteigend (const void*v1_ptr, const void*v2_ptr);
int vgl_fkt_id_aufsteigend(const void*v1_ptr, const void*v2_ptr);

// Prototypen von Callback-Funktionen zum Ausgeben
int ausgeben_int(const void *element_vptr, FILE *ausgabe_fptr);
int ausgeben_double(const void *element_vptr, FILE *ausgabe_fptr);
int ausgeben_text(const void *element_vptr, FILE *ausgabe_fptr);

int ausgeben_pds(const void *element_vptr, FILE *ausgabe_fptr);


// Programmieraufgabe 10/
/**
* Datentyp für Personendatensätze.
* Die Namen werden als getrennte Speicherobjekte
* angelegt.
*/
struct personen_typ {
	int id;
	char *name_ptr;
	double gehalt;
};


/**
 * Hauptprogramm.
 */
int main(int argc, char*argv[])
{
	struct personen_typ p_feld[] = {
		{ 1000, "Erna", 1500.10 },
		{ 1001, "Erna", 1500.90 },
		{ 1002, "Eva", 1400.00 },
		{ 1003, "Ernst", 1450.00 },
		{ 1004, "Peter", 1520.00 },
		{ 1005, "Otto", 1510.00 },
		{ 1006, "Klara", 1550.00 },
		{ 1007, "Klara", 1550.50 },
		{ 1008, "Peter", 1520.00 },
		{ 1009, "Petra", 1480.00 },
		};
	int p_feld_n = sizeof(p_feld) / sizeof(p_feld[0]);

	printf("Progammieraufgabe Ausgabe:\n");
	ausgeben_feld_allgemein(p_feld, p_feld_n, sizeof(p_feld[0]), ausgeben_pds, stdout);

	printf("Das Personendatenfeld sortieren...\n");
	qsort(p_feld, p_feld_n, sizeof(p_feld[0]), vgl_fkt_name_gehalt_id_aufsteigend);

	printf("Das Personendatenfeld sortiert:\n");
	ausgeben_feld_allgemein(p_feld, p_feld_n, sizeof(p_feld[0]), ausgeben_pds, stdout);

	printf("Das Personendatenfeld sortieren nach ID...\n");
	qsort(p_feld, p_feld_n, sizeof(p_feld[0]), vgl_fkt_id_aufsteigend);

	printf("Das Personendatenfeld sortiert nach ID:\n");
	ausgeben_feld_allgemein(p_feld, p_feld_n, sizeof(p_feld[0]), ausgeben_pds, stdout);

	printf("Das Personendatenfeld wird jetzt durchsucht!\n");
	{
		struct personen_typ suchwerte[] = {
			{ 1007, "Günter", 2500.00 },
			{ 1029, "Eberhardt", 500.90 }
		};
		int suchwerte_n = sizeof(suchwerte) / sizeof(suchwerte[0]);
		int i;
		struct personen_typ *treffer_ptr;
		for(i = 0; i < suchwerte_n; i++)
		{
			// Statt &suchwerte[i] einfach so: suchwerte+i
			treffer_ptr = (struct personen_typ *)
				bsearch(&suchwerte[i], p_feld, p_feld_n,
					sizeof(p_feld[0]), vgl_fkt_id_aufsteigend);
			if(treffer_ptr == NULL)
				printf("Gesuchter Wert nicht gefunden!\n");
			else
			{
				printf("Gesuchter Wert an Adresse %p bzw. "
					"bei Index %ld gefunden!\n", treffer_ptr, treffer_ptr - p_feld);
				ausgeben_pds(treffer_ptr, stdout);
			}
		}
	}

	printf("\n\n\n\n\n");


	// Vorlesung
	int i_feld[] = {
		34, 1, 29, 17, 0, 12, 24, -10, 55, 13 
	};
	int i_feld_n = sizeof(i_feld) / sizeof(i_feld[0]);
	double d_feld[] = {
		3.1, 3.2, 2.9, 1.7, 0.0, 1.2, 1.4, -10.4, 5.5, 1.3 
	};
	int d_feld_n = sizeof(d_feld) / sizeof(d_feld[0]);
	char texte[10][9] = {
		"Max", "Anton", "Petra", "Otto", "Norbert",
		"Peter", "Emil", "Hilde", "Tyler", "Karl"
	};
	int texte_n = sizeof(texte) / sizeof(texte[0]);

	if(0) printf("texte_n = %d\n", texte_n);

	printf("Sortieren und Suchen bei Feldern\n");

	// Vornamen-Feld
	printf("Das Vornamen-Feld unsortiert, mit Bibliotheksfunktion:\n");
	ausgeben_feld_allgemein(texte, texte_n, sizeof(texte[0]),
		ausgeben_text, stdout);

	printf("Die Vornamen aufsteigend sortieren...\n");
	qsort(texte, texte_n, sizeof(texte[0]), vgl_fkt_text_aufsteigend);

	printf("Die Vornamen aufsteigend sortiert, mit Bibliotheksfunktion:\n");
	ausgeben_feld_allgemein(texte, texte_n, sizeof(texte[0]),
		ausgeben_text, stdout);

	// int-Feld
	printf("Das int-Feld unsortiert, mit Bibliotheksfunktion:\n");
	ausgeben_feld_allgemein(i_feld, i_feld_n, sizeof(i_feld[0]),
		ausgeben_int, stdout);

	printf("Das int-Feld aufsteigend sortieren...\n");
	qsort(i_feld, i_feld_n, sizeof(i_feld[0]), vgl_fkt_int_aufsteigend);

	printf("Das int-Feld aufsteigend sortiert:\n");
	ausgeben_i_feld(i_feld, i_feld_n);

	printf("Das int-Feld absteigend sortieren...\n");
	qsort(i_feld, i_feld_n, sizeof(i_feld[0]), vgl_fkt_int_absteigend);

	printf("Das int-Feld absteigend sortiert:\n");
	ausgeben_i_feld(i_feld, i_feld_n);

	// double-Feld
	printf("Das double-Feld unsortiert:\n");
	ausgeben_d_feld(d_feld, d_feld_n);

	printf("Das double-Feld aufsteigend sortieren...\n");
	qsort(d_feld, d_feld_n, sizeof(d_feld[0]), vgl_fkt_double_aufsteigend);

	printf("Das double-Feld aufsteigend sortiert:\n");
	ausgeben_d_feld(d_feld, d_feld_n);

	printf("Das double-Feld absteigend sortieren...\n");
	qsort(d_feld, d_feld_n, sizeof(d_feld[0]), vgl_fkt_double_absteigend);

	printf("Das double-Feld absteigend sortiert; mit Bibliotheksfunktion:\n");
	ausgeben_feld_allgemein(d_feld, d_feld_n, sizeof(d_feld[0]),
		ausgeben_double, stdout);
	
	{
		double suchwerte[] = { 7.0, -10.4, 5.5 };
		int suchwerte_n = sizeof(suchwerte) / sizeof(suchwerte[0]);
		int i;
		double *treffer_ptr;
		for(i = 0; i < suchwerte_n; i++)
		{
			// Statt &suchwerte[i] einfach so: suchwerte+i
			treffer_ptr = (double *)
				bsearch(&suchwerte[i], d_feld, d_feld_n, 
					sizeof(d_feld[0]), vgl_fkt_double_absteigend);
			if(treffer_ptr == NULL)
				printf("Gesuchter Wert %.1lf nicht gefunden!\n",
					suchwerte[i]);
			else
			{
				printf("Gesuchter Wert %.1lf an Adresse %p bzw. "
					"bei Index %ld gefunden!\n",
					suchwerte[i], treffer_ptr,
					treffer_ptr - d_feld);
			}
		}
	}

	return EXIT_SUCCESS;
} // main


/**
 * Diese Funktion gibt ein int-Feld
 * aus.
 */
void ausgeben_i_feld(int *ifeld_anf_ptr, int i_feld_n)
{
	int i;
	for(i = 0; i < i_feld_n; i++)
		printf("%3d  ", ifeld_anf_ptr[i]);
	printf("\n");
} // ausgeben_i_feld


/**
 * Diese Funktion gibt ein double-Feld
 * aus.
 */
void ausgeben_d_feld(double *dfeld_anf_ptr, int d_feld_n)
{
	int i;
	for(i = 0; i < d_feld_n; i++)
		printf("%5.1lf  ", dfeld_anf_ptr[i]);
	printf("\n");
} // ausgeben_d_feld


/**
 * Diese Callback-Vergleichsfunktion vergleicht
 * 2 int-Werte so miteinander, dass sich eine
 * aufsteigende Reihenfolge beim Sortieren ergibt.
 * 
 * Formale Parameter:
 *   v1_ptr - Adresse des ersten zu vergleichenden Feldelementes
 *   v2_ptr - Adresse des zweiten zu vergleichenden Feldelementes
 *
 * R?ckgabewert:
 *   neg. Ganzzahl - 1. Element vor 2. Element einzusortieren
 *   0 - beide Elemente gleich (aus Sicht der aktuellen Sortiverreihenfolge)
 *   pos. Ganzzahl - 1. Element nach 2. Element einzusortieren
 */
int vgl_fkt_int_aufsteigend(const void*v1_ptr, const void*v2_ptr)
{
	const int *i1_ptr = (const int*)v1_ptr;
	const int *i2_ptr = (const int*)v2_ptr;
	if(0)
	{
		if(*i1_ptr < *i2_ptr)
			return -1;
		if(*i1_ptr == *i2_ptr)
			return 0;
		return +1;
	}
	else
		return *i1_ptr - *i2_ptr;
} // vgl_fkt_int_aufsteigend


/**
 * Diese Callback-Vergleichsfunktion vergleicht
 * 2 int-Werte so miteinander, dass sich eine
 * absteigende Reihenfolge beim Sortieren ergibt.
 * 
 * Formale Parameter:
 *   v1_ptr - Adresse des ersten zu vergleichenden Feldelementes
 *   v2_ptr - Adresse des zweiten zu vergleichenden Feldelementes
 *
 * R?ckgabewert:
 *   neg. Ganzzahl - 1. Element vor 2. Element einzusortieren
 *   0 - beide Elemente gleich (aus Sicht der aktuellen Sortiverreihenfolge)
 *   pos. Ganzzahl - 1. Element nach 2. Element einzusortieren
 */
int vgl_fkt_int_absteigend(const void*v1_ptr, const void*v2_ptr)
{
	const int *i1_ptr = (const int*)v1_ptr;
	const int *i2_ptr = (const int*)v2_ptr;
	return *i2_ptr - *i1_ptr;
} // vgl_fkt_int_absteigend


/**
 * Diese Callback-Vergleichsfunktion vergleicht
 * 2 double-Werte so miteinander, dass sich eine
 * aufsteigende Reihenfolge beim Sortieren ergibt.
 * 
 * Formale Parameter:
 *   v1_ptr - Adresse des ersten zu vergleichenden Feldelementes
 *   v2_ptr - Adresse des zweiten zu vergleichenden Feldelementes
 *
 * R?ckgabewert:
 *   neg. Ganzzahl - 1. Element vor 2. Element einzusortieren
 *   0 - beide Elemente gleich (aus Sicht der aktuellen Sortiverreihenfolge)
 *   pos. Ganzzahl - 1. Element nach 2. Element einzusortieren
 */
int vgl_fkt_double_aufsteigend(const void*v1_ptr, const void*v2_ptr)
{
	const double *d1_ptr = (const double*)v1_ptr;
	const double *d2_ptr = (const double*)v2_ptr;
	if(1)
	{
		if(*d1_ptr < *d2_ptr)
			return -1;
		if(*d1_ptr == *d2_ptr)
			return 0;
		return +1;
	}
	//else
		// ACHTUNG!!! Das wird zwar mit Compiler-Warnung ?bersetzt, f?hrt
		//   aber zu einer fehlerhaften Sortierung, wenn sich 
		//   2 double-Werte betragsm??ig um weniger als 1.0
		//   unterscheiden!! Die Differenz (z.B. 0.5) wird beim Umwandeln
		//   in int brutal zu 0 verf?lscht, was also zu scheinbarer Gleichheit
		//   der Werte f?hrt. --> Die Sortierung ist fehlerhaft!
		//return *d1_ptr - *d2_ptr; // NEIN!!! Nicht bei Gleitkommazahlen!!!!
} // vgl_fkt_double_aufsteigend


/**
 * Diese Callback-Vergleichsfunktion vergleicht
 * 2 double-Werte so miteinander, dass sich eine
 * absteigende Reihenfolge beim Sortieren ergibt.
 * 
 * Formale Parameter:
 *   v1_ptr - Adresse des ersten zu vergleichenden Feldelementes
 *   v2_ptr - Adresse des zweiten zu vergleichenden Feldelementes
 *
 * R?ckgabewert:
 *   neg. Ganzzahl - 1. Element vor 2. Element einzusortieren
 *   0 - beide Elemente gleich (aus Sicht der aktuellen Sortiverreihenfolge)
 *   pos. Ganzzahl - 1. Element nach 2. Element einzusortieren
 */
int vgl_fkt_double_absteigend(const void*v1_ptr, const void*v2_ptr)
{
	const double *d1_ptr = (const double*)v1_ptr;
	const double *d2_ptr = (const double*)v2_ptr;
	// return *d2_ptr - *d1_ptr; NEIN!!!! Hier nicht m?glich!!!!
	if(*d1_ptr > *d2_ptr)
		return -1;
	if(*d1_ptr == *d2_ptr)
		return 0;
	return +1;
} // vgl_fkt_double_absteigend


/**
 * Diese Callback-Vergleichsfunktion vergleicht
 * 2 Texte so miteinander, dass sich eine
 * aufsteigende Reihenfolge beim Sortieren ergibt.
 * 
 * Formale Parameter:
 *   v1_ptr - Adresse des ersten zu vergleichenden Feldelementes
 *   v2_ptr - Adresse des zweiten zu vergleichenden Feldelementes
 *
 * R?ckgabewert:
 *   neg. Ganzzahl - 1. Element vor 2. Element einzusortieren
 *   0 - beide Elemente gleich (aus Sicht der aktuellen Sortiverreihenfolge)
 *   pos. Ganzzahl - 1. Element nach 2. Element einzusortieren
 */
int vgl_fkt_text_aufsteigend(const void*v1_ptr, const void*v2_ptr)
{
	const char*s1_ptr = (const char*)v1_ptr;
	const char*s2_ptr = (const char*)v2_ptr;
	return strcmp(s1_ptr, s2_ptr);
} // vgl_fkt_text_aufsteigend


/**
 * Diese Callback-Vergleichsfunktion vergleicht
 * 2 Personendatensätze so miteinander, dass sich eine
 * aufsteigende Reihenfolge (nach Name, Gehalt, Id) beim Sortieren ergibt.
 *
 *   @param v1_ptr Adresse des ersten zu vergleichenden Feldelementes
 *   @param v2_ptr Adresse des zweiten zu vergleichenden Feldelementes
 *
 *   @return
 *   neg. Ganzzahl - 1. Element vor 2. Element einzusortieren\n
 *   0 - beide Elemente gleich (aus Sicht der aktuellen Sortiverreihenfolge)\n
 *   pos. Ganzzahl - 1. Element nach 2. Element einzusortieren
 */
int vgl_fkt_name_gehalt_id_aufsteigend (const void*v1_ptr, const void*v2_ptr) {
	const struct personen_typ*s1_ptr = (struct personen_typ*)v1_ptr;
	const struct personen_typ*s2_ptr = (struct personen_typ*)v2_ptr;
	int erg = strcmp(s1_ptr->name_ptr, s2_ptr->name_ptr);
	if (erg != 0) return erg;

	if (s1_ptr->gehalt - s2_ptr->gehalt != 0) {
		return vgl_fkt_double_aufsteigend(&s1_ptr->gehalt,&s2_ptr->gehalt);
	}

	return vgl_fkt_int_aufsteigend(&s1_ptr->id,&s2_ptr->id);

}


/**
 * Diese Callback-Vergleichsfunktion vergleicht
 * 2 Personendatensätze so miteinander, dass sich eine
 * aufsteigende Reihenfolge (nach ID) beim Sortieren ergibt.
 *
 *   @param v1_ptr Adresse des ersten zu vergleichenden Feldelementes
 *   @param v2_ptr Adresse des zweiten zu vergleichenden Feldelementes
 *
 *   @return
 *   neg. Ganzzahl - 1. Element vor 2. Element einzusortieren\n
 *   0 - beide Elemente gleich (aus Sicht der aktuellen Sortiverreihenfolge)\n
 *   pos. Ganzzahl - 1. Element nach 2. Element einzusortieren
 */
int vgl_fkt_id_aufsteigend(const void*v1_ptr, const void*v2_ptr) {
	const struct personen_typ*s1_ptr = (struct personen_typ*)v1_ptr;
	const struct personen_typ*s2_ptr = (struct personen_typ*)v2_ptr;
	return vgl_fkt_int_aufsteigend(&s1_ptr->id,&s2_ptr->id);
}



/**
 * Eine Callback-Funktion zum Ausgeben eines
 * int-Wertes.
 */
int ausgeben_int(const void *element_vptr, FILE *ausgabe_fptr)
{
	return
		fprintf(ausgabe_fptr, "%3d  ", *(int*)element_vptr);
} // ausgeben_int


/**
 * Eine Callback-Funktion zum Ausgeben eines
 * double-Wertes.
 */
int ausgeben_double(const void *element_vptr, FILE *ausgabe_fptr)
{
	return
		fprintf(ausgabe_fptr, "%5.1lf  ", *(double*)element_vptr);
} // ausgeben_double


/**
 * Eine Callback-Funktion zum Ausgeben eines
 * Textes.
 */
int ausgeben_text(const void *element_vptr, FILE *ausgabe_fptr)
{
	return
		fprintf(ausgabe_fptr, "%s  ", (char*)element_vptr);
} // ausgeben_text

/**
 * Eine Callback-Funktion zum Ausgeben eines
 * Personendatensatzes.
 */
int ausgeben_pds(const void *element_vptr, FILE *ausgabe_fptr) {
	struct personen_typ *pds_ptr = (struct personen_typ*) element_vptr;
	return fprintf(ausgabe_fptr, "%4d %-10s %7.2lf EUR\n", pds_ptr->id, pds_ptr->name_ptr, pds_ptr->gehalt);
} // ausgeben_pds
