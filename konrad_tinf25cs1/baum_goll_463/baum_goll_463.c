/**
* Baum-Beispiel aus Goll 6.Aufl. S.463ff.
*
* TINF25CS1, 24.11.2025
*/
// Standard-Header
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>       /* enthaelt den Prototyp von strcmp() */ 
#include <stdlib.h>       /* enthaelt den Prototyp von malloc() */ 

// Datentypen
struct knoten { char str[30]; 
long nummer; 
struct knoten * pointer_links; 
struct knoten * pointer_rechts; 
}; 

// Konstanten
const int ziffer_links  = 1; 
const int ziffer_rechts = 2; 

// Prototypen
long berechne_knoten_nummer (struct knoten *, long, int); 
struct knoten * knoten_einfuegen (struct knoten *, char *); 
struct knoten * suche (struct knoten *, char *); 
void drucke (struct knoten *); 
void knoten_loeschen (struct knoten *); 
struct knoten * pointer_auf_wurzel; 

/**
* Hauptprogramm.
*/
int main(void) 
{
	char buffer [30]; 
	struct knoten * neu_element_pointer; 
	struct knoten * ptr; 

	printf ("\n\n\nEs werden nun Knoten eingelesen, "); 
	printf ("(Abbruch mit $). \nGib den ersten Knoten ein: "); 
	while  (gets (buffer) != NULL && strcmp (buffer, "$")) 
	{ 
		if ((neu_element_pointer =
			knoten_einfuegen (pointer_auf_wurzel, buffer)) != NULL) 
		{ 
			if (pointer_auf_wurzel == NULL) 
			{ 
				/* Adresse der Wurzel                                 */ 
				pointer_auf_wurzel = neu_element_pointer; 
				/* Nummer der Wurzel                                  */ 
				pointer_auf_wurzel->nummer = 1L; 
			} 
			printf ("\nneue Knoten-Nummer: %ld",
				neu_element_pointer->nummer); 
		} 
		printf ("\n\nnaechsten Knoten eingeben: "); 
	} 
	printf ("\nNun werden die Knoten des Baumes ausgegeben\n\n"); 
	drucke (pointer_auf_wurzel); 
	printf ("Suchen nach Knoten, bis ein $ eingegeben wird."); 
	printf ("\nGib den Suchstring ein: "); 
	while (gets(buffer) != NULL && strcmp (buffer,"$")) 
	{ 
		if ((ptr = suche (pointer_auf_wurzel, buffer)) == NULL) 
			printf ("\nKnoten %s nicht vorhanden", buffer); 
		else 
			printf ("\nKnoten %s hat die Knoten-Nummer %ld", buffer, 
			ptr->nummer); 
		printf ("\n\nnaechsten Suchstring eingeben: "); 
	} 
	/* Zum Abschluss Loeschen aller Knoten */ 
	knoten_loeschen (pointer_auf_wurzel); 
	return 0; 
}


/** 
*
*/
long berechne_knoten_nummer (struct knoten * zeiger, long nummer, 
							 int ziffer) 
{
	if (zeiger == pointer_auf_wurzel) nummer = 10 + ziffer; 
	/* bei jedem Eintritt in die Wurzel muss wieder mit   */ 
	/* der Knotennummer 1 fuer die Wurzel begonnen werden */ 
	else 
		nummer = nummer * 10 + ziffer; 
	return nummer; 
}


/** 
*
*/
struct knoten * knoten_einfuegen (struct knoten * ptr, char * string) 
{
	static long knoten_nummer;   /* Wurzel enthaelt die Nummer 1   */ 
	struct knoten * ptrneu; 
	if(ptr == NULL) 
	{ 
		/* wenn ptr auf leeres Blatt zeigt, wird Knoten erzeugt.    */ 
		if((ptrneu =
			(struct knoten *)malloc (sizeof(struct knoten))) != NULL) 
		{ 
			strcpy (ptrneu->str, string) ; 
			/* im Knoten wird die Zeichenkette string gespeichert    */ 
			ptrneu->pointer_links = ptrneu->pointer_rechts = NULL; 
			/* der neu erzeugte Knoten hat noch keine Kinder         */ 
		} 
		else 
		{ 
			printf ("\nFehler bei malloc in Funktion knoten_einfuegen"); 
			return NULL; 
		} 
	} 
	else if (strcmp (string, ptr->str) < 0) 
	{ 
		/* es wird links weitergearbeitet */ 
		/* Bestimmung der Knotennummer    */ 
		knoten_nummer = berechne_knoten_nummer (ptr, knoten_nummer, 
			ziffer_links); 
		ptrneu = knoten_einfuegen(ptr->pointer_links, string); 
		if ((ptr->pointer_links == NULL) && (ptrneu != NULL)) 
			/* Wenn Teilbaum leer, wird der neue Knoten eingehaengt     */ 
		{ 
			ptr->pointer_links = ptrneu; 
			ptrneu->nummer    = knoten_nummer; 
		} 
	} 
	else if (strcmp(string, ptr->str) > 0) 
	{ 
		/* es wird rechts weitergearbeitet */ 
		/* Bestimmung der Knotennummer     */ 
		knoten_nummer = berechne_knoten_nummer (ptr, knoten_nummer, 
			ziffer_rechts); 
		ptrneu = knoten_einfuegen (ptr->pointer_rechts, string); 
		if ((ptr->pointer_rechts == NULL) && (ptrneu != NULL)) 
			/* Wenn Teilbaum leer, wird der neue Knoten eingehaengt     */ 
		{ 
			ptr->pointer_rechts = ptrneu; 
			ptrneu->nummer     = knoten_nummer; 
		} 
	} 
	else 
	{ 
		printf ("\nEintrag in Baum bereits vorhanden"); 
		return NULL; 
	} 
	return ptrneu;        /* Zeiger auf den neuen Knoten.          */ 
}


/** 
*
*/
struct knoten* suche (struct knoten * ptr, char * string) 
{
	struct knoten *ret_ptr; 
	if (ptr == NULL) 
		ret_ptr = NULL; 
	else 
	{ 
		if (strcmp (string, ptr->str) < 0) 
			ret_ptr = suche (ptr->pointer_links, string); 
		else if (strcmp (string, ptr->str) > 0) 
			ret_ptr = suche (ptr->pointer_rechts, string); 
		else 
			ret_ptr = ptr; 
	} 
	return ret_ptr; 
}


/** 
*
*/
void drucke (struct knoten * ptr) 
{
	if(ptr!= NULL) 
	{ 
		drucke (ptr->pointer_links);  /* linken Teilbaum ausgeben   */ 
		printf ("Knoten-String: %s", ptr->str); 
		/* Wurzel ausgeben                                          */ 
		printf (" Knoten-Nummer: %ld\n", ptr->nummer); 
		drucke (ptr->pointer_rechts); /* rechten Teilbaum ausgeben  */ 
	} 
}


/** 
*
*/
void knoten_loeschen (struct knoten * ptr) 
{
	if (ptr != NULL) 
	{ 
		knoten_loeschen (ptr->pointer_links); 
		knoten_loeschen (ptr->pointer_rechts); 
		free (ptr); 
	} 
}
