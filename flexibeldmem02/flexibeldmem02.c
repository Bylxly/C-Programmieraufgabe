/**
 * 
 * Dieses Programm zeigt die Verwendung des
 * struct-Datentyps in Verbindung mit
 *  enum   fuer die Metainformation ueber den
 *         aktuellen Datentyp
 *  union  fuer unterschiedliche Nutzung
 *
 * Ausserdem zeigt das Programm, wie man die
 * beiden Elemente miteinander verketten kann.
 *
 * 03.11.2025 TINF25CS1
 *
 */

/* Compiler-Direktiven
   fuer den Praeprozessor
*/

/* System-Header-Dateien */
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Eigene Header-Dateien */
/* ... */

/* Feldgroessen der statischen Felder.
*/
/* Laenge der statischen Textfelder. */
#define STR_LEN		100

/* Definitionen von eigenen Variablentypen */
enum typeninfo_typ{double_typ, int_typ, text_typ};
union mein_union_typ{double d; int i; char text[STR_LEN];};
struct flexibler_struct_typ
{ 
	/** Metainformation */
	enum typeninfo_typ			aktuellerTyp;
    union mein_union_typ		daten;
	/* Vorwaertsverkettungszeiger */
    struct flexibler_struct_typ	*next_ptr;
	/* Rueckwaertsverkettungszeiger */
    struct flexibler_struct_typ	*back_ptr;
};
enum richtungs_typ {
	vorwaerts, rueckwaerts
};

/* Globale Variablen */
/* ... */

/* Funktionsprototypen */
int durchlaufen(
	struct flexibler_struct_typ* einstiegs_ptr, 
	enum richtungs_typ richtung, 
	int (*ausgabe_fkt_ptr)
			(struct flexibler_struct_typ *element_ptr,
			 FILE *ausgabe_fptr),
	FILE *ausgabe_fptr);
int durchlaufen_rek(
	struct flexibler_struct_typ* einstiegs_ptr, 
	enum richtungs_typ richtung, 
	int (*ausgabe_fkt_ptr)
			(struct flexibler_struct_typ *element_ptr,
			 FILE *ausgabe_fptr),
	FILE *ausgabe_fptr);
// Callback-Funktionen zum Ausgeben
int ausgabe_lang
		(struct flexibler_struct_typ *element_ptr,
		FILE *ausgabe_fptr);
int ausgabe_kurz
		(struct flexibler_struct_typ *element_ptr,
		FILE *ausgabe_fptr);


/**
 *
 * Hauptprogramm ist Funktion main()
 *
 */

int main(int argc, char* argv[])
{
	/* Lokale Variablen */
	struct flexibler_struct_typ *anfangs_ptr = NULL, *ende_ptr = NULL;

	// Ausgabe-Datei/Datenstromzeiger
	FILE *ausgabe_fptr = stdout;
	// Anzahl der durchlaufenen Listenelemente
	int n;

	struct flexibler_struct_typ *temp = malloc(sizeof(struct flexibler_struct_typ));
	temp->next_ptr = NULL;
	temp->back_ptr = NULL;
	temp->aktuellerTyp = double_typ;
	temp->daten.d = 534.34;
	anfangs_ptr = temp;

	temp = calloc(1, sizeof(struct flexibler_struct_typ));
	temp->back_ptr = anfangs_ptr;
	temp->next_ptr = NULL;
	temp->aktuellerTyp = text_typ;
	strcpy(temp->daten.text, "Servus und Grüß Gott");
	anfangs_ptr->next_ptr = temp;
	ende_ptr = temp;


	// 7.5) 3. Element
	temp = realloc(NULL, sizeof(struct flexibler_struct_typ));
	temp->back_ptr = anfangs_ptr;
	anfangs_ptr->next_ptr = temp;

	temp->next_ptr = ende_ptr;
	ende_ptr->back_ptr = temp;

	temp->aktuellerTyp = int_typ;
	temp->daten.i = 192;



if(0)
{
	ausgabe_fptr = fopen("c:\\temp\\x1.txt", "wt");
	if(ausgabe_fptr != NULL)
		printf("Es wird in die gewuenschte Datei geschrieben!\n");
	else
		ausgabe_fptr = stdout;
}

	printf("Liste vorwaerts durchlaufen:\n");
	n = durchlaufen(anfangs_ptr, vorwaerts, ausgabe_lang, ausgabe_fptr);
	printf("main(): Anzahl Listenelemente = n = %d\n", n);

	printf("Liste rueckwaerts ITERATIV durchlaufen:\n");
	n = durchlaufen(ende_ptr, rueckwaerts, ausgabe_lang, ausgabe_fptr);
	printf("main(): Anzahl Listenelemente = n = %d\n", n);

	printf("Liste im Blindflug durchlaufen:\n");
	n = durchlaufen(anfangs_ptr, vorwaerts, NULL, ausgabe_fptr);
	printf("main(): Anzahl Listenelemente = n = %d\n", n);

	printf("Liste rueckwaerts REKURSIV mit kurzer Ausgabe durchlaufen:\n");
	n = durchlaufen_rek(ende_ptr, rueckwaerts, ausgabe_kurz, ausgabe_fptr);
	printf("main(): Anzahl Listenelemente = n = %d\n", n);

	if(ausgabe_fptr != stdout)
		fclose(ausgabe_fptr);

	printf("\n");

	return 0;
} /* main */


/**
 * Liste iterativ durchlaufen.
 */
int durchlaufen(
	struct flexibler_struct_typ* einstiegs_ptr, 
	enum richtungs_typ richtung, 
	int (*ausgabe_fkt_ptr)
			(struct flexibler_struct_typ *element_ptr,
			 FILE *ausgabe_fptr),
	FILE *ausgabe_fptr)
{
	// Lokale Zeigervariable zum Durchlaufen
	struct flexibler_struct_typ* lauf_ptr= einstiegs_ptr;
	// Zaehlvariable
	int n = 0;
	// Schleife zum Durchlaufen
	while (lauf_ptr != NULL)
	{
		if(ausgabe_fkt_ptr != NULL)
			ausgabe_fkt_ptr
				(lauf_ptr, ausgabe_fptr);
		n++; // Oder ++n; oder n=n+1; oder n += 1;
		if(richtung == vorwaerts)
			lauf_ptr= lauf_ptr->next_ptr;
		else
			lauf_ptr= lauf_ptr->back_ptr;
	} // while
	return n;
} // durchlaufen


/**
 * Liste rekursiv durchlaufen.
 */
int durchlaufen_rek(
	struct flexibler_struct_typ* einstiegs_ptr, 
	enum richtungs_typ richtung, 
	int (*ausgabe_fkt_ptr)
			(struct flexibler_struct_typ *element_ptr,
			 FILE *ausgabe_fptr),
	FILE *ausgabe_fptr)
{
	// Lokale Zeigervariable zum Durchlaufen
	struct flexibler_struct_typ* lauf_ptr= einstiegs_ptr;
	// Zaehlvariable
	int n = 0;
	// Schleife zum Durchlaufen ENTFAELLT!!!
	// while (lauf_ptr != NULL)
	if(lauf_ptr == NULL)
		return n;
	{
		if(ausgabe_fkt_ptr != NULL)
			ausgabe_fkt_ptr
				(lauf_ptr, ausgabe_fptr);
		n++; // Oder ++n; oder n=n+1; oder n += 1;
		if(richtung == vorwaerts)
			lauf_ptr= lauf_ptr->next_ptr;
		else
			lauf_ptr= lauf_ptr->back_ptr;
	} // while
	return n + durchlaufen_rek(
		lauf_ptr, richtung, ausgabe_fkt_ptr, ausgabe_fptr);
} // durchlaufen_rek


/**
 * Ausgabefunktion mit langer Ausgabe.
 */
int ausgabe_lang
		(struct flexibler_struct_typ *element_ptr,
		FILE *ausgabe_fptr)
{
	int anzahl_zeichen = 0;
	switch (element_ptr->aktuellerTyp)
	{
		case double_typ:
			anzahl_zeichen =
				fprintf(ausgabe_fptr, "Aktuelles Element enthaelt double_typ-Daten:  %f\n",
				element_ptr->daten.d);
			break;
		case int_typ:
			anzahl_zeichen =
			fprintf(ausgabe_fptr, "Aktuelles Element enthaelt int_typ-Daten:  %d\n",
				element_ptr->daten.i);
			break;
		case text_typ:
			anzahl_zeichen =
			fprintf(ausgabe_fptr, "Aktuelles Element enthaelt einen Text: '%s'\n",
				element_ptr->daten.text);
			break;
		default:
			fprintf(stderr,
				"Interner Fehler, unzulaessiger Datentyp = %d! "
				"Datei %s, Zeile %d Version %s %s\n",
				element_ptr->aktuellerTyp,
				__FILE__, __LINE__, __DATE__, __TIME__);
			exit(EXIT_FAILURE);
	} // switch
	return anzahl_zeichen;
} // ausgabe_lang


/**
 * Ausgabefunktion mit kurzer Ausgabe.
 */
int ausgabe_kurz
		(struct flexibler_struct_typ *element_ptr,
		FILE *ausgabe_fptr)
{
	int anzahl_zeichen = 0;
	switch (element_ptr->aktuellerTyp)
	{
		case double_typ:
			anzahl_zeichen =
				fprintf(ausgabe_fptr, "%f\n",
				element_ptr->daten.d);
			break;
		case int_typ:
			anzahl_zeichen =
			fprintf(ausgabe_fptr, "%d\n",
				element_ptr->daten.i);
			break;
		case text_typ:
			anzahl_zeichen =
			fprintf(ausgabe_fptr, "'%s'\n",
				element_ptr->daten.text);
			break;
		default:
			fprintf(stderr,
				"Interner Fehler, unzulaessiger Datentyp = %d! "
				"Datei %s, Zeile %d Version %s %s\n",
				element_ptr->aktuellerTyp,
				__FILE__, __LINE__, __DATE__, __TIME__);
			exit(EXIT_FAILURE);
	} // switch
	return anzahl_zeichen;
} // ausgabe_kurz
